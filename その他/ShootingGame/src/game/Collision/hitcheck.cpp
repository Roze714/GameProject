#include"hitcheck.h"
#include"../Player/player.h"
#include"../Enemy/enemy.h"
#include"../Enemy/enemyshot.h"
#include"../../lib/Math/collision.h"
#include"../Effect/effect.h"
#include"../System/soundmanager.h"

//この　cpp内で使えるように持ってくる
//externを使う場合は、externがついていない「本体」が
//プロジェクト内のどこかに定義されている必要がある


extern PLAYER_DATA g_player;
extern ENEMY_MANAGER g_enemyManager;
extern ENEMYSHOT_MANAGER g_enemyShotManager;


//定義関数-------------
#define ENEMY_SIZE_X (96)
#define ENEMY_SIZE_Y (96)
#define PLAYER_SHOT_SIZE_X (16)
#define ENEMYSHOT_SIZE (16)
#define PLAYER_SIZE (16)
//----------------------


//エネミーとプレイヤーの弾の当たり判定
void HitCheckEnemyToPlayerShot()
{
	bool isHit = false;

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//敵の生存フラグがオフなら当たり判定をしない
		if (g_enemyManager.m_enemy[i].m_isActive == false) continue;

		for (int j = 0; j < PL_SHOT_MAX; j++)
		{
			//敵の生存フラグがオフなら当たり判定をしない
			if (g_player.m_shot[i].m_isActive == false) continue;

			//弾と敵が当たったか判定
			bool isHit = CheckHitDotToSquare(g_player.m_shot[i].m_pos,
				g_enemyManager.m_enemy[i].m_pos, (int)(ENEMY_SIZE_X), (int)(ENEMY_SIZE_Y));

			//接触していた場合は、プレイヤーのフラグをオフにする
			if (isHit == true)
			{
				g_player.m_shot[j].m_isActive = false;
				g_enemyManager.m_enemy[i].m_isActive = false;
				//ここで敵の座標にエフェクト表示
				RequestExplosion(g_enemyManager.m_enemy[i].m_pos);
				RequestSound(SEID_EXPLOSION, DX_PLAYTYPE_BACK);
				break;
			}
		}
	}
}

//エネミーの弾とプレイヤーの当たり判定
bool HitCheckEnemyShotToPlayer()
{
	bool isHit = false;
	//敵の生存フラグがオフなら当たり判定をしない
	if (g_player.m_isActive == false) return false;

	for (int i = 0; i < ENEMYSHOT_SIZE; i++)
	{
		if (g_enemyShotManager.m_shot[i].m_isActive == false)continue;

		isHit = CheckHitCircleToCircle(g_player.m_pos, g_enemyShotManager.m_shot[i].m_pos,
			(int)(PLAYER_SIZE * 0.5f), (int)(ENEMYSHOT_SIZE * 0.5f));

		if (isHit == true)
		{
			g_player.m_isActive = false;
			g_enemyShotManager.m_shot[i].m_isActive = false;

			RequestExplosion(g_player.m_pos);
			break;
		}
	}

	return isHit;
}

//プレイヤーと敵の当たり判定
bool HitCheckEnemyToPlayer()
{
	bool isHit = false;

	//敵の生存フラグがオフなら当たり判定をしない
	if (g_player.m_isActive == false) return false;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//敵の生存フラグがオフなら当たり判定をしない
		if (g_enemyManager.m_enemy[i].m_isActive == false) continue;


		//プレイヤーと敵が当たったか判定
		isHit = CheckHitDotToSquare(g_player.m_pos,
			g_enemyManager.m_enemy[i].m_pos, (int)(ENEMY_SIZE_X), (int)(ENEMY_SIZE_Y));

		//接触していた場合は、プレイヤーのフラグをオフにする
		if (isHit == true)
		{
			g_player.m_isActive = false;
			g_enemyManager.m_enemy[i].m_isActive = false;
			//ここで敵の座標にエフェクト表示
			RequestExplosion(g_enemyManager.m_enemy[i].m_pos);
			break;
		}
	}
	return isHit;
}