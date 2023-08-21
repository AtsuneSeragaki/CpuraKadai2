#pragma once
#include "SphereCollider.h"
#include "GameMainScene.h"
class CharaBase : public SphereCollider
{
protected:
	float x, y;   // 座標 
	float speed;  // 速度
	int image;    // 画像用変数

public:
	virtual void Update() = 0;  // 更新処理(引数にゲームメインシーンのポインタを受け取る)
	virtual void Draw() const = 0;            // 描画処理

	virtual void Hit(int damage) = 0;  // ダメージを受けた時の処理(引数でダメージを受け取る)
};

