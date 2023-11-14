#include "GameManager.h"


//コンストラクタ
GameManager::GameManager() {
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
	sceneArr_[TITLE]->Init();
}

//デストラクタ
GameManager::~GameManager(){}

void GameManager::Update()
{
	prevSceneNo_ = currentSceneNo_;
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();
	if (prevSceneNo_ != currentSceneNo_) {
		sceneArr_[currentSceneNo_]->Init();
	}

	sceneArr_[currentSceneNo_]->Update();
}

void GameManager::Draw()
{
	sceneArr_[currentSceneNo_]->Draw();
}
