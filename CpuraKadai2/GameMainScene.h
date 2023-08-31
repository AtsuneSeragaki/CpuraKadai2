#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class GameMainScene : public SceneBase
{
private:
	int stageImg;                // ステージの背景画像
	int stageImgX,stageImgY;     // ステージの背景画像描画位置
	int life;                    // プレイヤーの残機
	const int enemyMax = 20;     // 敵の最大数 
	const int bulletMax = 100;   // 弾の最大数
	int okFlg;                   // ボタンを押したら一個だけ弾を生成する用フラグ
	int okFlg2;                  // ボタンを押したら一個だけ敵を生成する用フラグ
	int Fcnt;                    // フレームカウント用変数
	Bullet* bullet[100];         // 弾のポインタ配列
	Player player;               // プレイヤーの変数
	Enemy* enemy[20];            // 敵のポインタ配列

public:
	GameMainScene();   // コンストラクタ
	~GameMainScene();  // デストラクタ

	int HitCheck();     // 弾、プレイヤー、敵の当たり判定のチェックを行う
	void BackScrool();  // 背景画像のスクロール処理

	void Update() override;         // 更新処理
	void Draw() const override;     // 描画処理
	SceneBase* Change() override;   // 遷移先の指定
	void SpawnBullet();             // 弾の配列に新しくデータを作成する

};

