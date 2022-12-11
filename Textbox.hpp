#ifndef TEXTBOX_SFML 
#define TEXTBOX_SFML

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <sstream>


#define DELETE_KEY 8
#define LF 10
#define CR 13

class Textbox{
	private:
		sf::Text textbox;
		std::string text;
		bool isSelected; 	
	 	int limit;		// defense against buffer overflow

		void deleteLastChar(){
			text.pop_back();
			textbox.setString(text);
		}

		void inputLogic(int charInput)
		{
			if(charInput != DELETE_KEY && charInput != LF && charInput != CR){
				//text << static_cast<char>(charInput);
				text += static_cast<char>(charInput);
			}
			else if(charInput == DELETE_KEY){
				if(text.length() > 0){
					deleteLastChar();
				}
			}
			textbox.setString(text);
		}

	public:

		/**
		 * @brief Textbox is the constructor of the Textbox class
		 * @param fontSize is the size of the textbox font
		 */
		Textbox(int fontSize)
		{
			textbox.setCharacterSize(fontSize);
			isSelected = false;
			limit = 1;
			textbox.setString("");
		}

		/**
		 * @brief ~Textbox is the destructor of the Textbox class
		 */
		~Textbox(){}

		/**
		 * @brief TsetFont is used to set the font of the textbox
		 * @param font is a sf::Font given by reference, it's the new font of the textbox
		 */
		void setFont(sf::Font &font)
		{
			textbox.setFont(font);				
		}

		/**
	 	* @brief setPosition allow the code to change the position of the textbox on the window
	 	* @param position is a sf::Vector2f, a vector used as a position
	 	*/
		void setPosition(sf::Vector2f position){
			textbox.setPosition(position);		
		}
		
		/**
		* @brief setSelected set the isSelected bool to the new given value
		* @param set is a bool, it's the new value of isSelected
		*/
		void setSelected(bool sel){
			isSelected = sel;
		}

		/**
		* @brief getText return the actual content of the textbox
		* @return te function return a std::string, it's the actual content of the textbox
		*/
		std::string getText(){
			return text;
		}

		/**
	 	* @brief drawOnWindow is the function used to draw the textbox on the window
	 	* @param window window is a sf::RenderWindow passed by reference
	 	*/
		void drawOnWindow(sf::RenderWindow &window){
			window.draw(textbox);
		}

		/**
    	* @brief receivingInput is used to read inputs from the user
    	* @param input is a sf::Event depending on what it is we will either add a char to the string, delete the last char, or do nothing
    	*/
		void receivingInput(sf::Event input)
		{
			if(isSelected){
				int charTyped = input.text.unicode;
				if(charTyped < 128){
					if(text.length() < limit){
						inputLogic(charTyped);
					}
					else if(text.length() >= limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}
				}
			}
		}

		/**
		* @brief clearInput is used to clear the content of the string of the textbox
		*/
		void clearInput(){
			text.clear();
			textbox.setString(text);	
		}

		


};
#endif
