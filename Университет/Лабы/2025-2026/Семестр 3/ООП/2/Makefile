# author: Danila "akshin_" Axyonov (ideas were borrowed from Roman Ostafeychuk)

.PHONY: all

TARGET = main
SRC = main.cpp
CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -Werror

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

