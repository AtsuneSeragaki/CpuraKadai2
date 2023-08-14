#include "CharaBase.h"

#include "DxLib.h"

// コンストラクタ
CharaBase::CharaBase()
{
	speed = 0;
	image = 0;
}

// デストラクタ
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