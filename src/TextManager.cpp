#include "TextManager.h"

using namespace Game;

TextManager* TextManager::gInstance = 0;

TextManager* TextManager::GetInstance() {
	if (!gInstance) {
		gInstance = new TextManager();
		gInstance->Init();
	}
	return gInstance;
}

TextManager::~TextManager() {
	if (gInstance)
		delete gInstance;
}

void TextManager::Init() {
	const_cast<TextManager*>(TextManager::GetInstance())->font.loadFromFile("res/fonts/CyrilicOld.TTF");
}

sf::Font TextManager::GetFont() {
	return font;
}

sf::Text TextManager::GetText(std::string text, int size) {
	sf::Text result(text, font, size);
	return result;
}