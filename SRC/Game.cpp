#include "DxLib.h"
//#include "Dealing.h"
#include "Game.h"
#include "Mounten.h"
//#include "Player.h"
#include "Input.h"
//#include "Delete.h"
#include "SceneMgr.h"

/******************************
* 構造体
*******************************/
static class Player {
public: 
	static int Point[4];				/* 点数 */
	static int Hai[4][14];				/* 手牌 */
}mPlayer;


/******************************
* 関数宣言
*******************************/

/******************************
* 初期化処理
*******************************/
void Game_Initialize() {
	//mGame.King = GetRand(4);
	mGame.King = 0;
	
	for (int i = 0; i < 4; i++) {
		mPlayer.Point[i] = 25000;
	}
	Mounten_Initialize();			//牌画像格納処理
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
	Mounten_Update();
	if (mGame.Gameflg == false) {
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
