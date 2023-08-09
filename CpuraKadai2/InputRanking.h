#pragma once
#include"RankingScene.h"

class InputRanking : public RankingScene
{
public:
	InputRanking();   // コンストラクタ
	~InputRanking();  // デストラクタ

	void Update() override;          // 更新処理
	void Draw() const override;      // 描画処理
	SceneBase* Change() override;    // 遷移先の指定
};

