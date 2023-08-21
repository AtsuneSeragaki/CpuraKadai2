#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"

ENEMY Enemy::enemy[ENEMY_MAX];



// コンストラクタ
Enemy::Enemy()
{
	weapon = 0;

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
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		DrawGraph(enemy[i].x, enemy[i].y, enemy[i].img, TRUE);
	}
}

// 敵の移動処理
void Enemy::EnemyMove()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i].flg == TRUE)
		{

			// 真っすぐ下に移動
			enemy[i].x -= enemy[i].speed;

			// 画面をはみ出したら消去
			if (enemy[i].x < -60)
				enemy[i].flg = FALSE;

			//// 敵機を追い越したらカウントする
			//if (gEnemy[i].y > gPlayer.y && gEnemy[i].point == 1)
			//{
			//	gEnemy[i].point = 0;
			//	if (gEnemy[i].type == 0) gEnemyCount[0]++;
			//	if (gEnemy[i].type == 1) gEnemyCount[1]++;
			//	if (gEnemy[i].type == 2) gEnemyCount[2]++;
			//	if (gEnemy[i].type == 3) gEnemyCount[3]++;
			//}
			//// 当たり判定
			//if (HitBoxPlayer(&gPlayer, &gEnemy[i]) == TRUE && gPlayer.baricnt <= 0)
			//{
			//	gPlayer.flg = FALSE;
			//	gPlayer.count = 0;
			//	gPlayer.hp -= 100;
			//	gEnemy[i].flg = FALSE;
			//	if (gPlayer.hp <= 0) gGameMode = GAMEOVER;
			//}
		}
	}

	// 走行距離ごとに敵出現パターンを制御する
	if (Player::mileage / 10 % 50 == 0)
	{
		CreateEnemy();
	}
}

int Enemy::CreateEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i].flg == FALSE)
		{
			enemy[i] = enemy00;
			/*enemy[i].type = GetRand(3);*/
			enemy[i].img = LoadGraph("images/cone.bmp");
			enemy[i].x = 1200;
			enemy[i].y = GetRand(6) * 90 + 40;
			enemy[i].speed = 3;
			// 成功
			return TRUE;
		}
	}
	// 失敗
	return FALSE;
}

// ダメージを受けた時の処理(引数でダメージを受け取る)
void Enemy::Hit(int damage)
{
}

