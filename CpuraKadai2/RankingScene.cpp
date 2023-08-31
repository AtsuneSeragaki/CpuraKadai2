#include "RankingScene.h"
#include "InputController.h"
#include "TitleScene.h"
#include "DxLib.h"

// コンストラクタ
RankingScene::RankingScene()
{
}

// デストラクタ
RankingScene::~RankingScene()
{
}

// 更新処理
void RankingScene::Update()
{
}

// 描画処理
void RankingScene::Draw() const
{
#ifdef _DEBUG
	SetFontSize(16);
	DrawFormatString(0, 0, 0xffffff, "ランキング画面");
	DrawFormatString(0, 20, 0xffffff, "Aでタイトル画面へ");


#endif // DEBUG
}

// 遷移先を指定
SceneBase* RankingScene::Change()
{
	if (InputController::GetBotton(PAD_INPUT_A))
	{
		// Aボタンが押されたらタイトルへ
		return new TitleScene();
	}

	return this;
}