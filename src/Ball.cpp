#include "Ball.h"
#include "json\json.h"
#include "Constants.h"
#include "GameScene.h"

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
	if (mRect.mX + mRect.mWidth > WIDTH || mRect.mX < 0) {
		ChangeDirection(X);
	}
	if (mRect.mY + mRect.mHeight < 0) {
		ChangeDirection(Y);
	}
	if (mRect.mY > HEIGHT) {
		Die();
	}
	mSprite.setPosition(mRect.mX , mRect.mY);
}

void Ball::ChangeDirection(int direction) {
	switch (direction) {
	case X:
		speedX = static_cast<float>(rand() % 400 + 600) / 10000;
		speedY = static_cast<float>(rand() % 400 + 600) / 10000;
		directionX = -directionX;
		break;
	case Y:
		speedY = static_cast<float>(rand() % 400 + 600) / 10000;
		speedX = static_cast<float>(rand() % 400 + 600) / 10000;
		directionY = -directionY;
		break;
	}
}

void Ball::CheckIntersect(Rect rect) {
	if (Intersect(rect)) {
		ChangeDirection(Y);
	}
}

void Ball::Die() {
	listener->GameOver();
	mRect.mX = WIDTH / 2;
	mRect.mY = HEIGHT / 2;
	mSprite.setPosition(mRect.mX, mRect.mY);
}

void Ball::SetListener(GameScene* scene) {
	listener = scene;
}