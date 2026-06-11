#include "player.h"
#include <DxLib.h>
#include "../../lib/Input/input.h"
#include"../Shot/shot.h"

//定義関数-------------
#define PLAYER_SPEED (2)
#define SHOT_SPEED (4)
//----------------------

//プレイヤー用にグローバル変数を作成
PLAYER_DATA g_player;


//----------------
//プレイヤー用データの初期化関数
//---------------
void InitPlayer()
{
	//プレイヤー関連の初期化
	g_player.m_hndl = -1;
	g_player.m_pos.x = 320.0f;
	g_player.m_pos.y = 400.0f;
	g_player.m_isActive = true;
	//弾関連の初期化
	g_player.m_shotHndl = -1;
	g_player.m_pos.x = 320.0f;

}

//画像データをロード
void LoadPlayer()
{
	//プレイヤーの画像をロード
	if (g_player.m_hndl == -1)
	{
		g_player.m_hndl = LoadGraph("data/graphics/game/player.png");
	}
	
	//弾の画像をロード
	if (g_player.m_shotHndl == -1)
	{
		g_player.m_shotHndl = LoadGraph("data/graphics/game/shot00.png");
	}
}



//----------------------
//画像描画
//----------------------
void DrawPlayer()
{
	//2D画像表示
	//プレイヤーの画像表示

	DrawRotaGraph((int)g_player.m_pos.x, (int)g_player.m_pos.y,
		1.0, 0.0, g_player.m_hndl, TRUE);
	
	
	for (int i = 0; i < PL_SHOT_MAX; i++)
	{
		if (g_player.m_shot[i].m_isActive == true)
		{
			//弾の景画像表示
			DrawRotaGraph((int)g_player.m_shot[i].m_pos.x, (int)g_player.m_shot[i].m_pos.y,
				1.0, 0.0, g_player.m_shotHndl, TRUE);

		}
	}
}
//---------------------------------
//プレイヤーの毎フレーム更新処理関数
//---------------------------------
void StepPlayer()
{
		//弾の発射処理
	if (IsInputTrg(KEY_SHOT))
	{
		//
		for (int i = 0; i < PL_SHOT_MAX; i++)
		{
			if (g_player.m_shot[i].m_isActive == false)
			{
				//弾の位置をプレイヤーの位置に設定し、そこから発射開始
				g_player.m_shot[i].m_pos = g_player.m_pos;
				g_player.m_shot[i].m_isActive = true;
				break;
			}
		}
	}
	for (int i = 0; i < PL_SHOT_MAX; i++)
	{
		//弾の移動処理
		if (g_player.m_shot[i].m_isActive == true)
		{
			g_player.m_shot[i].m_pos.y -= SHOT_SPEED;
			//画像の一番上まで来たらフラグをオフに
			if (g_player.m_shot[i].m_pos.y < 0.0f)
			{
				g_player.m_shot[i].m_isActive = false;
			}
		}
	}
	
	//簡単な移動処理
	//引数：どのキーボードか	戻り値：1:押した　0=押していない 
	//上下移動
	if (IsInputRep(KEY_DOWN)) g_player.m_pos.y += PLAYER_SPEED;
	else if (IsInputRep(KEY_UP))g_player.m_pos.y -= PLAYER_SPEED;
	//左右移動
	if (IsInputRep(KEY_RIGHT))g_player.m_pos.x += PLAYER_SPEED;
	else if (IsInputRep(KEY_LEFT))g_player.m_pos.x -= PLAYER_SPEED;
}

//------------------
//終了前に行う
//---------------------
void ExitPlayer()
{
	//ハンドルが-1でなければ、何かしらロードがされているはず
	if (g_player.m_hndl != -1)
	{
		DeleteGraph(g_player.m_hndl);
		g_player.m_hndl = -1;
	}
	//弾の画像破棄
	if (g_player.m_shotHndl != -1)
	{
		DeleteGraph(g_player.m_shotHndl);
			g_player.m_shotHndl = -1;
	}
}