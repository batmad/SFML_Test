#include "Button.h"
#include "TextManager.h"
using namespace Game;

Button::Button(int x, int y, sf::Image img, std::string text) {
	mTexture.loadFromImage(img);
	mSprite.setTexture(mTexture);
	mSprite.setPosition(x, y);
	mSprite.setOrigin(mTexture.getSize().x / 2, mTexture.getSize().y / 2);

	mText = TextManager::GetInstance()->GetText(text);
	mText.setFillColor(sf::Color(0, 0, 0, 255));
	mText.setPosition(x, y );
	mText.setOrigin(mText.getLocalBounds().width / 2, mText.getLocalBounds().height / 2);

	scale = 1.0f;
	mouseState = IDLE;
}

Button::~Button() {

}

void Button::Draw(sf::RenderWindow* g) {
	mSprite.setScale(scale, scale);
	mText.setScale(scale, scale);
	g->draw(mSprite);
	g->draw(mText);
}

void Button::Update(float delta) {
	switch (mouseState) {
	case UP:
		scale += delta;
		if (scale > 1.0f) {
			scale = 1.0f;
			mouseState = IDLE;
			AnimationEnded();
		}
		break;
	case DOWN:
		scale -= delta;
		if (scale < 0.8f) {
			scale = 0.8f;
			mouseState = IDLE;
		}
		break;
	}
}

bool Button::MouseUp(int x, int y) {
	mouseState = UP;
	if (mSprite.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

bool Button::MouseDown(int x, int y) {
	mouseState = DOWN;
	if (mSprite.getGlobalBounds().contains(x, y))
		return true;
	return false;
}

void Button::AnimationEnded() {

}