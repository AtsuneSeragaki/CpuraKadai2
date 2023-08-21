#include "GameOverScene.h"
#include "TitleScene.h"
#include "InputController.h"
#include "DxLib.h"

// コンストラクタ
GameOverScene::GameOverScene()
{
}

// デストラクタ
GameOverScene::~GameOverScene()
{
}

// 更新処理
void GameOverScene::Update()
{
}

// 描画処理
void GameOverScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "ゲームオーバー画面");
	DrawFormatString(0, 20, 0xffffff, "Aでタイトル画面へ");

#endif // DEBUG
}

// 遷移先を指定
SceneBase* GameOverScene::Change()
{
	if (InputController::GetBottonDown(PAD_INPUT_4)==TRUE)
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new TitleScene();
	}

	return this;
}