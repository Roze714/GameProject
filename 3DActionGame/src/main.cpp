#include <crtdbg.h>
#include <memory>
#include "DxLib.h"
#include<math.h>
#include"game/Scene/SceneManager.h"
#include"lib/Frame/Frame.h"


// プログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// メモリリーク発見用
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// スクリーン設定
	ChangeWindowMode(TRUE);			// フルスクリーンorウィンドウモード
	SetGraphMode(1280, 720, 32);	// ウィンドウのサイズ

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	//一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);
	//当たり判定の球をきれいに表示
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	//FPS関連の初期化
	FrameRate::Init();
	
	//シーン
	SceneManager  SceneManager;


	//カメラのニアーファー設定
	SetCameraNearFar(1.0f, 1000.0f);

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{

		Sleep(1);	//システムに処理を返す

		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		//フレームを進めていいか判断
		if (!FrameRate::CheckNext()) continue;


		ClearDrawScreen();	// 画面クリア

		//フレームレート計算
		FrameRate::Calc();


		//ここにゲームの本体を書く
		
		//FPSの表示
		FrameRate::PrintFps();

		SceneManager.Loop();

		
		
		
		SceneManager.Draw();
		
		XINPUT_STATE input;
		// 入力状態を取得
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		// 画面に XINPUT_STATE の中身を描画
		int Color = GetColor(0, 255, 255);
		DrawFormatString(0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
			input.LeftTrigger, input.RightTrigger);
		DrawFormatString(0, 16, Color, "ThumbLX:%d ThumbLY:%d",
			input.ThumbLX, input.ThumbLY);
		DrawFormatString(0, 32, Color, "ThumbRX:%d ThumbRY:%d",
			input.ThumbRX, input.ThumbRY);
		DrawString(0, 64, "Button", Color);
		for (int i = 0; i < 16; i++)
		{
			DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
				"%2d:%d", i, input.Buttons[i]);
		}


		//FPS表示
		FrameRate::PrintFps();
		
		ScreenFlip();		// 描画切り替え

	}
	

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

