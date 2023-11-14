#include "StageScene.h"

void StageScene::Init()
{
	inputManager = InputManager::GetInstance();
	player_ = std::make_unique<Player>();
	player_->Init();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Init();
}

void StageScene::Update()
{
	player_->Update();
	enemy_->Update();
}

void StageScene::Draw(){
	ImGui::Begin("Stage");
	ImGui::Text("SPACE Change State");
	ImGui::End();
	if (inputManager->IsTriggerKey(DIK_SPACE)) {
		sceneNo = CLEAR;
	}
	player_->Draw();
	enemy_->Draw();
}
