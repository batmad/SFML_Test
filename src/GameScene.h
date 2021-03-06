#pragma once
#include "JsonManager.h"
#include "Scene.h"
#include "BrickManager.h"
#include "Bat.h"

namespace Game {
	class Ball;
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		void Draw(sf::RenderWindow*);
		void Update(float deltaTime);
		void MouseDown(int x, int y);
		void MouseUp(int x, int y);
		void Save();
		void GameOver();
	private:
		Ball* ball;
		Bat* bat;
		BrickManager* brickManager;
		sf::Texture map;
		sf::Sprite sMap;
		sf::Text scoreStr;
		sf::Text highscoreStr;
		std::string mPath;
		Json::Value mSettings;
		std::string scoreText;
		int score;
		int highscore;
	};
}