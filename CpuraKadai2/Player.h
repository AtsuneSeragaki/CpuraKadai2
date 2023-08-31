#pragma once
#include "CharaBase.h"

class BulletSpawner;

class Player : public CharaBase
{
private:
	int stickX, stickY;     // �R���g���[���[��X���W�AY���W
	int playerImg;          // �v���C���[�̉摜�p�ϐ�
	int score;              // �X�R�A

public:
	static int mileage; // �v���C���[�̑��s����
	static int pX, pY;  // �v���C���[��X���W�AY���W

	Player();   // �R���X�g���N�^
	~Player();  // �f�X�g���N�^

   void Update() override;           // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
   void Draw() const override;       // �`�揈��
   void Hit(int damage) override;    // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
   void PlayerMove();                // �v���C���[�̈ړ�����
};

