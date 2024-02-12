#include "StageScene.h"

void StageScene::Inisialize()
{
}

void StageScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	// 変数を初期化
	playerSpeed = 5.0f;
	bulletSpeed = 8.0f;

	
	//プレイヤー移動
	if (keys[DIK_W]) {
		if (playerPosy_ <= 20) {
			playerSpeed = 0;
		}
		playerPosy_ -= playerSpeed;
	}

	if (keys[DIK_S]) {
		if (playerPosy_ >= 700) {
			playerSpeed = 0;
		}
		playerPosy_ += playerSpeed;
	}

	if (keys[DIK_D]) {
		if (playerPosx_ >= 1260) {
			playerSpeed = 0;
		}
		playerPosx_ += playerSpeed;
	}

	if (keys[DIK_A]) {
		if (playerPosx_ <= 20) {
			playerSpeed = 0;
		}
		playerPosx_ -= playerSpeed;
	}

	// スペースキーで弾を発射
	if ((bool)isBulletShot == false) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			bulletPosx_ = playerPosx_;
			bulletPosy_ = playerPosy_;
			isBulletShot = true;
		}
	}
	if ((bool)isBulletShot == true) {
		if (bulletPosy_ <= 0) {
			isBulletShot = false;
		}
		bulletPosy_ -= bulletSpeed;
	}
	if (bulletPosy_ <= 0) {
		isBulletShot = false;
	}



	// 敵の移動
	enemyPosx_ = enemyPosx_ + enemySpeed;

	// 右端で反射
	if (enemyPosx_ >= 1260) {
		enemySpeed *= -1;
	}

	// 左端で反射
	if (enemyPosx_<= 20) {
		enemySpeed *= -1;
	}

	// 弾と敵の当たり判定の変数
	e2bX = enemyPosx_ - bulletPosx_;
	e2bY = enemyPosy_ - bulletPosy_;
	hit = enemyRadius + bulletRadius;

	// 弾に当たったら消滅
	if (e2bX * e2bX + e2bY * e2bY <= hit * hit) {
		isEnemyAlive = false;
	}

	if (isEnemyAlive == false) {
		sceneNo = CLEAR;
	}

}

void StageScene::Draw()
{
	// プレイヤーを表示
	Novice::DrawEllipse(
		(int)playerPosx_, (int)playerPosy_,
		20, 20,
		0.0f,
		WHITE,
		kFillModeSolid
	);

	// 弾を表示
	if (isBulletShot == true) {
		Novice::DrawTriangle(
			(int)bulletPosx_, (int)bulletPosy_ - (int)bulletRadius,
			(int)bulletPosx_ - (int)bulletRadius, (int)bulletPosy_ + (int)bulletRadius,
			(int)bulletPosx_ + (int)bulletRadius, (int)bulletPosy_ + (int)bulletRadius,
			WHITE,
			kFillModeSolid
		);
	}

	// 敵を表示
	if (isEnemyAlive == true) {
		Novice::DrawEllipse(
			(int)enemyPosx_, (int)enemyPosy_,
			(int)enemyRadius, (int)enemyRadius,
			0.0f,
			RED,
			kFillModeSolid
		);
	}
}