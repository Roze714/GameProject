#include "CollisionManager.h"
#include"../../lib/math/collision.h"

//--------------------------------
//プレイヤーの弾と敵の当たり判定
//--------------------------------
void CCollisionManager::CheckHitShotToEnemy
(ShotManager& shot, EnemyManager& enemy)
{
	for (int shotID = 0; shotID < PL_SHOT_NUM; shotID++)
	{
		Shot& oneShot = shot.GetShot(shotID);
		if (oneShot.IsActive() == false) continue;

		//敵の数だけループ
		for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
		{
			//敵１袋分の情報を取得し、生存確認
			Enemy& oneEnemy = enemy.GetShot(enemyID);
			if (oneEnemy.IsActive() == false)continue;

			//それぞれの座標と半径を所得
			VECTOR shotPos = oneShot.GetCenter();
			float shotRadius = oneShot.GetRadius();
			VECTOR enemyPos = oneEnemy.GetCenter();
			float enemyRadius = oneEnemy.GetRadius();

			//当たり判定開始
			bool isHIt = CCollision::CheckHitSphereToSphere(
				shotPos, shotRadius, enemyPos, enemyRadius);

			if (isHIt == true)
			{
				//お互い当たった!!
				oneShot.HitCalc();
				oneEnemy.HitCalc();

			}
		}
	}
}


//プレイヤーと敵の当たり判定
void CCollisionManager::CheckHitPlayerToEnemy(
	Player& player, EnemyManager& enemy)
{
	//プレイヤーが死んでいたら何もしない
	if (player.IsActive() == false)return;

	//敵の数だけループ
	for (int enemyID = 0; enemyID < ENEMY_NUM; enemyID++)
	{
		//敵１袋分の情報を取得し、生存確認
		Enemy& oneEnemy = enemy.GetShot(enemyID);
		if (oneEnemy.IsActive() == false)continue;

		//それぞれの座標と半径を所得
		VECTOR playerPos = player.GetCenter();
		float playerRadius = player.GetRadius();
		VECTOR enemyPos = oneEnemy.GetCenter();
		float enemyRadius = oneEnemy.GetRadius();

		//当たり判定開始
		bool isHIt = CCollision::CheckHitSphereToSphere(
			playerPos, playerRadius, enemyPos, enemyRadius);

		if (isHIt == true)
		{
			//お互い当たった!!
			player.HitCalc();
			oneEnemy.HitCalc();

		}
	}
}

//プレイヤーとゴールの当たり判定
 void CCollisionManager::CheckHitPlayerToGoal(
	 Player& player, Goal& goal)
{
	 //それぞれの座標と半径を所得
	 VECTOR playerPos = player.GetCenter();
	 float playerRadius = player.GetRadius();
	 VECTOR goalPos = goal.GetCenter();
	 float goalRadius = goal.GetRadius();

	 //当たり判定開始
	 bool isHIt = CCollision::CheckHitSphereToSphere(
		 playerPos, playerRadius, goalPos, goalRadius);

	 if (isHIt == true)
	 {
		 //お互い当たった!!
		 player.HitCalc();
		 goal.HitCalc();

	 }
}

