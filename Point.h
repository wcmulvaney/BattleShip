//  A7 Battleship
//  Author: William Mulvaney
//  Course: CS368
//
//  Description: Program implements battleshipt game, using multiple classes to do so. Class
//  instances represent board, point and ship objects.

#ifndef POINT_H
#define POINT_H

#include <stdexcept>
#include <iostream>

enum Status {EMPTY, SHIP, MISS, HIT}; // Enumerator for status of a point

/**
 * Class used to represent points on a board. Points have a status and a coordinate location.
 */
template<unsigned int xmax, unsigned int ymax>
class Point {
    
    template<unsigned, unsigned> friend class Board;
    template<unsigned, unsigned> friend class Ship;
   // friend std::ostream& operator<<(std::ostream& os, const Board& p);
    
 	/**
	 * Overloaded == operator. True if x and y coordinates of points are equal.
	 */
	friend bool operator==(const Point& p1, const Point& p2){
                return p1.x == p2.x && p1.y == p2.y;
        }
	/**
	 * Overloaded output operator, prints out point in coordinate form.
	 * Ex. point x = 0, y = 0 prints as (1, A).
	 */
	friend std::ostream& operator<<(std::ostream& os, const Point& p){
		os << "(" << p.x + 1 << "," << (char) xToChar(p.y) << ")";
	}


public:
	Point(){}
	/**
	 * Constructor that takes a char for the x coordinate and
	 * an unsigned int for y coordinate. 
	 * Throws out_of_range exception if either coordinate is outside
	 * range.
	 */
	Point(char xc, unsigned int yc){
		// Check if x-coordinate in range
		if(xToInt(xc) >= xmax || xToInt(xc) < 0)
			throw std::out_of_range("Alphabet x-coordinate outside range");
		// Check if y-coordinate in range
		if(yc >= ymax)
			throw std::out_of_range("Integer y-coordinate outside range");
		// Set x to correct int value based on upper/lower input
        x = xToInt(xc);

		y = yc;
	}

	/**
         * Constructor that takes an unsigned int for the x coordinate and
         * an unsigned int for y coordinate.
         * Throws out_of_range exception if either coordinate is outside
         * range.
         */
	Point(unsigned int xc, unsigned int yc){
		// Check if x-coordinate in range
		if(xc >= xmax)
			throw std::out_of_range("Integer x-coordinate outside range");
		// Check if y-coordinate in range
		if(yc >= ymax)
			throw std::out_of_range("Integer y-coordinate outside range");
		x = xc;
		y = yc;
	}

	/**
	 * Returns status of point
	 */
	Status getStatus(){
		return status;
	}

	/**
	 * Converts unsigned int to a char with starting position 'A'
	 */
	static char xToChar(unsigned int x) {return ((char) x + 'A');}
	
	/**
	 * Converts char to an int, assuming starting position 'A'
	 */
	static int xToInt(char x) {return (int) x - 'A';}
    
private:
    // Enumerator that keeps track of status of position
    Status status = EMPTY;
    unsigned int x = 0; // x coordinate of point
    unsigned int y = 0; // y coordinate of point
    
};
#endif
