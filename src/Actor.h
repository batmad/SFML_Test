#pragma once
#include "SFML\Graphics.hpp"
namespace Game {
	class Actor {
	public:
		struct Rect {
			int mX;
			int mY;
			int mWidth;
			int mHeight;
		};
		Actor() {};
		~Actor() {};
		virtual void		Draw(sf::RenderWindow*) {};
		virtual void		Update(float) {};		
		Rect				GetPosition() { return mRect; };		

	protected:
		sf::Texture			mTexture;
		sf::Sprite			mSprite;
		Rect				mRect;
	};
}