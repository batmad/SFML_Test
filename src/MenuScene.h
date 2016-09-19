#pragma once
#include "Scene.h"
namespace Game {
	class MenuScene : public Scene {
	public:
		MenuScene();
		~MenuScene();
		void Draw(sf::RenderWindow*);
		void Update(float deltaTime);
		void MouseDown(int x, int y);
		void MouseUp(int x, int y);
	private:
		sf::Texture bgTexture;
		sf::Texture btnTexture;
		sf::Sprite bgSprite;
		sf::Sprite btnSprite;
		sf::Vector2f mousePosition;
		bool gameScenePushed;
	};
}