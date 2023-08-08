#pragma once

class SphereCollider  // 当たり判定用のクラス
{
private:
	float location;  // 中心座標
	float radius;    // 半径

public:
	SphereCollider();    // コンストラクタ
	~SphereCollider();   // デストラクタ

	int CheckCollision(SphereCollider);  // 引数でSphereColliderを受け取る
	                                     // SphereCollider同士の当たり判定を行い当たったかどうかを返す
};

