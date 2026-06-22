#include "Input.h"
#include <DxLib.h>


//キー入力
typedef struct {
	XINPUT_STATE m_nowInput;
	XINPUT_STATE m_prevInput;
	unsigned int m_nowKey;		//現在のボタン情報
	unsigned int m_PrevKey;		//1フレーム前のボタン情報
}INPUT_DATA;

//キー入力用にグローバル変数を作成
static INPUT_DATA g_inputData;


//---------------------
//コンストラクタ
//---------------------
CInput::CInput()
{
	Init();
}

//---------------------
//デストラクタ
//---------------------
CInput::~CInput()
{
}

//----------------------
//キー入力の初期化
//----------------------

void CInput::Init()
{
	//プレイヤ1
	GetJoypadXInputState(DX_INPUT_PAD1, &g_inputData.m_nowInput);
	g_inputData.m_prevInput = g_inputData.m_nowInput;

}

//----------------------
//キー入力情報更新
//----------------------

void  CInput::Update()
{
	//プレイヤ1
	//前回の入力情報を最新に更新
	g_inputData.m_prevInput = g_inputData.m_nowInput;
	GetJoypadXInputState(DX_INPUT_PAD1, &g_inputData.m_nowInput);


}
//------------------------------
//キー入力判定(通常判定)
//------------------------------

//プレイヤー1
bool CInput::IsInputRep(unsigned int key)
{
	if (g_inputData.m_nowInput.Buttons[key] == 1) return true;
	else return false;

	if (g_inputData.m_nowKey & key) return true;
	else return false;
}

// ------------------------------
//キー入力判定(トリガー判定)
//-------------------------------

//プレイヤ1
bool CInput::IsInputTrg(unsigned int key)
{
	if ((g_inputData.m_nowInput.Buttons[key] == 1) &&
		(g_inputData.m_prevInput.Buttons[key] == 0))return true;
	else return false;
}

