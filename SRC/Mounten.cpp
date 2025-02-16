#include "DxLib.h"
#include "Mounten.h"
#include "Game.h"
#include "SceneMgr.h"

#define PI    3.14159265358979323846264

static class Mounten {
public:
	bool Reset;
	/* 描画座標(設定でできるようにする) */
	char UpDraw;
	const int Size = 24;
	const char IniWidth = 870;
	const char IniHeight = 130;
	const int Width[4]{
		834,
		410,/* mgr.SCREEN_WIDTH - mMounten.IniWidth, */
		450,
		870//mMounten.IniWidth
	};
	const int Height[4]{
		590,/*mgr.SCREEN_HEIGHT - mMounten.IniHeight,*/
		554,
		130,//mMounten.IniHeight,
		168
	};

	int Image;

	/* 番号 */
	const char ManzNumber = 0;
	const char SouzNumber = 9;
	const char PinzNumber = 18;
	const char SufonNumber = 27;
	const char SangenNumber = 31;
	const char HaiNumber = 4;
	const int AllTileNumber = 136;
	/* 画像 */
	int ManzImage[9];
	int SouzImage[9];
	int PinzImage[9];
	int SufonImage[4];
	int SangenImage[3];
	int DoraImage[3];
	int BackImage[136];
	int AllTile[136];

	/* 画像サイズ */
	const float DrawSize = 0.35f;
}mMounten;


static void Shuffle();

void Mounten_Initialize() {
	if (mMounten.Reset == true) {
		/* 画像処理 */
		LoadDivGraph("./images/Mans.png", 9, 9, 1, 66, 95,mMounten.ManzImage);
		LoadDivGraph("./images/Souz.png", 9, 9, 1, 66, 95,mMounten.SouzImage);
		LoadDivGraph("./images/Pinz.png", 9, 9, 1, 66, 96,mMounten.PinzImage);
		LoadDivGraph("./images/ma-jan4_sufonpai.png", 4, 4, 1, 66,	96,mMounten.SufonImage);
		LoadDivGraph("./images/ma-jan5_sangenpai.png", 3, 3, 1, 66,		96,mMounten.SangenImage);
		LoadDivGraph("./images/ma-jan6_akahai.png", 3, 3, 1, 66,	96,mMounten.DoraImage);
	
		/* 牌数値初期化処理 */
		int num = 0;
		for (int i = 0; i < 34; i++) {
			for (int j = 0; j < 4; j++) {
				num = i * 4 + i;
				mMounten.AllTile[num] = i;
			}
		}
		mMounten.Reset = false;
	}
	
	
	//ドラ画像初期化???
	/*for (int i = 0; i < 4; i++) {
		mDealing.DoraDraw[i] = -1;
	}*/
}

void Mounten_Update() {
	if (mGame.Gameflg == false) {
		//山牌画像
		for (int i = 0; i < 136; i++) {
			mMounten.BackImage[i] = LoadGraph("./images/Mountain.png");
		}
		//Shuffle();
	}
	else {
		
	}
}

void Mounten_Draw() {
	for (int num = 0; num < 4; num++) {
		for (int width = 0; width < 2; width++) {
			if (width == 0) mMounten.UpDraw = 0;
			else mMounten.UpDraw = 10;
			
			for (int tile = 0; tile < 17; tile++) {
				mMounten.Image = tile * 2 + width + num * 34;

				switch (num) {
				case 0:
					DrawRotaGraph(mMounten.Width[num] - (mMounten.Size * tile), mMounten.Height[num] - mMounten.UpDraw, mMounten.DrawSize, PI * 2, mMounten.BackImage[mMounten.Image], false);
					break;
					
				case 1:
					DrawRotaGraph(mMounten.Width[num] + mMounten.UpDraw, mMounten.Height[num] - (mMounten.Size * tile), mMounten.DrawSize, PI / 2, mMounten.BackImage[mMounten.Image], false);
					break;

				case 2:
					DrawRotaGraph(mMounten.Width[num] + (mMounten.Size * tile), mMounten.Height[num] + mMounten.UpDraw, mMounten.DrawSize, -PI, mMounten.BackImage[mMounten.Image], false);
					break;

				case 3:
					DrawRotaGraph(mMounten.Width[num] - mMounten.UpDraw, mMounten.Size * tile + mMounten.Height[num], mMounten.DrawSize, -(PI / 2), mMounten.BackImage[mMounten.Image], false);
					break;
				}
			}
		}
	}
}

void Mounten_Finalize() {
	mMounten.Reset = true;
}

/******************************
* 山牌シャッフル
*******************************/
void Shuffle() {
	int rand;
	int Tiles;
	for (int num = mMounten.AllTileNumber; num > 0; num--) {
		rand = GetRand(num);
		Tiles = mMounten.BackImage[num];
		mMounten.BackImage[num] = mMounten.BackImage[rand];
		mMounten.BackImage[rand] = Tiles;
	}
}


/******************************
* 山牌処理
*******************************/
