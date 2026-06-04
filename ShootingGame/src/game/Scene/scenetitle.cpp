#include"scenetitle.h"
#include<DxLib.h>
#include"../../lib/Input/input.h"
#include"../../lib/Fade/fade.h"

#define TITLE_SIZE_X	(640.0f)	//画像サイズ(横)
#define TITLE_SIZE_Y	(480.0f)	//画像サイズ(縦)

enum tagTitleScene {
	TITLESCENE_INIT,
	TITLESCENE_LOAD,
	TITLESCENE_STARTWAIT,
	TITLESCENE_MAIN,
	TITLESCENE_ENDWAIT,
	TITLESCENE_END,

	TITLESCENE_NUM
};


//ゲームの流れ管理の構造体
typedef struct {
	tagTitleScene m_state;			//現在のシーン番号管理
	int m_hndl;				//ゲーム終了時に一定時間待つためのカウント
}TITLESCENE_DATA;

//グローバル変数を作成
TITLESCENE_DATA g_titleScene;

//--------------------
//データの初期化
//---------------------
void InitTitle()
{
	//最初は初期化へ進む
	g_titleScene.m_state = TITLESCENE_INIT;
}

//---------------------- -
//タイトル画面の処理管理
//-----------------------
int StepTitle()
{
	//現在の状態に合わせて行き先を変更
	switch (g_titleScene.m_state)
	{
	case TITLESCENE_INIT:
		//初期化はここで行う===============================
		g_titleScene.m_hndl = -1;
		//=============================================
		g_titleScene.m_state = TITLESCENE_LOAD;
		break;


	case TITLESCENE_LOAD:
		//画像のロード関係==============================
		if (g_titleScene.m_hndl == -1)
		{
			g_titleScene.m_hndl = LoadGraph("data/graphics/title/title.jpg");
		}
		//==============================================
		//フェードイン開始
		RequestFadeIn();
		g_titleScene.m_state = TITLESCENE_STARTWAIT;
		break;


	case TITLESCENE_STARTWAIT:
		//フェードインが終わったら次へ
		if (IsEndFadeIn() == true)
		{
			g_titleScene.m_state = TITLESCENE_MAIN;
		}
		break;


	case TITLESCENE_MAIN:
		//ショット発射ボタンを押したら次へ
		if (IsInputTrg(KEY_SHOT) == true)
		{
			//フェードアウト開始
			RequestFadeOut();
			g_titleScene.m_state = TITLESCENE_ENDWAIT;
		}
		break;


	case  TITLESCENE_ENDWAIT:
		//フェードアウトが終わったら次へ
		if (IsEndFadeOut() == true)
		{
			g_titleScene.m_state = TITLESCENE_END;
		}
		break;
		
	case  TITLESCENE_END:
		//画像データ削除
		if (g_titleScene.m_hndl != -1)
		{
			DeleteGraph(g_titleScene.m_hndl);
			g_titleScene.m_hndl=-1;
		}

		g_titleScene.m_state = TITLESCENE_INIT;
		return 1;
	}

	return 0;
}

//---------------------------
//タイトル画面の描画管理
//---------------------------
void DrawTitle()
{
	switch (g_titleScene.m_state)
	{
	case TITLESCENE_STARTWAIT:
	case TITLESCENE_MAIN:
	case TITLESCENE_ENDWAIT:
			//タイトル画面描画
			DrawRotaGraph((int)(TITLE_SIZE_X * 0.5f), (int)(TITLE_SIZE_Y * 0.5f),
				1.0, 0.0, g_titleScene.m_hndl, TRUE);
			break;
	}
}