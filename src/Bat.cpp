#include "Bat.h"
#include "Constants.h"
using namespace Game;

Bat::Bat() {
	sf::Image img;
	img.loadFromFile("res/images/bat.png");
	img.createMaskFromColor(sf::Color::White);

	mTexture.loadFromImage(img);
	mSprite.setTexture(mTexture);

	mRect.mX = WIDTH / 2 - mTexture.getSize().x / 2;
	mRect.mY = HEIGHT - mTexture.getSize().y;
	mRect.mWidth = mTexture.getSize().x;
	mRect.mHeight = mTexture.getSize().y;

	speed = 0.2f;
}

Bat::~Bat() {

}

void Bat::Draw(sf::RenderWindow* g) {
	g->draw(mSprite);
	mousePosition = sf::Mouse::getPosition(*g);
}

void Bat::Update(float delta) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		mRect.mX = mousePosition.x - mRect.mWidth / 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		mRect.mX += -speed * delta;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		mRect.mX += speed * delta;
	}

	if (mRect.mX < 0)
		mRect.mX = 0;
	if (mRect.mX + mRect.mWidth > WIDTH)
		mRect.mX = WIDTH - mRect.mWidth;

	mSprite.setPosition(mRect.mX, mRect.mY);
}