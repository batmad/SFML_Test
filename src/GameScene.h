#pragma once
#include "Scene.h"
#include "Ball.h"
#include "JsonManager.h"

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
		sf::Texture map;
		sf::Sprite sMap;
		sf::Text scoreStr;
		std::string mPath;
		Json::Value mSettings;
		int score;
	};
}