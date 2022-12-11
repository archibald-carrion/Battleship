#include "Game.hpp"
#include "GameFunctions.hpp"

/**
 * @brief Game function is the default constructor of the Game class, it reveices no parameters
 */
Game::Game()
{
    gameFunctions = new GameFunctions();
    this->initWindow();
    this->initVariable();
}

/**
 * @brief ~Game function is the destructor of the Game class, it reveices no parameters
 */
Game::~Game()
{
    delete gameFunctions;

    delete this->ownBoardP1;
    delete this->ownBoardP2;

    delete this->startButton;
    delete this->startTextureDef;
    delete this->startTextureHov;
    delete this->startSpriteDef;
    delete this->startSpriteHov;

    delete this->abandonGameButton;
    delete this->abandonTextureDef;
    delete this->abandonTextureHov;
    delete this->abandonSpriteDef;
    delete this->abandonSpriteHov;

    delete this->leaveButton;
    delete this->leaveTextureDef;
    delete this->leaveTextureHov;
    delete this->leaveSpriteDef;
    delete this->leaveSpriteHov;

    delete this->returnMenuButton;
    delete this->returnMenuTextureDef;
    delete this->returnMenuTextureHov;
    delete this->returnMenuSpriteDef;
    delete this->returnMenuSpriteHov;
    
    delete this->endTurnButton;
    delete this->endTurnTextureDef;
    delete this->endTurnTextureHov;
    delete this->endTurnSpriteDef;
    delete this->endTurnSpriteHov;

    delete this->arrowUp;
    delete this->upTextureDef;
    delete this->upTextureHov;
    delete this->upSpriteDef;
    delete this->upSpriteHov;

    delete this->arrowDown;
    delete this->downTextureDef;
    delete this->downTextureHov;
    delete this->downSpriteDef;
    delete this->downSpriteHov;

    delete this->arrowRight;
    delete this->rightTextureDef;
    delete this->rightTextureHov;
    delete this->rightSpriteDef;
    delete this->rightSpriteHov;

    delete this->arrowLeft;
    delete this->leftTextureDef;
    delete this->leftTextureHov;
    delete this->leftSpriteDef;
    delete this->leftSpriteHov;

    delete this->placeShip;
    delete this->placeTextureDef;
    delete this->placeTextureHov;
    delete this->placeSpriteDef;
    delete this->placeSpriteHov;

    delete this->infoButton;
    delete this->infoTextureDef;
    delete this->infoTextureHov;
    delete this->infoSpriteDef;
    delete this->infoSpriteHov;


    delete this->xAxisInput;
    delete this->yAxisInput;
}

/**
 * @brief initVariable function is used to initialize some of the class attributes, buttons, sprites, and textures included
 */
