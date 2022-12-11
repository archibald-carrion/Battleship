all: compile link

compile:
	g++ -c main.cc Game.cc GameFunctions.cc Player.cc functions.s Board.cc vector.s

link:
	g++ main.o Game.o GameFunctions.o Player.o functions.o Board.o vector.o -o game.out -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o

cleanAll:
	del *.o
	del *.exe
	del *.out
