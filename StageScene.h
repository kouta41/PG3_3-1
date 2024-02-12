#pragma once
#include "IScene.h"

class StageScene : public IScene {
public:
	void Inisialize() override;
	void Update() override;
	void Draw() override;
private:
	// プレイヤーの座標と速さ
	float playerPosx_ = 500.0f;
	float playerPosy_ = 300.0f;
	float playerSpeed = 5.0f;

	// 弾の座標と速さ
	float bulletPosx_ = 0.0f;
	float bulletPosy_ = 0.0f;
	float bulletRadius = 10.0f;
	float bulletSpeed = 8.0f;
	bool isBulletShot = false;

	// 敵の座標と速さ
	float enemyPosx_ = 600.0f;
	float enemyPosy_ = 100.0f;
	float enemySpeed = 5.0f;
	float enemyRadius = 20.0f;
	float enemyRespawnTimer = 120;
	bool isEnemyAlive = true;

	// 弾と敵の当たり判定の変数
	float e2bX = enemyPosx_ - bulletPosx_;
	float e2bY = enemyPosy_ - bulletPosy_;
	float hit = enemyRadius + bulletRadius;
};