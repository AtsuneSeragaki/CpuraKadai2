#include "Player.h"
#include "InputController.h"
#include "DxLib.h"

int Player::mileage = 0;
int Player::pX = 0;
int Player::pY = 0;

// コンストラクタ
Player::Player()
{
	playerImg = 0;
	stickX = 0;
	stickY = 0;
	x = 100.0f;
	y = 360.0f;
	score = 0;
	speed = 2;
}

// デストラクタ
Player::~Player()
{
}

// 更新処理
void Player::Update()
{
	// コントローラーの座標を代入
	stickX = InputController::Xbuf;
	stickY = InputController::Ybuf;

	PlayerMove();
}

// 描画処理
void Player::Draw() const
{
	DrawBox((int)x, (int)y, (int)x + 40, (int)y + 50, 0xffffff, TRUE);
}

// ダメージを受けた時の処理(引数でダメージを受け取る)
void Player::Hit(int damage)
{
}

// プレイヤーの移動処理
void Player::PlayerMove()
{
	// 走行距離を加算
	mileage += (int)speed;
	
	// スティックが右に倒れていたら右に移動
	if (stickX > 0)
	{
		x += 10.0f;
	}
	else if(stickX < 0)
	{
		// スティックが左に倒れていたら左に移動
		x -= 10.0f;
	}

	// 画面外(左右)にはみ出さないようにリセット
	if (x < 0)
	{
		x = 0;
	}
	else if (x > 1240)
	{
		x = 1240;
	}

	// スティックが下に倒れていたら下に移動
	if (stickY > 0)
	{
		y += 10.0f;
	}
	else if (stickY < 0)
	{
		// スティックが上に倒れていたら上に移動
		y -= 10.0f;
	}

	// 画面外(上下)にはみ出さないようにリセット
	if (y < 0)
	{
		y = 0;
	}
	else if (y > 670)
	{
		y = 670;
	}

	// 弾を発射する位置を代入
	pX = (int)x + 40;
	pY = (int)y + 25;
}