#pragma once
class Player {
private:

public:
/******************************
* �ϐ�
*******************************/
	//Player
	static int PlayerHai[4][14];	//�v�̐��l
	static int PlayerImg[4][14];	//�v�̉摜
	int Point[4];
	//static float x[4][14], y[4][14], w, h;
	float sx1, sx2, sy1, sy2;		//�J�[�\�������蔻��
	int GetHai;						//Player�R�v���珊�����i�[
	static int GetPlayer;			//���擾��

	/* ���W(��ʃT�C�Y�Őݒ�łł���悤�ɂ���) */
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

	/* �`��T�C�Y(��ʃT�C�Y�Őݒ�łł���悤�ɂ���) */
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