# Java compiler
JC = javac

# Java runtime
JR = java

# Compiler flags
JFLAGS = -d bin -sourcepath .

# Source files
JAVALING_SOURCES = $(wildcard Javaling/*.java)
SRC_SOURCES = $(wildcard src/*.java)
ALL_SOURCES = $(JAVALING_SOURCES) $(SRC_SOURCES)

# Class files
CLASS_FILES = $(ALL_SOURCES:%.java=bin/%.class)

# Default target
all: bin $(CLASS_FILES)

# Create bin directory and subdirectories
bin:
	mkdir -p bin/Javaling
	mkdir -p bin/src

# Compile Java files
bin/%.class: %.java
	$(JC) $(JFLAGS) $<

# Run the program
run: all
	$(JR) -cp bin src.Main

# Clean compiled files
clean:
	rm -rf bin

# Phony targets
.PHONY: all run clean

# docs for Javaling and src to be seen in the same documentation
docs:
	@echo "Generating documentation..."
	javadoc -d docs -sourcepath . -subpackages Javaling src
	@echo "Documentation generated in docs directory."