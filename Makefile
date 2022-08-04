build:
	g++ -c card.cpp
	g++ -c main.cpp
	g++ -o main.exe main.o card.o

run:
	./main.exe