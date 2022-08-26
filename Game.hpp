#ifndef MYGAME_
#define MYGAME_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define HEIGHT 400
#define WIDTH 600
#define maxFPS 60

class Game
{
private:
    // Game class private functions
    void initVariable();
    void initWindow();
    void initEnemies();

    // Game class attributes
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::RectangleShape enemy;

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