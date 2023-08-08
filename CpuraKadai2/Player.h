#pragma once
#include "CharaBase.h"

class Player : public CharaBase
{
private:
	int score;   // �X�R�A
	int weapon;  // ����()

public:
	Player();   // �R���X�g���N�^
	~Player();  // �f�X�g���N�^

	void Update(GameMainScene*) override;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	void Draw() const override;            // �`�揈��

	void Hit(int damage) override;  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

