build:
	g++ -c CardName.cpp
	g++ -c Type.cpp
	g++ -c ManaCost.cpp
	g++ -c Card.cpp
	g++ -c Deck.cpp
	g++ -c BurnUtils.cpp
	g++ -c KeepPercentageResult.cpp
	g++ -c BurnCards.cpp
	g++ -c main.cpp
	g++ -o main.exe main.o Card.o BurnUtils.O Deck.o CardName.o Type.o ManaCost.o KeepPercentageResult.o BurnCards.o

run:
	./main.exe