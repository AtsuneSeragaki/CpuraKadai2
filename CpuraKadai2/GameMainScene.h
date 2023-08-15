#pragma once
#include "SceneBase.h"

class GameMainScene : public SceneBase
{
private:

	
	int life;      // �v���C���[�̎c�@
	


public:
	GameMainScene();   // �R���X�g���N�^
	~GameMainScene();  // �f�X�g���N�^

	int HitCheck();      // �e�A�v���C���[�A�G�̓����蔻��̃`�F�b�N���s��
	
	void Update() override;      // �X�V����
	void Draw() const override;  // �`�揈��
	SceneBase* Change() override;    // �J�ڐ�̎w��

	void SpawnBullet();  // �e�̔z��ɐV�����f�[�^���쐬����

};

