#include "DxLib.h"
#include "SceneManager.h"
#include "FPS.h"
#include "InputController.h"
#include "TitleScene.h"
#include "GameMainScene.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("シューティングゲーム"); // タイトルを変更

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetGraphMode(1280, 720, 32);  // 画面サイズ設定(横1280*縦720)

	if (DxLib_Init() == -1) // DXライブラリ初期化処理
	{

		return -1; // エラーが起きたら直ちに終了

	}

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	// 変数定義
	SceneManager sceneManager(dynamic_cast<SceneBase*>(new GameMainScene));
	FPS fps;

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();  // 画面の初期化

		fps.Update();	//FPS計測

		InputController::Update(); // コントローラー入力更新処理
		
		sceneManager.Update();
		sceneManager.Draw();

		fps.Wait();		//FPS同期

		#ifdef _DEBUG
		fps.Draw();		//FPS描画

		#endif // DEBUG
		
		ScreenFlip();  // 裏画面の内容を表画面に反映

		if (sceneManager.Change() == nullptr)
		{
			break;
		}
	}

	DxLib_End(); // DXライブラリ使用の終了処理
	return 0; // ソフトの終了
}