#pragma once
#include "SceneBase.h"

class GameClearScene : public SceneBase
{
public:
	GameClearScene();   // �R���X�g���N�^
	~GameClearScene();  // �f�X�g���N�^

	void Update() override;          // �X�V����
	void Draw() const override;      // �`�揈��
	SceneBase* Change() override;    // �J�ڐ�̎w��
};

