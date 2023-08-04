#pragma once

class SphereCollider // 当たり判定用のクラス
{
private:
	float location;  // 中心座標
	float radius;

public:
	int CheckCollision();  // 引数でSphereColliderを受け取る
	                       // SphereCollider同士の当たり判定を行い当たったかどうかを渡す
};

