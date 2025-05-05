.PHONY: all

TARGET = main
SRC = main.cpp RPN.cpp char_ops.cpp
CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -Werror

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
