#include "Bullet.h"
#include "DxLib.h"

// �R���X�g���N�^
Bullet::Bullet()
{
	damage = 0;
	speed = 0.0f;
	angle = 0.0f;
	acceleration = 0.0f;
	angulVelocity = 0.0f;
}

// �f�X�g���N�^
Bullet::~Bullet()
{
}

// �X�V����
void Bullet::Update()
{

}

// �`�揈��
void Bullet::Draw() const
{
	DrawCircle(0, 0, 10, 0xffffff, TRUE);
}

// �_���[�W���󂯎�鏈��
void Bullet::GetDamage()
{
}