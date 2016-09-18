#include "Brick.h"
using namespace Game;

Brick::Brick() {
	sf::Image img;
	img.loadFromFile("res/images/brick.png");
	img.createMaskFromColor(sf::Color::White);

	mTexture.loadFromImage(img);
	mSprite.setTexture(mTexture);
	mRect.mWidth = mTexture.getSize().x;
	mRect.mHeight = mTexture.getSize().y;
}

Brick::~Brick() {

}

void Brick::Draw(sf::RenderWindow* g) {
	g->draw(mSprite);
}

void Brick::Update(float delta) {
	mSprite.setPosition(mRect.mX, mRect.mY);
}

bool Brick::Intersect(Rect rect) {
	return !((rect.mX + rect.mWidth < mRect.mX) ||
		(rect.mX > mRect.mX + mRect.mWidth) ||
		(rect.mY + rect.mHeight < mRect.mY) ||
		(rect.mY > mRect.mY + mRect.mHeight));	
}