OPTIONS=-g -Wall -std=c++11 -pedantic

all: testSkipList

cellule.o: cellule.cpp
	g++ $(OPTIONS) -c cellule.cpp -o cellule.o

skipList.o: skipList.cpp
	g++ $(OPTIONS) -c skipList.cpp -o skipList.o

testSkipList.o: testSkipList.cpp
	g++ $(OPTIONS) -c testSkipList.cpp -o testSkipList.o

testSkipList: testSkipList.o cellule.o skipList.o
	g++ $(OPTIONS) testSkipList.o cellule.o skipList.o -o sl

clean:
	rm -f *.o sl