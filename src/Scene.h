#pragma once
#include "SFML/Graphics.hpp"

namespace Game {
	class Scene {
	public:
		Scene() {};
		~Scene() {};
		virtual void Draw(sf::RenderWindow*) {};
		virtual void Update(float deltaTime) {};
		virtual void KeyDown(sf::Keyboard::Key) {};
	};
}