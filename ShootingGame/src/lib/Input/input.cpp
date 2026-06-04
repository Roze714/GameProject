#include "input.h"
#include <DxLib.h>

//キー入力
typedef struct {
	unsigned int m_nowKey;		//現在のボタン情報
	unsigned int m_PrevKey;		//1フレーム前のボタン情報
}INPUT_DATA;

//キー入力用にグローバル変数を作成
static INPUT_DATA g_inputData;

//----------------------
//キー入力の初期化
//----------------------

void InitInput()
{
	g_inputData.m_PrevKey = g_inputData.m_PrevKey=0;
}

//----------------------
//キー入力情報更新
//----------------------

void  UpdateInput()
{
	//前回の入力情報を最新に更新
	g_inputData.m_PrevKey = g_inputData.m_nowKey;
	//今回の入力情報を一旦0にする
	g_inputData.m_nowKey = 0;

	//上を押した
	if (CheckHitKey(KEY_INPUT_UP))g_inputData.m_nowKey |= KEY_UP;
	//下を押した
	if (CheckHitKey(KEY_INPUT_DOWN))g_inputData.m_nowKey |= KEY_DOWN;
	//右を押した
	if (CheckHitKey(KEY_INPUT_RIGHT))g_inputData.m_nowKey |= KEY_RIGHT;
	//左を押した
	if (CheckHitKey(KEY_INPUT_LEFT))g_inputData.m_nowKey |= KEY_LEFT;
	//ショット発射を押した
	if (CheckHitKey(KEY_INPUT_Z))g_inputData.m_nowKey |= KEY_SHOT;
}
//------------------------------
//キー入力判定(通常判定)
//------------------------------
bool IsInputRep(unsigned int key)
{
	if (g_inputData.m_nowKey & key) return true;
	else return false;
}

// ------------------------------
//キー入力判定(トリガー判定)
//-------------------------------
bool IsInputTrg(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) &&
		!(g_inputData.m_PrevKey & key))return true;
	else return false;
}