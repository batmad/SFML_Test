#include "MenuScene.h"
#include "Constants.h"
#include "GameManager.h"
#include "GameScene.h"
#include "Button.h"
using namespace Game;

MenuScene::MenuScene() {
	sf::Image bgImg;
	bgImg.loadFromFile("res/images/bg.jpg");
	bgTexture.loadFromImage(bgImg);
	bgSprite.setTexture(bgTexture);

	
	sf::Image btnImg;
	btnImg.loadFromFile("res/images/btn.png");
	button = new Button(WIDTH / 2 - btnImg.getSize().x / 2, HEIGHT / 2 - btnImg.getSize().y / 2, btnImg);

	gameScenePushed = false;
}

MenuScene::~MenuScene() {
	delete button;
}

void MenuScene::Draw(sf::RenderWindow* g) {
	g->draw(bgSprite);
	button->Draw(g);
}

void MenuScene::Update(float delta) {
	button->Update(delta);
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && btnSprite.getGlobalBounds().contains(mousePosition) && !gameScenePushed) {
	//	GameManager::GetInstance()->Push(new GameScene());
	//}
}

void MenuScene::MouseDown(int x, int y) {
	button->MouseDown(x, y);
	gameScenePushed = false;
}

void MenuScene::MouseUp(int x, int y) {
	if (button->MouseUp(x,y) && !gameScenePushed) {
		gameScenePushed = true;
		GameManager::GetInstance()->Push(new GameScene());
	}
}