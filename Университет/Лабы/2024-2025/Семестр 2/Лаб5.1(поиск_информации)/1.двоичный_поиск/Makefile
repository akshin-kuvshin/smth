.PHONY: all

TARGET = main
SRC = main.c array_ops.c random.c binary_search.c
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
