#include "GameOverScene.h"
#include "TitleScene.h"
#include "InputController.h"
#include "DxLib.h"

// �R���X�g���N�^
GameOverScene::GameOverScene()
{
}

// �f�X�g���N�^
GameOverScene::~GameOverScene()
{
}

// �X�V����
void GameOverScene::Update()
{
}

// �`�揈��
void GameOverScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "�Q�[���I�[�o�[���");
	DrawFormatString(0, 20, 0xffffff, "A�Ń^�C�g����ʂ�");

#endif // DEBUG
}

// �J�ڐ���w��
SceneBase* GameOverScene::Change()
{
	if (InputController::GetBottonDown(PAD_INPUT_4)==TRUE)
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new TitleScene();
	}

	return this;
}