void Game::initVariable()
{
    positionData.initShipData();
    mainFont.loadFromFile("src/Roboto/Roboto-Bold.ttf");
    //this->window = 0;
    positionData.initShipData();

    // boards
    ownBoardP1 = new BoardInterface();
    ownBoardP2 = new BoardInterface();
    attackBoardP1 = new BoardInterface();
    attackBoardP2 = new BoardInterface();

    // START
    startTextureDef = new sf::Texture();
    startTextureDef->loadFromFile("src/assets/Start1.png");
    startSpriteDef = new sf::Sprite();
    startSpriteDef->setTexture(*startTextureDef);
    startButton = new Button(startSpriteDef);

    startTextureHov = new sf::Texture();
    startTextureHov->loadFromFile("src/assets/Start2.png");
    startSpriteHov = new sf::Sprite();
    startSpriteHov->setTexture(*startTextureHov);

    // LEAVE
    leaveTextureDef = new sf::Texture();
    leaveTextureDef->loadFromFile("src/assets/Exit1.png");
    leaveSpriteDef = new sf::Sprite();
    leaveSpriteDef->setTexture(*leaveTextureDef);
    leaveButton = new Button(leaveSpriteDef);

    leaveTextureHov = new sf::Texture();
    leaveTextureHov->loadFromFile("src/assets/Exit2.png");
    leaveSpriteHov = new sf::Sprite();
    leaveSpriteHov->setTexture(*leaveTextureHov);

    // ABANDON
    abandonTextureDef = new sf::Texture();
    abandonTextureDef->loadFromFile("src/assets/AbandonGame1.png");
    abandonSpriteDef = new sf::Sprite();
    abandonSpriteDef->setTexture(*abandonTextureDef);
    abandonGameButton = new Button(abandonSpriteDef);

    abandonTextureHov = new sf::Texture();
    abandonTextureHov->loadFromFile("src/assets/AbandonGame2.png");
    abandonSpriteHov = new sf::Sprite();
    abandonSpriteHov->setTexture(*abandonTextureHov);

    // RETURN MAIN MENU
    returnMenuTextureDef = new sf::Texture();
    returnMenuTextureDef->loadFromFile("src/assets/Return1.png");
    returnMenuSpriteDef = new sf::Sprite();
    returnMenuSpriteDef->setTexture(*returnMenuTextureDef);
    returnMenuButton = new Button(returnMenuSpriteDef);

    returnMenuTextureHov = new sf::Texture();
    returnMenuTextureHov->loadFromFile("src/assets/Return2.png");
    returnMenuSpriteHov = new sf::Sprite();
    returnMenuSpriteHov->setTexture(*returnMenuTextureHov);

    // END TURN
    endTurnTextureDef = new sf::Texture();
    endTurnTextureDef->loadFromFile("src/assets/EndTurn1.png");
    endTurnSpriteDef = new sf::Sprite();
    endTurnSpriteDef->setTexture(*endTurnTextureDef);
    endTurnButton = new Button(endTurnSpriteDef);

    endTurnTextureHov = new sf::Texture();
    endTurnTextureHov->loadFromFile("src/assets/EndTurn2.png");
    endTurnSpriteHov = new sf::Sprite();
    endTurnSpriteHov->setTexture(*endTurnTextureHov);

    // ATTACK
    attackTextureDef = new sf::Texture();
    attackTextureDef->loadFromFile("src/assets/AttackButton1.png");
    attackSpriteDef = new sf::Sprite();
    attackSpriteDef->setTexture(*attackTextureDef);
    attackButton = new Button(attackSpriteDef);

    attackTextureHov = new sf::Texture();
    attackTextureHov->loadFromFile("src/assets/AttackButton2.png");
    attackSpriteHov = new sf::Sprite();
    attackSpriteHov->setTexture(*attackTextureHov);

    // UP ARROW
    upTextureDef = new sf::Texture();
    upTextureDef->loadFromFile("src/assets/UpArrow1.png");
    upSpriteDef = new sf::Sprite();
    upSpriteDef->setTexture(*upTextureDef);
    arrowUp = new Button(upSpriteDef);

    upTextureHov = new sf::Texture();
    upTextureHov->loadFromFile("src/assets/UpArrow2.png");
    upSpriteHov = new sf::Sprite();
    upSpriteHov->setTexture(*upTextureHov);

    // DOWN ARROW
    downTextureDef = new sf::Texture();
    downTextureDef->loadFromFile("src/assets/downArrow1.png");
    downSpriteDef = new sf::Sprite();
    downSpriteDef->setTexture(*downTextureDef);
    arrowDown = new Button(downSpriteDef);

    downTextureHov = new sf::Texture();
    downTextureHov->loadFromFile("src/assets/downArrow2.png");
    downSpriteHov = new sf::Sprite();
    downSpriteHov->setTexture(*downTextureHov);

    // RIGHT ARROW
    rightTextureDef = new sf::Texture();
    rightTextureDef->loadFromFile("src/assets/rightArrow1.png");
    rightSpriteDef = new sf::Sprite();
    rightSpriteDef->setTexture(*rightTextureDef);
    arrowRight = new Button(rightSpriteDef);

    rightTextureHov = new sf::Texture();
    rightTextureHov->loadFromFile("src/assets/rightArrow2.png");
    rightSpriteHov = new sf::Sprite();
    rightSpriteHov->setTexture(*rightTextureHov);

    // LEFT ARROW
    leftTextureDef = new sf::Texture();
    leftTextureDef->loadFromFile("src/assets/leftArrow1.png");
    leftSpriteDef = new sf::Sprite();
    leftSpriteDef->setTexture(*leftTextureDef);
    arrowLeft = new Button(leftSpriteDef);

    leftTextureHov = new sf::Texture();
    leftTextureHov->loadFromFile("src/assets/leftArrow2.png");
    leftSpriteHov = new sf::Sprite();
    leftSpriteHov->setTexture(*leftTextureHov);

    // PLACE SHIP
    placeTextureDef = new sf::Texture();
    placeTextureDef->loadFromFile("src/assets/placeShip1.png");
    placeSpriteDef = new sf::Sprite();
    placeSpriteDef->setTexture(*placeTextureDef);
    placeShip = new Button(placeSpriteDef);

    placeTextureHov = new sf::Texture();
    placeTextureHov->loadFromFile("src/assets/placeShip2.png");
    placeSpriteHov = new sf::Sprite();
    placeSpriteHov->setTexture(*placeTextureHov);

    // INFO BUTTON
    infoTextureDef = new sf::Texture();
    infoTextureDef->loadFromFile("src/assets/InstructionsButton2.png");
    infoSpriteDef = new sf::Sprite();
    infoSpriteDef->setTexture(*infoTextureDef);
    infoButton = new Button(infoSpriteDef);

    infoTextureHov = new sf::Texture();
    infoTextureHov->loadFromFile("src/assets/InstructionsButton.png");
    infoSpriteHov = new sf::Sprite();
    infoSpriteHov->setTexture(*infoTextureHov);

    xAxisInput = new Textbox(30);
    yAxisInput = new Textbox(30);
    xAxisInput->setSelected(0);
    yAxisInput->setSelected(0);

}

