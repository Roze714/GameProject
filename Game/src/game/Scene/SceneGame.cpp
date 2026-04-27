#include"SceneGame.h"
#include"../Collision/CollisionManager.h"



//定義関連-------------------------
#define PLAY_SIZE_X	(640.0f)	//画像サイズ(横)
#define PLAY_SIZE_Y	(480.0f)	//画像サイズ(縦)
//---------------------------------


//---------------------------------
//		コンストラクタ
//---------------------------------
SceneGame::SceneGame()
{
	m_SceneID = INIT;
}

//---------------------------------
//		デストラクタ
//---------------------------------
SceneGame::~SceneGame()
{
}

//---------------------------------
//		初期化
//---------------------------------
void SceneGame::Init(void)
{
	m_SceneID = INIT;
}

//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int SceneGame::Step()
{
	switch (m_SceneID)
	{
	case SceneGame::INIT:
		//初期化==========================
		m_Hndl = -1;
		//================================
		m_SceneID = LOAD;
		break;
	case SceneGame::LOAD:
		//画像ロード=====================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/Image/game.png");
		}
		//=====================
		m_SceneID = MAIN;
		break;
	case SceneGame::MAIN:
		//決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_X) == true)
		{
			m_SceneID = END;
		}
		break;
	case SceneGame::ENDWAIN:
		break;
	case SceneGame::END:
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
void SceneGame::Draw()
{
	switch (m_SceneID)
	{
	case SceneGame::MAIN:
	case SceneGame::ENDWAIN:
		//タイトル画面描画
		DrawRotaGraph((int)(PLAY_SIZE_X * 1.0f), (int)(PLAY_SIZE_Y * 0.75f),
			1.35, 0.0, m_Hndl, TRUE);
		break;

	}
}




//---------------------------------
//		繰り返し行う処理
//---------------------------------
int SceneGame::Loop()
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
			m_Hndl = LoadGraph("data/Image/game.png");
		}
		//=====================
		m_SceneID = MAIN;
		break;
	case MAIN:
		Step();
		//決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_X) == true)
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
