CXXFLAGS=-std=c++11

main: main.o funcs.o
	g++ $(CXXFLAGS) -o main main.o funcs.o

test: test.o funcs.o
	g++ -$(CXXFLAGS) -o test test.o funcs.o

test.o: test.cpp funcs.h

main.o: main.cpp funcs.h

fact.o: funcs.cpp funcs.h

clean:
	rm funcs.o main.o
