#include "Enemy.h"

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
void Enemy::Update(GameMainScene* gamemain)
{
	EnemyMove();
}

// �`�揈��
void Enemy::Draw() const
{
}

// �G�̈ړ�����
void Enemy::EnemyMove()
{
}

// �G�̐�������
int Enemy::CreateEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i].flg == FALSE) {
			enemy[i] = enemy00;
			enemy[i].type = GetRand(2);
			/*enemy[i].img = enemyImg[enemy[i].type];*/
			enemy[i].x = GetRand(4) * 105 + 40;
			enemy[i].speed = enemy[i].type * 2;
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

