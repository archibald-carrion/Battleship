#ifndef BUTTON_WITH_SPRITE
#define BUTTON_WITH_SPRITE

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Button
{

	friend class Game;
	friend class BoardInterface;

private:
	sf::Sprite *sprite;

public:
	/**
	* @brief Button constructor without parameters
	*/
	Button(){}

	/**
	* @brief Button constructor that receive a sf::Sprite as parameter
	*/
	Button(sf::Sprite *defaultS)
	{
		sprite = defaultS;
	}

	~Button()
	{
	}

	/**
	 * @brief drawOnWindow is the function used to draw the button on the window
	 * @param window window is a sf::RenderWindow passed by reference
	 */
	void drawOnWindow(sf::RenderWindow &window)
	{
		window.draw(*sprite);
	}

	/**
	 * @brief setPosition allow the code to change the position of the button on the window
	 * @param position is a sf::Vector2f, a vector used as a position
	 */
	void setPosition(sf::Vector2f position)
	{
		sprite->setPosition(position);
	}

	/**
	 * @brief setSprite functions is used to change the active sprite of a button, for exemple, it's used when a button is clicked, or when a board cell change of state
	 * @param newSprite is a sf::Sprite, it's the new sprite used as the button sprite
	 */
	void setSprite(sf::Sprite *newSprite)
	{
		sprite = newSprite;
	}

	/**
	 * @brief mouseHovering function is used to know if the mouse if hovering the button in a given window
	 * @param window is a sf::RenderWindow given by reference, it;s used to know the position of the mouse on top of this window
	 * @return the function return a boolean value, a 1 if the mouse is hovering the button, else a 0
	 */
	bool mouseHovering(sf::RenderWindow &window)
	{
		int mousePosX = static_cast<float>(sf::Mouse::getPosition(window).x);
		int mousePosY = static_cast<float>(sf::Mouse::getPosition(window).y);
		return sprite->getGlobalBounds().contains(mousePosX, mousePosY);
	}

	/**
	 * @brief setScale function is used to scale the buttons x and y proportions
	 * @param x is a float value, it's the new scale for the x axis of the button sprite
	 * @param y is a float value, it's the new scale for the y axis of the button sprite
	 */
	void setScale(float x, float y)
	{
		sprite->setScale(x, y);
	}
};
#endif
