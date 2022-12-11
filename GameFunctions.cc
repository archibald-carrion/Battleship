#include "GameFunctions.hpp"


/**
 *  Interface to assembly routines
**/
extern "C" int canPlaceShip(long* myBoard, int index, int size, int direction);
extern "C" void placeShip(int shipValue, long* board, int size
   , int direction, int index);
extern "C" int canAttackPos(long* board, int index);
extern "C" int attackPos(long* attackBoard, long * myBoard, int index);
extern "C" int isShipSunken(long* board, int index, int size
   , int direction, int shipValue);
extern "C" int translate(int row, int column);
extern "C" void clearBoard(long* board);

/**
* @brief Class constructor
*/
GameFunctions::GameFunctions() {
    this->firstPlayerData = new ShipData [SHIP_AMOUNT];
    this->secondPlayerData = new ShipData [SHIP_AMOUNT];
    for (int i = 0; i < SHIP_AMOUNT; ++i) {
        firstPlayerData[i].initShipData();
        secondPlayerData[i].initShipData();
    }
}

/**
* @brief Class destructor
*/
GameFunctions::~GameFunctions() {  
    delete [] this->firstPlayerData;
    delete [] this->secondPlayerData;
}

/**
* @brief Checks if ship can be placed in desired direction
* @param shipData struct that contains ship information
* @param player Indicates the desired player
* @return Returns 1 if it can be placed 0 otherwise
*/
int GameFunctions::canPlace(ShipData* shipData, int player) {
    Player* currentPlayer;
    if (player == 1) {
        currentPlayer = &firstPlayer;
    } else { // Player is 2, no other number is expected
        currentPlayer = &secondPlayer;
    }
    int index = translate(shipData->row, shipData->column);

    return canPlaceShip(currentPlayer->getMyBoard(), index, shipData->size
      , shipData->dir);
}

/**
* @brief Places ship in desired position
* @param shipData struct that contains ship information
* @param player Indicates the desired player
*/
void GameFunctions::place(ShipData* shipData, int player) {
    Player* currentPlayer;
    if (player == 1) {
        currentPlayer = &firstPlayer;
    } else { // Player is 2, no other number is expected
        currentPlayer = &secondPlayer;
    }
    int index = translate(shipData->row, shipData->column);
    placeShip(shipData->symbol, currentPlayer->getMyBoard(), shipData->size
      , shipData->dir, index);
}

/**
* @brief Checks if position has been atacked before
* @param row Desired row to attack
* @param column Desired column to attack
* @param player Indicates the desired player
* @return Returns 1 if it can be attacked 0 otherwise
*/
int GameFunctions::canAttack(int row, int column, int player) {
    Player* currentPlayer;
    if (player == 1) {
        currentPlayer = &firstPlayer;
    } else { // Player is 2, no other number is expected
        currentPlayer = &secondPlayer;
    }
    int index = translate(row, column);

    return canAttackPos(currentPlayer->getAttackBoard(), index);
}

/**
* @brief Attacks in desired position
* @param row Desired row to attack
* @param column Desired column to attack
* @param player Indicates the desired player
* @return Returns -1 if attack failed, otherwise negative boat symbol
*/
int GameFunctions::attack(int row, int column, int player) {
    Player* attacker;
    Player* attacked;
    if (player == 1) {
        attacker = &firstPlayer;
        attacked = &secondPlayer;
    } else { // Player is 2, no other number is expected
        attacker = &secondPlayer;
        attacked = &firstPlayer;
    }
    int index = translate(row, column);

    return attackPos(attacker->getAttackBoard(), attacked->getMyBoard(), index);
}

/**
* @brief Checks if ship is sunken
* @param symbol Desired ship's symbol
* @param column Desired column to attack
* @return Returns -1 if ship is sunken, otherwise 0
*/
int GameFunctions::isSunken(int symbol, int player) {
    Player* currentPlayer;
    ShipData* shipData;
    if (player == 1) {
        currentPlayer = &firstPlayer;
        shipData = &firstPlayerData[symbol - 2];
    } else { // Player is 2, no other number is expected
        currentPlayer = &secondPlayer;
        shipData = &secondPlayerData[symbol - 2];
    }
    int index = translate(shipData->row, shipData->column);
    return isShipSunken(currentPlayer->getMyBoard(), index, shipData->size
      , shipData->dir, shipData->symbol);
}

/**
* @brief Adds ship to a player's array of ships
* @param shipData struct that contains ship information
* @param player Indicates the desired player
*/
void GameFunctions::addShip(ShipData* shipData, int player){
    // [0] = 2     [1] = 3     [2] = 4    [3] = 5
    int symbol = shipData->symbol;
    if (player == 2) {
        moveShipData(&secondPlayerData[symbol-2], shipData);
    } else {
        moveShipData(&firstPlayerData[symbol-2], shipData);
    }
    this->place(shipData, player);
}

/**
* @brief Moves ship data between two shipData
* @param destination shipData to be inserted into
* @param source Origin of ship data
*/
void GameFunctions::moveShipData(ShipData * destination, ShipData * source) {
    destination->row = source->row;
    destination->column = source->column;
    destination->size = source->size;
    destination->dir = source->dir;
    destination->symbol = source->symbol;
}

/**
* @brief Finds a ship through symbol and retrieves it's data
* @param symbol Desired ship's symbol
* @param player Indicates the desired player
*/
void GameFunctions::getShipData(int symbol, int player,
  ShipData * positionData) {
    ShipData* shipData;
    if (player == 1) {
        shipData = &firstPlayerData[symbol - 2];
    } else { // Player is 2, no other number is expected
        shipData = &secondPlayerData[symbol - 2];
    }
    positionData->row = shipData->row;
    positionData->column = shipData->column;
    positionData->size = shipData->size;
    positionData->dir = shipData->dir;
    positionData->symbol = shipData->symbol;
}

/**
* @brief Clears all boards
*/
void GameFunctions::clearBoards() {
    clearBoard(firstPlayer.getMyBoard());
    clearBoard(firstPlayer.getAttackBoard());
    clearBoard(secondPlayer.getMyBoard());
    clearBoard(secondPlayer.getAttackBoard());
}
