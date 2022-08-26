all: compile link

compile:
	g++ -c main.cpp Game.cpp -I"C:\Users\archi\Documents\Ordi\Technology\coding\c++\lib\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ main.o Game.o -o game -L"C:\Users\archi\Documents\Ordi\Technology\coding\c++\lib\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	del *.o

cleanA:
	del *.o
	del *.exe