#pragma once
#include "SceneBase.h"

class GameMainScene : public SceneBase
{
private:
	int player;    // �v���C���[�ϐ�
	int life;      // �v���C���[�̎c�@
	int* enemy;    // �G�̃|�C���^�z��
	int* bullets;  // �e�̃|�C���^�z��

public:
	GameMainScene();   // �R���X�g���N�^
	~GameMainScene();  // �f�X�g���N�^

	int HitCheck();      // �e�A�v���C���[�A�G�̓����蔻��̃`�F�b�N���s��
	
	void Update() override;      // �X�V����
	void Draw() const override;  // �`�揈��

	void SpawnBullet();  // �e�̔z��ɐV�����f�[�^���쐬����

};
