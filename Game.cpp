#include "Game.hpp"

/**
 * @brief Game function is the default constructor of the Game class, it reveices no parameters
 */
Game::Game()
{
    this->initVariable();
    this->initWindow();
    // this->initEnemies();
}

/**
 * @brief ~Game function is the destructor of the Game class, it reveices no parameters
 */
Game::~Game()
{
    delete this->window;
}

/**
 * @brief function description
 * @return function's return value description
 */
void Game::initVariable()
{
    this->window = 0;
}

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
void Game::initWindow()
{
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH; // give right dimension to the videoMode
    this->window = new sf::RenderWindow(this->videoMode, "Video game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    // add sprite --> maps  
    // sf::Image mainMenu; // mainMenu is the first window shown to the user
   //  if (!mainMenu.loadFromFile("src/map.tga")){
        // error -> cannot load sprite from file
   // }
    sf::Texture mainMenuTexture;
    if (!mainMenuTexture.loadFromFile("src/map.png")){
        // error -> cannot load texture
    }
    sf::Sprite mainMenuSprite;
    mainMenuSprite.setTexture(mainMenuTexture);
    this->window->draw(mainMenuSprite);

}

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
/*
void Game::initEnemies()
{

    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Blue);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(5.f);
}
*/

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
void Game::update()
{
    // event polling
    this->pollEvents();
}

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            break;

        default:
            break;
        }
    }
}

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
void Game::render()
{
   // this->window->clear(sf::Color::Red);

    // DRAW
   // this->window->draw(this->enemy);

    this->window->display();
}

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
int Game::running()
{
    return this->window->isOpen();
}