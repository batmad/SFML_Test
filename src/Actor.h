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
		bool				Intersect(Rect rect) {
								return !((rect.mX + rect.mWidth < mRect.mX) ||
										(rect.mX > mRect.mX + mRect.mWidth) ||
										(rect.mY + rect.mHeight < mRect.mY) ||
										(rect.mY > mRect.mY + mRect.mHeight));
							}

		Rect				mRect;
	protected:
		enum direction{
			UP,
			DOWN,
			LEFT,
			RIGHT
		};
		sf::Texture			mTexture;
		sf::Sprite			mSprite;
		direction			mDirection;
	};
}