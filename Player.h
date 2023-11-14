#pragma once
#include "Novice.h"
#include "Vector2.h"
#include "ImGuiManager.h"
#include <dinput.h>
class Player{
public:
	void Init();
	void Update();
	void Draw();


private:
	Vector2 pos;
	Vector2 size;
	float speed;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

};

