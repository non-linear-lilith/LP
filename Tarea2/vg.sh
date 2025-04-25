##############################################################################
#            VG 
# Valgrind Script Analyzer
# by Katherine Huidobro github:non-linear-lilith
#
# Generic script to run Valgrind on a C++ executable
# This script runs Valgrind on the specified executable, 
# checks for memory leaks, and stores the results in a specified directory.
# It also keeps track of the number of times it has been run
# and creates a new output file for each run.
# The script uses colors to highlight the output.
#
###############################################################################

# first check if valgrind is installed
if ! command -v valgrind &> /dev/null
then
    echo "Valgrind could not be found. Please install it first."
    exit
fi
# runs the makefile to compile the code, if you want to run it without compiling, comment this line below
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
OUTPUT_FILE="$VG_DIR/vg_${counter_of_test}.txt"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color
# Check if executable exists
if [ ! -f "./bin/Tarea2_LP" ]; then
    echo "Error: Executable ./bin/Tarea2_LP not found!"
    exit 1
fi


# Run valgrind with memory checking options and -s
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
echo -e "\n===== VALGRIND MEMORY ANALYSIS RESULTS =====\n"

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