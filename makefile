OBJECTS = main.o entity.o game.o map.o interface.o item.o
CFLAGS = -Wall -O2
LDFLAGS = -lm -lncurses
CC = gcc

all: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LDFLAGS)

main.o: main.c interface.h game.h
	$(CC) $(CFLAGS) -c main.c

entity.o: entity.c entity_p.h entity.h action.h game.h
	$(CC) $(CFLAGS) -c entity.c

game.o: game.c entity.h action.h map.h item.h
	$(CC) $(CFLAGS) -c game.c

map.o: map.c map.h map_p.h
	$(CC) $(CFLAGS) -c map.c

interface.o: interface.c interface_p.h interface.h game.h
	$(CC) $(CFLAGS) -c interface.c

item.o: item.c item_p.h item.h
	$(CC) $(CFLAGS) -c item.c

run: all
	./main

clean:
	rm *.o main

