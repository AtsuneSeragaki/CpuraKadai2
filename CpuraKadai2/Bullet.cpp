#include "Bullet.h"
#include "DxLib.h"

// コンストラクタ
Bullet::Bullet()
{
	damage = 0;
	speed = 0.0f;
	angle = 0.0f;
	acceleration = 0.0f;
	angulVelocity = 0.0f;
}

// デストラクタ
Bullet::~Bullet()
{
}

// 更新処理
void Bullet::Update()
{

}

// 描画処理
void Bullet::Draw() const
{
	DrawCircle(0, 0, 10, 0xffffff, TRUE);
}

// ダメージを受け取る処理
void Bullet::GetDamage()
{
}