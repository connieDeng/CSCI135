CXXFLAGS=-g
main: main.o DList.o Node.o
	g++ -o main main.o DList.o Node.o


DList.o: DList.cpp DList.h Node.h

Node.o: Node.cpp Node.h

test: test.cpp DList.o Node.o
	g++ -o test test.cpp DList.o Node.o

clean:
	rm -f main.o test.o DList.o Node.o