/**
 * @brief The initWindow function is used to initialize the video mode, the window, adn other similar parameters of the game
 */
void Game::initWindow()
{
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH; // give right dimension to the videoMode
    this->window = new sf::RenderWindow(this->videoMode, "Battleship", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60); // set the max FPS of the game to 60, this way the game does execute "faster" in some computer than in others
}

/**
 * @brief The update function allow us to poll events, read every input from the user and take decision depending from those inputs
 */
void Game::update()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
        {
            this->window->close();
            break;
        }

        case sf::Event::TextEntered:
        {
            this->readAxis(event);
            break;
        }

        case sf::Event::KeyPressed:
        {
            if (this->event.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }

            if (this->event.key.code == sf::Keyboard::Enter)
            {
                this->readAxis(event); // switch from textbox and/or checkout input to positionData
            }
            
            break;
        }

        case sf::Event::MouseMoved:
        {

            if (leaveButton->mouseHovering(*this->window))
            {
                leaveButton->setSprite(leaveSpriteHov);
            }
            else
            {
                leaveButton->setSprite(leaveSpriteDef);
            }

            switch (state)
            {
            case 0:
            { // main menu
                if (startButton->mouseHovering(*this->window))
                {
                    startButton->setSprite(startSpriteHov);
                }
                else
                {
                    startButton->setSprite(startSpriteDef);
                }

                if (infoButton->mouseHovering(*this->window))
                {
                    infoButton->setSprite(infoSpriteHov);
                }
                else
                {
                    infoButton->setSprite(infoSpriteDef);
                }
                break;
            }

            case 1:
            { // P1 positioning ships
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    abandonGameButton->setSprite(abandonSpriteHov);
                }
                else
                {
                    abandonGameButton->setSprite(abandonSpriteDef);
                }

                if (arrowUp->mouseHovering(*this->window))
                {
                    arrowUp->setSprite(upSpriteHov);
                }
                else
                {
                    arrowUp->setSprite(upSpriteDef);
                }

                if (arrowDown->mouseHovering(*this->window))
                {
                    arrowDown->setSprite(downSpriteHov);
                }
                else
                {
                    arrowDown->setSprite(downSpriteDef);
                }

                if (arrowRight->mouseHovering(*this->window))
                {
                    arrowRight->setSprite(rightSpriteHov);
                }
                else
                {
                    arrowRight->setSprite(rightSpriteDef);
                }

                if (arrowLeft->mouseHovering(*this->window))
                {
                    arrowLeft->setSprite(leftSpriteHov);
                }
                else
                {
                    arrowLeft->setSprite(leftSpriteDef);
                }

                if (placeShip->mouseHovering(*this->window))
                {
                    placeShip->setSprite(placeSpriteHov);
                }
                else
                {
                    placeShip->setSprite(placeSpriteDef);
                }

                if (endTurnButton->mouseHovering(*this->window))
                {
                    endTurnButton->setSprite(endTurnSpriteHov);
                }
                else
                {
                    endTurnButton->setSprite(endTurnSpriteDef);
                }
                
                // read user input -> return (wichShip, start, size, dir)
                // read answer -> if 1 changed matrix, else continue reading input from user
                //loop until every ships is positioned
                break;
            }

            case 2:
            { // P2 positioning ships
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    abandonGameButton->setSprite(abandonSpriteHov);
                }
                else
                {
                    abandonGameButton->setSprite(abandonSpriteDef);
                }

                if (arrowUp->mouseHovering(*this->window))
                {
                    arrowUp->setSprite(upSpriteHov);
                }
                else
                {
                    arrowUp->setSprite(upSpriteDef);
                }

                if (arrowDown->mouseHovering(*this->window))
                {
                    arrowDown->setSprite(downSpriteHov);
                }
                else
                {
                    arrowDown->setSprite(downSpriteDef);
                }

                if (arrowRight->mouseHovering(*this->window))
                {
                    arrowRight->setSprite(rightSpriteHov);
                }
                else
                {
                    arrowRight->setSprite(rightSpriteDef);
                }

                if (arrowLeft->mouseHovering(*this->window))
                {
                    arrowLeft->setSprite(leftSpriteHov);
                }
                else
                {
                    arrowLeft->setSprite(leftSpriteDef);
                }

                if (placeShip->mouseHovering(*this->window))
                {
                    placeShip->setSprite(placeSpriteHov);
                }
                else
                {
                    placeShip->setSprite(placeSpriteDef);
                }

                if (endTurnButton->mouseHovering(*this->window))
                {
                    endTurnButton->setSprite(endTurnSpriteHov);
                }
                else
                {
                    endTurnButton->setSprite(endTurnSpriteDef);
                }
                
                // read user input -> return (wichShip, start, size, dir)
                // read answer -> if 1 changed matrix, else continue reading input from user
                //loop until every ships is positioned
                break;
            }

            case 3: // P1 attacking
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    abandonGameButton->setSprite(abandonSpriteHov);
                }
                else
                {
                    abandonGameButton->setSprite(abandonSpriteDef);
                }

                if (endTurnButton->mouseHovering(*this->window))
                {
                    endTurnButton->setSprite(endTurnSpriteHov);
                }
                else
                {
                    endTurnButton->setSprite(endTurnSpriteDef);
                }

                if (attackButton->mouseHovering(*this->window))
                {
                    attackButton->setSprite(attackSpriteHov);
                }
                else
                {
                    attackButton->setSprite(attackSpriteDef);
                }

                break;
            }

            case 4: // P2 attacking
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    abandonGameButton->setSprite(abandonSpriteHov);
                }
                else
                {
                    abandonGameButton->setSprite(abandonSpriteDef);
                }

                if (endTurnButton->mouseHovering(*this->window))
                {
                    endTurnButton->setSprite(endTurnSpriteHov);
                }
                else
                {
                    endTurnButton->setSprite(endTurnSpriteDef);
                }

                if (attackButton->mouseHovering(*this->window))
                {
                    attackButton->setSprite(attackSpriteHov);
                }
                else
                {
                    attackButton->setSprite(attackSpriteDef);
                }
                break;
            }

            case 5: // intermediate menu
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    abandonGameButton->setSprite(abandonSpriteHov);
                }
                else
                {
                    abandonGameButton->setSprite(abandonSpriteDef);
                }

                if (startButton->mouseHovering(*this->window))
                {
                    startButton->setSprite(startSpriteHov);
                }
                else
                {
                    startButton->setSprite(startSpriteDef);
                }
                break;
            }

            case 6: // P1 win game
            {
                if (returnMenuButton->mouseHovering(*this->window))
                {
                    returnMenuButton->setSprite(returnMenuSpriteHov);
                }
                else
                {
                    returnMenuButton->setSprite(returnMenuSpriteDef);
                }
                break;
            }

            case 7: // P2 win game
            {
                if (returnMenuButton->mouseHovering(*this->window))
                {
                    returnMenuButton->setSprite(returnMenuSpriteHov);
                }
                else
                {
                    returnMenuButton->setSprite(returnMenuSpriteDef);
                }
                break;
            }

            case 8: // draw, nobody won this game
                break;

            case 9: // instructions
                if (returnMenuButton->mouseHovering(*this->window))
                {
                    returnMenuButton->setSprite(returnMenuSpriteHov);
                }
                else
                {
                    returnMenuButton->setSprite(returnMenuSpriteDef);
                }
                break;

            case 10: // credits
                break;

            default:
                break;
            }
            break;
        }

        case sf::Event::MouseButtonPressed:
        {
            if (leaveButton->mouseHovering(*this->window))
            {
                this->window->close();
            }

            switch (state)
            {
            case 0: // main menu
            {
                if (startButton->mouseHovering(*this->window))
                {
                    state = 1;
                }
                if (infoButton->mouseHovering(*this->window))
                {
                    state = 9;
                }
                break;
            }

            case 1: // P1 positioning ships
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    state = 7;
                }

                if (turnEnded && endTurnButton->mouseHovering(*this->window))
                {
                    state = 5;
                    turnEnded = 0;
                }

                if(!turnEnded && this->checkPositioning()){
                    ownBoardP1->addShip(positionData);
                    activeTextBox = 'x';

                    if(shipPositioning !=5){
                        ++shipPositioning;
                    }else{
                        shipPositioning = 2;
                        --init;

                        turnEnded = 1;                        
                        //state = 5; // temporary while we don't have a "end turn button"
                    }

                    positionData.initShipData();
                    xAxisInput->clearInput();
                    yAxisInput->clearInput();

                } else {
                    if(placeShip->mouseHovering(*this->window)){    // values not compatible, cannot be placed, clean the struct
                        positionData.initShipData();
                        xAxisInput->clearInput();
                        yAxisInput->clearInput();
                        activeTextBox = 'x';
                    }
                }
                // button to finish turn is only clickable after positioning every ships

                break;
            }

            case 2: // P2 positioning ships
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    state = 6;
                }

                if (turnEnded && endTurnButton->mouseHovering(*this->window))
                {
                    state = 5;
                    turnEnded = 0;
                }

                if(!turnEnded && this->checkPositioning()){
                    ownBoardP2->addShip(positionData);
                    activeTextBox = 'x';

                    if(shipPositioning !=5){
                        ++shipPositioning;
                    }else{
                        shipPositioning = 2;
                        --init;
                        turnEnded = 1;
                        //state = 5; // temporary while we don't have an "end turn" button
                    }

                    positionData.initShipData();
                    xAxisInput->clearInput();
                    yAxisInput->clearInput();

                } else {
                    if(placeShip->mouseHovering(*this->window)){    // values not compatible, cannot be placed, clean the struct
                        positionData.initShipData();
                        xAxisInput->clearInput();
                        yAxisInput->clearInput();
                        activeTextBox = 'x';
                    }
                }
                // button to finish turn is only clickable after positioning every ships
                break;
            }

            case 3: // P1 attacking
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    state = 7;
                }

                // if 0 or 1, then do nothing
                
                if(!turnEnded)
                {
                    int attackResult = checkAttack();
                    switch(attackResult)
                    {
                        case 0:
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            break;
                            
                        case 1:     
                            // hit water
                            attackBoardP1->setTile(positionData.column, positionData.row, -1);
                            turnEnded = 1;
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            // change water to hit water --> only change in assailant board
                            break;

                        case 2:     
                            // hit ship but not sunken
                            attackBoardP1->setTile(positionData.column, positionData.row, 4);
                            ownBoardP2->setTile(positionData.column, positionData.row, 4);
                            //turnEnded = 1;
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            // change in both boards
                            break;

                        case 3:
                            // ship is sunken 
                            ++quantitySunkenShipsP2;
                            attackBoardP1->setShipAsSunken(positionData);
                            ownBoardP2->setShipAsSunken(positionData);
                            //turnEnded = 1;
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            // change in both boards
                            break;

                        default:
                            break;
                    }
                }else{
                    positionData.initShipData();
                    xAxisInput->clearInput();
                    yAxisInput->clearInput();
                    activeTextBox = 'x';
                }

                if (turnEnded && endTurnButton->mouseHovering(*this->window))
                {
                    state = 5;
                    turnEnded = 0;
                }

                if(quantitySunkenShipsP2 == 4)
                {
                    state = 6;
                }
                break;
            }

            case 4: // P2 attacking
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    state = 6;
                }
                
                if(!turnEnded){ 
                    int attackResult = checkAttack();
                    switch(attackResult)
                    {
                        case 0:
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            break;

                        case 1:
                            // hit water
                            attackBoardP2->setTile(positionData.column, positionData.row, -1);
                            turnEnded = 1;
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            // change water to hit water --> only change in assailant board
                            break;

                        case 2:
                            // hit ship but not sunken
                            attackBoardP2->setTile(positionData.column, positionData.row, 4);
                            ownBoardP1->setTile(positionData.column, positionData.row, 4);
                            //turnEnded = 1;
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            // change in both boards
                            break;

                        case 3:
                            // ship is sunken 
                            ++quantitySunkenShipsP1;
                            attackBoardP2->setShipAsSunken(positionData);
                            ownBoardP1->setShipAsSunken(positionData);
                            //turnEnded = 1;
                            positionData.initShipData();
                            xAxisInput->clearInput();
                            yAxisInput->clearInput();
                            activeTextBox = 'x';
                            // change in both boards
                            break;

                        default:
                            break;
                    }
                }else{
                    positionData.initShipData();
                    xAxisInput->clearInput();
                    yAxisInput->clearInput();
                    activeTextBox = 'x';
                }

                if (turnEnded && endTurnButton->mouseHovering(*this->window))
                {
                    state = 5;
                    turnEnded = 0;
                }

                if(quantitySunkenShipsP1 == 4)
                {
                    state = 6;
                }
                
                // checkAttack -> similar to checkPositioning
                // if start is pressed
                // if init is 0 -> attack normal depengin on actual player
                // else switch to the other init
                break;
            }

            case 5: // intermediate menu
            {
                if (abandonGameButton->mouseHovering(*this->window))
                {
                    if(playerTurn == 1){
                        state = 6;
                    }else{
                        state = 7;
                    }
                }else{
                    if (startButton->mouseHovering(*this->window))
                    {
                        if(init != 0){ // case where ship positioning is not over
                            if(playerTurn == 1){
                                playerTurn = 2;
                                state = 2;
                            }else{
                                playerTurn = 1;
                                state = 1;
                            }

                        }else{ // ship positioning is over
                            if(playerTurn == 1){
                                playerTurn = 2;
                                state = 4;
                            }else{
                                playerTurn = 1;
                                state = 3;
                            }
                        }
                    }
                }
                    // only button -> start turn
                break;
            }

            case 6: // P1 win game
            {
                ownBoardP1->clearBoard();
                ownBoardP2->clearBoard();
                attackBoardP1->clearBoard();
                attackBoardP2->clearBoard();
                init = 2;
                quantitySunkenShipsP1 = 0;
                quantitySunkenShipsP2 = 0;
                // same for assembly
                gameFunctions->clearBoards();
                if (returnMenuButton->mouseHovering(*this->window))
                {
                    state = 0;
                    // clear boards
                }

                break;
            }

            case 7: // P2 win game
            {
                ownBoardP1->clearBoard();
                ownBoardP2->clearBoard();
                attackBoardP1->clearBoard();
                attackBoardP2->clearBoard();
                init = 2;
                quantitySunkenShipsP1 = 0;
                quantitySunkenShipsP2 = 0;
                // same for assembly
                gameFunctions->clearBoards();
                if (returnMenuButton->mouseHovering(*this->window))
                {
                    state = 0;
                    // clear boards
                }

                break;
            }

            case 8: // choose starting player
                break;

            case 9: // credits
                if (returnMenuButton->mouseHovering(*this->window))
                {
                    state = 0;
                }
                break;

            default:
                break;
            }
        }

        default:
            break;
        }
    }
}

