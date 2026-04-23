#include <DxLib.h>
#include "SceneGame.h"
#include "../Common.h"

static const char FILE_NAME[] = "data/game.png";


//-------------------------------
//		初期化
//-------------------------------
void CSceneGame::Init()
{
	m_hndl = -1;
}


//-------------------------------
//		データロード
//-------------------------------
void CSceneGame::Load()
{
	if (m_hndl == -1)
		m_hndl = LoadGraph(FILE_NAME);
}


//-------------------------------
//		実行処理
//-------------------------------
int CSceneGame::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_X))
		ret = SCENEID_CLEAR;
	if (CheckHitKey(KEY_INPUT_C))
		ret = SCENEID_GAMEOVER;
	return ret;
}


//-------------------------------
//		描画
//-------------------------------
void CSceneGame::Draw()
{
	DrawGraph(0, 0, m_hndl, TRUE);
}


//-------------------------------
//		終了処理
//-------------------------------
void CSceneGame::Fin()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}