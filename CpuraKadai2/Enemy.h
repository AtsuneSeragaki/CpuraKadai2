#pragma once
#include "CharaBase.h"

class NwaySpawner;

// 敵機の構造体
struct ENEMY {
	int flg = 0;   // 使用フラグ
	int type = 0;  // タイプ
	int img = 0;   // 画像
	int x = 0, y = 0, w = 0, h = 0; // 座標、幅、高さ
	int speed = 0; // 移動速度
	int hp = 0;    // 敵のHP
	int point = 0; // スコア加算ポイント
};

class Enemy:public CharaBase
{
private:
	NwaySpawner* weapon; // 武器(BulletsSpawnerの子クラス)
	ENEMY enemy00 = { 1, 0, 0, 0, -10, 63, 120, 0, 1, 1 }; // 敵のデータ初期化用
	const int enemyMax = 20; // 敵の最大数

public:
	static ENEMY enemy; // 敵のデータ

	Enemy();   // コンストラクタ
	~Enemy();  // デストラクタ

	void Update() override;        // 更新処理(引数にゲームメインシーンのポインタを受け取る)
	void Draw() const override;    // 描画処理

	void EnemyMove();  // 敵の移動処理
	int CreateEnemy(); // 敵の生成処理
	void Hit(int damage) override;  // ダメージを受けた時の処理(引数でダメージを受け取る)
};

