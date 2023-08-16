#include "Enemy.h"

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
void Enemy::Update(GameMainScene* gamemain)
{
	EnemyMove();
}

// 描画処理
void Enemy::Draw() const
{
}

// 敵の移動処理
void Enemy::EnemyMove()
{
}

// 敵の生成処理
int Enemy::CreateEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i].flg == FALSE) {
			enemy[i] = enemy00;
			enemy[i].type = GetRand(2);
			/*enemy[i].img = enemyImg[enemy[i].type];*/
			enemy[i].x = GetRand(4) * 105 + 40;
			enemy[i].speed = enemy[i].type * 2;
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

