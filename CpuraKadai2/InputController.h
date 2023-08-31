#pragma once

class InputController
{
public:
	static int botton_flg;  // ボタンフラグ(押された瞬間用)
	static int now_botton;  // ボタンフラグ(現在押されているボタン)
	static int old_botton;  // ボタンフラグ(ひとつ前に押されていたボタン)
	static int Xbuf;        // ジョイスティックのX座標
	static int Ybuf;        // ジョイスティックのY座標
	
	static void Update();  // 更新処理

	static int GetBotton(int botton);      // ボタンを押している間TRUE返す処理
	static int GetBottonDown(int botton);  // ボタンを押したかどうかを返す処理
};

