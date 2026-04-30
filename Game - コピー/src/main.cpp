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
		

		//FPS表示
		FrameRate::PrintFps();
		
		ScreenFlip();		// 描画切り替え

	}
	

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

