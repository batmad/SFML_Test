#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "MenuScene.h"

using namespace Game;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;
	
	Scene* menuScene = new MenuScene();
	int a = 0;
	GameManager::GetInstance()->Push(menuScene);
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					GameManager::GetInstance()->MouseDown(event.mouseButton.x, event.mouseButton.y);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					GameManager::GetInstance()->MouseUp(event.mouseButton.x, event.mouseButton.y);
				}
				break;
			case sf::Event::TouchBegan:
				GameManager::GetInstance()->MouseDown(event.touch.x, event.touch.y);
				break;
			case sf::Event::TouchEnded:
				GameManager::GetInstance()->MouseUp(event.touch.x, event.touch.y);				
				break;
			default:
				break;
			}
		}
		window.clear();
		GameManager::GetInstance()->Draw(&window);
		GameManager::GetInstance()->Update(time);
		window.display();
	}

	return 0;
}