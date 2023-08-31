#include "InputController.h"
#include "DxLib.h"

int InputController::botton_flg = 0;
int InputController:: now_botton = 0;
int InputController::old_botton = 0;
int InputController:: Xbuf = 0;
int InputController:: Ybuf = 0;

// 更新処理
void InputController::Update()
{
	GetJoypadAnalogInput(&Xbuf, &Ybuf, DX_INPUT_PAD1);
	old_botton = now_botton;
	now_botton = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	botton_flg = now_botton & ~old_botton;
}

// ボタン入力()
int InputController::GetBotton(int botton)
{
	if (now_botton & botton)
	{
		return TRUE;
	}

	return FALSE;
}

// ボタン入力()
int InputController::GetBottonDown(int botton)
{
	if (botton_flg & botton)
	{
		return TRUE;
	}

	return FALSE;
}