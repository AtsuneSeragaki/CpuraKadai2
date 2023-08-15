#include "SphereCollider.h"
#include "DxLib.h"

// コンストラクタ
SphereCollider::SphereCollider()
{
	location = 0.0f;
	radius = 0.0f;
}

// デストラクタ
SphereCollider::~SphereCollider()
{
}

// SphereCollider同士の当たり判定を行い当たったかどうかを返す
int SphereCollider::CheckCollision(SphereCollider)
{
	return 0;
}