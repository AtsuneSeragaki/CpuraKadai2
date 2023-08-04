#pragma once
#include "SphereCollider.h"

class CharaBase:public SphereCollider
{
private:
	int speed;
	int image;

public:
	virtual void Update(int* gamemain) = 0;  // �����ɃQ�[�����C���V�[���̃|�C���^���󂯎��
	virtual void Draw() const = 0;
	virtual void Hit();  // �����Ń_���[�W���󂯎��A�_���[�W���󂯂��Ƃ��̏���
};

