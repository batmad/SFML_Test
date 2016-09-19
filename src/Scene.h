#pragma once
#include "SFML/Graphics.hpp"

namespace Game {
	class Scene {
	public:
		Scene() {};
		~Scene() {};
		virtual void Draw(sf::RenderWindow*) {};
		virtual void Update(float deltaTime) {};
		virtual void MouseDown(int x, int y) {};
		virtual void MouseUp(int x, int y) {};
	};
}