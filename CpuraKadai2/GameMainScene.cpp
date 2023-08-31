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
	life = 0;  
	okFlg = 0;
	okFlg2 = 0;
	Fcnt = 0;

	for (int i = 0; i < enemyMax; i++)
	{
		enemy[i] = nullptr;
	}

	for (int i = 0; i < bulletMax; i++)
	{
		bullet[i] = nullptr;
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
	Fcnt++;

	// �v���C���[�̍X�V����
	player.Update();
	// �w�i�摜�̃X�N���[������
	BackScrool();

	// X�{�^������������e�𐶐�
	if (InputController::GetBottonDown(PAD_INPUT_3) == TRUE)
	{
		okFlg = 1;
		SpawnBullet();
	}

	// �G�̐���
	for (int i = 0; i < enemyMax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}

	}

	// �e����ʊO�ɏo����f�[�^������
	for (int i = 0; i < bulletMax; i++)
	{
		if (bullet[i] != nullptr)
		{
			if (bullet[i]->bullet.x > 1300)
			{
				bullet[i] = nullptr;
			}
			else
			{
				bullet[i]->Update();
			}
		}
	}
	
	// �t���[���J�E���g��60�������烊�Z�b�g
	if (Fcnt > 60)
	{
		// �G�̐����{�^�����������������e�𐶐�����p�t���O
		okFlg2 = 1;

		for (int i = 0; i < enemyMax; i++)
		{
			if (enemy[i] == nullptr && okFlg2 != 0)
			{
				enemy[i] = new Enemy;
				okFlg2++;

				if (okFlg2 > 3)
				{
					okFlg2 = 0;
				}
			}
		}
		
		Fcnt = 0;
	}
}

// �`�揈��
void GameMainScene::Draw() const
{
	// �w�i�摜�\��(����)
	DrawGraph(stageImgX, stageImgY, stageImg, FALSE);
	// �w�i�摜�\��(�E��)
	DrawGraph(stageImgX - 1280, stageImgY, stageImg, FALSE);
	// �v���C���[�̕\��
	player.Draw();

	// �G�̕\��
	for (int i = 0; i < enemyMax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	// �e�̕\��
	for (int i = 0; i < bulletMax; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}
}

// �J�ڐ���w��
SceneBase* GameMainScene::Change()
{
	
	if (InputController::GetBottonDown(PAD_INPUT_1) == TRUE)
	{
		// A�{�^���������ꂽ��Q�[���N���A��
		return new GameClearScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_2) == TRUE)
	{
		// B�{�^���������ꂽ��Q�[���I�[�o�[��
		return new GameOverScene();
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
	for (int i = 0; i < bulletMax; i++)
	{
		if (bullet[i] == nullptr && okFlg == 1)
		{
			bullet[i] = new Bullet;
			okFlg = 0;
		}
	}
}