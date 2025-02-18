#pragma once

static class Mounten {
public:
	bool Reset;
	bool PlayerStart;			//Player初期配布
	/* 描画座標(画面サイズで設定でできるようにする) */
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

void Mounten_Initialize();
void Mounten_Update();
void Mounten_Draw();
void Mounten_Finalize();