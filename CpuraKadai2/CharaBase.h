#pragma once
#include "SphereCollider.h"
#include "GameMainScene.h"
class CharaBase : public SphereCollider
{
protected:
	float x, y;   // ���W 
	float speed;  // ���x
	int image;    // �摜�p�ϐ�

public:
	virtual void Update() = 0;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	virtual void Draw() const = 0;            // �`�揈��

	virtual void Hit(int damage) = 0;  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

