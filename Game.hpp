#ifndef MYGAME_
#define MYGAME_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define HEIGHT 720
#define WIDTH 1480
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
    int state = 0;
    // 0 -> main menu
    // 1 -> j1
    // 2 -> j2
    // 3 -> menu between 2 players boards

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