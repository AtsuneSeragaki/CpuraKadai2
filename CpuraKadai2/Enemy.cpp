#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"

ENEMY Enemy::enemy;

// コンストラクタ
Enemy::Enemy()
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 更新処理
void Enemy::Update()
{
	EnemyMove();
}

// 描画処理
void Enemy::Draw() const
{
	DrawGraph(enemy.x,enemy.y,enemy.img,TRUE);
}

// 敵の移動処理
void Enemy::EnemyMove()
{
	if (enemy.flg == TRUE)
	{
		// 真っすぐ下に移動
		enemy.x -= enemy.speed;

		// 画面をはみ出したら消去
		if (enemy.x < -65)
			enemy.flg = FALSE;
	}
	
	// 走行距離ごとに敵出現パターンを制御する
	if (Player::mileage / 10 % 50 == 0)
	{
		CreateEnemy();
	}
}

// 敵の生成処理
int Enemy::CreateEnemy()
{	
	if (enemy.flg == FALSE)
	{
		enemy = enemy00;
		enemy.img = LoadGraph("images/cone.bmp");
		enemy.x = 1300;
		enemy.y = GetRand(6) * 90 + 40;
		enemy.speed = 2;
		// 成功
		return TRUE;
	}
	
	// 失敗
	return FALSE;
}

// ダメージを受けた時の処理(引数でダメージを受け取る)
void Enemy::Hit(int damage)
{
}

