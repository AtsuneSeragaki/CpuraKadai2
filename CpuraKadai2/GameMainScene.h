#pragma once
#include "SceneBase.h"

class GameMainScene : public SceneBase
{
private:

	
	int life;      // プレイヤーの残機
	


public:
	GameMainScene();   // コンストラクタ
	~GameMainScene();  // デストラクタ

	int HitCheck();      // 弾、プレイヤー、敵の当たり判定のチェックを行う
	
	void Update() override;      // 更新処理
	void Draw() const override;  // 描画処理
	SceneBase* Change() override;    // 遷移先の指定

	void SpawnBullet();  // 弾の配列に新しくデータを作成する

};

