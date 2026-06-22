#include"SceneResult.h"
#include"../Collision/CollisionManager.h"
//定義関連===================
//===========================


//----------------------
//コンストラクタ
//----------------------
ResultScene::ResultScene()
{
	m_Scene = INIT;
}


//----------------------
//デストラクタ
//----------------------

ResultScene::~ResultScene()
{
	Exit();
}
//----------------------
//実行処理
//----------------------
int ResultScene::Loop()
{
	int result = 0;
	switch (m_Scene)
	{
	case INIT:
		Init();
		m_Scene = LOAD;
		break;
	case LOAD:
		Load();
		//SoundManager::Play(SoundManager::BGM_GAME, DX_PLAYTYPE_LOOP);
		m_Scene = LOOP;
		break;
	case LOOP:
		Step();
		break;
	case END:
		Exit();
		m_Scene = INIT;
		result = 1;
		break;

	}
	return result;

}
//----------------------
//描画処理
//----------------------
void ResultScene::Draw()
{
	m_Field.Draw();
	m_Player.Draw();
	m_shot.Draw();
	m_Enemy.Draw();

}

//-------------
//初期化
//-------------
void ResultScene::Init()
{
	m_CameraManager.Init();
	m_Field.Init();
	m_Player.Init();
	m_shot.Init();
	m_Enemy.Init();
}

//-------------
//終了処理
//-------------
void ResultScene::Exit()
{
	m_Enemy.Exit();
	m_Player.Exit();
	m_shot.Exit();
	m_Field.Exit();
}

//-------------
//データのロード
//-------------
void ResultScene::Load()
{
	m_Player.Load();
	m_shot.Load();
	m_Enemy.Load();
	m_Field.Load();
}

//---------------------
//更新
//---------------------
void  ResultScene::Step()
{
	if (m_CameraManager.GetID() == CameraManager::ID_PLAY)
	{
		m_Player.Step(m_shot);
		m_shot.Step();
		m_Enemy.Step();
		m_Field.Step();
	}


	if (CheckHitKey(KEY_INPUT_C))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_DEBUG);
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_PLAY);
	}

	//当たり判定処理
	CollisionManager::CheckHitShotToEnemy(m_shot, m_Enemy);
	CollisionManager::CheckHitPlayerToEnemy(m_Player, m_Enemy);
	//プレイヤーの生存フラグが消えたら、ゲーム終了へ
	if (m_Player.IsActive() == false)
	{
		m_Scene = END;
	}


	m_Player.Updete();
	m_Enemy.Updete();
	m_shot.Updete();
	m_Field.Updete();
	//カメラ更新処理
	m_CameraManager.Step(m_Player.GetPos(), m_Player.GetPosY());
	m_CameraManager.Updete();

}

//#include"sceneresult.h"
//#include<DxLib.h>
//#include"../lib/input.h"
//#include"../lib/fade.h"
//
//#define RESULT_SIZE_X	(640.0f)	//画像サイズ(横)
//#define RESULT_SIZE_Y	(480.0f)	//画像サイズ(縦)
//
//enum tagresultScene {
//	RESULTSCENE_INIT,
//	RESULTSCENE_LOAD,
//	RESULTSCENE_STARTWAIT,
//	RESULTSCENE_MAIN,
//	RESULTSCENE_ENDWAIT,
//	RESULTSCENE_END,
//
//	RESULTSCENE_NUM
//};
//
//
////ゲームの流れ管理の構造体
//typedef struct {
//	tagresultScene m_state;			//現在のシーン番号管理
//	int m_hndl;						//ゲーム終了時に一定時間待つためのカウント
//}RESULTSCENE_DATA;
//
////グローバル変数を作成
//RESULTSCENE_DATA g_resultScene;
//
////--------------------
////データの初期化
////---------------------
//void InitResult()
//{
//	//最初は初期化へ進む
//	g_resultScene.m_state = RESULTSCENE_INIT;
//}
//
////---------------------- -
////リザルト画面の処理管理
////-----------------------
//int StepResult()
//{
//	//現在の状態に合わせて行き先を変更
//	switch (g_resultScene.m_state)
//	{
//	case RESULTSCENE_INIT:
//		//初期化はここで行う===============================
//		g_resultScene.m_hndl = -1;
//		//=============================================
//		g_resultScene.m_state = RESULTSCENE_LOAD;
//		break;
//
//	case RESULTSCENE_LOAD:
//		//画像のロード関係==============================
//		if (g_resultScene.m_hndl == -1)
//		{
//			g_resultScene.m_hndl = LoadGraph("data/graphics/title/result.jpg");
//		}
//		//==============================================
//		//フェードイン開始
//		RequestFadeIn();
//		g_resultScene.m_state = RESULTSCENE_STARTWAIT;
//		break;
//
//	case RESULTSCENE_STARTWAIT:
//		//フェードインが終わったら次へ
//		if (IsEndFadeIn() == true)
//		{
//			g_resultScene.m_state = RESULTSCENE_MAIN;
//		}
//		break;
//
//	case RESULTSCENE_MAIN:
//		//ショット発射ボタンを押したら次へ
//		if (IsInputTrg(KEY_SHOT) == true)
//		{
//			//フェードアウト開始
//			RequestFadeOut();
//			g_resultScene.m_state = RESULTSCENE_ENDWAIT;
//		}
//		break;
//
//
//	case  RESULTSCENE_ENDWAIT:
//		//フェードアウトが終わったら次へ
//		if (IsEndFadeOut() == true)
//		{
//			g_resultScene.m_state = RESULTSCENE_END;
//		}
//		break;
//
//	case  RESULTSCENE_END:
//		//画像データ削除
//		if (g_resultScene.m_hndl != -1)
//		{
//			DeleteGraph(g_resultScene.m_hndl);
//			g_resultScene.m_hndl = -1;
//		}
//
//		g_resultScene.m_state = RESULTSCENE_INIT;
//		return 1;
//	}
//
//	return 0;
//}
//
////---------------------------
////リザルト画面の描画管理
////---------------------------
//void DrawResult()
//{
//	switch (g_resultScene.m_state)
//	{
//	case RESULTSCENE_STARTWAIT:
//	case RESULTSCENE_MAIN:
//	case RESULTSCENE_ENDWAIT:
//		//リザルト画面描画
//		DrawRotaGraph((int)(RESULT_SIZE_X * 0.5f), (int)(RESULT_SIZE_Y * 0.5f),
//			1.0, 0.0, g_resultScene.m_hndl, TRUE);
//		break;
//	}
//}