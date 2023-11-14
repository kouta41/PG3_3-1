#include "Player.h"

void Player::Init()
{

	pos = { 50,300 };
	size = { 32,32 };
	speed = 5.0f;
}

void Player::Update()
{
	if (keys[DIK_UP]) {
		pos.y -= speed;
	}
	if (keys[DIK_DOWN]) {
		pos.y += speed;
	}
	if (keys[DIK_LEFT]) {
		pos.x -= speed;
	}
	if (keys[DIK_RIGHT]) {
		pos.x += speed;
	}
}

void Player::Draw()
{
	Novice::DrawBox(
		(int)pos.x, (int)pos.y, (int)size.x, (int)size.y, 0.0f, WHITE,
		kFillModeSolid);
}
