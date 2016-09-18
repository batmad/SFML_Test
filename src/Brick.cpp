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
	scale = 1.0f;
	isDead = false;
	deadAnimEnded = false;
	mSprite.setOrigin(mRect.mWidth / 2, mRect.mHeight / 2);
	deadState = UP;
}

Brick::~Brick() {

}

void Brick::Draw(sf::RenderWindow* g) {
	mSprite.setScale(scale, scale);
	g->draw(mSprite);
}

void Brick::Update(float delta) {
	if (isDead && !deadAnimEnded) {
		switch (deadState) {
		case UP:
			scale += 0.01 * delta;
			if (scale > 1.5)
				deadState = DOWN;
			break;
		case DOWN:
			scale -= 0.01 * delta;
			if (scale < 0) {
				deadAnimEnded = true;
				scale = 0;
			}
			break;
		}
	}
	mSprite.setPosition(mRect.mX, mRect.mY);
}

void Brick::SetDead() {
	isDead = true;
}