#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("シューティングゲーム"); // タイトルを test に変更

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) // DXライブラリ初期化処理
	{

		return -1; // エラーが起きたら直ちに終了

	}

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	//// 変数定義
	//SceneManager sceneManager(dynamic_cast<AbstructScene*>(new TitleScene));

	while (ProcessMessage() != -1)
	{
		/*InputControl::Update();
		sceneManager.Update();
		sceneManager.Draw();
		if (sceneManager.Change() == nullptr)
		{
			break;
		}*/
	}

	DxLib_End(); // DXライブラリ使用の終了処理
	return 0; // ソフトの終了
}