#include "GameScene.h"
#include "TigerActor.h"
#include "TextManager.h"
#include "MakeString.h"


using namespace Game;

GameScene::GameScene() {	
	ball = new Ball();
	brickManager = new BrickManager();

	sf::Image mapImg;
	mapImg.loadFromFile("res/images/bg.jpg");

	map.loadFromImage(mapImg);
	sMap.setTexture(map);	

	scoreStr = TextManager::GetInstance()->GetText("Набрано очков:");
	scoreStr.setPosition(0,0);
	mPath = "res/balance/settings";
	mSettings = JsonManager::LoadJson(mPath);
}

GameScene::~GameScene() {
	delete ball;
	delete brickManager;
}

void GameScene::Draw(sf::RenderWindow* g) {
	g->draw(sMap);
	ball->Draw(g);
	brickManager->Draw(g);
	g->draw(scoreStr);
}

void GameScene::Update(float deltaTime) {
	ball->Update(deltaTime);
	brickManager->Update(deltaTime);
	score += brickManager->CheckIntersect(ball);
	scoreStr.setPosition(0,0);
	sf::String tString(MakeString() << "Набрано очков:" << score);
	scoreStr.setString(tString);
}

void GameScene::Save() {
	JsonManager::WriteJson(mPath, mSettings);
}