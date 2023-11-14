#pragma once
#include <memory>
#include "IScene.h"
#include "ImGuiManager.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"



class StageScene:public IScene{
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
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
};

