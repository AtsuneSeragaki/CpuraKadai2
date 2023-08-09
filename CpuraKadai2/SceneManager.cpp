#include "SceneManager.h"
#include "DxLib.h"

// コンストラクタ
SceneManager::SceneManager()
{
	now_scene = nullptr;
	next_scene = now_scene;
}

// 引数付きコンストラクタ
// 引数：最初のシーン情報
SceneManager::SceneManager(SceneBase* scene)
{
	now_scene = scene;
	next_scene = now_scene;
}

// デストラクタ
SceneManager::~SceneManager()
{

}

// 更新処理
void SceneManager::Update()
{
	if (now_scene != nullptr)
	{
		now_scene->Update();
	}
}

// 描画処理
void SceneManager::Draw() const
{

	// シーン画面の描画
	if (now_scene != nullptr)
	{
		now_scene->Draw();
	}

}

// 遷移先の指定処理
SceneBase* SceneManager::Change()
{
	// 遷移先を受け取る
	next_scene = now_scene->Change();

	// 遷移先が現在のシーンと違っていたら変更する
	if (next_scene != now_scene)
	{
		delete now_scene;
		now_scene = next_scene;
	}

	// 遷移先を返却
	return next_scene;
}
