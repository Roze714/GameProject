//#include "player.h"
#include "enemy.h"
#include <DxLib.h>
#include "enemyshot.h"
#include "../Player/player.h"
#include<math.h>

//定義関数-----------------------------

#define ENEMY_SPEED (1.0f)		//敵の移動速度
#define WAIT_COUNT (120)
#define SHOT_WAIT_COUNT (120)
//-------------------------------------


//敵画像表示用構造体


//敵用にグローバル変数を作成
ENEMY_MANAGER g_enemyManager;

//----------------
//敵用データの初期化関数
//---------------
void InitEnemy()
{
	g_enemyManager.m_hndl = -1;
	g_enemyManager.m_waitCount = 0;

	g_enemyManager.Wait_count = 120 * 60;

	//敵の数だけループ
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		g_enemyManager.m_enemy[i].m_pos.x = 0.0f;
		g_enemyManager.m_enemy[i].m_pos.y = 0.0f;
		//敵は一度すべて消す
		g_enemyManager.m_enemy[i].m_isActive = false;
	}
}
	
	//	g_enemyManager.g_enemy[i].m_pos.x = 320.0f;
	//	g_enemyManager.g_enemy[i].m_pos.y = 50.0f;;
	//	
	//}


//画像データをロード
void LoadEnemy()
{
	//敵の画像をロード
	if (g_enemyManager.m_hndl == -1)
	{
		g_enemyManager.m_hndl = LoadGraph("data/graphics/game/enemy00.png");
	}

}


// -------------------------------- -
//敵の毎フレーム更新処理関数
//---------------------------------
void StepEnemy()
{
	bool isAppear = false;	//現在敵が画面内に登場しているかを保存

	//敵の移動処理-----------------------------------
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//出現していない敵は無視する
		if (g_enemyManager.m_enemy[i].m_isActive == false)continue;

		//ひとまずは単純にした方向へ移動===============================================
		g_enemyManager.m_enemy[i].m_pos.y += ENEMY_SPEED;
		//ある程度下まで到着したらフラグをオフにして消す
		if (g_enemyManager.m_enemy[i].m_pos.y > 500.0f)
		{
			g_enemyManager.m_enemy[i].m_isActive = false;
		}
		else
		{
			//ここまで来た場合は、少なくとも敵1体以上は敵が存在していることが確定!
			isAppear = true;
		}
		//=============================================================================
		// 
		//弾の発射管理を行う=====================================
		g_enemyManager.m_enemy[i].m_shotWait--;

		if (g_enemyManager.m_enemy[i].m_shotWait <= 0)
		{
			RequestEnemyShot(g_enemyManager.m_enemy[i].m_pos);

			g_enemyManager.m_enemy[i].m_shotWait = SHOT_WAIT_COUNT;
		}
		//==========================================================
	}

	//敵の出現処理-----------------------------
	//待機カウントを減らす
	g_enemyManager.m_waitCount--;

	g_enemyManager.Wait_count--;
	//待機カウントがなくなるか、敵が画面内にいないなら、新しく出現させる
	if (g_enemyManager.m_waitCount <= 0 || isAppear == false)
	{
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			//すでに出現している敵は使えない
			if (g_enemyManager.m_enemy[i].m_isActive == true)continue;

			//敵の初期データ設定
			g_enemyManager.m_enemy[i].m_isActive = true;
			g_enemyManager.m_enemy[i].m_pos.x = (float)(GetRand(640));
			g_enemyManager.m_enemy[i].m_pos.y = -30.0f;	//少しだけ画面外から登場
			g_enemyManager.m_enemy[i].m_shotWait = SHOT_WAIT_COUNT;
			//待機カウントを再設定
			//g_enemyManager.m_waitCount = g_enemyManager.Wait_count / 60;
			g_enemyManager.m_waitCount = WAIT_COUNT;

			//1体出現させたら終了
			break;
		}
	}

	
}

//----------------------
//画像描画
//----------------------
void DrawEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//プレイヤーの画像表示
		if (g_enemyManager.m_enemy[i].m_isActive == true)
		{

			DrawRotaGraph((int)g_enemyManager.m_enemy[i].m_pos.x,(int)g_enemyManager.m_enemy[i].m_pos.y,
				1.0, 0.0, g_enemyManager.m_hndl, TRUE);
		}
	}
}

//終了前に行う
void ExitEnemy()
{
	//ハンドルが-1でなければ、何かしらロードがされているはず
	if (g_enemyManager.m_hndl != -1)
	{
		DeleteGraph(g_enemyManager.m_hndl);
		g_enemyManager.m_hndl = -1;
	}
}

