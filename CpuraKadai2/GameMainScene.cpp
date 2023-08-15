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
	life = 0;     // プレイヤーの残機
	
}

// デストラクタ
GameMainScene::~GameMainScene()
{
}

// 更新処理
void GameMainScene::Update()
{
	player.Update(0);
	/*enemy->Update(0);
	bullet->Update();*/
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
	player.Draw();
	/*enemy->Draw();
	bullet->Draw();*/
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

// 弾の配列に新しくデータを作成する
void GameMainScene::SpawnBullet()
{
}