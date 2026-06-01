#include "SceneTitle.h"
#include"../Camera/CameraManager.h"
#include"../System/SoundManager.h"
#include"../../lib/Fade/Fade.h"
#include "../Common.h"

static const char FILE_NAME[] = "data/Image/title/title.png";

//定義関連-------------------------
//---------------------------------


////---------------------------------
////		コンストラクタ
////---------------------------------
//CSceneTitle::CSceneTitle()
//{
//}
//
////---------------------------------
////		デストラクタ
////---------------------------------
//CSceneTitle::~CSceneTitle()
//{
//}

//---------------------------------
//		初期化
//---------------------------------
void CSceneTitle::Init()
{
	m_Hndl = -1;
}

//-------------------------------
//		データロード
//-------------------------------
void CSceneTitle::Load()
{
	if (m_Hndl == -1)
		m_Hndl = LoadGraph(FILE_NAME);
}


//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int CSceneTitle::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_Z))
		ret = SCENEID_GAME;
	return ret;
}


//---------------------------------
//		描画処理
//---------------------------------
void CSceneTitle::Draw()
{
	DrawGraph(0, 0, m_Hndl, TRUE);
}

//-------------------------------
//		終了処理
//-------------------------------
void CSceneTitle::Exit()
{
	if (m_Hndl != -1)
	{
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}
}

////---------------------------------
////		繰り返し行う処理
////---------------------------------
//int CSceneTitle::Loop()
//{
//}
//
