#include "DxLib.h"
//#include "Dealing.h"
#include "Game.h"
//#include "Mounten.h"
//#include "Player.h"
#include "Input.h"
//#include "Delete.h"
#include "SceneMgr.h"

/******************************
* �\����
*******************************/
static class Game{
private:
public:
	static char King;					/* �e */
	bool Gameflg;						/* �Q�[�� */
}mGame;

static class Player {
public: 
	static int Point[4];				/* �_�� */
	static int Hai[4][14];				/* ��v */
}mPlayer;

static class Mounten {
public:
	/* �ԍ� */
	const char ManzNumber = 0;
	const char SouzNumber = 9;
	const char PinzNumber = 18;
	const char SufonNumber = 27;
	const char SangenNumber = 31;
	const char HaiNumber = 4;
	const int AllTileNumber = 136;
	/* �摜 */
	static int ManzImage[9];
	static int SouzImage[9];
	static int PinzImage[9];
	static int SufonImage[4];
	static int SangenImage[3];
	static int DoraImage[3];
	static int BackImage[136];
	static int AllTile[136];

	static bool Reset;
}mMounten;

/******************************
* �֐��錾
*******************************/
static void Mounten_Initialize();
static void MountenDraw_Initialize();
static void Mounten_Update();
static void Mounten_Draw();

static void Mounten_Shuffle();

/******************************
* ����������
*******************************/
void Game_Initialize() {
	mMounten.Reset = true;
	MountenDraw_Initialize();			//�v�摜�i�[����

	//mGame.King = GetRand(4);
	mGame.King = 0;
	
	for (int i = 0; i < 4; i++) {
		mPlayer.Point[i] = 25000;
	}
	
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
	if (mGame.Gameflg == false) {
		MountenDraw_Initialize();			//�v�摜�i�[����
		//mMounten.Mounten_Initialize();
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

/******************************
* �v�摜����
*******************************/
void MountenDraw_Initialize() {
	if (mMounten.Reset == true) {
		/* �摜���� */
		LoadDivGraph("./images/Mans.png", 9, 9, 1, 66, 95, mMounten.ManzImage);
		LoadDivGraph("./images/Souz.png", 9, 9, 1, 66, 95, mMounten.SouzImage);
		LoadDivGraph("./images/Pinz.png", 9, 9, 1, 66, 96, mMounten.PinzImage);
		LoadDivGraph("./images/ma-jan4_sufonpai.png", 4, 4, 1, 66, 96, mMounten.SufonImage);
		LoadDivGraph("./images/ma-jan5_sangenpai.png", 3, 3, 1, 66, 96, mMounten.SangenImage);
		LoadDivGraph("./images/ma-jan6_akahai.png", 3, 3, 1, 66, 96, mMounten.DoraImage);

		/* �v���l���������� */
		int num = 0;
		for (int i = 0; i < 34; i++) {
			for (int j = 0; j < 4; j++) {
				num = i * 4 + i;
				mMounten.AllTile[num] = i;
			}
		}

		mMounten.Reset = false;

	}

	//�R�v�摜
	for (int i = 0; i < 136; i++) {
		mMounten.BackImage[i] = LoadGraph("./images/Mountain.png");
	}

	//�h���摜������???
	/*for (int i = 0; i < 4; i++) {
		mDealing.DoraDraw[i] = -1;
	}*/
}


/******************************
* �R�v����
*******************************/
void Mounten_Initialize() {
	//�R�v���V���b�t������
	Mounten_Shuffle();

	//�R�v����i�E���i�ɕ��� ( 2�i * 68�� ( 34��� * 2 ) )
	for (int height = 0; height < 2; height++) {
		for (int width = 0; width < 68; width++) {

		}
	}
}



/******************************
* �R�v�V���b�t��
*******************************/
void Mounten_Shuffle() {
	int tile;
	int Tiles[136];
	for (int num = mMounten.AllTileNumber; num > 0; num--) {
		tile = GetRand(num - 1);
		Tiles[num] = mMounten.BackImage[num];
		mMounten.BackImage[num] = mMounten.BackImage[tile];
		mMounten.BackImage[tile] = Tiles[num];
	}
}