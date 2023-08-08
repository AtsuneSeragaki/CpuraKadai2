#pragma once
#include "SphereCollider.h"
#include "GameMainScene.h"

class CharaBase : public SphereCollider
{
private:
	float speed;  // ���x
	int image;    // �摜�p�ϐ�

public:
	CharaBase();   // �R���X�g���N�^
	~CharaBase();  // �f�X�g���N�^

	virtual void Update(GameMainScene*) = 0;  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	virtual void Draw() const = 0;            // �`�揈��

	virtual void Hit(int damage);  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

