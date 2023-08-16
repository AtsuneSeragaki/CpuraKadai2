#include "GameMainScene.h"
#include "InputController.h"
#include "GameOverScene.h"
#include "GameClearScene.h"
#include "CharaBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "DxLib.h"

Player player;
Enemy* enemy;
Bullet* bullet;

// コンストラクタ
GameMainScene::GameMainScene()
{
	stageImg = LoadGraph("images/stage_background.png");
	stageImgX = 0;
	stageImgY = 0;
	life = 0;     // プレイヤーの残機
}

// デストラクタ
GameMainScene::~GameMainScene()
{
}

// 更新処理
void GameMainScene::Update()
{
	// プレイヤーの更新処理
	player.Update(0);
	// 背景画像のスクロール処理
	BackScrool();
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
	
}

// 遷移先を指定
SceneBase* GameMainScene::Change()
{
	
	if (InputController::GetBottonDown(PAD_INPUT_A))
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new GameOverScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_B))
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
}