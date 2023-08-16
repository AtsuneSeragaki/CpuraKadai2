#pragma once
#include "CharaBase.h"
#include "DxLib.h"
#define ENEMY_MAX 15   // 敵の最大数

// 敵機の構造体
struct ENEMY {
	int flg; // 使用フラグ
	int type; // タイプ
	int img; // 画像
	int x, y, w, h; // 座標、幅、高さ
	int speed; // 移動速度
	int hp;     // 敵のHP
	int point; // スコア加算ポイント
};

class Enemy : public CharaBase
{
private:
	int weapon; // 武器(BulletsSpawnerの子クラス)
	ENEMY enemy00 = { TRUE, 0, 0, 0, -50, 63, 120, 0, 1, 1 };

public:
	static ENEMY enemy[ENEMY_MAX];
	Enemy();   // コンストラクタ
	~Enemy();  // デストラクタ

	void Update(GameMainScene* gamemain) override;  // 更新処理(引数にゲームメインシーンのポインタを受け取る)
	void Draw() const override;            // 描画処理

	void EnemyMove();  // 敵の移動処理
	int CreateEnemy(); // 敵の生成処理
	void Hit(int damage) override;  // ダメージを受けた時の処理(引数でダメージを受け取る)
};

