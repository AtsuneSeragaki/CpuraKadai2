#pragma once

class InputController
{
public:
	static int botton_flg;  // �{�^���t���O(�����ꂽ�u�ԗp)
	static int now_botton;  // �{�^���t���O(���݉�����Ă���{�^��)
	static int old_botton;  // �{�^���t���O(�ЂƂO�ɉ�����Ă����{�^��)
	static int Xbuf;        // �W���C�X�e�B�b�N��X���W
	static int Ybuf;        // �W���C�X�e�B�b�N��Y���W
	
	static void Update();  // �X�V����

	static int GetBotton(int botton);      // �{�^���������Ă����TRUE�Ԃ�����
	static int GetBottonDown(int botton);  // �{�^�������������ǂ�����Ԃ�����
};

