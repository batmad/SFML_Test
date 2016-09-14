#pragma once
#include "SFML\Graphics.hpp"
namespace Game {
	class Actor {
	public:
		struct Rect {
			float mX = 0;
			float mY = 0;
			int mWidth = 0;
			int mHeight = 0;
		};
		Actor() {};
		~Actor() {};
		virtual void		Draw(sf::RenderWindow*) {};
		virtual void		Update(float) {};		
		Rect				GetRect() { return mRect; };		

	protected:
		enum direction{
			UP,
			DOWN,
			LEFT,
			RIGHT
		};
		sf::Texture			mTexture;
		sf::Sprite			mSprite;
		Rect				mRect;
		direction			mDirection;
	};
}