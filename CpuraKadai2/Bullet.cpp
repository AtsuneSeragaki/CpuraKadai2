#include "Bullet.h"
#include "Player.h"
#include "InputController.h"
#include "DxLib.h"

// コンストラクタ
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
}

// デストラクタ
Bullet::~Bullet()
{
}

// 更新処理
void Bullet::Update()
{
	if (InputController::GetBottonDown(PAD_INPUT_3) == TRUE)
	{
		for (int i = 0; i < BULLET_MAX; i++)
		{
			if (bullet[i].flg == 0 && okFlg == 0)
			{
				bullet[i].flg = 1;
				bullet[i].x = Player::pX;
				bullet[i].y = Player::pY;
				okFlg = 1;
			}
		}
	}

	okFlg = 0;

	MoveBullet();
	
}

// 描画処理
void Bullet::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "%d",bulletFlg);

	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i].flg == 1)
		{
			DrawCircle(bullet[i].x + 10, bullet[i].y, 5, 0x11eeff, TRUE);
		}
	}
}

// ダメージを受け取る処理
void Bullet::GetDamage()
{
}

// 弾の移動処理
void Bullet::MoveBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i].flg == 1)
		{
			bullet[i].x += 3;
		}
		
		if (bullet[i].x > 1300)
		{
			bullet[i].flg = 0;
		}
	}
	
}