/**
 * @brief The render function manage what the players see, it neither receive parameters nor returns values, but it changes the content of the window
 */
void Game::render()
{
    // CLEAR
    this->window->clear(sf::Color::Black);

    this->setAssets();

    // DRAW
    switch (state)
    {
    case 0: // main menu
        this->renderMainMenu();
        break;

    case 1: // P1 positioning ships
        this->renderInitialBoardP1();
        break;

    case 2: // P2 positioning ships
        this->renderInitialBoardP2();
        break;

    case 3: // P1 attacking
        this->renderP1();
        break;

    case 4: // P2 attacking
        this->renderP2();
        break;

    case 5: // intermediate menu
        this->renderIntermediateMenu();
        break;

    case 6: // P1 win game
        this->p1WinRender();
        break;

    case 7: // P2 win game
        this->p2WinRender();
        break;

    case 8: // choose starting player
        break;

    case 9: // info, instructions
        this->instructionsRender();
        break;

    default:
        break;
    }

    // DISPLAY
    this->window->display();
}

/**
 * @brief Running function allow us to know if the game is still running
 * @return The running function return a 0 if the window is not open, but in any other case it returns something different of 0
 */
int Game::running()
{
    return this->window->isOpen();
}

/**
 * @brief initButtonsMenu is used to initialized every assets used in the game
 */
