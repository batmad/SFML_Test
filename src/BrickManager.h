#pragma once
#include "Brick.h"
#include "Ball.h"

namespace Game {
	class BrickManager {
	public:
		BrickManager();
		~BrickManager();
		void Draw(sf::RenderWindow* g);
		void Update(float delta);
		void CreateBricks(int);
		int CheckIntersect(Ball*);
	private:
		std::vector<Brick*> bricks;
		std::vector<Brick*> dead_bricks;
	};
}