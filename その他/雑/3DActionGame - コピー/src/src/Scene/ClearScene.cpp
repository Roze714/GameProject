#include <DxLib.h>
#include "ClearScene.h"
#include "Common.h"

static const char FILE_NAME[] = "data/clear.png";


//-------------------------------
//		初期化
//-------------------------------
void CClearScene::Init()
{
	m_hndl = -1;
}


//-------------------------------
//		データロード
//-------------------------------
void CClearScene::Load()
{
	if (m_hndl == -1)
		m_hndl = LoadGraph(FILE_NAME);
}


//-------------------------------
//		実行処理
//-------------------------------
int CClearScene::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_V))
		ret = SCENEID_TITLE;
	return ret;
}


//-------------------------------
//		描画
//-------------------------------
void CClearScene::Draw()
{
	DrawGraph(0, 0, m_hndl, TRUE);
}


//-------------------------------
//		終了処理
//-------------------------------
void CClearScene::Fin()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}