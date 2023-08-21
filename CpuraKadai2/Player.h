#pragma once
#include "CharaBase.h"
#include "BulletsSpawner.h"

class Player : public CharaBase
{
private:
	int stickX, stickY;
	int playerImg;
	int score;   // �X�R�A
	BulletsSpawner* weapon;  // ����()

public:
	static int mileage; 
	Player();   // �R���X�g���N�^
	~Player();  // �f�X�g���N�^

   void Update() override;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
   void Draw() const override;                     // �`�揈��
   void Hit(int damage) override;                  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
   void PlayerMove();                              // �v���C���[�̈ړ�����
};

