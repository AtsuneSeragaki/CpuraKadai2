#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�V���[�e�B���O�Q�[��"); // �^�C�g���� test �ɕύX

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) // DX���C�u��������������
	{

		return -1; // �G���[���N�����璼���ɏI��

	}

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	//// �ϐ���`
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

	DxLib_End(); // DX���C�u�����g�p�̏I������
	return 0; // �\�t�g�̏I��
}