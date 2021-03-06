#include "BrickManager.h"
#include "Constants.h"
#include "JsonManager.h"
using namespace Game;

BrickManager::BrickManager() {
	Json::Value root = JsonManager::LoadJson("res/balance/settings");
	int bricksNum = root["bricks"].asInt();
	CreateBricks(bricksNum);
}

BrickManager::~BrickManager() {
	for (std::vector<Brick*>::iterator it = bricks.begin(); it != bricks.end(); ++it) {
		delete (*it);
	}
	bricks.clear();
}

void BrickManager::CreateBricks(int num) {
	for (int i = 0; i < num; ++i) {
		Brick* tBrick = new Brick();
		int origin_x = 40;
		int origin_y = 40;
		int offset_x = 5;
		int offset_y = 10;
		int numPerWidth = (WIDTH - origin_x) / (tBrick->mRect.mWidth + offset_x);
		tBrick->mRect.mX = origin_x + (i % numPerWidth) * tBrick->mRect.mWidth + (i % numPerWidth) * offset_x;
		tBrick->mRect.mY = origin_y + (i / numPerWidth) * tBrick->mRect.mHeight + (i / numPerWidth) * offset_y;
		bricks.push_back(tBrick);
	}
}

void BrickManager::Draw(sf::RenderWindow* g) {
	for (auto it = bricks.begin(); it != bricks.end(); ++it) {
		(*it)->Draw(g);
	}
	for (auto it = dead_bricks.begin(); it != dead_bricks.end(); ++it) {
		(*it)->Draw(g);
	}
}

void BrickManager::Update(float delta) {
	for (auto it = bricks.begin(); it != bricks.end(); ++it) {
		(*it)->Update(delta);
	}
	for (auto it = dead_bricks.begin(); it != dead_bricks.end(); ) {
		if ((*it)->IsDead()) {
			delete (*it);
			dead_bricks.erase(it);
			break;
		}
		else {
			(*it)->Update(delta);
			++it;
		}
	}
}

int BrickManager::CheckIntersect(Ball* ball) {
	int score = 0;
	for (auto it = bricks.begin(); it != bricks.end();) {
		if ((*it)->Intersect(ball->mRect)) {
			(*it)->SetDead();
			dead_bricks.push_back(*it);
			bricks.erase(it);
			ball->ChangeDirection(Ball::Y);
			return ++score;
		}
		else {
			++it;
		}
	}
	return score;
}
