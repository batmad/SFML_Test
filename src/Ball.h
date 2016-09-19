#pragma once
#include "SFML/Graphics.hpp"
#include "Actor.h"

namespace Game {
	class GameScene;
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
		void SetListener(GameScene* scene);

	private:
		void Die();

		GameScene* listener;
		float speedY;
		float speedX;
		int directionX;
		int directionY;
	};
}