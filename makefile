OBJECTS = entity.o game.o map.o
CFLAGS = -Wall
LDFLAGS = 
CC = gcc

all: $(OBJECTS)
	@echo "we do not have a main yet"

entity.o: entity.c entity.h action.h game.h
	$(CC) $(CFLAGS) -c entity.c

game.o: game.c entity.h action.h map.h
	$(CC) $(CFLAGS) -c game.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

clean:
	rm *.o

