#include "Enemy.h"

void Enemy::Init() {

	pos = { 400, 300 };
	size = { 32, 32 };
	speed = 5.0f;
}

void Enemy::Update() {
	if (pos.y > 720) {
		speed *= -1;
	}
	if (pos.y < 0) {
		speed *= -1;
	}
	pos.y += speed;
}

void Enemy::Draw() {
	Novice::DrawBox(
		(int)pos.x, (int)pos.y, (int)size.x, (int)size.y, 0.0f, BLUE,
		kFillModeSolid);
}