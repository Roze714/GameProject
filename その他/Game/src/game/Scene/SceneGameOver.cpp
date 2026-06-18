#include"SceneGameOver.h"
#include"../Collision/CollisionManager.h"
#include"../../lib/Fade/Fade.h"


//定義関連-----------------------------
#define GAMEOVER_SIZE_X	(640.0f)	//画像サイズ(横)
#define GAMEOVER_SIZE_Y	(480.0f)	//画像サイズ(縦)
//-------------------------------------


//-------------------------------------
//		コンストラクタ
//-------------------------------------
CSceneGameOver::CSceneGameOver()
{
	m_SceneID = INIT;
}

//-------------------------------------
//		デストラクタ
//-------------------------------------
CSceneGameOver::~CSceneGameOver()
{
}

//-------------------------------------
//		初期化
//-------------------------------------
void CSceneGameOver::Init(void)
{
	m_SceneID = INIT;
}

//-------------------------------------
//		毎フレーム呼ぶ処理
//-------------------------------------
int CSceneGameOver::Step()
{
	switch (m_SceneID)
	{
	case CSceneGameOver::INIT:
		//初期化==========================
		m_Hndl = -1;
		//================================
		m_SceneID = LOAD;
		break;
	case CSceneGameOver::LOAD:
		//画像ロード==========================================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/Image/gameo-ba.png");
		}
		//====================================================
		m_SceneID = MAIN;
		break;
	case CSceneGameOver::MAIN:
		// 決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_SceneID = END;
		}
		break;
	case CSceneGameOver::ENDWAIN:
		break;
	case CSceneGameOver::END:
		//画像データ削除
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


//-------------------------------------
//		描画処理
//-------------------------------------
void CSceneGameOver::Draw()
{
	switch (m_SceneID)
	{
	case CSceneGameOver::MAIN:
	case CSceneGameOver::ENDWAIN:
		//リザルト画面描画
		DrawRotaGraph((int)(GAMEOVER_SIZE_X * 1.0f), (int)(GAMEOVER_SIZE_Y * 0.75f),
			1.35, 0.0, m_Hndl, TRUE);
		break;

	}
}



//-------------------------------------
//		繰り返し行う処理
//-------------------------------------
int CSceneGameOver::Loop()
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
		//画像ロード=====================================================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/Image/gameo-ba.png");
		}
		//================================================================
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

