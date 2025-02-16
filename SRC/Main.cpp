#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

Scene_Mgr mgr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetMainWindowText("����");   //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);         //�E�B���h�E���[�h�ύX
	SetGraphMode(mgr.SCREEN_WIDTH, mgr.SCREEN_HEIGHT, 32);    //�E�B���h�E�T�C�Y�ݒ�
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);  //����ʐݒ�

	SceneMgr_Initialize();

	//���b�Z�[�W�����A��ʍ폜�A��ʍX�V
	while (ClearDrawScreen() == 0 && ProcessMessage() == 0) {
		InputKey();        //����
		SceneMgr_Update();

		SceneMgr_Draw();

		ScreenFlip();
	}

	SceneMgr_Finalize();

	DxLib_End(); // DX���C�u�����I������
	return 0;
}