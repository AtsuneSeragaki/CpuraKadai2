#pragma once

class SceneBase
{
public:
	~SceneBase() {};
	virtual void Update() = 0;         // 更新処理
	virtual void Draw() const = 0;     // 描画処理
	virtual SceneBase* Change() = 0;   // 遷移先の指定
};

