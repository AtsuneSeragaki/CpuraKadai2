#include "Bullet.h"
#include "Player.h"
#include "InputController.h"
#include "DxLib.h"

// �R���X�g���N�^
Bullet::Bullet()
{
	//x = Player::pX, y = Player::pY;
	damage = 0;
	speed = 0.0f;
	angle = 0.0f;
	acceleration = 0.0f;
	angulVelocity = 0.0f;
	bulletFlg = 0;
	okFlg = 0;
	bulletImg = LoadGraph("images/bullet.png");
}

// �f�X�g���N�^
Bullet::~Bullet()
{
}

// �X�V����
void Bullet::Update()
{
	if (InputController::GetBottonDown(PAD_INPUT_3) == TRUE)
	{
		if (bullet.flg == 0 && okFlg == 0)
		{
			bullet.flg = 1;
			bullet.x = Player::pX;
			bullet.y = Player::pY;
			okFlg = 1;
		}
	}

	//okFlg = 0;

	MoveBullet();
	
}

// �`�揈��
void Bullet::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "%d",bulletFlg);

	
	if (bullet.flg == 1)
	{
		//DrawCircle(bullet[i].x + 10, bullet[i].y, 5, 0x11eeff, TRUE);
		DrawGraph(bullet.x + 10, bullet.y - 20, bulletImg, TRUE);
	}
	
}

// �_���[�W���󂯎�鏈��
void Bullet::GetDamage()
{
}

// �e�̈ړ�����
void Bullet::MoveBullet()
{

	if (bullet.flg == 1)
	{
		bullet.x += 3;
	}

	if (bullet.x > 1300)
	{
		bullet.flg = 0;
	}
}