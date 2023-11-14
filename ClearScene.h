#pragma once
#include "IScene.h"
#include "ImGuiManager.h"
#include "InputManager.h"

class ClearScene:public IScene{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Init()	override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	InputManager* inputManager = nullptr;

};

