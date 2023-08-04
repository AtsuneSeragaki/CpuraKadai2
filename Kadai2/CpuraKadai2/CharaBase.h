#pragma once
#include "SphereCollider.h"

class CharaBase:public SphereCollider
{
private:
	int speed;
	int image;

public:
	virtual void Update(int* gamemain) = 0;  // 引数にゲームメインシーンのポインタを受け取る
	virtual void Draw() const = 0;
	virtual void Hit();  // 引数でダメージを受け取る、ダメージを受けたときの処理
};

