output: main.o
	g++ -std=c++0x -Wall main.o -o vector

main.o: main.cpp methods.h methods.hxx
	g++ -c main.cpp

clean:
	rm *.o vector