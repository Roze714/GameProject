#include"Scenetitle.h"
#include"../Camera/CameraManager.h"
#include"../System/SoundManager.h"
#include"../../lib/fade/fade.h"



#define TITLE_SIZE_X	(640.0f)	//画像サイズ(横)
#define TITLE_SIZE_Y	(480.0f)	//画像サイズ(縦)




//---------------------
//コンストラクタ
//---------------------
TitleScene::TitleScene()
{
	Init();
}
//---------------------
//デストラクタ
//---------------------
TitleScene:: ~TitleScene()
{
	Exit();
}


//---------------------
//データの初期化
//---------------------
void TitleScene::Init()
{
	m_Scene = INIT;
}


//---------------------- -
//実行処理
//-----------------------

int TitleScene::Loop()
{
	int result = 0;
	switch (m_Scene)
	{
	case INIT:
		Init();
		m_Scene = LOAD;
		break;
	case LOAD:
		m_Scene = MAIN;
		break;
	case MAIN:
		Step();
		m_Scene = END;
		break;
	case END:
		m_Scene = INIT;
		result = 1;
		break;

	}
	return result;

}


//---------------------------
//タイトル画面の描画管理
//---------------------------
void TitleScene::Draw()
{
	switch (m_Scene)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		//タイトル画面描画
		DrawRotaGraph((int)(TITLE_SIZE_X * 0.5f), (int)(TITLE_SIZE_Y * 0.5f),
			1.0, 0.0, m_Hndl, TRUE);
		break;
	}
}

//-------------
//終了処理
//-------------
void TitleScene::Exit()
{
	//画像データ削除
	if (m_Hndl != -1)
	{
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}
}

//-------------
//データのロード
//-------------
void TitleScene::Load()
{

}

//---------------------
//更新
//---------------------
int  TitleScene::Step()
{
	//現在の状態に合わせて行き先を変更
	switch (m_Scene)
	{
	case INIT:
		//初期化はここで行う===============================
		m_Hndl = -1;
		//=============================================
		m_Scene = LOAD;
		break;
	case LOAD:
		//画像のロード関係==============================
		if (m_Hndl == -1)
		{
			m_Hndl = LoadGraph("data/title/title.jpg");
		}
		//==============================================

		m_Scene = STARTWAIT;
		break;
	case STARTWAIT:
		m_Scene = MAIN;
		break;
	case MAIN:
		//ショット発射ボタンを押したら次へ
		if (CheckHitKey(KEY_INPUT_Z))
		{
			m_Scene = ENDWAIT;
		}
		break;


	case  ENDWAIT:
		m_Scene = END;
		break;
	case  END:
		//画像データ削除
		if (m_Hndl != -1)
		{
			DeleteGraph(m_Hndl);
			m_Hndl = -1;
		}

		m_Hndl = INIT;
		return 0;
	}
	return 1;
}


