#!/bin/bash
# filepath: /home/lilith/LP/Tarea2/vg.sh
make
# Define output directory
VG_DIR="vg_results"

# Create output directory if it doesn't exist
if [ ! -d "$VG_DIR" ]; then
    echo "Creating directory $VG_DIR for valgrind results"
    mkdir -p "$VG_DIR"
fi

# Store counter in a file so it persists between runs
COUNTER_FILE="$VG_DIR/.vg_counter"

# Initialize or read counter
if [ -f "$COUNTER_FILE" ]; then
    counter_of_test=$(cat "$COUNTER_FILE")
else
    counter_of_test=0
    echo "$counter_of_test" > "$COUNTER_FILE"
fi

# Increment counter for this run
counter_of_test=$((counter_of_test + 1))
echo "$counter_of_test" > "$COUNTER_FILE"

# Output file for this run
OUTPUT_FILE="$VG_DIR/vg_${counter_of_test}"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

echo "Running Valgrind analysis #${counter_of_test}..."
echo "Output will be saved to: ${OUTPUT_FILE}"

# Run valgrind with memory checking options
valgrind --leak-check=full --show-leak-kinds=all \
         --track-origins=yes \
         --log-file="${OUTPUT_FILE}" ./bin/Tarea2_LP

# Extract memory leak information
DEFINITELY_LOST=$(grep "definitely lost:" "${OUTPUT_FILE}" | awk '{print $4}')
INDIRECTLY_LOST=$(grep "indirectly lost:" "${OUTPUT_FILE}" | awk '{print $4}')
POSSIBLY_LOST=$(grep "possibly lost:" "${OUTPUT_FILE}" | awk '{print $4}')
ERRORS=$(grep "ERROR SUMMARY:" "${OUTPUT_FILE}" | awk '{print $4}')

# Calculate total leaks
TOTAL_LEAKS=$((DEFINITELY_LOST + INDIRECTLY_LOST + POSSIBLY_LOST))

# Print results
echo -e "\n===== MEMORY ANALYSIS RESULTS =====\n"

if [ "$ERRORS" -gt 0 ]; then
    echo -e "${RED}$ERRORS memory errors detected${NC}"
else
    echo -e "${GREEN}No memory errors detected${NC}"
fi

if [ "$TOTAL_LEAKS" -gt 0 ]; then
    echo -e "${RED}$TOTAL_LEAKS bytes leaked in heap:${NC}"
    echo -e "  ${YELLOW}Definitely lost: $DEFINITELY_LOST bytes${NC}"
    echo -e "  ${YELLOW}Indirectly lost: $INDIRECTLY_LOST bytes${NC}" 
    echo -e "  ${YELLOW}Possibly lost: $POSSIBLY_LOST bytes${NC}"
else
    echo -e "${GREEN}0 leaks detected${NC}"
fi

echo -e "\nFull details available in: ${OUTPUT_FILE}"