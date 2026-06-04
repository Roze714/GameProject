#include"Scenetitle.h"
/*#include"../Camera/CameraManager.h"*/
#include"../System/SoundManager.h"
#include"../../lib/Fade/Fade.h"

//定義関連-------------------------
#define TITLE_SIZE_X	(640.0f)	//画像サイズ(横)
#define TITLE_SIZE_Y	(480.0f)	//画像サイズ(縦)
static const char TITLE_IMAGE_PATH[] =
{ "data/Image/taitoru.png" };
//---------------------------------


//---------------------------------
//		コンストラクタ
//---------------------------------
SceneTitle::SceneTitle()
{
	m_Scene = INIT;
}

//---------------------------------
//		デストラクタ
//---------------------------------
SceneTitle::~SceneTitle()
{
}

//---------------------------------
//		初期化
//---------------------------------
void SceneTitle::Init(void)
{
	m_Scene = INIT;
}

//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int SceneTitle::Step()
{
	switch (m_Scene)
	{
	case SceneTitle::INIT:
		//初期化==========================
		m_Hndl = -1;
		//================================
		m_Scene = LOAD;
		break;
	case SceneTitle::LOAD:
		//画像ロード=====================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph(TITLE_IMAGE_PATH);
		}
		//=====================
		m_Scene = MAIN;
		break;
	case SceneTitle::MAIN:
		//決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_Scene = END;
		}
		break;
	case SceneTitle::ENDWAIN:
		break;
	case SceneTitle::END:
		//画像データ削除
		if (m_Hndl != -1)
		{
			DeleteGraph(m_Hndl);
			m_Hndl = -1;
		}

		m_Scene = INIT;
		return 1;
	}
	return 0;
}


//---------------------------------
//		描画処理
//---------------------------------
void SceneTitle::Draw()
{
	switch (m_Scene)
	{
	case SceneTitle::MAIN:
	case SceneTitle::ENDWAIN:
		//タイトル画面描画
		DrawRotaGraph((int)(TITLE_SIZE_X * 1.0f), (int)(TITLE_SIZE_Y * 0.75f),
			1.35, 0.0, m_Hndl, TRUE);
		break;

	}
}




//---------------------------------
//		繰り返し行う処理
//---------------------------------
int SceneTitle::Loop()
{
	int result = 0;
	switch (m_Scene)
	{
	case INIT:
		Init();
		//初期化==========================
		m_Hndl = -1;
		//================================
		m_Scene = LOAD;
		break;
	case LOAD:
		//画像ロード=====================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph(TITLE_IMAGE_PATH);
		}
		//=====================
		m_Scene = MAIN;
		break;
	case MAIN:
		Step();
		//決定ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			m_Scene = END;
		}
		break;
		m_Scene = END;
		//画像データ削除
		if (m_Hndl != -1)
		{
			DeleteGraph(m_Hndl);
			m_Hndl = -1;
		}
	case END:
		m_Scene = INIT;
		result = 1;
		break;

	}
	return result;


}





