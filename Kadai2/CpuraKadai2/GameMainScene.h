#pragma once
#include "SceneBase.h"

class GameMainScene:public SceneBase
{
private:
	int player;
	int life;
	int* enemy[3];
	int* bullets[3];

public:
	GameMainScene();     // コンストラクタ
	~GameMainScene();    // デストラクタ
	int HitCheck();      // 弾/プレイヤー/敵の当たり判定のチェックを行う
	void SpawnBullet();  // 弾の配列に新しくデータを作成する
	void Update() override;       // 更新処理
	void Draw() const override;   // 描画処理
};

