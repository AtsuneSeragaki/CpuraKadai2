#pragma once
#include "CharaBase.h"


class Enemy : public CharaBase
{
private:

	int hp;     // �G��HP
	int point;  // �X�R�A�̉��Z��
	int weapon; // ����(BulletsSpawner�̎q�N���X)

public:
	Enemy();   // �R���X�g���N�^
	~Enemy();  // �f�X�g���N�^

	void Update(GameMainScene* gamemain) override;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	void Draw() const override;            // �`�揈��

	void Hit(int damage) override;  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

