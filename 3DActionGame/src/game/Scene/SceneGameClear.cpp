#include <DxLib.h>
#include"SceneGameClear.h"
#include "../Common.h"

#include"../Collision/CollisionManager.h"


static const char FILE_NAME[] = "data/Image/result/GameClear.png";


//定義関連-------------------------
//---------------------------------


////---------------------------------
////		コンストラクタ
////---------------------------------
//CSceneGameClear::CSceneGameClear()
//{
//}
//
////---------------------------------
////		デストラクタ
////---------------------------------
//CSceneGameClear::~CSceneGameClear()
//{
//}

//---------------------------------
//		初期化
//---------------------------------
void CSceneGameClear::Init()
{
	m_Hndl = -1;
}


//-------------------------------
//		データロード
//-------------------------------
void CSceneGameClear::Load()
{
	if (m_Hndl == -1)
		m_Hndl = LoadGraph(FILE_NAME);
}



//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int CSceneGameClear::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_V))
		ret = SCENEID_TITLE;
	return ret;
}


//---------------------------------
//		描画処理
//---------------------------------
void CSceneGameClear::Draw()
{
	DrawGraph(0, 0, m_Hndl, TRUE);
}

//-------------------------------
//		終了処理
//-------------------------------
void CSceneGameClear::Exit()
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
//int CSceneGameClear::Loop()
//{
//	//int result = 0;
//	//switch (m_SceneID)
//	//{
//	//case INIT:
//	//	Init();
//	//	//初期化==========================
//	//	m_Hndl = -1;
//	//	//================================
//	//	m_SceneID = LOAD;
//	//	break;
//	//case LOAD:
//	//	//画像ロード=====================
//	//	if (m_Hndl == -1)
//	//	{
//	//		m_Hndl = LoadGraph("data/Image/result/kuria.png");
//	//	}
//	//	//=====================
//	//	m_SceneID = MAIN;
//	//	break;
//	//case MAIN:
//	//	Step();
//	//	//決定ボタンを押したら次へ
//	//	if (CheckHitKey(KEY_INPUT_Z) == true)
//	//	{
//	//		m_SceneID = END;
//	//	}
//	//	break;
//	//	m_SceneID = END;
//	//	//画像データ削除
//	//	if (m_Hndl != -1)
//	//	{
//	//		DeleteGraph(m_Hndl);
//	//		m_Hndl = -1;
//	//	}
//	//case END:
//	//	m_SceneID = INIT;
//	//	result = 1;
//	//	break;
//
//	//}
//	//return result;
//}



