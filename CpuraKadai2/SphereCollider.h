#pragma once

class SphereCollider  // �����蔻��p�̃N���X
{
private:
	float location;  // ���S���W
	float radius;    // ���a

public:
	SphereCollider();    // �R���X�g���N�^
	~SphereCollider();   // �f�X�g���N�^

	int CheckCollision(SphereCollider);  // ������SphereCollider���󂯎��
	                                     // SphereCollider���m�̓����蔻����s�������������ǂ�����Ԃ�
};

