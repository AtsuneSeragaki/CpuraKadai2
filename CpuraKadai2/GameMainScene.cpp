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
	okFlg = 0;
	Fcnt = 0;
	okFlg2 = 0;

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

	if (InputController::GetBottonDown(PAD_INPUT_3) == TRUE)
	{
		okFlg = 1;
		SpawnBullet();
	}

	for (int i = 0; i < enemyMax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}

	}

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
	
	if (Fcnt > 60)
	{
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
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	for (int i = 0; i < bulletMax; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

	DrawFormatString(100, 40, 0xff0000, "%d", Fcnt);
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
	for (int i = 0; i < bulletMax; i++)
	{
		if (bullet[i] == nullptr && okFlg == 1)
		{
			bullet[i] = new Bullet;
			okFlg = 0;
		}
	}
}