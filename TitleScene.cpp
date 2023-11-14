#include "TitleScene.h"
/// <summary>
/// 初期化
/// </summary>
void TitleScene::Init()
{
	inputManager = InputManager::GetInstance();
}


/// <summary>
/// 更新
/// </summary>
void TitleScene::Update()
{
}


/// <summary>
/// 描画
/// </summary>	
void TitleScene::Draw(){
	ImGui::Begin("Title");
	ImGui::Text("SPACE Change State");
	ImGui::End();
	if(inputManager->IsTriggerKey(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}
