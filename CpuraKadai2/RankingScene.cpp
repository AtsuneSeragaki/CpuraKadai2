#include "RankingScene.h"
#include "InputController.h"
#include "TitleScene.h"
#include "DxLib.h"

// �R���X�g���N�^
RankingScene::RankingScene()
{
}

// �f�X�g���N�^
RankingScene::~RankingScene()
{
}

// �X�V����
void RankingScene::Update()
{
}

// �`�揈��
void RankingScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "�����L���O���");
	DrawFormatString(0, 20, 0xffffff, "A�Ń^�C�g����ʂ�");


#endif // DEBUG
}

// �J�ڐ���w��
SceneBase* RankingScene::Change()
{
	if (InputController::GetBotton(PAD_INPUT_A))
	{
		// A�{�^���������ꂽ��^�C�g����
		return new TitleScene();
	}

	return this;
}