#pragma once
#include "SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();   // �R���X�g���N�^
	~TitleScene();  // �f�X�g���N�^

	void Update() override;          // �X�V����
	void Draw() const override;      // �`�揈��
	SceneBase* Change() override;    // �J�ڐ�̎w��
};

