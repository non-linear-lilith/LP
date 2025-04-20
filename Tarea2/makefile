# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g
# Directories
AUTHOR = "Katherine Huidobro Castillo"
MAIL = "khuidobro@usm.cl"
GITHUB = "non-linear-lilith"
ROL = "202304656-6"
# Variables
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include
FILENAME = Tarea2_LP
# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
EXEC = $(BIN_DIR)/$(FILENAME)

# Timing variables
TIME1_as_number = $(shell date +%s%N | cut -b1-13)

# Targets
.PHONY: all clean run dirs

all: dirs $(EXEC)
	
	@echo "Iniciando Compilación $(FILENAME)..."
	@echo "Construyendo carpeta build: $(BUILD_DIR)"
	@echo "Archivos del bin: $(BIN_DIR)"
	@echo "Archivos fuente (source): $(SRCS)"
	@echo "Archivos de tipo Objeto: $(OBJS)"
	@echo "Ejecutable: $(EXEC)"
	@echo "Compilación Completada."
	@echo "Iniciar programa con: ./$(EXEC)"
	@echo "Limpiar bin y build con: make clean"
	@echo "Correr con: make run"
	@echo "Makefile creado por $(AUTHOR)"
	@echo "Github: $(GITHUB)"
	@echo "Correo: $(MAIL)"
	@echo "Rol: $(ROL)"
	@TIME2_as_number=$$(date +%s%N | cut -b1-13); \
	ELAPSED_TIME=$$(($$TIME2_as_number - $(TIME1_as_number))); \
	echo "Compilación exitosa, tiempo de compilación: $$ELAPSED_TIME ms \n \n"


dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	rm -rf .vscode
run: all
	./$(EXEC)



Time2_as_number = "$(shell date +%s)"

