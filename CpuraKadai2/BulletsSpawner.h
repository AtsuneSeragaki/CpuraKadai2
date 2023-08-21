#pragma once
#include "GameMainScene.h"
#include "Bullet.h"

class BulletsSpawner
{
private:
	float speed;         // 速度
	float angle;         // 角度
	float acceleration;  // 速度の変化量
	float angulVelocity; // 角度の変化量
	Bullet bullet;

public:
	BulletsSpawner();   // コンストラクタ
	~BulletsSpawner();  // デストラクタ

	void Shoot(GameMainScene*);  // SpawnBulletで弾を生成する(引数にゲームメインシーンのポインタを受け取る)
};

