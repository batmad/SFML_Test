#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Constants.h"

namespace Game {
	class GameManager {
	public:
		static GameManager* GetInstance();
		void Update(float);
		void Draw(sf::RenderWindow*);
		void Pop();
		void Push(Scene*);
		void MouseDown(int x, int y);
		void MouseUp(int x, int y);
	private:
		GameManager() {};
		GameManager(const GameManager& gm);
		~GameManager();
		GameManager& operator=(const GameManager&) {};
		void KillZombie();
		static GameManager* gInstance;
		std::stack<Scene*> scenes;
		Scene* zombieScene;
	};
}