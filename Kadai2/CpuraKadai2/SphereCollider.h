#pragma once

class SphereCollider // �����蔻��p�̃N���X
{
private:
	float location;  // ���S���W
	float radius;

public:
	int CheckCollision();  // ������SphereCollider���󂯎��
	                       // SphereCollider���m�̓����蔻����s�������������ǂ�����n��
};

