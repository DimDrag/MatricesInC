CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
TFLAGS=-lcheck -lm -lpthread
CGFLAGS = -fprofile-arcs -ftest-coverage --coverage -O0

BUILD_DIR = build
TESTS_DIR = tests
TARGET_LIB_SOURCES = $(wildcard *.c)
TESTS_SOURCES = $(wildcard tests/*.c)
TARGET_LIB_OBJECTS = $(patsubst %.c, %.o, $(TARGET_LIB_SOURCES))
TARGET_LIB = s21_matrix.a
TESTS_EXEC_FILE = tests_exec_file
OS_NAME = $(shell uname)
MEMORY_CHECKER = leaks -atExit --

ifeq ($(OS_NAME), Linux)
	TFLAGS += -lsubunit -lrt
	MEMORY_CHECKER = valgrind -s --leak-check=full
endif

all: $(TARGET_LIB) test run_test gcov_report

$(TARGET_LIB): $(TARGET_LIB_OBJECTS)
	echo $(BUILD_DIR)/tests
	ar -rcs $(TARGET_LIB) $(BUILD_DIR)/*.o

test:
	@for file in $(patsubst %.c, %, $(TARGET_LIB_SOURCES) $(TESTS_SOURCES)); do \
	$(CC) $(CFLAGS) -c $$file.c -o $(BUILD_DIR)/$$file.o $(TFLAGS) $(CGFLAGS); \
	done
	ar -rcs $(TARGET_LIB) $(BUILD_DIR)/*.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/$(TESTS_DIR)/*.o $(TARGET_LIB) -o $(TESTS_DIR)/$(TESTS_EXEC_FILE) $(TFLAGS) $(CGFLAGS)

run_test: test
	$(TESTS_DIR)/$(TESTS_EXEC_FILE)

style_fix:
	clang-format --style=Google -i *.c *.h
	clang-format --style=Google -i $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h

style_check:
	clang-format --style=Google -n *.c *.h
	clang-format --style=Google -n $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h

memory_leaks_check: test
	CK_FORK=no $(MEMORY_CHECKER) $(TESTS_DIR)/$(TESTS_EXEC_FILE)

gcov_report: test run_test
	@rm -rf $(BUILD_DIR)/$(TESTS_DIR)/*
	@lcov -f -d $(BUILD_DIR) -c -o report/report.info
	@genhtml -o report report/report.info

clean:
	rm -rf $(TARGET_LIB) $(TESTS_DIR)/$(TESTS_EXEC_FILE) report/*
	rm -rf $(BUILD_DIR)/*.gc* $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TESTS_DIR)/*

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/$@