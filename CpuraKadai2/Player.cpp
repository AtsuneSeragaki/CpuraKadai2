#include "Player.h"
#include "GameMainScene.h"
#include "InputController.h"
#include "DxLib.h"

int Player::mileage = 0;
int Player::pX = 0;
int Player::pY = 0;

// �R���X�g���N�^
Player::Player()
{
	playerImg = 0;
	stickX = 0;
	stickY = 0;
	x = 100.0f;
	y = 360.0f;
	score = 0;
	weapon = 0;	
	speed = 2;
}

// �f�X�g���N�^
Player::~Player()
{
}

// �X�V����
void Player::Update()
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
	DrawBox((int)x, (int)y, (int)x + 40, (int)y + 50, 0xffffff, TRUE);
}

// �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
void Player::Hit(int damage)
{
}

// �v���C���[�̈ړ�����
void Player::PlayerMove()
{
	
	mileage += speed;
	

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

	pX = x + 40;
	pY = y + 25;
}