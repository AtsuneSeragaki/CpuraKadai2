#pragma once
#include "SphereCollider.h"

class GameMainScene;

class CharaBase : public SphereCollider
{
protected:
	float x, y;   // 座標 
	float speed;  // 速度
	int image;    // 画像用変数

public:
	CharaBase()
	{
		x = 0;
		y = 0;
		image = 0;
		speed = 0;
	};

	~CharaBase(){};

	virtual void Update() = 0;  // 更新処理(引数にゲームメインシーンのポインタを受け取る)
	virtual void Draw() const = 0;            // 描画処理

	virtual void Hit(int damage) = 0;  // ダメージを受けた時の処理(引数でダメージを受け取る)
};