void Game::setAssets()
{
    // START BUTTON
    startButton->setPosition({(float)(window->getSize().x / 2 - 160), (float)(300)});
    
    // LEAVE BUTTON
    leaveButton->setPosition({(float)(window->getSize().x - 80), (float)20});
    leaveButton->setScale(0.5f, 0.5f);

    // INFO BUTTON
    infoButton->setPosition({(float)(window->getSize().x - 80), (float)470});
    infoButton->setScale(0.5f, 0.5f);

    // ABANDON BUTTON
    abandonGameButton->setPosition({(float)(window->getSize().x - 450), (float)20});
    abandonGameButton->setScale(0.5f, 0.5f);

    // RETURN MAIN MENU BUTTON
    returnMenuButton->setPosition({(float)(20), (float)20});
    returnMenuButton->setScale(0.5f, 0.5f);

    // END TURN BUTTON
    endTurnButton->setPosition({(float)(window->getSize().x / 2 - 100), (float)(window->getSize().y - 70)});
    endTurnButton->setScale(0.5f, 0.5f);

    // ARROWS
    arrowUp->setPosition({(float)(window->getSize().x - 200), (float)(window->getSize().y / 2)});
    arrowUp->setScale(0.3f, 0.3f);
    arrowDown->setPosition({(float)(window->getSize().x - 200), (float)(window->getSize().y / 2 + 70)});
    arrowDown->setScale(0.3f, 0.3f);
    arrowRight->setPosition({(float)(window->getSize().x - 160), (float)(window->getSize().y / 2 + 40)});
    arrowRight->setScale(0.3f, 0.3f);
    arrowLeft->setPosition({(float)(window->getSize().x - 250), (float)(window->getSize().y / 2 + 40)});
    arrowLeft->setScale(0.3f, 0.3f);

    // PLACE SHIP
    placeShip->setPosition({(float)(window->getSize().x - 315), (float)(window->getSize().y / 2 + 150)});
    placeShip->setScale(0.5f, 0.5f);

    // ATTACK
    attackButton->setPosition({(float)(window->getSize().x - 315), (float)(window->getSize().y - 70)});
    attackButton->setScale(0.5f, 0.5f);

    // AXIS INPUT TEXTBOX	
    xAxisInput->setFont(mainFont);
    xAxisInput->setPosition({(float)(window->getSize().x - 460), (float)(window->getSize().y / 2 - 20)});
    yAxisInput->setFont(mainFont);
    yAxisInput->setPosition({(float)(window->getSize().x - 460), (float)(window->getSize().y / 2 + 78)});

    // BOARDS
    ownBoardP1->setPosition(0);
    ownBoardP2->setPosition(0);
    attackBoardP1->setPosition(1);
    attackBoardP2->setPosition(1);
}


