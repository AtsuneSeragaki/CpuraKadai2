#include "GameMainScene.h"
#include "InputController.h"
#include "GameOverScene.h"
#include "GameClearScene.h"
#include "CharaBase.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"

Player pla;
Enemy* ene;


// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	player = 0;   // �v���C���[�ϐ�
	life = 0;     // �v���C���[�̎c�@
	enemy = 0;    // �G�̃|�C���^�z��
	bullets = 0;  // �e�̃|�C���^�z��
}

// �f�X�g���N�^
GameMainScene::~GameMainScene()
{
}

// �X�V����
void GameMainScene::Update()
{
}

// �`�揈��
void GameMainScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "�Q�[�����C�����");
	DrawFormatString(0, 20, 0xffffff, "A�ŃQ�[���I�[�o�[��ʂ�");
	DrawFormatString(0, 40, 0xffffff, "B�ŃQ�[���N���A��ʂ�");

#endif // DEBUG
	pla.Draw();
}

// �J�ڐ���w��
SceneBase* GameMainScene::Change()
{
	
	if (InputController::GetBottonDown(PAD_INPUT_A))
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new GameOverScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_B))
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new GameClearScene();
	}

	return this;
}

// �e�A�v���C���[�A�G�̓����蔻��̃`�F�b�N���s��
int GameMainScene::HitCheck()
{
	return 0;
}

// �e�̔z��ɐV�����f�[�^���쐬����
void GameMainScene::SpawnBullet()
{
}