#ifndef PLAYER_H
#define PLAYER_H

#include "Board.hpp"

class Player {
  public:
    Player();
    ~Player();
    long* getAttackBoard();
    long* getMyBoard();
    void printBoard();
  private:
    Board* myBoard;
    Board* attackBoard;
};

#endif  // PLAYER_H