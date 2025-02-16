#pragma once

static class Game {
public:
	char King;
	bool Gameflg;
}mGame;
/******************************
* 構造体
*******************************/
//関数
void Game_Initialize();	//初期化
//void Game_Finalize();	//終了処理
void Game_Update();		//更新
void Game_Draw();		//描画