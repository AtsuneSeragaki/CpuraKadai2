#pragma once
#include "CharaBase.h"

class Enemy:public CharaBase
{
private:
	int hp;
	int point;   // �X�R�A�̉��Z��
	int weapon;  // BulletsSpawner�̎q�N���X

public:
	void Update(int* gamemain) override;
	void Draw() const override;
	void Hit() override;
};

