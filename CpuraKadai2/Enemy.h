#pragma once
#include "CharaBase.h"
#include "DxLib.h"
#define ENEMY_MAX 15   // �G�̍ő吔

// �G�@�̍\����
struct ENEMY {
	int flg; // �g�p�t���O
	int type; // �^�C�v
	int img; // �摜
	int x, y, w, h; // ���W�A���A����
	int speed; // �ړ����x
	int hp;     // �G��HP
	int point; // �X�R�A���Z�|�C���g
};

class Enemy : public CharaBase
{
private:
	int weapon; // ����(BulletsSpawner�̎q�N���X)
	ENEMY enemy00 = { TRUE, 0, 0, 0, -50, 63, 120, 0, 1, 1 };

public:
	static ENEMY enemy[ENEMY_MAX];
	Enemy();   // �R���X�g���N�^
	~Enemy();  // �f�X�g���N�^

	void Update(GameMainScene* gamemain) override;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	void Draw() const override;            // �`�揈��

	void EnemyMove();  // �G�̈ړ�����
	int CreateEnemy(); // �G�̐�������
	void Hit(int damage) override;  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

