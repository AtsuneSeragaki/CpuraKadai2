#include "CharaBase.h"

#include "DxLib.h"

// �R���X�g���N�^
CharaBase::CharaBase()
{
	x = 0.0f;
	y = 0.0f;
	speed = 0.0f;
	image = 0;
}

// �f�X�g���N�^
CharaBase::~CharaBase()
{
}

void CharaBase::Update(GameMainScene* gamemain)
{	
}

void CharaBase::Draw() const
{
}

void CharaBase::Hit(int damage)
{
}