#pragma once
#include "SphereCollider.h"

class Bullet:public SphereCollider
{
private:
	int damege;
	int speed;           // ���x
	float angle;         // �p�x
	float acceleration;  // ���x�̕ω���
	float angulVelocity; // �p�x�̕ω���

public:
	void Update();
	void Draw();
	void GetDamage();
};

