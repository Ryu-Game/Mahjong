#include "DxLib.h"
#include "Mounten.h"
#include "Game.h"

static class Mounten {
public:
	bool Reset;
	static char UpDraw;

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
}mMounten;


static void Shuffle();

void Mounten_Initialize() {	
	if (mMounten.Reset == true) {
		/* �摜���� */
		LoadDivGraph("./images/Mans.png", 9, 9, 1, 66, 95,mMounten.ManzImage);
		LoadDivGraph("./images/Souz.png", 9, 9, 1, 66, 95,mMounten.SouzImage);
		LoadDivGraph("./images/Pinz.png", 9, 9, 1, 66, 96,mMounten.PinzImage);
		LoadDivGraph("./images/ma-jan4_sufonpai.png", 4, 4, 1, 66,	96,mMounten.SufonImage);
		LoadDivGraph("./images/ma-jan5_sangenpai.png", 3, 3, 1, 66,		96,mMounten.SangenImage);
		LoadDivGraph("./images/ma-jan6_akahai.png", 3, 3, 1, 66,	96,mMounten.DoraImage);
	
		/* �v���l���������� */
		int num = 0;
		for (int i = 0; i < 34; i++) {
			for (int j = 0; j < 4; j++) {
				num = i * 4 + i;
				mMounten.AllTile[num] = i;
			}
		}
		mMounten.UpDraw = 0;
		mMounten.Reset = false;
	}
	
	
	//�h���摜������???
	/*for (int i = 0; i < 4; i++) {
		mDealing.DoraDraw[i] = -1;
	}*/
}

void Mounten_Update() {
	if (mGame.Gameflg == false) {
		mMounten.UpDraw = 0;
		//�R�v�摜
		for (int i = 0; i < 136; i++) {
			mMounten.BackImage[i] = LoadGraph("./images/Mountain.png");
		}
		Shuffle();
	}
	else {
		
	}
}

void Mounten_Draw() {
	if (mGame.Gameflg == true) {
		
	}
}

void Mounten_Finalize() {
	mMounten.Reset = true;
}

/******************************
* �R�v�V���b�t��
*******************************/
void Shuffle() {
	int tile;
	int Tiles[136];
	for (int num = mMounten.AllTileNumber; num > 0; num--) {
		tile = GetRand(num - 1);
		Tiles[num] = mMounten.BackImage[num];
		mMounten.BackImage[num] = mMounten.BackImage[tile];
		mMounten.BackImage[tile] = Tiles[num];
	}
}


/******************************
* �R�v����
*******************************/
void Mounten_Initialize() {

	
}
