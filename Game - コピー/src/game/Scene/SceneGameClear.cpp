#include"SceneGameClear.h"
#include"../Collision/CollisionManager.h"
#include"../../lib/Fade/Fade.h"


//定義関連-------------------------
#define GAMECLEAR_SIZE_X	(640.0f)	//画像サイズ(横)
#define GAMECLEAR_SIZE_Y	(480.0f)	//画像サイズ(縦)
//---------------------------------


//---------------------------------
//		コンストラクタ
//---------------------------------
SceneGameClear::SceneGameClear()
{
	m_SceneID = INIT;
}

//---------------------------------
//		デストラクタ
//---------------------------------
SceneGameClear::~SceneGameClear()
{
}

//---------------------------------
//		初期化
//---------------------------------
void SceneGameClear::Init(void)
{
	m_SceneID = INIT;
}

//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int SceneGameClear::Step()
{
	switch (m_SceneID)
	{
	case SceneGameClear::INIT:
		//初期化==========================
		m_Hndl = -1;
		//================================
		m_SceneID = LOAD;
		break;
	case SceneGameClear::LOAD:
		//画像ロード=====================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/Image/result/kuria.png");
		}
		//=====================
		m_SceneID = MAIN;
		break;
	case SceneGameClear::MAIN:
		//決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_SceneID = END;
		}
		break;
	case SceneGameClear::ENDWAIN:
		break;
	case SceneGameClear::END:
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


//---------------------------------
//		描画処理
//---------------------------------
void SceneGameClear::Draw()
{
	switch (m_SceneID)
	{
	case SceneGameClear::MAIN:
	case SceneGameClear::ENDWAIN:
		//リザルト画面描画
		DrawRotaGraph((int)(GAMECLEAR_SIZE_X * 1.0f), (int)(GAMECLEAR_SIZE_Y * 0.75f),
			1.35, 0.0, m_Hndl, TRUE);
		break;

	}
}




//---------------------------------
//		繰り返し行う処理
//---------------------------------
int SceneGameClear::Loop()
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
			m_Hndl = LoadGraph("data/Image/result/kuria.png");
		}
		//=====================
		m_SceneID = MAIN;
		break;
	case MAIN:
		Step();
		//決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_SceneID = END;
		}
		break;
		m_SceneID = END;
		//画像データ削除
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



