.PHONY: all

TARGET = main
SRC = main.c lib.c
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
