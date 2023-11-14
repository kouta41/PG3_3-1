#pragma once
#include "InputManager.h"

class Enemy  {
public:
	void Init() ;
	void Update();
	void Draw();

	bool GetIsAlive() { return IsAlive; }

private:
	bool IsAlive = true;
	Vector2 pos;
	Vector2 size;
	float speed;
};