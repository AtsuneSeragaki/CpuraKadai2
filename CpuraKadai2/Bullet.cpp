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
	bulletImg = LoadGraph("images/bullet.png");
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

// 描画処理
void Bullet::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "%d",bulletFlg);

	
	if (bullet.flg == 1)
	{
		//DrawCircle(bullet[i].x + 10, bullet[i].y, 5, 0x11eeff, TRUE);
		DrawGraph(bullet.x + 10, bullet.y - 20, bulletImg, TRUE);
	}
	
}

// ダメージを受け取る処理
void Bullet::GetDamage()
{
}

// 弾の移動処理
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