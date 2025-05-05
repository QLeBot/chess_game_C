CC = gcc
CFLAGS = -Wall -Wextra -g
SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LIBS = $(shell sdl2-config --libs)

SRCS = main.c interface.c initialisation.c mouvements.c etatechec.c transformation.c IA.c pieces.c
OBJS = $(SRCS:.c=.o)
TARGET = chess_game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(SDL2_LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(SDL2_CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 