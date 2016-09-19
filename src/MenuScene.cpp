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
	btnImg.loadFromFile("res/images/btn.png");
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
}

void MenuScene::Update(float delta) {
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && btnSprite.getGlobalBounds().contains(mousePosition) && !gameScenePushed) {
	//	GameManager::GetInstance()->Push(new GameScene());
	//}
}

void MenuScene::MouseDown(int x, int y) {

}

void MenuScene::MouseUp(int x, int y) {
	if (btnSprite.getGlobalBounds().contains(x,y) && !gameScenePushed) {
		gameScenePushed = true;
		GameManager::GetInstance()->Push(new GameScene());
	}
}