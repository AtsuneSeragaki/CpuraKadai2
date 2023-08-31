#include "GameClearScene.h"
#include "InputRanking.h"
#include "InputController.h"
#include "TitleScene.h"
#include "DxLib.h"

// �R���X�g���N�^
GameClearScene::GameClearScene()
{
}

// �f�X�g���N�^
GameClearScene::~GameClearScene()
{
}

// �X�V����
void GameClearScene::Update()
{
}

// �`�揈��
void GameClearScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "�Q�[���N���A���");
	DrawFormatString(0, 20, 0xffffff, "A�Ń^�C�g����ʂ�");
	DrawFormatString(0, 40, 0xffffff, "B�Ń����L���O��ʂ�");


#endif // DEBUG
}

// �J�ڐ���w��
SceneBase* GameClearScene::Change()
{
	// ��
	if (InputController::GetBottonDown(PAD_INPUT_1) == TRUE)
	{
		// A�{�^���������ꂽ��^�C�g����
		return new TitleScene();
	}

	// ��
	if (InputController::GetBottonDown(PAD_INPUT_2) == TRUE)
	{
		// B�{�^���������ꂽ�烉���L���O���͂�
		return new InputRanking();
	}

	return this;
}