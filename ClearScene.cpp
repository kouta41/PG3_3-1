#include "ClearScene.h"

void ClearScene::Init()
{
	inputManager = InputManager::GetInstance();

}

void ClearScene::Update()
{
}

void ClearScene::Draw(){
	ImGui::Begin("Clear");
	ImGui::Text("SPACE Change State");
	ImGui::End();
	if (inputManager->IsTriggerKey(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}
