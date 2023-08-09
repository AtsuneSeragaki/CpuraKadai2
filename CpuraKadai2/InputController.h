#pragma once

class InputController
{
public:
	static int botton_flg;
	static int now_botton;
	static int old_botton;

	static int Xbuf;
	static int Ybuf;

	static int X_flg;
	static int X_now;
	static int X_old;

	static int Y_flg;
	static int Y_now;
	static int Y_old;

	static void Update();

	//‰Ÿ‚µ‚Ä‚¢‚éŠÔM†‚ğ‘—‚é
	static int GetBotton(int botton);

	//‰Ÿ‚µ‚½uŠÔM†‚ğ‘—‚é
	static int GetBottonDown(int botton);

	static int GetJoyStickX(int x);
	static int GetJoyStickY(int y);

	static int GetJoyStickXOnes(int x);
	static int GetJoyStickYOnes(int y);
};

