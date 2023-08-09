#include "TitleScene.h"
#include "InputController.h"
#include "GameMainScene.h"
#include "RankingScene.h"
#include "DxLib.h"

// �R���X�g���N�^
TitleScene::TitleScene()
{
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
}

// �X�V����
void TitleScene::Update()
{
	//���j���[�J�[�\���ړ�����
	if (InputController::GetBotton(PAD_INPUT_DOWN))
	{
		/*if (++MenuNumber > 1)
		{
			MenuNumber = 0;
		}*/
	}
	if (InputController::GetBotton(PAD_INPUT_UP))
	{
		/*if (--MenuNumber < 0) MenuNumber = 1;*/
	}

	//// ���j���[�J�[�\��Y���W
	//MenuY = MenuNumber * 52;

}

// �`�揈��
void TitleScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "�^�C�g�����");
	DrawFormatString(0, 20, 0xffffff, "A�ŃQ�[�����C����ʂ�");
	DrawFormatString(0, 40, 0xffffff, "B�Ń����L���O��ʂ�");

#endif // DEBUG
	////�^�C�g���摜�\��
	//DrawGraph(0, 0, TitleImg, FALSE);

	//SetFontSize(16);
	//DrawFormatString(180, 440, 0x6495f2, "�ړ��F���L�[ or ���L�[  ����FZ�L�[");

	////���j���[�J�[�\���i�O�p�`�j�̕\��
	//DrawTriangle(250, 255 + MenuY, 270, 270 + MenuY, 250, 285 + MenuY, 0xFFD700, TRUE);
}

// �J�ڐ�̎w�菈��
SceneBase* TitleScene::Change()
{
	if (InputController::GetBottonDown(PAD_INPUT_A))
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new GameMainScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_B))
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new RankingScene();
	}

	return this;
}

