#ifndef MYGAME_
#define MYGAME_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define h HEIGHT
#define w WIDTH
#define maxFPS 60

class Game
{
private:
    /*
     * Dimension is a struct used to store 2 const unsigned int:
     * HEIGHT and WIDTH, both represent the constante value of the window dimension
     */
    struct Dimension
    {
        const unsigned int HEIGHT = 600;
        const unsigned int WIDTH = 1000;
    };

    // Game class private functions
    void initVariable();
    void initWindow();
    void initEnemies();

    // Game class attributes
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::RectangleShape enemy;
    Dimension *dimension;

public:

    // Game class default constructor and desctructor
    Game();
    ~Game();

    // Game class public functions
    void update();
    void render();
    int running();
    void pollEvents();
};
#endif