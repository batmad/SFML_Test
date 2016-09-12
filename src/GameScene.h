#pragma once
#include "Scene.h"
#include "TigerActor.h"

namespace Game {
	class GameScene : public Scene {
	public:
		GameScene();
		~GameScene();
		void Draw(sf::RenderWindow*);
		void Update(float deltaTime);

	private:
		TigerActor* tiger;
	};
}