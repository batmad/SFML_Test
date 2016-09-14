#pragma once
#include "Actor.h"
namespace Game {
	class TigerActor : public Actor {
	public:
		TigerActor();
		~TigerActor();
		void Draw(sf::RenderWindow*);
		void Update(float delta);

	private:
		float frame;
		float speed;
	};
}