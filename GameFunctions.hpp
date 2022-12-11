#ifndef GAMEFUNCTIONS_HPP
#define GAMEFUNCTIONS_HPP

#include "Common.hpp"
#include "Player.hpp"

#define SHIP_AMOUNT 4

class GameFunctions {
  public:
    GameFunctions();
    ~GameFunctions();
    // player = 1 or player = 2
    int canPlace(ShipData* shipData, int player);
    void place(ShipData* shipData, int player);
    int canAttack(int row, int columun, int player);
    int attack(int row, int columun, int player);
    int isSunken(int symbol, int player);
    // [0] = 2     [1] = 3     [2] = 4    [3] = 5
    void addShip(ShipData* shipData, int player);
    void getShipData(int symbol, int player, ShipData * shipData);
    void clearBoards();

  private:
    // Attributes
    Player firstPlayer;
    Player secondPlayer;
    ShipData * firstPlayerData;
    ShipData * secondPlayerData;
    // Methods
    // destination -> inserted into source
    void moveShipData(ShipData * destination, ShipData * source);
};

#endif  // GAMEFUNCTIONS_HPP
