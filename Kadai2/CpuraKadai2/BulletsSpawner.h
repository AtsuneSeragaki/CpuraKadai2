#pragma once

class BulletsSpawner
{
private:
	int speed;           // ���x
	float angle;         // �p�x
	float acceleration;  // ���x�̕ω���
	float angulVelocity; // �p�x�̕ω���

public:
	void Shoot(); // �����ɃQ�[�����C���V�[���̃|�C���^���󂯎��
	              // Spawnbullet�Œe�𐶐�����
};

