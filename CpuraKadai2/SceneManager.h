#pragma once
#include "SceneBase.h"

class SceneManager : public SceneBase
{
private:
	SceneBase* now_scene;    // 現在のシーン
	SceneBase* next_scene;   // 次のシーン

public:
	SceneManager();                    // コンストラクタ
	SceneManager(SceneBase* scene);    // 引数付きコンストラクタ(遷移先を指定)
	~SceneManager();                   // デストラクタ

	void Update() override;            // 更新処理
	void Draw() const override;        // 描画処理
	SceneBase* Change() override;      // 遷移先の指定
};

