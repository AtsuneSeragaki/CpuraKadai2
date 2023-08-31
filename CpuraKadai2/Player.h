#pragma once
#include "CharaBase.h"

class BulletSpawner;

class Player : public CharaBase
{
private:
	int stickX, stickY;     // コントローラーのX座標、Y座標
	int playerImg;          // プレイヤーの画像用変数
	int score;              // スコア

public:
	static int mileage; // プレイヤーの走行距離
	static int pX, pY;  // プレイヤーのX座標、Y座標

	Player();   // コンストラクタ
	~Player();  // デストラクタ

   void Update() override;           // 更新処理(引数にゲームメインシーンのポインタを受け取る)
   void Draw() const override;       // 描画処理
   void Hit(int damage) override;    // ダメージを受けた時の処理(引数でダメージを受け取る)
   void PlayerMove();                // プレイヤーの移動処理
};

