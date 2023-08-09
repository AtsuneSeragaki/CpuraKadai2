#pragma once
#include <math.h>
#include "DxLib.h"

class FPS {
	int mStartTime;				//����J�n����
	int mNow;					//����J�n����
	int mCount;					//�J�E���^
	float mFps;					//fps
	static const int N = 60;	//���ς����T���v����
	static const int Fps = 60;	//�ݒ肵��FPS

public:
	FPS() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
		mNow = 0;
	}

	bool Update() {
		if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		mNow = GetNowCount();
		return true;
	}

	void Draw() {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
	}

	void Wait() {
		int tookTime = GetNowCount() - mStartTime;		//������������
		int waitTime = mCount * 1000 / Fps - tookTime;	//�҂ׂ�����
		if (waitTime > 0) {
			Sleep(waitTime);	//�ҋ@
		}
	}
};