void Game::instructionsRender()
{
    sf::Texture instructionsTexture;
    instructionsTexture.loadFromFile("src/assets/InstructionsPage.png");
    sf::Sprite instructionsSprite;
    instructionsSprite.setTexture(instructionsTexture);

    spriteWindow = instructionsSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    returnMenuButton->drawOnWindow(*this->window);
}
/**
 * @brief the function renderMainMenu draw on the game windows every assets of the scene
 */
void Game::renderMainMenu()
{
    // MAIN MENU
    sf::Texture mainMenuTexture;
    mainMenuTexture.loadFromFile("src/assets/menuMain.png");
    sf::Sprite mainMenuSprite;
    mainMenuSprite.setTexture(mainMenuTexture);

    spriteWindow = mainMenuSprite;
    this->window->draw(this->spriteWindow);
    startButton->drawOnWindow(*this->window);
    leaveButton->drawOnWindow(*this->window);
    infoButton->drawOnWindow(*this->window);
}

/**
 * @brief the function renderInitialBoardP1 draw on the game windows every assets of the scene
 */
void Game::renderInitialBoardP1()
{
    playerTurn = 1;
    sf::Texture boardTexture;
    boardTexture.loadFromFile("src/assets/SelectBoardP1.png");
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);

    spriteWindow = boardSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    abandonGameButton->drawOnWindow(*this->window);
    arrowUp->drawOnWindow(*this->window);
    arrowDown->drawOnWindow(*this->window);
    arrowRight->drawOnWindow(*this->window);
    arrowLeft->drawOnWindow(*this->window);
    placeShip->drawOnWindow(*this->window);
    ownBoardP1->drawOnWindow(*this->window);
    xAxisInput->drawOnWindow(*this->window);
    yAxisInput->drawOnWindow(*this->window);

    if(turnEnded){
        endTurnButton->drawOnWindow(*this->window);
    }
}

