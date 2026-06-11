#include <DxLib.h>			// DxLibを使用するために必須
#include"lib/Frame/frame.h"
#include"lib/Input/input.h"
#include"game/BackGround/background.h"
#include"game/Player/player.h"
#include"game/Collision/hitcheck.h"
#include"game/Effect/effect.h"
#include"game/Scene/scene.h"
#include"game/System/soundmanager.h"

// ゲームプログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);			// ウィンドウモードにするかどうか
	SetGraphMode(640, 480, 32);		// ウィンドウの解像度を設定する

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag( false );
#endif

	// ＤＸライブラリ初期化処理　基本的にはこれより後でDxLib関数を使う
	if (DxLib_Init() == -1) return -1;

	// 一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);	// 画面のちらつきを無くす
	SetTransColor(255, 0, 255);		// 透過色指定　今回は真紫色を透明

	
	
	//初期化はここで行う
	InitFps();			//FPS関連
	InitInput();		//キー入力情報
	InitScene();
	InitSound();		//サウンド処理
	LoadSound();		//ゲームで使うすべてのサウンドをロード

	//InitScene();
	
	//InitFade();			//フェード処理
	
	
	
	//画像ロード関連============
	//============================
	

	//ゲームメインループ
	while (ProcessMessage() != -1)	// 問題が発生したら終了
	{
		WaitTimer(1);

		// 「escキー」が押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		//フレームを進めていいか判断
		if (IsNextFrame() == false) continue;

		// 画面を一度何もない状態へ
		ClearDrawScreen();


		// ゲーム本体の命令はこれより下に書く
		
		//更新関連======================
		UpdateInput();	//キー入力情報の更新
		StepScene();
		StepFps();			//フレームレート情報
		//==============================
		
		

		//描画関数===========================================
		
		DrawBG();			//画像の描画管理
		DrawScene();
		PrintFps();			//FPSの表示
		//===============================================
		
		// ゲーム本体の命令はこれより上に書く
		
		
		// 作成した画面をモニターへ転送
		ScreenFlip();

	}

	// 終了前処理==================
	ExitSound();			//音楽の破棄

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	//=============================

	return 0;				// プログラムの終了 
}
