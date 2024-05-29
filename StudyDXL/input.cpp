#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�T�C�Y���w��
	const int WIDTH = 960, HEIGHT = 640;
	const int WHITE = GetColor(255, 255, 255);
	//�E�C���h�̐ݒ�
	SetWindowText("DX���C�u�����̎g����");
	SetGraphMode(WIDTH, HEIGHT, 32);
	//�E�C���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	//�G���[���N������I��
	if (DxLib_Init() == -1)return -1;
	SetBackgroundColor(0, 0, 0);
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	int timer = 0;

	while (1) {
		//��ʂ��N���A����
		ClearDrawScreen();
		timer++;
		//�^�C�}�[��\��
		DrawFormatString(0, 0, WHITE, "%d", timer);

		//�\���L�[�̎擾
		if (CheckHitKey(KEY_INPUT_UP)) DrawString(0, 20, "��", WHITE);
		if (CheckHitKey(KEY_INPUT_DOWN)) DrawString(0, 40, "��", WHITE);
		if (CheckHitKey(KEY_INPUT_LEFT)) DrawString(0, 60, "��", WHITE);
		if (CheckHitKey(KEY_INPUT_RIGHT)) DrawString(0, 80, "�E", WHITE);
		//�}�E�X�̍��W�ƃ{�^���̎擾
		int mouseX, mouseY;
		GetMousePoint(&mouseX, &mouseY);
		DrawFormatString(400, 0, WHITE, "(%d,%d)", mouseX, mouseY);
		if (GetMouseInput() & MOUSE_INPUT_LEFT)DrawString(400, 20, "���{�^��", WHITE);
		if (GetMouseInput() & MOUSE_INPUT_RIGHT)DrawString(400, 40, "�E�{�^��", WHITE);
		//����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
		WaitTimer(33);
		if (ProcessMessage() == -1)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
	}

	DxLib_End();
	return 0;
}