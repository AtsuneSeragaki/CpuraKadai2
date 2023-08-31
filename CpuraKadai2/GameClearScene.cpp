#include "GameClearScene.h"
#include "InputRanking.h"
#include "InputController.h"
#include "TitleScene.h"
#include "DxLib.h"

// コンストラクタ
GameClearScene::GameClearScene()
{
}

// デストラクタ
GameClearScene::~GameClearScene()
{
}

// 更新処理
void GameClearScene::Update()
{
}

// 描画処理
void GameClearScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "ゲームクリア画面");
	DrawFormatString(0, 20, 0xffffff, "Aでタイトル画面へ");
	DrawFormatString(0, 40, 0xffffff, "Bでランキング画面へ");


#endif // DEBUG
}

// 遷移先を指定
SceneBase* GameClearScene::Change()
{
	// 仮
	if (InputController::GetBottonDown(PAD_INPUT_1) == TRUE)
	{
		// Aボタンが押されたらタイトルへ
		return new TitleScene();
	}

	// 仮
	if (InputController::GetBottonDown(PAD_INPUT_2) == TRUE)
	{
		// Bボタンが押されたらランキング入力へ
		return new InputRanking();
	}

	return this;
}