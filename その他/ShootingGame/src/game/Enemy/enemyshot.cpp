#include"enemyshot.h"
#include "../Player/player.h"
#include<math.h>

//定義関数-------------
#define SHOT_SPEED (2.0f)
#define SHOT_SIZE (8.0f)
//----------------------

//グローバル変数を作成
ENEMYSHOT_MANAGER g_enemyShotManager;
// player.cppにあるプレイヤー情報を使う
extern PLAYER_DATA g_player;

//----------------
//敵弾用データの初期化関数
//---------------
void InitEnemyShot()
{
	g_enemyShotManager.m_hndl = -1;
	
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		g_enemyShotManager.m_shot[i].m_isActive = false;
		g_enemyShotManager.m_shot[i].m_pos = { 0.0f,0.0f,0.0f };
		g_enemyShotManager.m_shot[i].m_speed = { 0.0f,0.0f,0.0f};
	}
}

//画像データをロード
void LoadEnemyShot()
{
	//プレイヤーの画像をロード
	if (g_enemyShotManager.m_hndl == -1)
	{
		g_enemyShotManager.m_hndl = LoadGraph("data/graphics/game/Shot01.png");
	}
	
}

//---------------------------------
//敵の弾の毎フレーム更新処理関数
//---------------------------------
void StepEnemyShot()
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (g_enemyShotManager.m_shot[i].m_isActive == false)
		{
			continue;
		}

		//速度を座標に加算していく
		g_enemyShotManager.m_shot[i].m_pos.x += g_enemyShotManager.m_shot[i].m_speed.x;
		g_enemyShotManager.m_shot[i].m_pos.y += g_enemyShotManager.m_shot[i].m_speed.y;



		if (g_enemyShotManager.m_shot[i].m_pos.x < 0.0f
			|| g_enemyShotManager.m_shot[i].m_pos.x>640.0f
			|| g_enemyShotManager.m_shot[i].m_pos.y < 0.0f
			|| g_enemyShotManager.m_shot[i].m_pos.y>480.0f)
		{
			g_enemyShotManager.m_shot[i].m_isActive = false;
		}
	}
}
//----------------------
//敵の弾表示描画
//----------------------
void DrawEnemyShot()
{
	//弾の画像表示
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (g_enemyShotManager.m_shot[i].m_isActive == false)
		{
			continue;
		}
		DrawRotaGraph((int)g_enemyShotManager.m_shot[i].m_pos.x, (int)g_enemyShotManager.m_shot[i].m_pos.y,
			1.0, 0.0, g_enemyShotManager.m_hndl, TRUE);
		}
	}


//終了前に行う
void ExitEnemyShot()
{

	//弾の画像破棄
	if (g_enemyShotManager.m_hndl != -1)
	{
		DeleteGraph(g_enemyShotManager.m_hndl);
		g_enemyShotManager.m_hndl = -1;
	}
}
//-------------------------
//敵の弾発射
//-------------------------
void RequestEnemyShot(VECTOR pos)
{
	VECTOR v;
	float len;

	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (g_enemyShotManager.m_shot[i].m_isActive == true)
		{
			continue;
		}


		g_enemyShotManager.m_shot[i].m_isActive = true;
		g_enemyShotManager.m_shot[i].m_pos = pos;


		v.x = g_player.m_pos.x - pos.x;
		v.y = g_player.m_pos.y - pos.y;


		len = sqrtf(v.x * v.x + v.y * v.y);

		v.x /= len;
		v.y /= len;

		g_enemyShotManager.m_shot[i].m_speed.x = v.x * SHOT_SPEED;
		g_enemyShotManager.m_shot[i].m_speed.y = v.y * SHOT_SPEED;

		break;
	}
}