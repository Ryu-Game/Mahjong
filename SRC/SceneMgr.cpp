#include <DxLib.h>
#include "Game.h"
#include "SceneMgr.h"
/******************************
* 構造体
*******************************/
typedef enum {
	eScene_Title,
	eScene_Game,
	eScene_End,

	eScene_None,
}eScene;

//現シーンの管理変数（初期シーン設定）
eScene mScene = eScene_Game;
//次シーンの管理変数
eScene mNextScene = eScene_None;

static int BckImg;

/******************************
* 関数
*******************************/
static void SceneMgr_ChangeScene(eScene nextScene);

static void SceneMgr_InitializeModule(eScene scene);
static void SceneMgr_FinalizeModule(eScene scene);

//Scene：初期化処理
void SceneMgr_Initialize() {
	SceneMgr_InitializeModule(mScene);
}

//Scene：終了処理
void SceneMgr_Finalize() {
	SceneMgr_FinalizeModule(mScene);
}

//Scene：更新処理
void SceneMgr_Update() {
	if (mNextScene != eScene_None) {
		//現在のシーンの終了処理実行
		SceneMgr_FinalizeModule(mScene);
		//次のシーンを現在のシーンをセット
		mScene = mNextScene;
		//現在のシーンを初期化
		SceneMgr_InitializeModule(mScene);
	}
	switch (mScene) {
	case eScene_Game:
		Game_Update();
		break;
	}
}

//Scene：描画処理
void SceneMgr_Draw() {
	DrawGraph(0, 0, BckImg, false);
	switch (mScene) {
	case eScene_Game:
		Game_Draw();
		break;
	}
}

//引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene NextScene) {
	mNextScene = NextScene;
}

//引数 Scene モジュールを初期化する
static void SceneMgr_InitializeModule(eScene scene) {
	switch (scene) {
	case eScene_Game:
		BckImg = LoadGraph("./images/zyantaku.jpg");
		Game_Initialize();
		break;
	}
}

//引数 Scene モジュールの終了処理を行う
static void SceneMgr_FinalizeModule(eScene scene) {
	switch (scene) {
	case eScene_Game:
		//Game_Finalize();
		break;
	}
}