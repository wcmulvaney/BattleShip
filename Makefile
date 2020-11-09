# MakeFile for BattleShip
# William Mulvaney
# ID: 9078280725

CXX = g++

CXXFLAGS = -Wall -g

all: build

Point.o: Point.h
Board.o: Board.h Point.h
Ship.o: Ship.h Board.h Point.h
BattleShip.o: BattleShip.h BattleShip.cpp

clean:
	-rm BattleShip.o
	-rm Point.o
	-rm Board.o
	-rm Ship.o

build: BattleShip.o 
	$(CXX) $(CXXFLAGS) -o BattleShip.exe BattleShip.o

