#include "GameScene.h"
#include "TigerActor.h"
#include "TextManager.h"
#include "MakeString.h"

using namespace Game;

GameScene::GameScene() {	
	tiger = new TigerActor();
	
	sf::Image mapImg;
	mapImg.loadFromFile("res/images/map.png");

	map.loadFromImage(mapImg);
	sMap.setTexture(map);	

	scoreStr = TextManager::GetInstance()->GetText("Набрано очков:");
	scoreStr.setPosition(0,0);
}

GameScene::~GameScene() {

}

void GameScene::Draw(sf::RenderWindow* g) {
	g->setView(view);
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  sMap.setTextureRect(sf::IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
			if (TileMap[i][j] == 's')  sMap.setTextureRect(sf::IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
			if ((TileMap[i][j] == '0')) sMap.setTextureRect(sf::IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


			sMap.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

			g->draw(sMap);//рисуем квадратики на экран
		}
	tiger->Draw(g);
	g->draw(scoreStr);
}

void GameScene::Update(float deltaTime) {
	view.reset(sf::FloatRect(0, 0, 640, 480));
	tiger->Update(deltaTime);
	int dx = (tiger->mRect.mX > 320) ? tiger->mRect.mX : 320;
	int dy = tiger->mRect.mY;
	if (tiger->mRect.mY < 240)
		dy = 240;
	if (tiger->mRect.mY > 554)
		dy = 554;
	view.setCenter(dx, dy);
	scoreStr.setPosition(view.getCenter());
	InteractMap();
}

void GameScene::InteractMap() {
	for (int i = tiger->mRect.mY / 32; i < (tiger->mRect.mY + tiger->mRect.mHeight) / 32; i++) {
		for (int j = tiger->mRect.mX / 32; j < (tiger->mRect.mX + tiger->mRect.mWidth) / 32; j++){
			if (TileMap[i][j] == '0'){
				if (tiger->mRect.mX < 0)
					tiger->mRect.mX = 0;
				if (tiger->mRect.mY < 0)
					tiger->mRect.mY = 0;
				if (i == HEIGHT_MAP - 1)
					tiger->mRect.mY = i * 32 - tiger->mRect.mHeight;
				if (j == WIDTH_MAP - 1)
					tiger->mRect.mX = j * 32 - tiger->mRect.mWidth;
			}
			if (TileMap[i][j] == 's') {
				TileMap[i][j] = ' ';
				score++;
				sf::String tString(MakeString() << "Набрано очков:" << score);
				scoreStr.setString(tString);
			}
		}
	}
}