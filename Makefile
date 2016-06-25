# Makefile for RomanCalculator

# Directories used
INC_DIR = ./include
SRC_DIR = ./src
LIB_DIR = ./lib
BIN_DIR = ./bin
OBJ_DIR = ./obj
TEST_SRC_DIR = ./test

# Target names and paths
BASE_NAME = RomanCalculator
LIB_BASE_NAME = lib$(BASE_NAME).a
LIB_NAME = $(LIB_DIR)/$(LIB_BASE_NAME)
LIB_OBJS = $(OBJ_DIR)/$(BASE_NAME).o
TEST_BASE_NAME = $(BASE_NAME)Test
TEST_NAME = $(BIN_DIR)/$(TEST_BASE_NAME)
TEST_OBJS = $(OBJ_DIR)/$(TEST_BASE_NAME).o $(OBJ_DIR)/ValidRomanTestData.o

# compiler / linker flags
CFLAGS = -Wall -Werror -I$(INC_DIR)
CFLAGS_TEST = $(CFLAGS) -pthread
LFLAGS = -L$(LIB_DIR)
LIBS = -l$(BASE_NAME)

all: test lib

test: $(TEST_NAME)

$(TEST_NAME): $(LIB_NAME) $(TEST_OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) -o $(TEST_NAME) $(TEST_OBJS) $(LFLAGS) $(LIBS) -lcheck

lib: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJS)
	mkdir -p $(LIB_DIR)
	ar -r $@ $(LIB_OBJS)

$(OBJ_DIR)/$(BASE_NAME).o: $(SRC_DIR)/$(BASE_NAME).c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/$(TEST_BASE_NAME).o: $(TEST_SRC_DIR)/$(TEST_BASE_NAME).c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS_TEST) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/ValidRomanTestData.o: $(TEST_SRC_DIR)/ValidRomanTestData.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS_TEST) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(LIB_OBJS) $(TEST_OBJS) $(TEST_NAME) $(LIB_NAME)

.PHONY: all test lib clean
