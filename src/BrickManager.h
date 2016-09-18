#pragma once
#include "Brick.h"

namespace Game {
	class BrickManager {
	public:
		BrickManager();
		~BrickManager();
		void Draw(sf::RenderWindow* g);
		void Update(float delta);
		void CreateBricks(int);
		bool CheckIntersect(Actor::Rect);
	private:
		std::vector<Brick*> bricks;
	};
}