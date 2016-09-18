#include "Ball.h"
#include "json\json.h"
#include "Constants.h"

using namespace Game;

Ball::Ball() {
	sf::Image image;
	image.loadFromFile("res/images/ball.png");
	image.createMaskFromColor(sf::Color::White);
	mTexture.loadFromImage(image);
	mSprite.setTexture(mTexture);

	mRect.mX = WIDTH / 2;
	mRect.mY = HEIGHT / 2;
	mRect.mWidth = mTexture.getSize().x;
	mRect.mHeight = mTexture.getSize().y;

	speedY = 0.06;
	speedX = 0.06;
	directionX = 1;
	directionY = 1;
	srand(time(0));
}

Ball::~Ball() {

}

void Ball::Draw(sf::RenderWindow* g) {	
	g->draw(mSprite);
}

void Ball::Update(float delta) {
	mRect.mX += speedX * directionX * delta;
	mRect.mY += speedY * directionY * delta;
	if (mRect.mX + mTexture.getSize().x > WIDTH || mRect.mX < 0) {
		speedX = static_cast<float>(rand() % 400 + 600) / 10000;
		speedY = static_cast<float>(rand() % 400 + 600) / 10000;
		directionX = -directionX;
	}
	if (mRect.mY + mTexture.getSize().y > HEIGHT || mRect.mY < 0) {
		speedY = static_cast<float>(rand() % 400 + 600) / 10000;
		speedX = static_cast<float>(rand() % 400 + 600) / 10000;
		directionY = -directionY;
	}
	mSprite.setPosition(mRect.mX , mRect.mY);
}