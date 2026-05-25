#pragma once
#include"../Player/Player.h"
#include"../Enemy/EnemyManager.h"
#include"../Enemy/Enemy2Manager.h"
#include"../Shot/ShotManager.h"
#include"../Goal/Goal.h"


//各種オブジェクトの当たり判定管理用クラス
class CollisionManager
{
public:
	//プレイヤーの弾と敵の当たり判定
	static void CheckHitShotToEnemy(
		ShotManager& shot, EnemyManager& enemy);

	//プレイヤーの弾と敵2の当たり判定
	static void CheckHitShotToEnemy2(
		ShotManager& shot, Enemy2Manager& enemy2);

	//プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(
		Player& player, EnemyManager& enemy);

	//プレイヤーと敵2の当たり判定
	static void CheckHitPlayerToEnemy2(
		Player& player, Enemy2Manager& enemy2);

	//プレイヤーとゴールの当たり判定
	static void CheckHitPlayerToGoal(
		Player& player, Goal& goal);


	
};



