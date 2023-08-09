#include "InputController.h"
#include "DxLib.h"

int InputController::botton_flg = 0;
int InputController::now_botton = 0;
int InputController::old_botton = 0;

int InputController::Xbuf = 0;
int InputController::Ybuf = 0;

int InputController::X_flg = 0;
int InputController::X_now = 0;
int InputController::X_old = 0;

int InputController::Y_flg = 0;
int InputController::Y_now = 0;
int InputController::Y_old = 0;

void InputController::Update()
{
	GetJoypadAnalogInput(&Xbuf, &Ybuf, DX_INPUT_PAD1);
	X_old = X_now;
	X_now = Xbuf;
	X_flg = X_now & ~X_old;

	Y_old = Y_now;
	Y_now = Ybuf;
	Y_flg = Y_now & ~Y_old;

	old_botton = now_botton;
	now_botton = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	botton_flg = now_botton & ~old_botton;
}

/********ボタン入力*********/
int InputController::GetBotton(int botton)
{
	if (now_botton & botton)
	{
		return TRUE;
	}

	return FALSE;
}

int InputController::GetBottonDown(int botton)
{
	if (botton_flg & botton)
	{
		return TRUE;
	}

	return FALSE;
}

/********ジョイスティックX軸*********/
int InputController::GetJoyStickX(int x)
{
	if (X_now & x)
	{
		return TRUE;
	}

	return FALSE;
}

int InputController::GetJoyStickXOnes(int x)
{
	if (X_flg & x) 
	{
		return TRUE;
	}

	return FALSE;
}

/********ジョイスティックY軸*********/
int InputController::GetJoyStickY(int y)
{
	if (Y_now & y) 
	{
		return TRUE;
	}

	return FALSE;
}

int InputController::GetJoyStickYOnes(int Y)
{
	if (Y_flg & Y) 
	{
		return TRUE;
	}

	return FALSE;
}