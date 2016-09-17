#include "GameScene.h"
#include "TigerActor.h"
#include "TextManager.h"
#include "MakeString.h"


using namespace Game;

GameScene::GameScene() {	
	ball = new Ball();
	
	sf::Image mapImg;
	mapImg.loadFromFile("res/images/bg.jpg");

	map.loadFromImage(mapImg);
	sMap.setTexture(map);	

	scoreStr = TextManager::GetInstance()->GetText("������� �����:");
	scoreStr.setPosition(0,0);
	mPath = "res/balance/settings";
	mSettings = JsonManager::LoadJson(mPath);
}

GameScene::~GameScene() {
	delete ball;
}

void GameScene::Draw(sf::RenderWindow* g) {
	g->draw(sMap);
	ball->Draw(g);
	g->draw(scoreStr);
}

void GameScene::Update(float deltaTime) {
	ball->Update(deltaTime);
	scoreStr.setPosition(0,0);
	score++;
	sf::String tString(MakeString() << "������� �����:" << score);
	scoreStr.setString(tString);
}

void GameScene::Save() {
	JsonManager::WriteJson(mPath, mSettings);
}