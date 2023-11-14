#pragma once
#include "Novice.h"
#include "Vector2.h"
#include "ImGuiManager.h"
#include "InputManager.h"
#include "PlayerBullet.h"
class Player{
public:
	void Init();
	void Update();
	void Draw();


	Vector2 Getpos() { return pos; }
private:
	Vector2 pos;
	Vector2 size;
	float speed;
	PlayerBullet* playerBullet_;
	InputManager* inputManager = nullptr;

};

