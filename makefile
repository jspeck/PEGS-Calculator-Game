CC = gcc
CFLAGS = -I include
LDFLAGS = -L/usr/lib -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf
INCLUDE = -I. -I./include -I/usr/include/allegro5

OBJS = main.o game_loop.o input.o levels.o Play.o shapes.o System.o
OUT = PEGS

all: PEGS

clean:
	rm -rf *.o PEGS

PEGS: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)