/**
 * @brief the function renderInitialBoardP2 draw on the game windows every assets of the scene
 */
void Game::renderInitialBoardP2()
{
    playerTurn = 2;
    sf::Texture boardTexture;
    boardTexture.loadFromFile("src/assets/SelectBoardP2.png");
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);

    spriteWindow = boardSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    abandonGameButton->drawOnWindow(*this->window);
    arrowUp->drawOnWindow(*this->window);
    arrowDown->drawOnWindow(*this->window);
    arrowRight->drawOnWindow(*this->window);
    arrowLeft->drawOnWindow(*this->window);
    placeShip->drawOnWindow(*this->window);
    ownBoardP2->drawOnWindow(*this->window);
    xAxisInput->drawOnWindow(*this->window);
    yAxisInput->drawOnWindow(*this->window);

    if(turnEnded){
        endTurnButton->drawOnWindow(*this->window);
    }
}

/**
 * @brief the function renderP1 draw on the game windows every assets of the scene
 */
void Game::renderP1()
{
    playerTurn = 1;
    sf::Texture boardTexture;
    boardTexture.loadFromFile("src/assets/BattleBoardP1.png");
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);

    spriteWindow = boardSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    abandonGameButton->drawOnWindow(*this->window);
    ownBoardP1->drawOnWindow(*this->window);
    attackBoardP1->drawOnWindow(*this->window);
    xAxisInput->drawOnWindow(*this->window);
    yAxisInput->drawOnWindow(*this->window);
    attackButton->drawOnWindow(*this->window);

    if(turnEnded){
        endTurnButton->drawOnWindow(*this->window);
    }
    
}

/**
 * @brief the function renderP2 draw on the game windows every assets of the scene
 */
void Game::renderP2()
{
    playerTurn = 2;
    sf::Texture boardTexture;
    boardTexture.loadFromFile("src/assets/BattleBoardP2.png");
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);

    spriteWindow = boardSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    abandonGameButton->drawOnWindow(*this->window);
    ownBoardP2->drawOnWindow(*this->window);
    attackBoardP2->drawOnWindow(*this->window);
    xAxisInput->drawOnWindow(*this->window);
    yAxisInput->drawOnWindow(*this->window);
    attackButton->drawOnWindow(*this->window);

    if(turnEnded){
        endTurnButton->drawOnWindow(*this->window);
    }
}

/**
 * @brief the function p1WinRender draw on the game windows every assets of the scene
 */
void Game::p1WinRender()
{
    sf::Texture boardTexture;
    boardTexture.loadFromFile("src/assets/WinnerFirstPlayer.png");
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);

    spriteWindow = boardSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    returnMenuButton->drawOnWindow(*this->window);
}

/**
 * @brief the function p2WinRender draw on the game windows every assets of the scene
 */
void Game::p2WinRender()
{
    sf::Texture boardTexture;
    boardTexture.loadFromFile("src/assets/WinnerSecondPlayer.png");
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);

    spriteWindow = boardSprite;
    this->window->draw(this->spriteWindow);
    leaveButton->drawOnWindow(*this->window);
    returnMenuButton->drawOnWindow(*this->window);

}

/**
 * @brief the function renderIntermediateMenu draw on the game windows every assets of the scene
 */
void Game::renderIntermediateMenu()
{
    sf::Texture intermediateMenuTexture;
    intermediateMenuTexture.loadFromFile("src/assets/intermediate.png");
    sf::Sprite intermediateMenuSprite;
    intermediateMenuSprite.setTexture(intermediateMenuTexture);


    spriteWindow = intermediateMenuSprite;
    this->window->draw(this->spriteWindow);
    startButton->drawOnWindow(*this->window);
    abandonGameButton->drawOnWindow(*this->window);
    leaveButton->drawOnWindow(*this->window);
}

