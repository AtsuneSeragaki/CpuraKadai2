#include "Player.h"
#include "GameMainScene.h"
#include "InputController.h"
#include "DxLib.h"

// �R���X�g���N�^
Player::Player()
{
	stickX = 0;
	stickY = 0;
	x = 100.0f;
	y = 360.0f;
	score = 0;
	weapon = 0;
}

// �f�X�g���N�^
Player::~Player()
{
}

// �X�V����
void Player::Update(GameMainScene* gamemain)
{
	InputController::Update();
	GetJoypadAnalogInput(&stickX, &stickY, DX_INPUT_PAD1);
	PlayerMove();
}

// �`�揈��
void Player::Draw() const
{
#ifdef _DEBUG
	DrawFormatString(0, 150, 0xffffff, "%d",stickX);
#endif // DEBUG
	DrawBox(x, y, x + 40, y + 50, 0xffffff, TRUE);
}

// �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
void Player::Hit(int damage)
{
}

// �v���C���[�̈ړ�����
void Player::PlayerMove()
{
	if (stickX > 0)
	{
		x += 10.0f;
	}
	else if(stickX < 0)
	{
		x -= 10.0f;
	}

	if (x < 0)
	{
		x = 0;
	}
	else if (x > 1240)
	{
		x = 1240;
	}

	if (stickY > 0)
	{
		y += 10.0f;
	}
	else if (stickY < 0)
	{
		y -= 10.0f;
	}

	if (y < 0)
	{
		y = 0;
	}
	else if (y > 670)
	{
		y = 670;
	}
}