#ifndef BOARD_BATTLESHIP_SFML
#define BOARD_BATTLESHIP_SFML

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Button.hpp"
#include "Common.hpp"

#define north 0
#define east 1
#define south 2
#define west 3

// El barco va a ser parte del sprite. Entonces son muchas combinaciones.
class BoardInterface
{
    friend class Game;

private:
    class Tile
    {
        friend class BoardInterface;

    private:
        Button *tile;
        sf::Texture *BasicTileTexture;
        sf::Texture *failedBombTexture;
        sf::Texture *TileGREYTexture;
        sf::Texture *TileREDTexture;
        sf::Texture *TileBLACKTexture;

        sf::Sprite *BasicTileSprite;  // basic water
        sf::Sprite *failedBombSprite; // bomb in water
        sf::Sprite *TileGREYSprite;   // normal ship
        sf::Sprite *TileREDSprite;    // fully destroyed ship
        sf::Sprite *TileBLACKSprite;  // partially destroyed ship

        int state;
        
        /**
        * @brief Tile is the constructor of the Tile class
        */
        Tile()
        {
            this->initVariable();
            tile = new Button(BasicTileSprite);
            state = 0;
        }

        /**
        * @brief Tile is the destructor of the Tile class
        */
        ~Tile()
        {
            delete tile;
            delete BasicTileSprite;
            delete failedBombSprite;
            delete TileGREYSprite;
            delete TileREDSprite;
            delete TileBLACKSprite;
            delete BasicTileTexture;
            delete failedBombTexture;
            delete TileGREYTexture;
            delete TileREDTexture;
            delete TileBLACKTexture;
        }

        /**
        * @brief intiVariable is a function used to initialize all the sprites, textures of the class
        */
        void initVariable()
        {
            BasicTileTexture = new sf::Texture();
            BasicTileTexture->loadFromFile("src/assets/tile1.png");
            BasicTileSprite = new sf::Sprite();
            BasicTileSprite->setTexture(*BasicTileTexture);

            TileGREYTexture = new sf::Texture();
            TileGREYTexture->loadFromFile("src/assets/Tiles/tileGREY.png");
            TileGREYSprite = new sf::Sprite();
            TileGREYSprite->setTexture(*TileGREYTexture);

            TileREDTexture = new sf::Texture();
            TileREDTexture->loadFromFile("src/assets/Tiles/tileRED.png");
            TileREDSprite = new sf::Sprite();
            TileREDSprite->setTexture(*TileREDTexture);

            TileBLACKTexture = new sf::Texture();
            TileBLACKTexture->loadFromFile("src/assets/ReducedTiles/tileBlack.png");
            TileBLACKSprite = new sf::Sprite();
            TileBLACKSprite->setTexture(*TileBLACKTexture);

            failedBombTexture = new sf::Texture();
            failedBombTexture->loadFromFile("src/assets/ReducedTiles/tileNotSunkenMiss.png");
            failedBombSprite = new sf::Sprite();
            failedBombSprite->setTexture(*failedBombTexture);
        }

        /**
	    * @brief setPosition allow the code to change the position of the tile on the window
	    * @param position is a sf::Vector2f, a vector used as a position
	    */
        void setPosition(sf::Vector2f position)
        {
            tile->setPosition(position);
        }

        /**
	    * @brief setScale function is used to scale the tile x and y proportions
	    * @param x is a float value, it's the new scale for the x axis of the tile
	    * @param y is a float value, it's the new scale for the y axis of the tile
	    */
        void setScale(float x, float y)
        {
            tile->setScale(x, y);
        }

        /**
	    * @brief drawOnWindow is the function used to draw the tile on the window
	    * @param window window is a sf::RenderWindow passed by reference
	    */
        void drawOnWindow(sf::RenderWindow &window)
        {
            tile->drawOnWindow(window);
        }

        /**
	    * @brief getState is used to return the actual state of the object
	    * @return the function return an int, the actual state of the object
	    */
        int getState()
        {
            return state;
        }

        /**
	    * @brief setState is used to cahnge the actual state of the object
	    */
        void setState(int newState)
        {
            switch (newState)
            {
            case -1: // bomb in water
                tile->setSprite(failedBombSprite);
                break;

            case 1: // water
                tile->setSprite(BasicTileSprite);
                break;

            case 2: // boat
                tile->setSprite(TileGREYSprite);
                break;

            case 3: // fully destroyed ship
                tile->setSprite(TileREDSprite);
                break;

            case 4: // partially  destroyed ship
                tile->setSprite(TileBLACKSprite);
                break;

            default:
                break;
            }
            state = newState;
        }
    };

