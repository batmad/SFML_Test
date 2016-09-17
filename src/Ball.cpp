#include "Ball.h"
#include "json\json.h"

using namespace Game;

Ball::Ball() {
	mRect.mX = 0;
	mRect.mY = 0;
	
	sf::Image image;
	image.loadFromFile("res/images/ball.png");
	image.createMaskFromColor(sf::Color::White);
	mTexture.loadFromImage(image);
	mSprite.setTexture(mTexture);
}

Ball::~Ball() {

}

void Ball::Draw(sf::RenderWindow* g) {
	g->draw(mSprite);
}

void Ball::Update(float delta) {
	mRect.mX += 0.1 * delta;
	mRect.mY += 0.1 * delta;
	mSprite.setPosition(mRect.mX , mRect.mY);
}