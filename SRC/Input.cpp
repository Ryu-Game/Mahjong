#include "DxLib.h"
//#include "Game.h"
#include "Input.h"
int iOldKey;	//�O��̓��̓L�[
int iNowKey;	//����̓��̓L�[
int iKeyFlg;	//���̓L�[���

int iMouseX;
int iMouseY;

void InputKey(void) {
	//���̓L�[�擾
	iOldKey = iNowKey;
	iNowKey = GetMouseInput();
	iKeyFlg = iNowKey & ~iOldKey;
}