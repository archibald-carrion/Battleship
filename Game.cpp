#include "Game.hpp"

/**
 * @brief Game function is the default constructor of the Game class, it reveices no parameters
 */
Game::Game()
{
    this->initVariable();
    this->initWindow();
    this->initEnemies();
    this->dimension = new Dimension();
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
 * @param param1 param1 description
 * @param param2 param2 description
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
    this->videoMode.height = dimension->h;
    this->videoMode.width = dimension->w;

    this->window = new sf::RenderWindow(this->videoMode, "Video game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

/**
 * @brief function description
 * @param param1 param1 description
 * @param param2 param2 description
 * @return function's return value description
 */
void Game::initEnemies()
{

    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Blue);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(5.f);
}

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
    this->window->clear(sf::Color::Red);

    // DRAW
    this->window->draw(this->enemy);
   
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