build:
	g++ -c card-enum.cpp
	g++ -c main.cpp
	g++ -o main.exe main.o card-enum.o

run:
	./main.exe