#pragma once
#include "SphereCollider.h"
#include "GameMainScene.h"
class CharaBase : public SphereCollider
{
public:

	float speed;  // ���x
	int image;    // �摜�p�ϐ�

	CharaBase();   // �R���X�g���N�^
	~CharaBase();  // �f�X�g���N�^

	virtual void Update(GameMainScene* gamemain);  // �X�V����(�����ɃQ�[�����C���V�[���̃|�C���^���󂯎��)
	virtual void Draw() const;            // �`�揈��

	virtual void Hit(int damage);  // �_���[�W���󂯂����̏���(�����Ń_���[�W���󂯎��)
};

