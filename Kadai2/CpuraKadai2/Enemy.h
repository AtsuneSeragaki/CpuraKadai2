#pragma once
#include "CharaBase.h"

class Enemy:public CharaBase
{
private:
	int hp;
	int point;   // スコアの加算量
	int weapon;  // BulletsSpawnerの子クラス

public:
	void Update(int* gamemain) override;
	void Draw() const override;
	void Hit() override;
};

