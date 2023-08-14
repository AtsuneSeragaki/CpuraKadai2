#include "Player.h"
#include "GameMainScene.h"
#include "DxLib.h"

// コンストラクタ
Player::Player()
{
	score = 0;
	weapon = 0;
}

// デストラクタ
Player::~Player()
{
}

// 更新処理
void Player::Update(GameMainScene* gamemain)
{

}

// 描画処理
void Player::Draw() const
{
	DrawBox(100, 300, 150, 350, 0xffffff, TRUE);
}

// ダメージを受けた時の処理(引数でダメージを受け取る)
void Player::Hit(int damage)
{
}