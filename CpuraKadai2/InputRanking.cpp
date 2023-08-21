#include "InputRanking.h"
#include "RankingScene.h"
#include "InputController.h"
#include "DxLib.h"

// �R���X�g���N�^
InputRanking::InputRanking()
{
}

// �f�X�g���N�^
InputRanking::~InputRanking()
{
}

// �X�V����
void InputRanking::Update()
{
}

// �`�揈��
void InputRanking::Draw() const
{
#ifdef DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "�����L���O���͉��");
	DrawFormatString(0, 20, 0xffffff, "A�Ń����L���O��ʂ�");

#endif // DEBUG
}

// �J�ڐ���w��
SceneBase* InputRanking::Change()
{
	if (InputController::GetBottonDown(PAD_INPUT_A))
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new RankingScene();
	}

	return this;
}