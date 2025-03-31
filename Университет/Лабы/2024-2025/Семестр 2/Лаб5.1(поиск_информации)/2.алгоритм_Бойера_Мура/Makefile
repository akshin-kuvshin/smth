.PHONY: all

TARGET = main
SRC = main.c boyer_moore.c
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror -Wno-char-subscripts

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
