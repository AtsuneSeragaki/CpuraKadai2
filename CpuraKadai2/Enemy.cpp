#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"

ENEMY Enemy::enemy[ENEMY_MAX];



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
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		DrawGraph(enemy[i].x, enemy[i].y, enemy[i].img, TRUE);
	}
}

// �G�̈ړ�����
void Enemy::EnemyMove()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i].flg == TRUE)
		{

			// �^���������Ɉړ�
			enemy[i].x -= enemy[i].speed;

			// ��ʂ��͂ݏo���������
			if (enemy[i].x < -60)
				enemy[i].flg = FALSE;

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
	}

	// ���s�������ƂɓG�o���p�^�[���𐧌䂷��
	if (Player::mileage / 10 % 50 == 0)
	{
		CreateEnemy();
	}
}

int Enemy::CreateEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i].flg == FALSE)
		{
			enemy[i] = enemy00;
			/*enemy[i].type = GetRand(3);*/
			enemy[i].img = LoadGraph("images/cone.bmp");
			enemy[i].x = 1200;
			enemy[i].y = GetRand(6) * 90 + 40;
			enemy[i].speed = 3;
			// ����
			return TRUE;
		}
	}
	// ���s
	return FALSE;
}

// �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
void Enemy::Hit(int damage)
{
}

