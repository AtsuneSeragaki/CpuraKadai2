#pragma once
#include "BulletsSpawner.h"

class NwaySpawner : public BulletsSpawner
{
private:
	int numBullets;   // ���˂���e�̐�
	float baseAngle;  // ���˂���ŏ��̒e�̌���
	float angleDiff;  // �e���m�̊p�x��
};