/**
* @brief the readAxis function is used to read textual input from the user, the column and row value used in positioning and attack
* @param myEvent is type sf::Event is the event that must be processed by the function, it's the user input
*/
void Game::readAxis(sf::Event myEvent){
    // is event is [ENTER] then check intput and if valid switch textbox & store value in positionData
    if(myEvent.key.code == sf::Keyboard::Enter){
        if(activeTextBox == 'x'){               // change activeTextBox to 'y' and if valid value, checkout actual value of the textbox
            // if valid input - >stoi and pass to positionData and switch to yAxisInput
            std::string iBuff = xAxisInput->getText();
            if(iBuff=="1" || iBuff=="2" || iBuff=="3" || iBuff=="4" || iBuff=="5" || iBuff=="6" || iBuff=="7"){
                positionData.column = stoi(iBuff)-1; // rest 1 to input (pass from (1,7) to (0,6))
                activeTextBox = 'y';
                xAxisInput->setSelected(0);
                yAxisInput->setSelected(1);
            }

        }else{                                      // if valid input, checkout y value
            std::string iBuff = yAxisInput->getText();
            if(iBuff=="1" || iBuff=="2" || iBuff=="3" || iBuff=="4" || iBuff=="5" || iBuff=="6" || iBuff=="7"){
                positionData.row = stoi(iBuff)-1;   // rest 1 to input (pass from (1,7) to (0,6))
                yAxisInput->setSelected(0);
            }
        }

    }else{
        if(activeTextBox == 'x'){                   // read input for xAxisInput
            xAxisInput->setSelected(1);
            yAxisInput->setSelected(0);
            xAxisInput->receivingInput(myEvent);

        }else{                                      // read input for yAxisInput
            yAxisInput->receivingInput(myEvent);

        }
    }
}

/**
* @brief the checkAttack function is used to check if the user pressed the attack button and entered valid inputs, depending on this factors the function return a different ouptu
* @return if the position is not valid, then return 0, if hit water return 1, if hit ship 2, if ship sunken return 3 and modify the position data to receive all the sunken ship data
*/
int Game::checkAttack()
{    
    if(attackButton->mouseHovering(*this->window) && positionData.column != -1 && positionData.row != -1){
        if(gameFunctions->canAttack(positionData.row, positionData.column, playerTurn)){
            // attack
            int isAttacked = gameFunctions->attack(positionData.row, positionData.column, playerTurn);
            if(isAttacked != -1){
                int isSunken;
                if(playerTurn == 1){
                    isSunken = gameFunctions->isSunken(isAttacked*(-1), 2);
                }else{
                    isSunken = gameFunctions->isSunken(isAttacked*(-1), 1);
                }
                int columnPosHit = positionData.column;
                int rowPosHit = positionData.row;

                if(playerTurn == 1){
                    gameFunctions->getShipData(isAttacked*(-1), 2, &positionData);
                }else{
                    gameFunctions->getShipData(isAttacked*(-1), 1, &positionData);
                }
               
                if(isSunken){
                    return 3; // ship is sunken
                }else{
                    positionData.column = columnPosHit;
                    positionData.row = rowPosHit;
                    return 2; // hit ship, but not sunken
                    
                }
            }else{
                return 1; // failed, hit water
            }
        }else{
            return 0; // cannot attack this position
        }
    }
    return 0;
}

/**
* @brief the checkPositioning function is used to check if the user's given ship position and dirrection is valid for the given ship
* @return if the position is not valid, then return 0, else position ship in assembly
*/
int Game::checkPositioning(){

 if(positionData.dir == 0){                                      // if dirr is not initialize, look for input from user (arrows)
        if (arrowUp->mouseHovering(*this->window))
        {
            positionData.dir = 2;
        }

        if (arrowDown->mouseHovering(*this->window))
        {
            positionData.dir = 4;
        }

        if (arrowRight->mouseHovering(*this->window))
        {
            positionData.dir = 3;
        }

        if (arrowLeft->mouseHovering(*this->window))
        {
            positionData.dir = 1;
        }
    }


    if((positionData.dir != 0) && (positionData.column != -1) && (positionData.row != -1)){
        if (placeShip->mouseHovering(*this->window))
        {
            if(shipPositioning == 2 || shipPositioning == 3){
                positionData.size = 2;
            } else{
                if(shipPositioning == 4){
                    positionData.size = 3;
                }else{
                    if(shipPositioning == 5){
                        positionData.size = 4;
                    }
                }
            }
            positionData.symbol = shipPositioning;

            int isValid = this->gameFunctions->canPlace(&positionData, playerTurn);

            // ask if the positioning is correct
            //if so, return 1, else return 0               
            if(isValid){
                // addShip in assembly and track the position
                gameFunctions->addShip(&positionData, playerTurn);
            }
            return isValid;
        }   
    }
    return 0; // positioning not finished
}

