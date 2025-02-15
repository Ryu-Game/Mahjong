#pragma once

class Scene_Mgr {
public:
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
};

void SceneMgr_Initialize();
void SceneMgr_Finalize();
void SceneMgr_Update();
void SceneMgr_Draw();

extern Scene_Mgr mgr;