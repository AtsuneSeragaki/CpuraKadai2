#pragma once
#include "SceneBase.h"

class RankingScene : public SceneBase
{
public:
	RankingScene();   // �R���X�g���N�^
	~RankingScene();  // �f�X�g���N�^

	void Update() override;          // �X�V����
	void Draw() const override;      // �`�揈��
	SceneBase* Change() override;    // �J�ڐ�̎w��
};

