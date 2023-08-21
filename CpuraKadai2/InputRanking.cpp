#include "InputRanking.h"
#include "RankingScene.h"
#include "InputController.h"
#include "DxLib.h"

// コンストラクタ
InputRanking::InputRanking()
{
}

// デストラクタ
InputRanking::~InputRanking()
{
}

// 更新処理
void InputRanking::Update()
{
}

// 描画処理
void InputRanking::Draw() const
{
#ifdef DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "ランキング入力画面");
	DrawFormatString(0, 20, 0xffffff, "Aでランキング画面へ");

#endif // DEBUG
}

// 遷移先を指定
SceneBase* InputRanking::Change()
{
	if (InputController::GetBottonDown(PAD_INPUT_A))
	{
		// Zキーが押された＆メニューナンバー0でゲームメインへ
		return new RankingScene();
	}

	return this;
}