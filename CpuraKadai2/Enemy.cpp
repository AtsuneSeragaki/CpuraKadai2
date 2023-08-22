#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"

ENEMY Enemy::enemy;

// �R���X�g���N�^
Enemy::Enemy()
{
	weapon = 0;

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

		//// �G�@��ǂ��z������J�E���g����
		//if (gEnemy[i].y > gPlayer.y && gEnemy[i].point == 1)
		//{
		//	gEnemy[i].point = 0;
		//	if (gEnemy[i].type == 0) gEnemyCount[0]++;
		//	if (gEnemy[i].type == 1) gEnemyCount[1]++;
		//	if (gEnemy[i].type == 2) gEnemyCount[2]++;
		//	if (gEnemy[i].type == 3) gEnemyCount[3]++;
		//}
		//// �����蔻��
		//if (HitBoxPlayer(&gPlayer, &gEnemy[i]) == TRUE && gPlayer.baricnt <= 0)
		//{
		//	gPlayer.flg = FALSE;
		//	gPlayer.count = 0;
		//	gPlayer.hp -= 100;
		//	gEnemy[i].flg = FALSE;
		//	if (gPlayer.hp <= 0) gGameMode = GAMEOVER;
		//}
	}
	
	// ���s�������ƂɓG�o���p�^�[���𐧌䂷��
	if (Player::mileage / 10 % 50 == 0)
	{
		CreateEnemy();
	}
}

int Enemy::CreateEnemy()
{	
	if (enemy.flg == FALSE)
	{
		enemy = enemy00;
		enemy.img = LoadGraph("images/cone.bmp");
		enemy.x = 1300;
		enemy.y = GetRand(6) * 90 + 40;
		enemy.speed = 3;
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

