#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"

namespace Game {
	class Ball : public Actor {
	public:
		enum {
			X,
			Y
		};
		Ball();
		~Ball();
		void Draw(sf::RenderWindow*);
		void Update(float delta);
		void ChangeDirection(int);
		void CheckIntersect(Rect);

	private:
		void Die();

		float speedY;
		float speedX;
		int directionX;
		int directionY;
	};
}