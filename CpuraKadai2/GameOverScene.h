#pragma once
#include "SceneBase.h"

class GameOverScene : public SceneBase
{
public:
	GameOverScene();   // �R���X�g���N�^
	~GameOverScene();  // �f�X�g���N�^

	void Update() override;          // �X�V����
	void Draw() const override;      // �`�揈��
	SceneBase* Change() override;    // �J�ڐ�̎w��
};

