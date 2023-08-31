#include "Player.h"
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
	speed = 2;
}

// �f�X�g���N�^
Player::~Player()
{
}

// �X�V����
void Player::Update()
{
	// �R���g���[���[�̍��W����
	stickX = InputController::Xbuf;
	stickY = InputController::Ybuf;

	PlayerMove();
}

// �`�揈��
void Player::Draw() const
{
	DrawBox((int)x, (int)y, (int)x + 40, (int)y + 50, 0xffffff, TRUE);
}

// �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
void Player::Hit(int damage)
{
}

// �v���C���[�̈ړ�����
void Player::PlayerMove()
{
	// ���s���������Z
	mileage += (int)speed;
	
	// �X�e�B�b�N���E�ɓ|��Ă�����E�Ɉړ�
	if (stickX > 0)
	{
		x += 10.0f;
	}
	else if(stickX < 0)
	{
		// �X�e�B�b�N�����ɓ|��Ă����獶�Ɉړ�
		x -= 10.0f;
	}

	// ��ʊO(���E)�ɂ͂ݏo���Ȃ��悤�Ƀ��Z�b�g
	if (x < 0)
	{
		x = 0;
	}
	else if (x > 1240)
	{
		x = 1240;
	}

	// �X�e�B�b�N�����ɓ|��Ă����牺�Ɉړ�
	if (stickY > 0)
	{
		y += 10.0f;
	}
	else if (stickY < 0)
	{
		// �X�e�B�b�N����ɓ|��Ă������Ɉړ�
		y -= 10.0f;
	}

	// ��ʊO(�㉺)�ɂ͂ݏo���Ȃ��悤�Ƀ��Z�b�g
	if (y < 0)
	{
		y = 0;
	}
	else if (y > 670)
	{
		y = 670;
	}

	// �e�𔭎˂���ʒu����
	pX = (int)x + 40;
	pY = (int)y + 25;
}