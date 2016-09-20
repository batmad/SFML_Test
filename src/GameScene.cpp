#include "GameScene.h"
#include "TigerActor.h"
#include "TextManager.h"
#include "MakeString.h"
#include "GameManager.h"
#include "Ball.h"

using namespace Game;

GameScene::GameScene() {	
	ball = new Ball();
	ball->SetListener(this);
	bat = new Bat();
	brickManager = new BrickManager();

	sf::Image mapImg;
	mapImg.loadFromFile("res/images/bg.jpg");

	map.loadFromImage(mapImg);
	sMap.setTexture(map);	

	mPath = "res/balance/settings";
	mSettings = JsonManager::LoadJson(mPath);
	highscore = mSettings["Profile"]["Highscore"].asInt();
	scoreText = "Очки:";
	scoreStr		= TextManager::GetInstance()->GetText(scoreText);
	highscoreStr	= TextManager::GetInstance()->GetText(MakeString() << "Максимум:" << highscore);
	scoreStr.setPosition(0, 0);
	highscoreStr.setPosition(WIDTH - highscoreStr.getLocalBounds().width, 0);

}

GameScene::~GameScene() {
	delete ball;
	delete bat;
	delete brickManager;
}

void GameScene::Draw(sf::RenderWindow* g) {
	g->draw(sMap);
	ball->Draw(g);
	bat->Draw(g);
	brickManager->Draw(g);
	g->draw(scoreStr);
	g->draw(highscoreStr);
}

void GameScene::Update(float deltaTime) {
	ball->Update(deltaTime);
	bat->Update(deltaTime);
	brickManager->Update(deltaTime);

	ball->CheckIntersect(bat->mRect);
	score += brickManager->CheckIntersect(ball);

	scoreStr.setPosition(0,0);
	sf::String tString(MakeString() << scoreText << score);
	scoreStr.setString(tString);
}

void GameScene::MouseDown(int x, int y) {

}

void GameScene::MouseUp(int x, int y) {

}

void GameScene::Save() {
	if (score > highscore)
		mSettings["Profile"]["Highscore"] = score;
	mSettings["Profile"]["Score"] = score;
	JsonManager::WriteJson(mPath, mSettings);
}

void GameScene::GameOver() {
	Save();
	GameManager::GetInstance()->Pop();
}