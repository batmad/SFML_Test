#pragma once
#include "Actor.h"

namespace Game {
	class Brick : public Actor {
	public:
		Brick();
		~Brick();
		void Draw(sf::RenderWindow*);
		void Update(float);
		bool IsDead() { return deadAnimEnded; };
		void SetDead();
	private:
		enum {
			UP,
			DOWN
		};
		bool isDead;
		bool deadAnimEnded;
		int deadState;
		float scale;
	};
}