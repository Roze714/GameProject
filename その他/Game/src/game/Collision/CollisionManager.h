#pragma once
#include"../Player/Player.h"
#include"../Enemy/EnemyManager.h"
#include"../Shot/ShotManager.h"
#include"../Goal/Goal.h"


// 各種オブジェクトの当たり判定
class CCollisionManager{
public:
	// プレイヤーの弾と敵の当たり判定
	static void CheckHitShotToEnemy(
		CShotManager& shot, CEnemyManager& enemy);

	// プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(
		CPlayer& player, CEnemyManager& enemy);


	// プレイヤーとゴールの当たり判定
	static void CheckHitPlayerToGoal(
		CPlayer& player, CGoal& goal);

};



