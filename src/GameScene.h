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
		const int HEIGHT_MAP = 25;
		const int WIDTH_MAP = 40;
		sf::String TileMap[25] = {
			"0000000000000000000000000000000000000000",
			"0                                      0",
			"0   s                                  0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0                                      0",
			"0000000000000000000000000000000000000000",
		};
		TigerActor* tiger;
		sf::Texture map;
		sf::Sprite sMap;
	};
}