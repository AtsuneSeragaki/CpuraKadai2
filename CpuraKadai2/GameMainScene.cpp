#include "GameMainScene.h"
#include "InputController.h"
#include "GameClearScene.h"
#include "GameOverScene.h"
#include "DxLib.h"

// コンストラクタ
GameMainScene::GameMainScene()
{
	stageImg = LoadGraph("images/stage_background.png");
	stageImgX = 0;
	stageImgY = 0;
	life = 0;     // プレイヤーの残機
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

// デストラクタ
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

// 更新処理
void GameMainScene::Update()
{
	Fcnt++;

	// プレイヤーの更新処理
	player.Update();
	// 背景画像のスクロール処理
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

// 描画処理
void GameMainScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "ゲームメイン画面");
	DrawFormatString(0, 20, 0xffffff, "Aでゲームオーバー画面へ");
	DrawFormatString(0, 40, 0xffffff, "Bでゲームクリア画面へ");

#endif // DEBUG

	// 背景画像表示(左側)
	DrawGraph(stageImgX, stageImgY, stageImg, FALSE);
	// 背景画像表示(右側)
	DrawGraph(stageImgX - 1280, stageImgY, stageImg, FALSE);
	// プレイヤーの表示
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

// 遷移先を指定
SceneBase* GameMainScene::Change()
{
	
	if (InputController::GetBottonDown(PAD_INPUT_1) == TRUE)
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new GameClearScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_2) == TRUE)
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new GameClearScene();
	}

	return this;
}

// 弾、プレイヤー、敵の当たり判定のチェックを行う
int GameMainScene::HitCheck()
{
	return 0;
}

// 背景画像のスクロール処理
void GameMainScene::BackScrool()
{
	int speed = 2;

	stageImgX -= speed;

	if (stageImgX < 0)
	{
		stageImgX = 1280;
	}
}

// 弾の配列に新しくデータを作成する
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