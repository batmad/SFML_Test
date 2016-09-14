#include "TigerActor.h"
using namespace Game;

TigerActor::TigerActor() {
	sf::Image heroImage;
	heroImage.loadFromFile("images/hero.png");

	mTexture.loadFromImage(heroImage);

	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(0, 192, 96, 96));
	mSprite.setPosition(50, 25);
	frame = 0;
	speed = 0.1;
	mRect.mWidth = 96;
	mRect.mHeight = 96;
}

TigerActor::~TigerActor() {

}

void TigerActor::Draw(sf::RenderWindow* g) {
	g->draw(mSprite);
}

void TigerActor::Update(float deltaTime) {
	float dx = 0;
	float dy = 0;
	frame += 0.005*deltaTime;
	if (frame > 3)
		frame -= 3;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dy = -speed * deltaTime;
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 288, 96, 96));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dy = speed * deltaTime;
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 0, 96, 96));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dx = -speed * deltaTime;
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 96, 96, 96));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dx = speed * deltaTime;
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame + 96, 96, -96, 96));
	}
	mRect.mX += dx;
	mRect.mY += dy;

	mSprite.setPosition(mRect.mX, mRect.mY);
}

