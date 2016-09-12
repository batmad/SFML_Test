#pragma once
#include "Actor.h"
namespace Game {
	class TigerActor : Actor {
	public:
		TigerActor();
		~TigerActor();
		void Draw(sf::RenderWindow*);
		void Update(float delta);

	private:
		float frame;
	};
}