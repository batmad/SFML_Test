#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"

namespace Game {
	class Ball : public Actor {
		public:
			Ball();
			~Ball();
			void Draw(sf::RenderWindow*);
			void Update(float delta);
	};
}