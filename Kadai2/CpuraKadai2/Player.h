#pragma once
#include "CharaBase.h"

class Player:public CharaBase
{
private:
	int score;
	int* weapon;

public:
	void Update(int* gamemain) override;
	void Draw() const override;
	void Hit() override;
};

