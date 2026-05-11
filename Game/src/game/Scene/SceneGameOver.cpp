#include "SceneGameOver.h"
#include "../Collision/CollisionManager.h"
#include "../../lib/Fade/Fade.h"
#include "../Common.h"


static const char FILE_NAME[] = "data/Image/result/GameOver.png"; 

//定義関連-------------------------
//---------------------------------


////---------------------------------
////		コンストラクタ
////---------------------------------
//CSceneGameover::CSceneGameover()
//{
//}
//
////---------------------------------
////		デストラクタ
////---------------------------------
//CSceneGameover::~CSceneGameover()
//{
//}

//---------------------------------
//		初期化
//---------------------------------
void CSceneGameover::Init()
{
	m_Hndl = -1;
}

//-------------------------------
//		データロード
//-------------------------------
void CSceneGameover::Load()
{
	if (m_Hndl == -1)
		m_Hndl = LoadGraph(FILE_NAME);
}



//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int CSceneGameover::Step()
{
	int ret = -1;
	if (CheckHitKey(KEY_INPUT_V))
		ret = SCENEID_TITLE;
	return ret;
}

//---------------------------------
//		描画処理
//---------------------------------
void CSceneGameover::Draw()
{
	DrawGraph(0, 0, m_Hndl, TRUE);
}


//-------------------------------
//		終了処理
//-------------------------------
void CSceneGameover::Exit()
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
//int CSceneGameover::Loop()
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
//	//		m_Hndl = LoadGraph("data/Image/result/gameo-ba.png");
//	//	}
//	//	//=====================
//	//	m_SceneID = MAIN;
//	//	break;
//	//case MAIN:
//	//	Step();
//	//	//決定ボタンを押したら次へ
//	//	if (CheckHitKey(KEY_INPUT_C) == true)
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



