#include "DxLib.h"
#include "SceneManager.h"
#include "FPS.h"
#include "InputController.h"
#include "TitleScene.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�V���[�e�B���O�Q�[��"); // �^�C�g���� test �ɕύX

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetGraphMode(1280, 720, 32);  // ��ʃT�C�Y�ݒ�(��1280*�c720)

	if (DxLib_Init() == -1) // DX���C�u��������������
	{

		return -1; // �G���[���N�����璼���ɏI��

	}

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	// �ϐ���`
	SceneManager sceneManager(dynamic_cast<SceneBase*>(new TitleScene));
	FPS fps;

	while (ProcessMessage() != -1)
	{
		fps.Update();	//FPS�v��
		fps.Wait();		//FPS����
		InputController::Update();
		sceneManager.Update();
		sceneManager.Draw();

		#ifdef _DEBUG
		fps.Draw();		//FPS�`��

		#endif // DEBUG
		
		if (sceneManager.Change() == nullptr)
		{
			break;
		}
	}

	DxLib_End(); // DX���C�u�����g�p�̏I������
	return 0; // �\�t�g�̏I��
}