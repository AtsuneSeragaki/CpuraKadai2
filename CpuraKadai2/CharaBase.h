#pragma once
#include "SphereCollider.h"
#include "GameMainScene.h"
class CharaBase : public SphereCollider
{
public:

	float speed;  // 速度
	int image;    // 画像用変数

	CharaBase();   // コンストラクタ
	~CharaBase();  // デストラクタ

	virtual void Update(GameMainScene* gamemain);  // 更新処理(引数にゲームメインシーンのポインタを受け取る)
	virtual void Draw() const;            // 描画処理

	virtual void Hit(int damage);  // ダメージを受けた時の処理(引数でダメージを受け取る)
};

