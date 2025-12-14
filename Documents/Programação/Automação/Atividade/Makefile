# Variáveis
CC := gcc
CFLAGS := -Iunity -Isrc -Wall -Wextra -g
BUILD_DIR := build
SRC_DIR := src
TEST_DIR := test
UNITY := unity/unity.c

# Fontes
SRC := $(SRC_DIR)/atividade.c
TEST := $(TEST_DIR)/test_atividade.c

# Nome do executável de teste
TEST_EXE := $(BUILD_DIR)/tests

.PHONY: all test_run clean

# alvo padrão
all: test_run

# Compila e executa os testes
test_run: $(TEST_EXE)
	@echo "Running tests..."
	@./$(TEST_EXE)

# Linking/compilação do executável de testes
$(TEST_EXE): $(SRC) $(TEST) $(UNITY) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(TEST) $(UNITY)

# Garante que o diretório build existe antes de compilar
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpeza
clean:
	@echo "Cleaning..."
	-rm -f $(TEST_EXE)
	-rm -f $(BUILD_DIR)/relatorio.txt