#pragma once
class Player {
private:

public:
/******************************
* 変数
*******************************/
	//Player
	static int PlayerHai[4][14];	//牌の数値
	static int PlayerImg[4][14];	//牌の画像
	int Point[4];
	//static float x[4][14], y[4][14], w, h;
	float sx1, sx2, sy1, sy2;		//カーソル当たり判定
	int GetHai;						//Player山牌から所得数格納
	static int GetPlayer;			//現取得者

	/* 座標(画面サイズで設定でできるようにする) */
	const float Width[4]{
		240.0f,
		80.0f,						//mgr.SCREEN_WIDTH - 1200
		400.0f,
		1200.0f
	};
	const float Height[4]{
		675.0f,						//mgr.SCREEN_HEIGHT - 45
		80.0f,
		45.0f,
		80.0f
	};

	const float Move = 10.0f;
	const float MogeGet = -1.0f;

	/* 描画サイズ(画面サイズで設定でできるようにする) */
	const float Size[2]{
		0.9f,
		0.6f
	};
	const float SizeWidth[2]{
		59.4f,
		40.0f
	};
	const float SizeHeight[2]{
		85.5f,
		40.0f
	};

}mPlayer;