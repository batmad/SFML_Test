#pragma once
#include "Scene.h"
#include "Button.h"

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
		Button* button;
		sf::Texture bgTexture;
		sf::Sprite bgSprite;
		bool gameScenePushed;
	};
}