#include "CollisionManager.h"
#include"../../lib/math/collision.h"

//------------------------------------------------
//		プレイヤーの弾と敵の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitShotToEnemy
(CShotManager& shot, CEnemyManager& enemy)
{
	for (int shotID = 0; shotID < PL_SHOT_NUM; shotID++)
	{
		CShot& oneShot = shot.GetShot(shotID);
		if (oneShot.IsActive() == false) continue;

		// 敵の数だけループ
		for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
		{
			// 敵１袋分の情報を取得し、生存確認
			CEnemy& oneEnemy = enemy.GetShot(enemyID);
			if (oneEnemy.IsActive() == false)continue;

			// それぞれの座標と半径を所得
			VECTOR shotPos = oneShot.GetCenter();
			float shotRadius = oneShot.GetRadius();
			VECTOR enemyPos = oneEnemy.GetCenter();
			float enemyRadius = oneEnemy.GetRadius();

			// 当たり判定開始
			bool isHIt = CCollision::CheckHitSphereToSphere(
				shotPos, shotRadius, enemyPos, enemyRadius);

			if (isHIt == true)
			{
				// お互い当たった!!
				oneShot.HitCalc();
				oneEnemy.HitCalc();

			}
		}
	}
}

//------------------------------------------------
//		プレイヤーと敵の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitPlayerToEnemy(
	CPlayer& player, CEnemyManager& enemy)
{
	// プレイヤーが死んでいたら何もしない
	if (player.IsActive() == false)return;

	// 敵の数だけループ
	for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
	{
		// 敵１袋分の情報を取得し、生存確認
		CEnemy& oneEnemy = enemy.GetShot(enemyID);
		if (oneEnemy.IsActive() == false)continue;

		// それぞれの座標と半径を所得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy.GetCenter();
		float enemyRadius = oneEnemy.GetRadius();

		// 当たり判定開始
		bool isHIt = CCollision::CheckHitSphereToSphere(
			playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHIt == true)
		{
			// お互い当たった!!
			player.HitCalc();
			oneEnemy.HitCalc();

		}
	}
}

//------------------------------------------------
//		プレイヤーの弾と敵2の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitShotToEnemy2(
	CShotManager& shot, CEnemyManager2& enemy2)
{
	for (int shotID = 0; shotID < PL_SHOT_NUM; shotID++)
	{
		CShot& oneShot = shot.GetShot(shotID);
		if (oneShot.IsActive() == false) continue;

		// 敵の数だけループ
		for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
		{
			// 敵１袋分の情報を取得し、生存確認
			CEnemy2& oneEnemy = enemy2.GetShot(enemyID);
			if (oneEnemy.IsActive() == false)continue;

			// それぞれの座標と半径を所得
			VECTOR shotPos = oneShot.GetCenter();
			float shotRadius = oneShot.GetRadius();
			VECTOR enemyPos = oneEnemy.GetCenter();
			float enemyRadius = oneEnemy.GetRadius();

			// 当たり判定開始
			bool isHIt = CCollision::CheckHitSphereToSphere(
				shotPos, shotRadius, enemyPos, enemyRadius);

			if (isHIt == true)
			{
				// お互い当たった!!
				oneShot.HitCalc();
				oneEnemy.HitCalc();

			}
		}
	}
}

//------------------------------------------------
//		プレイヤーと敵2の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitPlayerToEnemy2(
	CPlayer& player, CEnemyManager2& enemy2)
{
	// プレイヤーが死んでいたら何もしない
	if (player.IsActive() == false)return;

	// 敵の数だけループ
	for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
	{
		// 敵１袋分の情報を取得し、生存確認
		CEnemy2& oneEnemy = enemy2.GetShot(enemyID);
		if (oneEnemy.IsActive() == false)continue;

		// それぞれの座標と半径を所得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy.GetCenter();
		float enemyRadius = oneEnemy.GetRadius();

		// 当たり判定開始
		bool isHIt = CCollision::CheckHitSphereToSphere(
			playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHIt == true)
		{
			// お互い当たった!!
			player.HitCalc();
			oneEnemy.HitCalc();

		}
	}

}

