CC = gcc
CFLAGS = -Wall -Wextra -g
SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LIBS = $(shell sdl2-config --libs)

# Source and include directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(BUILD_DIR)/chess_game

# Include paths
INCLUDES = -I$(INCLUDE_DIR)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $(TARGET) $(SDL2_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SDL2_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean