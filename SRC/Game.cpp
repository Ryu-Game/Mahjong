#include "DxLib.h"
//#include "Dealing.h"
#include "Game.h"
//#include "Mounten.h"
//#include "Player.h"
#include "Input.h"
//#include "Delete.h"
#include "SceneMgr.h"

/******************************
* 構造体
*******************************/
static class Game{
private:
public:
	static char King;					/* 親 */
	bool Gameflg;						/* ゲーム */
}mGame;

static class Player {
public: 
	static int Point[4];				/* 点数 */
	static int Hai[4][14];				/* 手牌 */
}mPlayer;

static class Mounten {
public:
	/* 番号 */
	const char ManzNumber = 0;
	const char SouzNumber = 9;
	const char PinzNumber = 18;
	const char SufonNumber = 27;
	const char SangenNumber = 31;
	const char HaiNumber = 4;
	const int AllTileNumber = 136;
	/* 画像 */
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
* 関数宣言
*******************************/
static void Mounten_Initialize();
static void MountenDraw_Initialize();
static void Mounten_Update();
static void Mounten_Draw();

static void Mounten_Shuffle();

/******************************
* 初期化処理
*******************************/
void Game_Initialize() {
	mMounten.Reset = true;
	MountenDraw_Initialize();			//牌画像格納処理

	//mGame.King = GetRand(4);
	mGame.King = 0;
	
	for (int i = 0; i < 4; i++) {
		mPlayer.Point[i] = 25000;
	}
	
	mGame.Gameflg = true;
}

/******************************
* 終了処理
*******************************/
//void Game_Finalize() {
//
//}

/******************************
* 更新
*******************************/
void Game_Update() {
	if (mGame.Gameflg == false) {
		MountenDraw_Initialize();			//牌画像格納処理
		//mMounten.Mounten_Initialize();
		//mPlayer.Player_Initialize();

		mGame.Gameflg = true;
	}
	else if (mGame.Gameflg == true) {
		//mMounten.Mounten_Update();
		GetMousePoint(&iMouseX, &iMouseY);	//マウスカーソル
		//mPlayer.Player_Update();
		//mDelete.Delete_Update();
		//if (mPlayer.Get > 136) {	//最初の番号から拾えるようにする
		//	mPlayer.Get = 0;
		//}
		//if (mPlayer.Del_count > 70) {	//捨てる数
		//	mGame.StartGame = true;
		//}
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		DxLib_End();
	}
}

/******************************
* 描画
*******************************/
void Game_Draw() {
	//グリッド線
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

	////右回り
	//switch (mGame.King) {
	//case 0:
	//	DrawString(0, 0, "東", mGame.Cr);
	//	break;
	//case 1:
	//	DrawString(0, 0, "南", mGame.Cr);
	//	break;
	//case 2:
	//	DrawString(0, 0, "西", mGame.Cr);
	//	break;
	//case 3:
	//	DrawString(0, 0, "北", mGame.Cr);
	//	break;
	//}
	///*DrawFormatString(0, 50, mGame.Cr, "%d", mMounten.All_house[1][4], false);
	//for (int i = 0; i < 10; i++) {
	//	DrawFormatString(100, 50 * i, mGame.Cr, "%d", mMounten.All_house[0][67+i], false);
	//}
	//DrawFormatString(0, 100, mGame.Cr, "%d", mMounten.All_house[1][(5 + 17) / 2], false);*/

	////サイコロ
	//switch (mMounten.Rand) {
	//default:
	//	DrawFormatString(50, 0, mGame.Cr, "%d", mMounten.Rand, false);
	//}
}

/******************************
* 牌画像処理
*******************************/
void MountenDraw_Initialize() {
	if (mMounten.Reset == true) {
		/* 画像処理 */
		LoadDivGraph("./images/Mans.png", 9, 9, 1, 66, 95, mMounten.ManzImage);
		LoadDivGraph("./images/Souz.png", 9, 9, 1, 66, 95, mMounten.SouzImage);
		LoadDivGraph("./images/Pinz.png", 9, 9, 1, 66, 96, mMounten.PinzImage);
		LoadDivGraph("./images/ma-jan4_sufonpai.png", 4, 4, 1, 66, 96, mMounten.SufonImage);
		LoadDivGraph("./images/ma-jan5_sangenpai.png", 3, 3, 1, 66, 96, mMounten.SangenImage);
		LoadDivGraph("./images/ma-jan6_akahai.png", 3, 3, 1, 66, 96, mMounten.DoraImage);

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

	//山牌画像
	for (int i = 0; i < 136; i++) {
		mMounten.BackImage[i] = LoadGraph("./images/Mountain.png");
	}

	//ドラ画像初期化???
	/*for (int i = 0; i < 4; i++) {
		mDealing.DoraDraw[i] = -1;
	}*/
}


/******************************
* 山牌処理
*******************************/
void Mounten_Initialize() {
	//山牌をシャッフル処理
	Mounten_Shuffle();

	//山牌を上段・下段に分割 ( 2段 * 68列 ( 34種類 * 2 ) )
	for (int height = 0; height < 2; height++) {
		for (int width = 0; width < 68; width++) {

		}
	}
}



/******************************
* 山牌シャッフル
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