#include"Scenetitle.h"
#include"../Camera/CameraManager.h"
#include"../System/SoundManager.h"
#include"../../lib/Fade/Fade.h"

//定義関連-------------------------
#define TITLE_SIZE_X	(640.0f)	//画像サイズ(横)
#define TITLE_SIZE_Y	(480.0f)	//画像サイズ(縦)
//---------------------------------


//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CSceneTitle::CSceneTitle()
{
	m_SceneID = INIT;
}

//------------------------------------------------
//		デストラクタ
//------------------------------------------------
CSceneTitle::~CSceneTitle()
{
}

//------------------------------------------------
//		初期化
//------------------------------------------------
void CSceneTitle::Init(void)
{
	m_SceneID = INIT;
}

//------------------------------------------------
//		毎フレーム呼ぶ処理
//------------------------------------------------
int CSceneTitle::Step()
{
	switch (m_SceneID)
	{
	case CSceneTitle::INIT:
		//初期化===========================================
		m_Hndl = -1;
		//=================================================
		m_SceneID = LOAD;
		break;
	case CSceneTitle::LOAD:
		//画像ロード=======================================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/title/taitoru.png");
		}
		//=================================================
		m_SceneID = MAIN;
		break;
	case CSceneTitle::MAIN:
		// 決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_SceneID = END;
		}
		break;
	case CSceneTitle::ENDWAIN:
		break;
	case CSceneTitle::END:
		// 画像データ削除
		if (m_Hndl != -1)
		{
			DeleteGraph(m_Hndl);
			m_Hndl = -1;
		}
		m_SceneID = INIT;
		return 1;
	}
	return 0;
}


//------------------------------------------------
//		描画処理
//------------------------------------------------
void CSceneTitle::Draw()
{
	switch (m_SceneID)
	{
	case CSceneTitle::MAIN:
	case CSceneTitle::ENDWAIN:
		// タイトル画面描画
		DrawRotaGraph((int)(TITLE_SIZE_X * 1.0f), (int)(TITLE_SIZE_Y * 0.75f),
			1.35, 0.0, m_Hndl, TRUE);
		break;

	}
}




//------------------------------------------------
//		繰り返し行う処理
//------------------------------------------------
int CSceneTitle::Loop()
{
	int result = 0;
	switch (m_SceneID)
	{
	case INIT:
		Init();
		//初期化==========================
		m_Hndl = -1;
		//================================
		m_SceneID = LOAD;
		break;
	case LOAD:
		//画像ロード=====================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/Image/taitoru.png");
		}
		//=====================
		m_SceneID = MAIN;
		break;
	case MAIN:
		Step();
		// 決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_SceneID = END;
		}
		break;
		m_SceneID = END;
		// 画像データ削除
		if (m_Hndl != -1)
		{
			DeleteGraph(m_Hndl);
			m_Hndl = -1;
		}
	case END:
		m_SceneID = INIT;
		result = 1;
		break;

	}
	return result;
}

//-------------------------------------
//		終了処理
//-------------------------------------
void CSceneTitle::Exit()
{
	//画像データ削除
	if (m_Hndl != -1)
	{
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}
}

