#include "CollisionManager.h"
#include"../../lib/math/collision.h"




//プレイヤーと敵の当たり判定
void CollisionManager::CheckHitPlayerToEnemy(
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
		bool isHIt = Collision::CheckHitCircleToCircle(
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
 void CollisionManager::CheckHitPlayerToGoal(
	 Player& player, Goal& goal)
{
	 //それぞれの座標と半径を所得
	 VECTOR PlayerPos = player.GetCenter();
	 float PlayerRadius = player.GetRadius();
	 VECTOR GoalPos = goal.GetCenter();
	 float GoalRadius = goal.GetRadius();

	 //当たり判定開始
	 bool isHIt = Collision::CheckHitCircleToCircle(
		 PlayerPos, PlayerRadius, GoalPos, GoalRadius);

	 if (isHIt == true)
	 {
		 //お互い当たった!!
		 player.HitCalc();
		 goal.HitCalc();

	 }
}


 

