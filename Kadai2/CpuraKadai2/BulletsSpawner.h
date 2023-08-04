#pragma once

class BulletsSpawner
{
private:
	int speed;           // 速度
	float angle;         // 角度
	float acceleration;  // 速度の変化量
	float angulVelocity; // 角度の変化量

public:
	void Shoot(); // 引数にゲームメインシーンのポインタを受け取る
	              // Spawnbulletで弾を生成する
};

