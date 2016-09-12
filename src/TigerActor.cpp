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
}

TigerActor::~TigerActor() {

}

void TigerActor::Draw(sf::RenderWindow* g) {
	g->draw(mSprite);
}

void TigerActor::Update(float deltaTime) {
	frame += 0.005*deltaTime;
	if (frame > 3)
		frame -= 3;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		mSprite.move(0, -0.1*deltaTime);
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 288, 96, 96));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		mSprite.move(0, 0.1*deltaTime);
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 0, 96, 96));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		mSprite.move(-0.1*deltaTime, 0);
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 96, 96, 96));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame + 96, 96, -96, 96));
		mSprite.move(0.1*deltaTime, 0);
	}
}