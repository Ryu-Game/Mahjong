#pragma once

class Game {
public:
	static char King;
	bool Gameflg;
	bool Reset;
}mGame;
/******************************
* �\����
*******************************/
//�֐�
void Game_Initialize();	//������
//void Game_Finalize();	//�I������
void Game_Update();		//�X�V
void Game_Draw();		//�`��