#pragma once
#include "SceneBase.h"

class GameMainScene:public SceneBase
{
private:
	int player;
	int life;
	int* enemy[3];
	int* bullets[3];

public:
	GameMainScene();     // �R���X�g���N�^
	~GameMainScene();    // �f�X�g���N�^
	int HitCheck();      // �e/�v���C���[/�G�̓����蔻��̃`�F�b�N���s��
	void SpawnBullet();  // �e�̔z��ɐV�����f�[�^���쐬����
	void Update() override;       // �X�V����
	void Draw() const override;   // �`�揈��
};

