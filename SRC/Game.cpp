#include "DxLib.h"
//#include "Dealing.h"
#include "Game.h"
#include "Mounten.h"
//#include "Player.h"
#include "Input.h"
//#include "Delete.h"
#include "SceneMgr.h"

/******************************
* �\����
*******************************/
static class Player {
public: 
	static int Point[4];				/* �_�� */
	static int Hai[4][14];				/* ��v */
}mPlayer;


/******************************
* �֐��錾
*******************************/

/******************************
* ����������
*******************************/
void Game_Initialize() {
	//mGame.King = GetRand(4);
	mGame.King = 0;
	
	for (int i = 0; i < 4; i++) {
		mPlayer.Point[i] = 25000;
	}
	Mounten_Initialize();			//�v�摜�i�[����
	mGame.Gameflg = true;
}

/******************************
* �I������
*******************************/
//void Game_Finalize() {
//
//}

/******************************
* �X�V
*******************************/
void Game_Update() {
	Mounten_Update();
	if (mGame.Gameflg == false) {
		//mPlayer.Player_Initialize();

		mGame.Gameflg = true;
	}
	else if (mGame.Gameflg == true) {
		//mMounten.Mounten_Update();
		GetMousePoint(&iMouseX, &iMouseY);	//�}�E�X�J�[�\��
		//mPlayer.Player_Update();
		//mDelete.Delete_Update();
		//if (mPlayer.Get > 136) {	//�ŏ��̔ԍ�����E����悤�ɂ���
		//	mPlayer.Get = 0;
		//}
		//if (mPlayer.Del_count > 70) {	//�̂Ă鐔
		//	mGame.StartGame = true;
		//}
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		DxLib_End();
	}
}

/******************************
* �`��
*******************************/
void Game_Draw() {
	//�O���b�h��
	/*for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 18; j++) {
			if (i == 15 || i == 16 || j == 8 || j == 9) {
				DrawBox(i * 40, j * 40, i * 40 + 40, j * 40 + 40, 0xff0000, false);
			}
			else {
				DrawBox(i * 40, j * 40, i * 40 + 40, j * 40 + 40, 0xffffff, false);
			}
		}
	}*/
	//mMounten.Mounten_Draw();
	//mPlayer.Player_Draw();
	//mDelete.Delete_Draw();

	//DrawFormatString(0, 20, mGame.Cr, "%d", mPlayer.d_Get);
	//DrawFormatString(0, 40, mGame.Cr, "%d", mPlayer.Get_num);
	//DrawFormatString(0, 60, mGame.Cr, "%d", mPlayer.getnumber);

	////�E���
	//switch (mGame.King) {
	//case 0:
	//	DrawString(0, 0, "��", mGame.Cr);
	//	break;
	//case 1:
	//	DrawString(0, 0, "��", mGame.Cr);
	//	break;
	//case 2:
	//	DrawString(0, 0, "��", mGame.Cr);
	//	break;
	//case 3:
	//	DrawString(0, 0, "�k", mGame.Cr);
	//	break;
	//}
	///*DrawFormatString(0, 50, mGame.Cr, "%d", mMounten.All_house[1][4], false);
	//for (int i = 0; i < 10; i++) {
	//	DrawFormatString(100, 50 * i, mGame.Cr, "%d", mMounten.All_house[0][67+i], false);
	//}
	//DrawFormatString(0, 100, mGame.Cr, "%d", mMounten.All_house[1][(5 + 17) / 2], false);*/

	////�T�C�R��
	//switch (mMounten.Rand) {
	//default:
	//	DrawFormatString(50, 0, mGame.Cr, "%d", mMounten.Rand, false);
	//}
}
