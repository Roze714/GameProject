#pragma once
#include"../Player/Player.h"
#include"../Enemy/EnemyManager.h"
#include"../Goal/Goal.h"
#include"../Shot/ShotManager.h"

//各種オブジェクトの当たり判定
class CollisionManager
{
public:

	//プレイヤーの弾と敵の当たり判定
	static void CheckHitShotToEnemy(
		ShotManager& shot, CEnemyManager& enemy);

	//プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(
		CPlayer& player, CEnemyManager& enemy);


	//プレイヤーとゴールの当たり判定
	static void CheckHitPlayerToGoal(
		CPlayer& player, CGoal& goal);

public:
	
};



