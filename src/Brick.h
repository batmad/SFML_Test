#pragma once
#include "Actor.h"

namespace Game {
	class Brick : public Actor {
	public:
		Brick();
		~Brick();
		void Draw(sf::RenderWindow*);
		void Update(float);
		bool Intersect(Rect);
	};
}