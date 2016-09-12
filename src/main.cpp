#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "GameScene.h"

using namespace Game;

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;
	
	Scene* gameScene = new GameScene();
	int a = 0;
	GameManager::GetInstance()->Push(gameScene);
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		GameManager::GetInstance()->Draw(&window);
		GameManager::GetInstance()->Update(time);
		window.display();
	}

	return 0;
}