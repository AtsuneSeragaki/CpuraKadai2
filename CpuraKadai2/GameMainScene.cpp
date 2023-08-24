#include "GameMainScene.h"
#include "InputController.h"
#include "GameClearScene.h"
#include "GameOverScene.h"
#include "DxLib.h"

// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	stageImg = LoadGraph("images/stage_background.png");
	stageImgX = 0;
	stageImgY = 0;
	life = 0;     // �v���C���[�̎c�@
	for (int i = 0; i < enemyMax; i++)
	{
		enemy[i] = new Enemy;
	}

	for (int i = 0; i < bulletMax; i++)
	{
		bullet[i] = new Bullet;
	}
}

// �f�X�g���N�^
GameMainScene::~GameMainScene()
{
	for (int i = 0; i < enemyMax; i++)
	{
		delete enemy[i];
	}
	
	for (int i = 0; i < bulletMax; i++)
	{
		delete bullet[i];
	}
}

// �X�V����
void GameMainScene::Update()
{
	// �v���C���[�̍X�V����
	player.Update();
	// �w�i�摜�̃X�N���[������
	BackScrool();
	for (int i = 0; i < enemyMax; i++)
	{
		enemy[i]->Update();
	}

	for (int i = 0; i < bulletMax; i++)
	{
		bullet[i]->Update();
	}
	
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

	// �w�i�摜�\��(����)
	DrawGraph(stageImgX, stageImgY, stageImg, FALSE);
	// �w�i�摜�\��(�E��)
	DrawGraph(stageImgX - 1280, stageImgY, stageImg, FALSE);
	// �v���C���[�̕\��
	player.Draw();
	for (int i = 0; i < enemyMax; i++)
	{
		enemy[i]->Draw();
	}

	for (int i = 0; i < bulletMax; i++)
	{
		bullet[i]->Draw();
	}
}

// �J�ڐ���w��
SceneBase* GameMainScene::Change()
{
	
	if (InputController::GetBottonDown(PAD_INPUT_1) == TRUE)
	{
		// Z�L�[�������ꂽ�����j���[�i���o�[0�ŃQ�[�����C����
		return new GameClearScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_2) == TRUE)
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

// �w�i�摜�̃X�N���[������
void GameMainScene::BackScrool()
{
	int speed = 2;

	stageImgX -= speed;

	if (stageImgX < 0)
	{
		stageImgX = 1280;
	}
}

// �e�̔z��ɐV�����f�[�^���쐬����
void GameMainScene::SpawnBullet()
{
}