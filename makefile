CC = g++
CFLAGS = -Wall -Wextra

build: tictactoe

tictactoe: board.o player.o main.o
	$(CC) $(CFLAGS) -o tictactoe board.o player.o main.o

board.o: board.cpp board.h
	$(CC) $(CFLAGS) -c board.cpp

player.o: player.cpp player.h
	$(CC) $(CFLAGS) -c player.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f tictactoe *.o
