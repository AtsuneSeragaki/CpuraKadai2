#pragma once
#include"RankingScene.h"

class InputRanking : public RankingScene
{
public:
	InputRanking();   // �R���X�g���N�^
	~InputRanking();  // �f�X�g���N�^

	void Update() override;          // �X�V����
	void Draw() const override;      // �`�揈��
	SceneBase* Change() override;    // �J�ڐ�̎w��
};