    Tile board[7][7]; // actual board, made of 49 tiles

public:

    /**
	* @brief BoardInterface is the constructor of the BoardInferface class
	*/
    BoardInterface() {}

    /**
	* @brief ~BoardInterface is the constructor of the BoardInferface class
	*/
    ~BoardInterface() {}

    /**
     * @brief the function setPosition let the program set the current position of the board on the window
     * @param side side is the only parameter of the function, if side is 0, then we set the board to the left side of the 		board, if side is 1, we set the board on the right side of the board
     */
    void setPosition(int side)
    {
        int xModifier;
        int yModifier = 160;

        if (side == 0)
        {
            for (size_t row = 0; row < 7; row++)
            { // board is positioned in the left side
                xModifier = 75;
                for (size_t column = 0; column < 7; column++)
                {
                    board[row][column].setPosition({(float)(xModifier), (float)(yModifier)});
                    board[row][column].setScale(0.3f, 0.3f);
                    xModifier = xModifier + 45;
                }
                yModifier = yModifier + 45;
            }
        }
        else
        { // same, but to the right side instead of the left side

            for (size_t row = 0; row < 7; row++)
            {
                xModifier = 725;
                for (size_t column = 0; column < 7; column++)
                {
                    board[row][column].setPosition({(float)(xModifier), (float)(yModifier)});
                    board[row][column].setScale(0.3f, 0.3f);
                    xModifier = xModifier + 45;
                }
                yModifier = yModifier + 45;
            }
        }

    }

    /**
     * @brief the function setTile is used to change the state of a given cell of the board
     * @param column is the value of the column of the cell of wich we want to change the state
     * @param row is the value of the row of the cell of wich we want to change the state
     * @param state is the new value of the state of the cell [row][column]
     */
    void setTile(int column, int row, int state)
    {
        board[row][column].setState(state);
    }

    /**
    * @brief setShipAsSunken is used to change the state of a ship to sunken
    * @param positionData is of type ShipData, it's the data of the ship we want to set as sunken
    */
    void setShipAsSunken(ShipData positionData)
    {
        // set ship as sunken

        int posY = positionData.row;
        int posX = positionData.column;

        int size = positionData.size;
        int counter = 0;

        int dir = positionData.dir;

        while (counter < size)
        {
            board[posY][posX].setState(3);
            // switch for every position -> inc or dec
            switch (dir)
            {
            case 1: // left
                --posX;
                break;

            case 2: // up
                --posY;
                break;

            case 3: // right
                ++posX;
                break;

            case 4: // down
                ++posY;
                break;
            }

            ++counter;
        }
    }

    /**
     * @brief drawOnWindow is used to draw the board on the given window
     * @param window is a sf::RenderWindow given by reference, it's the window on wich we want to draw the board
     */
    void drawOnWindow(sf::RenderWindow &window)
    {
        for (size_t row = 0; row < 7; row++)
        {
            for (size_t column = 0; column < 7; column++)
            {
                board[row][column].drawOnWindow(window);
            }
        }
    }

    /**
    * @brief saddShip is used to place a new ship on the board
    * @param positionData is of type ShipData, it's the data of the ship we want to add to the board
    */
    void addShip(ShipData positionData)
    {
        int posY = positionData.row;
        int posX = positionData.column;

        int size = positionData.size;
        int counter = 0;

        int dir = positionData.dir;

        while (counter < size)
        {
            board[posY][posX].setState(2);
            // switch for every position -> inc or dec
            switch (dir)
            {
            case 1: // left
                --posX;
                break;

            case 2: // up
                --posY;
                break;

            case 3: // right
                ++posX;
                break;

            case 4: // down
                ++posY;
                break;
            }
            ++counter;
        }
    }

    /**
    * @brief clearBoard is used to clear the board, in other words, it's used to set all the tiles as water
    */
    void clearBoard()
    {
        for (size_t row = 0; row < 7; row++)
        {
            for (size_t column = 0; column < 7; column++)
            {
                board[row][column].setState(1);
            }
        }
    }
};
#endif