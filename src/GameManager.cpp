#include "GameManager.h"


using namespace Game;
GameManager* GameManager::gInstance = 0;

GameManager::~GameManager(){
	while (!scenes.empty()) {
		delete scenes.top();
		scenes.pop();
	}
	if(gInstance)
		delete gInstance;
}

GameManager* GameManager::GetInstance() {
	if (!gInstance)
		gInstance = new GameManager();
	return gInstance;
}

void GameManager::Draw(sf::RenderWindow* g){
	if(scenes.top())
		scenes.top()->Draw(g);
}
void GameManager::Update(float deltaTime){
	if (scenes.top())
		scenes.top()->Update(deltaTime);
}

void GameManager::Pop() {
	scenes.pop();
}

void GameManager::Push(Scene* scene) {
	scenes.push(scene);
}