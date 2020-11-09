//  A7 Battleship
//  Author: William Mulvaney
//  Course: CS368
//
//  Description: Program implements battleshipt game, using multiple classes to do so. Class
//  instances represent board, point and ship objects.

#ifndef BOARD_H
#define BOARD_H

#include "Point.h"

/**
 * Class that is used to represent a board. Stores information about each point
 * on the board.
 */
template<unsigned int xmax, unsigned int ymax>
class Board{

    /**
     * Overloaded output operator. Displays formatted output to os.
     */
	friend std::ostream& operator<<(std::ostream& os, const Board& p){
        os << "   ";
        for(int i = 0; i < xmax; i++)
			os << (char) ('A' + i);
		os << std::endl;
		for(int i = 0; i < ymax; i++){
            if(i + 1 < 10)
                os << " ";
            os << " " << i + 1;
			for(int j = 0; j < xmax; j++){
				switch(p.statuses[j][i]){
					case EMPTY:
						os << '~';
						break;
					case SHIP:
						if(p.hideShips)
							os << '~';
						else
							os << '=';
						break;
					case MISS:
						os << 'x';
						break;
					case HIT:
						os << '*';
						break;
				}
			}
            os << std::endl;
		}			
	}

public:
    /**
     * Constructor that allows hideShips boolean to be set.
     * Initializes statuses
     */
	explicit Board(bool hide){
        hideShips = hide;
        for(int i = 0; i < xmax; i++)
            for(int j = 0; j < ymax; j++)
                statuses[i][j] = EMPTY;
    }
    /**
     * Default constructor that only initializes statuses.
     */
	explicit Board(){
        for( int i = 0; i < xmax; i++)
            for( int j = 0; j < ymax; j++)
                statuses[i][j] = EMPTY;
    }

    /**
     * Set status of a given point.
     */
	void setStatus(const Point <xmax, ymax> p, Status s){
        if(p.x >= xmax || p.y >= ymax) throw std::invalid_argument("Point not on board");
        board[p.x][p.y].status = s;
        updateStatuses();
	}
	

    /**
     * Returns the point from variable ship, and sets the status to SHIP. Used to put ships
     * on the board.
     */
	Point<xmax, ymax>* getShipPoint (const Point<xmax, ymax> p, unsigned X, unsigned Y){
		
        if(p.x + X >= xmax ||p.y + Y >= ymax)
            throw std::invalid_argument("Ship placed partially or completely off board");
	if(board[p.x + X][p.y + Y].status == SHIP)
		throw std::invalid_argument("Already a ship here");

		
	board[p.x + X][p.y + Y].status = SHIP;
        board[p.x + X][p.y + Y].x = p.x + X;
        board[p.x + X][p.y + Y].y = p.y + Y;
        
        updateStatuses();
	return &board[p.x + X][p.y + Y];
	}

private:
    Point<xmax, ymax> board[xmax][ymax];
    bool hideShips = true;
    Status statuses[xmax][ymax]; // Private array used to store statuses for use by << operator
    
    /**
     * Private function used to update statuses array
     */
    void updateStatuses(){
        for(int i = 0; i < xmax; i++)
            for(int j = 0; j < ymax; j++)
                statuses[i][j] = board[i][j].status;
    }
};









#endif
