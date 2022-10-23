#ifndef BUTTON_DRAWABLE_BACKGROUND
#define BUTTON_DRAWABLE_BACKGROUND

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class ButtonWithBackground
{
private:
    // private attributes of the ButtonWithBackground class
    sf::Text text;
    sf::RectangleShape button;

public:
    /**
     * @brief
     * @param
     */
    ButtonWithBackground(std::string textButton, sf::Vector2f size, int fontSize, sf::Color textColor, sf::Color backgroundColor)
    {
        text.setString(textButton);
        text.setFillColor(textColor);
        text.setCharacterSize(fontSize);

        button.setSize(size);
        button.setFillColor(backgroundColor);
    }

    /**
     * @brief
     * @param
     */
    void setBackgroundColor(sf::Color backgroundColor)
    {
        button.setFillColor(backgroundColor);
    }

    /**
     * @brief
     * @param
     */
    void setFont(sf::Font &textFont)
    {
        text.setFont(textFont);
    }

    /**
     * @brief
     * @param
     */
    void setPosition(sf::Vector2f position)
    {
        button.setPosition(position);
        float textPosX = position.x + 25;
        float textPosY = position.y + 25;
        text.setPosition(textPosX, textPosY);
    }

    /**
     * @brief
     * @param
     */
    void drawOnWindow(sf::RenderWindow &window)
    {
        window.draw(button);
        window.draw(text);
    }

    /**
     * @brief
     * @param
     * @return
     */
    bool mouseHovering(sf::RenderWindow &window)
    {
        float mousePosX = sf::Mouse::getPosition(window).x;
        float mousePosY = sf::Mouse::getPosition(window).y;

        float buttonPosX = button.getPosition().x;
        float buttonPosY = button.getPosition().y;

        float buttonPosWidth = buttonPosX + button.getLocalBounds().width;
        float buttonPosHeight = buttonPosY + button.getLocalBounds().height;

        // return true if the mouse position is equal to a position between the button limits
        if (mousePosX < buttonPosWidth && mousePosX > buttonPosX && mousePosY < buttonPosHeight && mousePosY > buttonPosY)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief
     * @param
     * @return
     */
    bool isClicked(sf::RenderWindow &window)
    {
        float mousePosX = sf::Mouse::getPosition(window).x;
        float mousePosY = sf::Mouse::getPosition(window).y;

        float buttonPosX = button.getPosition().x;
        float buttonPosY = button.getPosition().y;

        float buttonPosWidth = buttonPosX + button.getLocalBounds().width;
        float buttonPosHeight = buttonPosY + button.getLocalBounds().height;

        // return true if the mouse is clicking on top of the button, else return false
        if (mousePosX < buttonPosWidth && mousePosX > buttonPosX && mousePosY < buttonPosHeight && mousePosY > buttonPosY && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif