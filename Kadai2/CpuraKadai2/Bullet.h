#pragma once
#include "SphereCollider.h"

class Bullet:public SphereCollider
{
private:
	int damege;
	int speed;           // ‘¬“x
	float angle;         // Šp“x
	float acceleration;  // ‘¬“x‚Ì•Ï‰»—Ê
	float angulVelocity; // Šp“x‚Ì•Ï‰»—Ê

public:
	void Update();
	void Draw();
	void GetDamage();
};

