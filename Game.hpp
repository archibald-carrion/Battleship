#ifndef MYGAME_
#define MYGAME_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Button.hpp"
#include "BoardInterface.hpp"
#include "Common.hpp"
#include "GameFunctions.hpp"
#include "Textbox.hpp"

#define HEIGHT 548
#define WIDTH 1086
#define maxFPS 60

class Game
{
private:
    // GameFunctions attribute
    GameFunctions *gameFunctions;

    // Game class private functions
    void initVariable();
    void initWindow();
    void initEnemies();

    Button *startButton;
    Button *leaveButton;
    Button *abandonGameButton;
    Button *returnMenuButton;
    Button *endTurnButton;
    Button *infoButton;

    // POISTIONING BUTTONS
    Button *arrowUp;
    Button *arrowDown;
    Button *arrowRight;
    Button *arrowLeft;
    Button *placeShip;
    Button *attackButton;

    // START BUTTON TEXTURES & SPRITES
    sf::Texture *startTextureDef;
    sf::Texture *startTextureHov;
    sf::Sprite *startSpriteDef;
    sf::Sprite *startSpriteHov;

    // ABANDON GAME BUTTON TEXTURES & SPRITES
    sf::Texture *abandonTextureDef;
    sf::Texture *abandonTextureHov;
    sf::Sprite *abandonSpriteDef;
    sf::Sprite *abandonSpriteHov;

    // LEAVE BUTTON TEXTURES & SPRITES
    sf::Texture *leaveTextureDef;
    sf::Texture *leaveTextureHov;
    sf::Sprite *leaveSpriteDef;
    sf::Sprite *leaveSpriteHov;


    // RETURN MAIN MENU TEXTURES & SPRITES
    sf::Texture *returnMenuTextureDef;
    sf::Texture *returnMenuTextureHov;
    sf::Sprite *returnMenuSpriteDef;
    sf::Sprite *returnMenuSpriteHov;

    // END TURN TEXTURES & SPRITES
    sf::Texture *endTurnTextureDef;
    sf::Texture *endTurnTextureHov;
    sf::Sprite *endTurnSpriteDef;
    sf::Sprite *endTurnSpriteHov;

    // ATTACK TEXTURES & SPRITES
    sf::Texture *attackTextureDef;
    sf::Texture *attackTextureHov;
    sf::Sprite *attackSpriteDef;
    sf::Sprite *attackSpriteHov;

    // ARROW UP
    sf::Texture *upTextureDef;
    sf::Texture *upTextureHov;
    sf::Sprite *upSpriteDef;
    sf::Sprite *upSpriteHov;

    // ARROW DOWN
    sf::Texture *downTextureDef;
    sf::Texture *downTextureHov;
    sf::Sprite *downSpriteDef;
    sf::Sprite *downSpriteHov;

    // ARROW RIGHT
    sf::Texture *rightTextureDef;
    sf::Texture *rightTextureHov;
    sf::Sprite *rightSpriteDef;
    sf::Sprite *rightSpriteHov;

    // ARROW LEFT left
    sf::Texture *leftTextureDef;
    sf::Texture *leftTextureHov;
    sf::Sprite *leftSpriteDef;
    sf::Sprite *leftSpriteHov;

    // PLACE SHIP
    sf::Texture *placeTextureDef;
    sf::Texture *placeTextureHov;
    sf::Sprite *placeSpriteDef;
    sf::Sprite *placeSpriteHov;

    // INFO BUTTON
    sf::Texture *infoTextureDef;
    sf::Texture *infoTextureHov;
    sf::Sprite *infoSpriteDef;
    sf::Sprite *infoSpriteHov;


    // BOARDS
    BoardInterface *ownBoardP1;
    BoardInterface *ownBoardP2;
    BoardInterface *attackBoardP1;
    BoardInterface *attackBoardP2;

    // TEXTBOX FOR receiving (x,y) inputs from user
    Textbox *xAxisInput;
    Textbox *yAxisInput;

    // Game class attributes
    //int finishPositioning = 0;
    int playerTurn = 1; // 1 means that it's P1 turn, and 2 means that it's P2 turn
    int init = 2;
    int state = 0;
    int shipPositioning = 2;
    char activeTextBox = 'x';
    int turnEnded = 0;
    int quantitySunkenShipsP1 = 0;
    int quantitySunkenShipsP2 = 0;
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Sprite spriteWindow; // either board, main menu, intermediate menu, or credits
    sf::Font mainFont;       // the font that we use for botton, text box, text, [...]


    void setAssets();       // position&scale buttons and other assets
    void renderMainMenu();
    void renderInitialBoardP1();
    void renderInitialBoardP2();
    void renderIntermediateMenu();
    void renderP1();
    void renderP2();
    int checkPositioning();
    int checkAttack();
    void readAxis(sf::Event);
    void p1WinRender();
    void p2WinRender();
    void instructionsRender();

    


    ShipData positionData;
    //positionData.initShipData();

public:
    Game();        // Game class constructor
    ~Game();       // Game class destructor
    void update(); // poll the events and execute a different routine depending of the event
    void render(); // manage the window, choose depending the game state what must be shown to the player
    int running(); // function checking if the game is still running or not
};

#endif
