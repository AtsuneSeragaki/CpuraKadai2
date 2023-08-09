#include "FPS.h"
#include <math.h>
#include "DxLib.h"

const int FPS::N = 60;
const int FPS::Fps = 60;

// コンストラクタ
FPS::FPS()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
	mNow = 0;
}

// デストラクタ
FPS::~FPS()
{
}

// 更新処理(FPS計測処理)
bool FPS::Update()
{
	if (mCount == 0) 
	{ //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}

	if (mCount == N) 
	{ //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}

	mCount++;
	mNow = GetNowCount();

	return true;
}

// 描画処理
void FPS::Draw() const
{
	DrawFormatString(0, 700, GetColor(255, 255, 255), "%.1f", mFps);
}

// FPS同期処理
void FPS::Wait()
{
	int tookTime = GetNowCount() - mStartTime;		//かかった時間
	int waitTime = mCount * 1000 / Fps - tookTime;	//待つべき時間

	if (waitTime > 0) 
	{
		Sleep(waitTime);	//待機
	}
}