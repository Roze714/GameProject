#include <DxLib.h>
#include "GameoverScene.h"
#include "Common.h"

static const char FILE_NAME[] = "data/gameover.png";


//-------------------------------
//		初期化
//-------------------------------
void CGameoverScene::Init()
{
	m_hndl = -1;
}


//-------------------------------
//		データロード
//-------------------------------
void CGameoverScene::Load()
{
	if (m_hndl == -1)
		m_hndl = LoadGraph(FILE_NAME);
}


//-------------------------------
//		実行処理
//-------------------------------
int CGameoverScene::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_V))
		ret = SCENEID_TITLE;
	return ret;
}


//-------------------------------
//		描画
//-------------------------------
void CGameoverScene::Draw()
{
	DrawGraph(0, 0, m_hndl, TRUE);
}


//-------------------------------
//		終了処理
//-------------------------------
void CGameoverScene::Fin()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}