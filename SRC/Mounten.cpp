#include <DxLib.h>
#include "Mounten.h"
#include "Game.h"
#include "SceneMgr.h"
#include "Player.h"

#define PI    3.14159265358979323846264

static void Shuffle();
static void PlayerIni_Distribution();

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
	
	mMounten.PlayerStart = true;

	//ドラ画像初期化???
	/*for (int i = 0; i < 4; i++) {
		mDealing.DoraDraw[i] = -1;
	}*/
}

void Mounten_Update() {
	if (mGame.Gameflg == false) {	//初期化処理
		//山牌画像
		for (int i = 0; i < 136; i++) {
			mMounten.BackImage[i] = LoadGraph("./images/Mountain.png");
		}
		Shuffle();
	}
	else {
		if (mMounten.PlayerStart == true) {
			PlayerIni_Distribution();
		}
		else {
			
		}
	}
}

void Mounten_Draw() {
	for (int num = 0; num < 4; num++) {
		for (int width = 1; width >= 0; width--) {
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
	int ImgTiles;
	int NumTiles;
	for (int num = mMounten.AllTileNumber - 1; num >= 0; num--) {
		rand = GetRand(num);
		ImgTiles = mMounten.BackImage[num];
		NumTiles = num;
		mMounten.BackImage[num] = mMounten.BackImage[rand];
		mMounten.AllTile[num] = mMounten.AllTile[rand];
		mMounten.BackImage[rand] = ImgTiles;
		mMounten.AllTile[rand] = NumTiles;
	}
}


/******************************
* Player配布初期処理
*******************************/
static void PlayerIni_Distribution() {


	mMounten.PlayerStart = false;
}
