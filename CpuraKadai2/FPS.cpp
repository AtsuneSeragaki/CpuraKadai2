#include "FPS.h"
#include <math.h>
#include "DxLib.h"

const int FPS::N = 60;
const int FPS::Fps = 60;

// �R���X�g���N�^
FPS::FPS()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
	mNow = 0;
}

// �f�X�g���N�^
FPS::~FPS()
{
}

// �X�V����(FPS�v������)
bool FPS::Update()
{
	if (mCount == 0) 
	{ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}

	if (mCount == N) 
	{ //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}

	mCount++;
	mNow = GetNowCount();

	return true;
}

// �`�揈��
void FPS::Draw() const
{
	DrawFormatString(0, 700, GetColor(255, 255, 255), "%.1f", mFps);
}

// FPS��������
void FPS::Wait()
{
	int tookTime = GetNowCount() - mStartTime;		//������������
	int waitTime = mCount * 1000 / Fps - tookTime;	//�҂ׂ�����

	if (waitTime > 0) 
	{
		Sleep(waitTime);	//�ҋ@
	}
}