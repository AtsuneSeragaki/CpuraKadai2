#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"

ENEMY Enemy::enemy;

// �R���X�g���N�^
Enemy::Enemy()
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �X�V����
void Enemy::Update()
{
	EnemyMove();
}

// �`�揈��
void Enemy::Draw() const
{
	DrawGraph(enemy.x,enemy.y,enemy.img,TRUE);
}

// �G�̈ړ�����
void Enemy::EnemyMove()
{
	if (enemy.flg == TRUE)
	{
		// �^���������Ɉړ�
		enemy.x -= enemy.speed;

		// ��ʂ��͂ݏo���������
		if (enemy.x < -65)
			enemy.flg = FALSE;
	}
	
	// ���s�������ƂɓG�o���p�^�[���𐧌䂷��
	if (Player::mileage / 10 % 50 == 0)
	{
		CreateEnemy();
	}
}

// �G�̐�������
int Enemy::CreateEnemy()
{	
	if (enemy.flg == FALSE)
	{
		enemy = enemy00;
		enemy.img = LoadGraph("images/cone.bmp");
		enemy.x = 1300;
		enemy.y = GetRand(6) * 90 + 40;
		enemy.speed = 2;
		// ����
		return TRUE;
	}
	
	// ���s
	return FALSE;
}

// �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
void Enemy::Hit(int damage)
{
}

