#pragma once
#include <Novice.h>
#include <memory>//std::unique_ptrを使うために必要

#include "IScene.h"//シーンの基底クラスに加えて
#include "StageScene.h"//各シーンを読み込む
#include "TitleScene.h"
#include "ClearScene.h"

class GameManager{
private:
	//シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	//どのステージを呼び出すのかを管理する変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

public:
	GameManager();//コンストラクタ
	~GameManager();//デストラクタ

	void Update();

	void Draw();
};

