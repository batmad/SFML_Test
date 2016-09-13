#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "Scene.h"

namespace Game {
	class GameManager {
	public:
		static GameManager* GetInstance();
		void Update(float);
		void Draw(sf::RenderWindow*);
		void Pop();
		void Push(Scene*);
		void KeyDown(sf::Keyboard::Key);
	private:
		GameManager() {};
		GameManager(const GameManager& gm);
		~GameManager();
		GameManager& operator=(const GameManager&) {};
		static GameManager* gInstance;
		std::stack<Scene*> scenes;
	};
}