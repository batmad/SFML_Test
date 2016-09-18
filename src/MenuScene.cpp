#include "MenuScene.h"
#include "Constants.h"
#include "GameManager.h"
#include "GameScene.h"
using namespace Game;

MenuScene::MenuScene() {
	sf::Image bgImg;
	bgImg.loadFromFile("res/images/bg.jpg");
	bgTexture.loadFromImage(bgImg);
	bgSprite.setTexture(bgTexture);

	sf::Image btnImg;
	btnImg.loadFromFile("res/images/bat.png");
	btnImg.createMaskFromColor(sf::Color::White);
	btnTexture.loadFromImage(btnImg);
	btnSprite.setTexture(btnTexture);

	btnSprite.setPosition(WIDTH / 2 - btnTexture.getSize().x / 2, HEIGHT / 2 - btnTexture.getSize().y / 2);
	gameScenePushed = false;
}

MenuScene::~MenuScene() {

}

void MenuScene::Draw(sf::RenderWindow* g) {
	g->draw(bgSprite);
	g->draw(btnSprite);
	mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*g));
}

void MenuScene::Update(float delta) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && btnSprite.getGlobalBounds().contains(mousePosition) && !gameScenePushed) {
		GameManager::GetInstance()->Push(new GameScene());
	}
}