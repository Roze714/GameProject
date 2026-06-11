#pragma once
#include"DxLib.h"

//ボタン設定------------------------------------------------------------
#define XINPUT_BUTTON_DPAD_UP		(0)			// デジタル方向ボタン上
#define XINPUT_BUTTON_DPAD_DOWN		(1)			// デジタル方向ボタン下
#define XINPUT_BUTTON_DPAD_LEFT		(2)			// デジタル方向ボタン左
#define XINPUT_BUTTON_DPAD_RIGHT	(3)			// デジタル方向ボタン右
#define XINPUT_BUTTON_DPAD_A		(12)		// デジタルAボタン	
#define XINPUT_BUTTON_DPAD_B		(13)		// デジタルBボタン
#define XINPUT_BUTTON_DPAD_X		(14)		// デジタルXボタン
#define XINPUT_BUTTON_DPAD_Y		(15)		// デジタルYボタン
#define XINPUT_BUTTON_DPAD_LB		(8)			// デジタルLBボタン
#define XINPUT_BUTTON_DPAD_RB		(9)			// デジタルRBボタン
//----------------------------------------------------------------------

class Input
{
public:
	//コンストラクタ・デストラクタ
	Input();
	~Input();




private:

	//キー入力初期化
	void Init();
	//キー入力情報更新
	void Update();
	//キー入力判定(通常判定) プレイヤー1
	bool IsInputRep(unsigned int key);
	//キー入力判定(トリガー判定) プレイヤー1
	bool IsInputTrg(unsigned int key);

};



