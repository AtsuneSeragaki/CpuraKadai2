#include "SphereCollider.h"
#include "DxLib.h"

// �R���X�g���N�^
SphereCollider::SphereCollider()
{
	location = 0.0f;
	radius = 0.0f;
}

// �f�X�g���N�^
SphereCollider::~SphereCollider()
{
}

// SphereCollider���m�̓����蔻����s�������������ǂ�����Ԃ�
int SphereCollider::CheckCollision(SphereCollider)
{
	return 0;
}