#pragma once
#include "SphereCollider.h"

class Bullet : public SphereCollider
{
private:
	int damage;           // �_���[�W
	float speed;          // ���x
	float angle;          // �p�x
	float acceleration;   // ���x�̕ω���
	float angulVelocity;  // �p�x�̕ω���
	int bulletFlg;        // �e�̃t���O(0:�������Ȃ� 1:�������\��)
	const int bulletMax = 100;  // �e�̍ő吔

public:
	int okFlg;   // �{�^�����������������e�𐶐�����p�t���O

	// �G�@�̍\����
	struct BULLET
	{
		int flg = 0; // �g�p�t���O
		int x = 0, y = 0; // ���W�A���A����
		int speed = 3; // �ړ����x
	};

	BULLET bullet;  // �G�̃f�[�^

	Bullet();   // �R���X�g���N�^
	~Bullet();  // �f�X�g���N�^

	void Update();      // �X�V����
	void Draw() const;  // �`�揈��
	
	void GetDamage();   // �_���[�W���󂯎�鏈��
	void MoveBullet();  // �e�̈ړ�����
};

