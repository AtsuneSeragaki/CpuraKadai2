#include "TitleScene.h"
#include "InputController.h"
#include "GameMainScene.h"
#include "RankingScene.h"
#include "DxLib.h"

// コンストラクタ
TitleScene::TitleScene()
{
}

// デストラクタ
TitleScene::~TitleScene()
{
}

// 更新処理
void TitleScene::Update()
{
	//メニューカーソル移動処理
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

	//// メニューカーソルY座標
	//MenuY = MenuNumber * 52;

}

// 描画処理
void TitleScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "タイトル画面");
	DrawFormatString(0, 20, 0xffffff, "Aでゲームメイン画面へ");
	DrawFormatString(0, 40, 0xffffff, "Bでランキング画面へ");

#endif // DEBUG
	////タイトル画像表示
	//DrawGraph(0, 0, TitleImg, FALSE);

	//SetFontSize(16);
	//DrawFormatString(180, 440, 0x6495f2, "移動：↑キー or ↓キー  決定：Zキー");

	////メニューカーソル（三角形）の表示
	//DrawTriangle(250, 255 + MenuY, 270, 270 + MenuY, 250, 285 + MenuY, 0xFFD700, TRUE);
}

// 遷移先の指定処理
SceneBase* TitleScene::Change()
{
	if (InputController::GetBottonDown(PAD_INPUT_A))
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new GameMainScene();
	}

	if (InputController::GetBottonDown(PAD_INPUT_B))
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new RankingScene();
	}

	return this;
}

