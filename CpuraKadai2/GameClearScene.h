#pragma once
#include "SceneBase.h"

class GameClearScene : public SceneBase
{
public:
	GameClearScene();   // コンストラクタ
	~GameClearScene();  // デストラクタ

	void Update() override;          // 更新処理
	void Draw() const override;      // 描画処理
	SceneBase* Change() override;    // 遷移先の指定
};

