#pragma once
#include "CharaBase.h"

class Player : public CharaBase
{
private:
	int stickX, stickY;
	int score;   // スコア
	int weapon;  // 武器()

public:
	Player();   // コンストラクタ
	~Player();  // デストラクタ

   void Update(GameMainScene* gamemain) override;  // 更新処理(引数にゲームメインシーンのポインタを受け取る)
   void Draw() const override;                     // 描画処理
   void Hit(int damage) override;                  // ダメージを受けた時の処理(引数でダメージを受け取る)
   void PlayerMove();                              // プレイヤーの移動処理
};

