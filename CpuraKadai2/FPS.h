#pragma once

class FPS 
{
	int mStartTime;		   //測定開始時刻
	int mNow;			   //測定開始時刻
	int mCount;			   //カウンタ
	float mFps;			   //fps
	static const int N;	   //平均を取るサンプル数
	static const int Fps;  //設定したFPS

public:
	FPS();   // コンストラクタ
	~FPS();  // デストラクタ

	void Update();      // 更新処理
	void Draw() const;  // 描画処理
	void Wait();        // FPS同期処理

};