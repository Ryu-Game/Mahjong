#include <DxLib.h>
#include "Game.h"
#include "SceneMgr.h"
/******************************
* �\����
*******************************/
typedef enum {
	eScene_Title,
	eScene_Game,
	eScene_End,

	eScene_None,
}eScene;

//���V�[���̊Ǘ��ϐ��i�����V�[���ݒ�j
eScene mScene = eScene_Game;
//���V�[���̊Ǘ��ϐ�
eScene mNextScene = eScene_None;

static int BckImg;

/******************************
* �֐�
*******************************/
static void SceneMgr_ChangeScene(eScene nextScene);

static void SceneMgr_InitializeModule(eScene scene);
static void SceneMgr_FinalizeModule(eScene scene);

//Scene�F����������
void SceneMgr_Initialize() {
	SceneMgr_InitializeModule(mScene);
}

//Scene�F�I������
void SceneMgr_Finalize() {
	SceneMgr_FinalizeModule(mScene);
}

//Scene�F�X�V����
void SceneMgr_Update() {
	if (mNextScene != eScene_None) {
		//���݂̃V�[���̏I���������s
		SceneMgr_FinalizeModule(mScene);
		//���̃V�[�������݂̃V�[�����Z�b�g
		mScene = mNextScene;
		//���݂̃V�[����������
		SceneMgr_InitializeModule(mScene);
	}
	switch (mScene) {
	case eScene_Game:
		Game_Update();
		break;
	}
}

//Scene�F�`�揈��
void SceneMgr_Draw() {
	DrawGraph(0, 0, BckImg, false);
	switch (mScene) {
	case eScene_Game:
		Game_Draw();
		break;
	}
}

//���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene) {
	mNextScene = NextScene;
}

//���� Scene ���W���[��������������
static void SceneMgr_InitializeModule(eScene scene) {
	switch (scene) {
	case eScene_Game:
		BckImg = LoadGraph("./images/zyantaku.jpg");
		Game_Initialize();
		break;
	}
}

//���� Scene ���W���[���̏I���������s��
static void SceneMgr_FinalizeModule(eScene scene) {
	switch (scene) {
	case eScene_Game:
		//Game_Finalize();
		break;
	}
}