#include "Player.hpp"

#include <iostream>
using namespace std;

/**
* @brief Class constructor for Player instances
*/
Player::Player() {
    myBoard = new Board(49, 0);
    attackBoard = new Board(49, 0);
}

/**
* @brief Class destructor
*/
Player::~Player() {
    delete myBoard;
    delete attackBoard;
}

/**
* @brief Returns this player's attack board
* @return this->attackBoard->vector Desired attack board
*/
long * Player::getAttackBoard() {
    return this->attackBoard->vector;
}
  
/**
* @brief Returns this player's own defense board
* @return this->attackBoard->vector Desired defense board
*/
long * Player::getMyBoard() {
    return this->myBoard->vector;
}

/**
* @brief Prints the board
*/
void Player::printBoard() {
    myBoard->printBoard();
    cout << "\n";
    attackBoard->printBoard();
}