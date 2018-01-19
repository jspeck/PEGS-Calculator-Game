CC = gcc
LD = gcc
CFLAGS = -g -Wall -Iinclude
LDFLAGS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf
RM = /bin/rm -f
OBJS = main.o game_loop.o input.o levels.o Play.o shapes.o System.o
PROG = PEGS

all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

main.o: main.c game_loop.c input.c levels.c Play.c shapes.c System.c

game_loop.o: input.c levels.c Play.c shapes.c System.c
	$(CC) $(CFLAGS) -c file1.c

input.o : game_loop.c levels.c Play.c shapes.c System.c
	$(CC) $(CFLAGS) -c file1.c

levels.o : game_loop.c input.c Play.c shapes.c System.c
	$(CC) $(CFLAGS) -c file1.c

Play.o : game_loop.c input.c levels.c shapes.c System.c
	$(CC) $(CFLAGS) -c file1.c

shapes.o : game_loop.c input.c levels.c Play.c System.c
	$(CC) $(CFLAGS) -c file1.c

System.o : game_loop.c input.c levels.c Play.c shapes.c
	$(CC) $(CFLAGS) -c file1.c

clean:
	$(RM) $(PROG) $(OBJS)



