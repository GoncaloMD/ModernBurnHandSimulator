build:
	g++ -c Type.cpp
	g++ -c ManaCost.cpp
	g++ -c Card.cpp
	g++ -c main.cpp
	g++ -o main.exe main.o Card.o Type.o ManaCost.o

run:
	./main.exe