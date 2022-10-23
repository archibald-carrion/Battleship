#ifndef BUTTON_DRAWABLE
#define BUTTON_DRAWABLE

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Button
{
private:
    // private attributes of the Button class
    sf::Text text;

public:
    /**
     * @brief
     * @param
     * @return
     */
    Button(std::string textButton, int fontSize, sf::Color textColor)
    {
        text.setString(textButton);
        text.setFillColor(textColor);
        text.setCharacterSize(fontSize);
        // text.setStyle(sf::Text::Underlined);
    }

    /**
     * @brief
     * @param
     * @return
     */
    void setFont(sf::Font &textFont)
    {
        text.setFont(textFont);
    }

    /**
     * @brief
     * @param
     * @return
     */
    void setPosition(sf::Vector2f position)
    {
        text.setPosition(position);
    }

    /**
     * @brief
     * @param
     * @return
     */
    void drawOnWindow(sf::RenderWindow &window)
    {
        window.draw(text);
    }

    /**
     * @brief
     * @param
     * @return
     */
    void setFontColor(sf::Color newFontColor)
    {
        text.setFillColor(newFontColor);
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

        float textPosX = text.getPosition().x;
        float textPosY = text.getPosition().y;
        float textPosWidth = text.getPosition().x + text.getLocalBounds().width;
        float textPosHeight = text.getPosition().y + text.getLocalBounds().height;

        // return true if the mouse position is equal to a position between the button limits
        if (mousePosX < textPosWidth && mousePosX > textPosX && mousePosY < textPosHeight && mousePosY > textPosY)
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

        float textPosX = text.getPosition().x;
        float textPosY = text.getPosition().y;
        float textPosWidth = text.getPosition().x + text.getLocalBounds().width;
        float textPosHeight = text.getPosition().y + text.getLocalBounds().height;

        // return true if the mouse position is equal to a position between the button limits
        if (mousePosX < textPosWidth && mousePosX > textPosX && mousePosY < textPosHeight && mousePosY > textPosY && sf::Mouse::isButtonPressed(sf::Mouse::Left))
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