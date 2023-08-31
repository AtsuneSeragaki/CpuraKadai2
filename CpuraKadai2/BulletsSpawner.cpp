#include "BulletsSpawner.h"


// コンストラクタ
BulletsSpawner::BulletsSpawner()
{
	speed = 0.0f;
	angle = 0.0f;
	acceleration = 0.0f;
	angulVelocity = 0.0f;
}

// デストラクタ
BulletsSpawner::~BulletsSpawner()
{
}

// SpawnBulletで弾を生成する(引数にゲームメインシーンのポインタを受け取る)
void BulletsSpawner::Shoot(GameMainScene* gamemain)
{
	
}