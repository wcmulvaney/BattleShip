//  A7 Battleship
//  Author: William Mulvaney (Not this file)
//  Course: CS368
//
//  Description: Program implements battleshipt game, using multiple classes to do so. Class
//  instances represent board, point and ship objects.

#ifndef BATTLESHIP_MAIN_H
#define BATTLESHIP_MAIN_H

#include <random>
#include <vector>
#include "Point.h"
#include "Ship.h"
#include "Board.h"

constexpr unsigned MAX_X{10};
constexpr unsigned MAX_Y{10};

std::vector<Ship<MAX_X,MAX_Y>> player;
std::vector<Ship<MAX_X,MAX_Y>> computer;
Board<MAX_X,MAX_Y> pBoard(false);
Board<MAX_X,MAX_Y> cBoard(true);

/**
 * Ship object, defined by a name and a length
 */
struct DefShip {
  unsigned len;
  std::string name;
};
  
std::vector<DefShip> ships {{2, "destroyer"},
                            {3, "cruiser"},
                            {3, "submarine"},
                            {4, "battleship"},
                            {5, "carrier"}};
/**
* Create the board, initialize players
*/
void initGame();

/**
* Places computer ships randomly on board.
* Gets user input and places ships as specified.
*/
void placeShips(std::default_random_engine &rand);
/**
* Runs the loop that the game is played through.
* Continues until computer or player wins.
*/
void playGame(std::default_random_engine &rand);
/**
* Check whether a player has lost all of their ships
*/
bool checkLost(std::vector<Ship<MAX_X,MAX_Y>> &ships);
/**
 * Perform a shot operation based on coordinates given by computer or user
 */
void doShot(Point<MAX_X,MAX_Y> &shot, std::vector<Ship<MAX_X,MAX_Y>> &ships, Board<MAX_X,MAX_Y> &board);
/**
 * Print the current computer and player board
 */
void printBoards();

#endif

