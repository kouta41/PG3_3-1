#include "Player.h"

void Player::Init()
{
	inputManager = InputManager::GetInstance();

	pos = { 50,300 };
	size = { 32,32 };
	speed = 5.0f;
}

void Player::Update()
{
	if (inputManager->IsPressKey(DIK_UP)) {
		pos.y -= speed;
	}
	if (inputManager->IsPressKey(DIK_DOWN)) {
		pos.y += speed;
	}
	if (inputManager->IsPressKey(DIK_LEFT)) {
		pos.x -= speed;
	}
	if (inputManager->IsPressKey(DIK_RIGHT)) {
		pos.x += speed;
	}

	if (inputManager->IsPressKey(DIK_RSHIFT)) {
		playerBullet_->Update();
	}
}

void Player::Draw()
{
	Novice::DrawBox(
		(int)pos.x, (int)pos.y, (int)size.x, (int)size.y, 0.0f, WHITE,
		kFillModeSolid);
}
