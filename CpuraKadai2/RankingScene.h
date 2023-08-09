#pragma once
#include "SceneBase.h"

class RankingScene : public SceneBase
{
public:
	RankingScene();   // コンストラクタ
	~RankingScene();  // デストラクタ

	void Update() override;          // 更新処理
	void Draw() const override;      // 描画処理
	SceneBase* Change() override;    // 遷移先の指定
};

