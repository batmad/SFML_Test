#include "GameScene.h"
#include "TigerActor.h"

using namespace Game;

GameScene::GameScene() {	
	tiger = new TigerActor();
}

GameScene::~GameScene() {

}

void GameScene::Draw(sf::RenderWindow* g) {
	tiger->Draw(g);
}

void GameScene::Update(float deltaTime) {

	tiger->Update(deltaTime);

}