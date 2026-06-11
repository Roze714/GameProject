#include"scenegame.h"
#include"../BackGround/background.h"
#include"../Player/player.h"
#include"../Enemy/enemy.h"
#include"../Enemy/enemyshot.h"
#include"../Collision/hitcheck.h"
#include"../Effect/effect.h"
#include"../System/soundmanager.h"
#include"../../lib/Fade/fade.h"



//定義関連----------------------------
#define END_WAIT (60)
////---------------------------------- 

//ゲームの流れを一つずつ設定
enum tagGameScene {
	GAMESCENE_INIT,
	GAMESCENE_LOAD,
	GAMESCENE_STARTWAIT,
	GAMESCENE_MAIN,
	GAMESCENE_ENDWAIT,
	GAMESCENE_END,

	GAMESCENE_NUM

};


//ゲームの流れ管理の構造体
typedef struct {
	tagGameScene m_state;			//現在のシーン番号管理
	int m_endWaitCount;				//ゲーム終了時に一定時間待つためのカウント
}GAMESCENE_DATA;

//グローバル変数を作成
GAMESCENE_DATA g_gameScene;


//--------------------
//変数周りの初期化
//---------------------
void InitGame()
{
	//最初は初期化へ進む
	g_gameScene.m_state = GAMESCENE_INIT;
}

//-----------------------
//ゲーム全体の処理管理
//-----------------------
int StepGame()
{
	//現在の状態に合わせて行き先を変更
	switch (g_gameScene.m_state)
	{
	case GAMESCENE_INIT:
		//初期化はここで行う===============================
		InitBG();			//背景
		InitPlayer();		//プレイヤー
		InitEnemy();		//敵の初期化
		InitEnemyShot();	//敵の弾の初期化
		InitExplosion();	//爆発エフェクトの初期化
		//=============================================
		g_gameScene.m_state = GAMESCENE_LOAD;
		break;
	case GAMESCENE_LOAD:
		//画像のロード関係==============================
		LoadBG();			//背景画像のロード
		LoadPlayer();		//プレイヤー画像のロード
		LoadEnemy();		//敵画像のロード
		LoadEnemyShot();	//敵の弾画像のロード
		LoadExplosion();	//爆発エフェクト画像のロード
		//==============================================
		// //フェードイン開始
		RequestFadeIn();
		g_gameScene.m_state = GAMESCENE_STARTWAIT;
		break;


	case GAMESCENE_STARTWAIT:
		//フェードインが終わったら次へ
		if (IsEndFadeIn() == true)
		{
			RequestSound(BGMID_GAME, DX_PLAYTYPE_LOOP);
			g_gameScene.m_state = GAMESCENE_MAIN;
		}
		break;

	case GAMESCENE_MAIN:
		//更新関連=====================================
		StepBG();			//背景の移動処理
		StepPlayer();		//プレイヤーの移動処理
		StepEnemy();		//敵の処理
		StepEnemyShot();	//敵の弾の処理
		StepExplosion();	//爆発エフェクトの処理
		HitCheckEnemyToPlayerShot();
		//=============================================

		//当たり判定処理=========================
		HitCheckEnemyToPlayerShot();
		//プレイヤーがやられた場合は終了させる方向で
		if (HitCheckEnemyToPlayer() == true
			|| HitCheckEnemyShotToPlayer() == true)
		{
			g_gameScene.m_endWaitCount = END_WAIT;
			g_gameScene.m_state = GAMESCENE_ENDWAIT;
			//フェードアウト開始
			RequestFadeOut();
		}
		//=======================================
		break;
	case GAMESCENE_ENDWAIT:
		//爆発エフェクトだけは更新する
		StepExplosion();

		g_gameScene.m_endWaitCount--;
		if (g_gameScene.m_endWaitCount == 0)
		{
			g_gameScene.m_state = GAMESCENE_END;
		}
		break;
	case GAMESCENE_END:
		ExitBG();			//背景画像の破棄
		ExitPlayer();		//プレイヤー画像の破棄
		ExitEnemy();		//敵画像の破棄
		ExitExplosion();	//爆発エフェクト画像の破棄
		ExitEnemyShot();
		StopAllSound();
		g_gameScene.m_state = GAMESCENE_INIT;
		return 1;
	}

	return 0;
}

//--------------------------------
//	ゲーム全体の描画管理
//---------------------------------
void DrawGame()
{
	switch (g_gameScene.m_state)
	{
	case GAMESCENE_MAIN:
	case GAMESCENE_ENDWAIT:
		//描画関数===========================================
		DrawBG();			//背景画像の表示
		DrawPlayer();		//プレイヤー画像の表示
		DrawEnemy();		//敵画像の表示
		DrawEnemyShot();	//敵の弾の表示
		DrawExplosion();	//爆発エフェクト画像の表示
		//=====================================================
		break;

	}
}

