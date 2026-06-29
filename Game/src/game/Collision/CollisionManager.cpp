#include "CollisionManager.h"
#include"../../lib/math/collision.h"

//敵1-----------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------


//敵2-----------------------------------------------------------------------------------------------
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
			CEnemy2& oneEnemy2 = enemy2.GetShot(enemyID);
			if (oneEnemy2.IsActive() == false)continue;

			// それぞれの座標と半径を所得
			VECTOR shotPos = oneShot.GetCenter();
			float shotRadius = oneShot.GetRadius();
			VECTOR enemyPos = oneEnemy2.GetCenter();
			float enemyRadius = oneEnemy2.GetRadius();

			// 当たり判定開始
			bool isHIt = CCollision::CheckHitSphereToSphere(
				shotPos, shotRadius, enemyPos, enemyRadius);

			if (isHIt == true)
			{
				// お互い当たった!!
				oneShot.HitCalc();
				oneEnemy2.HitCalc();

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
		CEnemy2& oneEnemy2 = enemy2.GetShot(enemyID);
		if (oneEnemy2.IsActive() == false)continue;

		// それぞれの座標と半径を所得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy2.GetCenter();
		float enemyRadius = oneEnemy2.GetRadius();

		// 当たり判定開始
		bool isHIt = CCollision::CheckHitSphereToSphere(
			playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHIt == true)
		{
			// お互い当たった!!
			player.HitCalc();
			oneEnemy2.HitCalc();

		}
	}

}
//--------------------------------------------------------------------------------------------------


//敵3-----------------------------------------------------------------------------------------------
//------------------------------------------------
//		プレイヤーの弾と敵3の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitShotToEnemy3(
	CShotManager& shot, CEnemyManager3& enemy3)
{
	for (int shotID = 0; shotID < PL_SHOT_NUM; shotID++)
	{
		CShot& oneShot = shot.GetShot(shotID);
		if (oneShot.IsActive() == false) continue;

		// 敵の数だけループ
		for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
		{
			// 敵１袋分の情報を取得し、生存確認
			CEnemy3& oneEnemy3 = enemy3.GetShot(enemyID);
			if (oneEnemy3.IsActive() == false)continue;

			// それぞれの座標と半径を所得
			VECTOR shotPos = oneShot.GetCenter();
			float shotRadius = oneShot.GetRadius();
			VECTOR enemyPos = oneEnemy3.GetCenter();
			float enemyRadius = oneEnemy3.GetRadius();

			// 当たり判定開始
			bool isHIt = CCollision::CheckHitSphereToSphere(
				shotPos, shotRadius, enemyPos, enemyRadius);

			if (isHIt == true)
			{
				// お互い当たった!!
				oneShot.HitCalc();
				oneEnemy3.HitCalc();

			}
		}
	}
}

//------------------------------------------------
//		プレイヤーと敵3の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitPlayerToEnemy3(
	CPlayer& player, CEnemyManager3& enemy3)
{
	// プレイヤーが死んでいたら何もしない
	if (player.IsActive() == false)return;

	// 敵の数だけループ
	for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
	{
		// 敵１袋分の情報を取得し、生存確認
		CEnemy3& oneEnemy3 = enemy3.GetShot(enemyID);
		if (oneEnemy3.IsActive() == false)continue;

		// それぞれの座標と半径を所得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy3.GetCenter();
		float enemyRadius = oneEnemy3.GetRadius();

		// 当たり判定開始
		bool isHIt = CCollision::CheckHitSphereToSphere(
			playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHIt == true)
		{
			// お互い当たった!!
			player.HitCalc();
			oneEnemy3.HitCalc();

		}
	}

}
//--------------------------------------------------------------------------------------------------


//敵4-----------------------------------------------------------------------------------------------
//------------------------------------------------
//		プレイヤーの弾と敵4の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitShotToEnemy4(
	CShotManager& shot, CEnemyManager4& enemy4)
{
	for (int shotID = 0; shotID < PL_SHOT_NUM; shotID++)
	{
		CShot& oneShot = shot.GetShot(shotID);
		if (oneShot.IsActive() == false) continue;

		// 敵の数だけループ
		for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
		{
			// 敵１袋分の情報を取得し、生存確認
			CEnemy3& oneEnemy3 = enemy3.GetShot(enemyID);
			if (oneEnemy3.IsActive() == false)continue;

			// それぞれの座標と半径を所得
			VECTOR shotPos = oneShot.GetCenter();
			float shotRadius = oneShot.GetRadius();
			VECTOR enemyPos = oneEnemy3.GetCenter();
			float enemyRadius = oneEnemy3.GetRadius();

			// 当たり判定開始
			bool isHIt = CCollision::CheckHitSphereToSphere(
				shotPos, shotRadius, enemyPos, enemyRadius);

			if (isHIt == true)
			{
				// お互い当たった!!
				oneShot.HitCalc();
				oneEnemy3.HitCalc();

			}
		}
	}
}

//------------------------------------------------
//		プレイヤーと敵3の当たり判定
//------------------------------------------------
void CCollisionManager::CheckHitPlayerToEnemy3(
	CPlayer& player, CEnemyManager3& enemy3)
{
	// プレイヤーが死んでいたら何もしない
	if (player.IsActive() == false)return;

	// 敵の数だけループ
	for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
	{
		// 敵１袋分の情報を取得し、生存確認
		CEnemy3& oneEnemy3 = enemy3.GetShot(enemyID);
		if (oneEnemy3.IsActive() == false)continue;

		// それぞれの座標と半径を所得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy3.GetCenter();
		float enemyRadius = oneEnemy3.GetRadius();

		// 当たり判定開始
		bool isHIt = CCollision::CheckHitSphereToSphere(
			playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHIt == true)
		{
			// お互い当たった!!
			player.HitCalc();
			oneEnemy3.HitCalc();

		}
	}

}
//--------------------------------------------------------------------------------------------------
