#pragma once
#include "JsonManager.h"
#include "Scene.h"
#include "Ball.h"
#include "BrickManager.h"
#include "Bat.h"

namespace Game {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		void Draw(sf::RenderWindow*);
		void Update(float deltaTime);
		void Save();

	private:
		Ball* ball;
		Bat* bat;
		BrickManager* brickManager;
		sf::Texture map;
		sf::Sprite sMap;
		sf::Text scoreStr;
		std::string mPath;
		Json::Value mSettings;
		int score;
	};
}