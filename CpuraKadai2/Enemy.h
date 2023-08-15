#pragma once
#include "CharaBase.h"


class Enemy : public CharaBase
{
private:

	int hp;     // 敵のHP
	int point;  // スコアの加算量
	int weapon; // 武器(BulletsSpawnerの子クラス)

public:
	Enemy();   // コンストラクタ
	~Enemy();  // デストラクタ

	void Update(GameMainScene* gamemain) override;  // 更新処理(引数にゲームメインシーンのポインタを受け取る)
	void Draw() const override;            // 描画処理

	void Hit(int damage) override;  // ダメージを受けた時の処理(引数でダメージを受け取る)
};

