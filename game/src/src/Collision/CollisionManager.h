#pragma once
#include"../Player/Player.h"
#include"../Enemy/EnemyManager.h"
#include"../Shot/ShotManager.h"



//各種オブジェクトの当たり判定
class CollisionManager
{
public:
	//プレイヤーの弾と敵の当たり判定
	static void CheckHitShotToEnemy(
		ShotManager& shot, EnemyManager& enemy);

	//プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(
		Player& player, EnemyManager& enemy);





public:
	
};



