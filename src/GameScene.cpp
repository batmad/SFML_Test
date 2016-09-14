#include "GameScene.h"
#include "TigerActor.h"


using namespace Game;

GameScene::GameScene() {	
	tiger = new TigerActor();
	
	sf::Image mapImg;
	mapImg.loadFromFile("images/map.png");

	map.loadFromImage(mapImg);
	sMap.setTexture(map);	
}

GameScene::~GameScene() {

}

void GameScene::Draw(sf::RenderWindow* g) {
	g->setView(view);
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  sMap.setTextureRect(sf::IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
			if (TileMap[i][j] == 's')  sMap.setTextureRect(sf::IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
			if ((TileMap[i][j] == '0')) sMap.setTextureRect(sf::IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������


			sMap.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

			g->draw(sMap);//������ ���������� �� �����
		}
	tiger->Draw(g);
}

void GameScene::Update(float deltaTime) {
	view.reset(sf::FloatRect(0, 0, 640, 480));
	tiger->Update(deltaTime);
	int dx = (tiger->GetRect().mX > 320) ? tiger->GetRect().mX : 320;
	int dy = tiger->GetRect().mY;
	if (tiger->GetRect().mY < 240)
		dy = 240;
	if (tiger->GetRect().mY > 554)
		dy = 554;
	view.setCenter(dx, dy);
}
