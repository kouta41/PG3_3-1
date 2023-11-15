#include "PlayerBullet.h"

void PlayerBullet::Init()
{
	inputManager = InputManager::GetInstance();

	pos = { -50,-300 };
	size = { 16,16 };
	speed = 10.0f;
}

void PlayerBullet::Update()
{
	pos = player_.Getpos();
	pos.y -= speed;

}

void PlayerBullet::Draw()
{
	Novice::DrawBox(
		(int)pos.x, (int)pos.y, (int)size.x, (int)size.y, 0.0f, RED,
		kFillModeSolid);
}
