#pragma once
#include "SphereCollider.h"

// 敵機の構造体
struct BULLET 
{
	int flg = 0; // 使用フラグ
	//int img = LoadGraph("images/cone.bmp"); // 画像
	int x = 0, y = 0; // 座標、幅、高さ
	int speed = 3; // 移動速度
};

class Bullet : public SphereCollider
{
private:
	int damage;           // ダメージ
	float speed;          // 速度
	float angle;          // 角度
	float acceleration;   // 速度の変化量
	float angulVelocity;  // 角度の変化量
	int bulletFlg;        // 弾のフラグ(0:何もしない 1:生成＆表示)
	const int bulletMax = 100;
	BULLET bullet;
	int okFlg;
	int bulletImg;

public:
	Bullet();   // コンストラクタ
	~Bullet();  // デストラクタ

	void Update();      // 更新処理
	void Draw() const;  // 描画処理
	
	void GetDamage();   // ダメージを受け取る処理
	void MoveBullet();  // 弾の移動処理
};

