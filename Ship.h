//  A7 Battleship
//  Author: William Mulvaney
//  Course: CS368
//
//  Description: Program implements battleshipt game, using multiple classes to do so. Class
//  instances represent board, point and ship objects.

#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <vector>
#include "Point.h"
#include "Board.h"

enum Direction {VERTICAL, HORIZONTAL}; // Enumerator used to store direction

/**
 * Class used to represent Ship objects. Stores coordinates of ship.
 */
template<unsigned int xmax, unsigned int ymax>
class Ship{


public:
    /**
     * Ship constructor that takes in a ship name and a vector with ship coordinates
     */
	Ship(std::string shipName, const std::vector<Point<xmax, ymax>*> shipCoor){
		name = shipName;
		ship = shipCoor;
	}

    /**
     * Ship constructor that takes in a starting point, a ship length, and a direction.
     * Creates the ship by adding all necessary points
     */
	Ship(std::string shipName, const Point<xmax, ymax>& p, unsigned len, Direction direction, Board<xmax,ymax>& board){
		name = shipName;
		ship = std::vector<Point<xmax, ymax>*>();
		
		int i = 0;
		try{
			for(; i < len; i++){
				if(direction == HORIZONTAL)
					ship.push_back(board.getShipPoint(p, i, 0));
				else
					ship.push_back(board.getShipPoint(p, 0, i));
		}
		} catch(const std::invalid_argument& e){
			for(int j = 0; j < i; j++)
			       ship[j]->status = EMPTY;	
			throw std::invalid_argument("Overlapping Ships");
		}
	}

    /**
     * Returns true if input point exists on ship
     */
	bool isHit(const Point <xmax, ymax> & p) {
        for(int i = 0; i < ship.size(); i++){
            if(p == *ship[i]){
                ship[i]->status = HIT;
                return true;
                break;
            }
        }
        return false;
	}
    /**
     * Returns true if the ship has been entirely hit
     */
	bool isSunk(){
		for(int i = 0; i < ship.size(); i++){
			if(ship[i]->status != HIT)
				return false;
		}
		return true;
	}
    /**
     * Sets name of ship
     */
	void setName(std::string shipName){
		name = shipName;
	}
    
    /**
     * Retrieves the name of the ship
     */
	std::string getName(){
		return name;
	}
    
private:
    std::string name;
    std::vector < Point<xmax, ymax>* > ship;
};
#endif
