#include <DxLib.h>
#include"TitleScene.h"
#include "Common.h"

static const char FILE_NAME[] = "data/title/title.jpg";



//---------------------
//コンストラクタ
//---------------------
CTitleScene::CTitleScene()
{
	Init();
}
//---------------------
//デストラクタ
//---------------------
CTitleScene:: ~CTitleScene()
{
	Exit();
}


//---------------------
//データの初期化
//---------------------
void CTitleScene::Init()
{
	m_Hndl = -1;
}


//-------------
//データのロード
//-------------
void CTitleScene::Load()
{

	if (m_Hndl == -1)
		m_Hndl = LoadGraph(FILE_NAME);
}


//---------------------
//更新
//---------------------
int  CTitleScene::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_Z))
		ret = SCENEID_GAME;
	return ret;
}


//---------------------------
//タイトル画面の描画管理
//---------------------------
void CTitleScene::Draw()
{
	DrawGraph(0, 0, m_Hndl, TRUE);;
}

//-------------
//終了処理
//-------------
void CTitleScene::Exit()
{
	//画像データ削除
	if (m_Hndl != -1)
	{
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}
}





