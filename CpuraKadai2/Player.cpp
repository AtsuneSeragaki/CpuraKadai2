#include "Player.h"
#include "GameMainScene.h"
#include "DxLib.h"

// �R���X�g���N�^
Player::Player()
{
	score = 0;
	weapon = 0;
}

// �f�X�g���N�^
Player::~Player()
{
}

// �X�V����
void Player::Update(GameMainScene* gamemain)
{

}

// �`�揈��
void Player::Draw() const
{
	DrawBox(100, 300, 150, 350, 0xffffff, TRUE);
}

// �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
void Player::Hit(int damage)
{
}