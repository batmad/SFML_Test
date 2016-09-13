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
	float dx = 0;
	float dy = 0;
	frame += 0.005*deltaTime;
	if (frame > 3)
		frame -= 3;
	switch(mDirection) {
	case UP: 
		dy =  -speed * deltaTime; 
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 288, 96, 96));
		break;
	case DOWN: 
		dy = speed * deltaTime; 
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 0, 96, 96));
		break;
	case LEFT: 
		dx = -speed * deltaTime; 
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 96, 96, 96));
		break;
	case RIGHT: 
		dx = speed * deltaTime;
		mSprite.setTextureRect(sf::IntRect(96 * (int)frame + 96, 96, -96, 96));
		break;
	}
	mRect.mX += dx;
	mRect.mY += dy;
	
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	//	mSprite.move(0, -0.1*deltaTime);
	//	mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 288, 96, 96));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	//	mSprite.move(0, 0.1*deltaTime);
	//	mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 0, 96, 96));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	//	mSprite.move(-0.1*deltaTime, 0);
	//	mSprite.setTextureRect(sf::IntRect(96 * (int)frame, 96, 96, 96));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	//	mSprite.setTextureRect(sf::IntRect(96 * (int)frame + 96, 96, -96, 96));
	//	mSprite.move(0.1*deltaTime, 0);
	//}
	speed = 0;
	//mSprite.setPosition(mRect.mX, mRect.mY);
	mSprite.move(dx, dy);
}

void TigerActor::KeyDown(sf::Keyboard::Key key) {
	speed = 0.1f;
	switch (key) {
	case sf::Keyboard::Up:
	case sf::Keyboard::W:
		mDirection = UP;
		break;
	case sf::Keyboard::Down:
	case sf::Keyboard::S:
		mDirection = DOWN;
		break;
	case sf::Keyboard::Left:
	case sf::Keyboard::A:
		mDirection = LEFT;
		break;
	case sf::Keyboard::Right:
	case sf::Keyboard::D:
		mDirection = RIGHT;
		break;
	}
}