#pragma once

class FPS 
{
	int mStartTime;		   //����J�n����
	int mNow;			   //����J�n����
	int mCount;			   //�J�E���^
	float mFps;			   //fps
	static const int N;	   //���ς����T���v����
	static const int Fps;  //�ݒ肵��FPS

public:
	FPS();   // �R���X�g���N�^
	~FPS();  // �f�X�g���N�^

	void Update();      // �X�V����
	void Draw() const;  // �`�揈��
	void Wait();        // FPS��������

};