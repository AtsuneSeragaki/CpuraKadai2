#pragma once
#include "CharaBase.h"
#include "DxLib.h"
#define ENEMY_MAX 15   // �G�̍ő吔

// �G�@�̍\����
struct ENEMY {
	int flg = FALSE; // �g�p�t���O
	int type = 0; // �^�C�v
	int img = LoadGraph("images/cone.bmp"); // �摜
	int x = 0, y = 0, w = 0, h = 0; // ���W�A���A����
	int speed = 0; // �ړ����x
	int hp = 0;     // �G��HP
	int point = 0; // �X�R�A���Z�|�C���g
};

class Enemy : public CharaBase
{
private:
	int weapon; // ����(BulletsSpawner�̎q�N���X)
	ENEMY enemy00 = { TRUE, 0, 0, 0, -50, 63, 120, 0, 1, 1 };

public:
	static ENEMY enemy;
	Enemy();   // �R���X�g���N�^
	~Enemy();  // �f�X�g���N�^

	void Update() override;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	void Draw() const override;            // �`�揈��

	void EnemyMove();  // �G�̈ړ�����
	int CreateEnemy(); // �G�̐�������
	void Hit(int damage) override;  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

