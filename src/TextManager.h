#pragma once
#include "SFML/Graphics.hpp"
namespace Game {
	class TextManager {		
	public:
		static TextManager*		GetInstance();
		void					Init();
		sf::Font				GetFont();
		sf::Text				GetText(std::string, int size = 20);
	private:
		TextManager() {};
		~TextManager();
		TextManager(const TextManager& rhs) {};
		TextManager& operator=(const TextManager& rhs) {};
		static TextManager* gInstance;
		sf::Font font;
	};
}