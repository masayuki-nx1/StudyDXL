#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドサイズを指定
	const int WIDTH = 960, HEIGHT = 640;
	const int WHITE = GetColor(255, 255, 255);
	//ウインドの設定
	SetWindowText("DXライブラリの使い方");
	SetGraphMode(WIDTH, HEIGHT, 32);
	//ウインドウモードに変更
	ChangeWindowMode(TRUE);
	//エラーが起きたら終了
	if (DxLib_Init() == -1)return -1;
	SetBackgroundColor(0, 0, 0);
	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	int timer = 0;

	//画像の読み込み
	int imgBG = LoadGraph("images/background.jpg");
	int imgCat = LoadGraph("images/Player_cat.png");

	int sizeImgCatWidth = 300, sezeImgCatHeight = 300;
	int catX = 0, catY = 400;


	while (1) {
		//画面をクリアする
		ClearDrawScreen();
		//背景の表示
		DrawGraph(0, 0, imgBG, FALSE);


		timer++;
		//タイマーを表示
		DrawFormatString(0, 0, WHITE, "%d", timer);

		//十字キーの取得
		if (CheckHitKey(KEY_INPUT_UP)) DrawString(0, 20, "上", WHITE);
		if (CheckHitKey(KEY_INPUT_DOWN)) DrawString(0, 40, "下", WHITE);
		if (CheckHitKey(KEY_INPUT_LEFT)) DrawString(0, 60, "左", WHITE);
		if (CheckHitKey(KEY_INPUT_RIGHT)) DrawString(0, 80, "右", WHITE);
		//マウスの座標とボタンの取得
		int mouseX, mouseY;
		GetMousePoint(&mouseX, &mouseY);
		DrawFormatString(400, 0, WHITE, "(%d,%d)", mouseX, mouseY);
		if (GetMouseInput() & MOUSE_INPUT_LEFT)DrawString(400, 20, "左ボタン", WHITE);
		if (GetMouseInput() & MOUSE_INPUT_RIGHT)DrawString(400, 40, "右ボタン", WHITE);

		catX = mouseX - sizeImgCatWidth / 2;
		catY = mouseY - sezeImgCatHeight / 2;

		//catの表示
		DrawGraph(catX, catY, imgCat, TRUE);

		//裏画面の内容を表画面に反映する
		ScreenFlip();
		WaitTimer(33);
		if (ProcessMessage() == -1)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
	}

	DxLib_End();
	return 0;
}