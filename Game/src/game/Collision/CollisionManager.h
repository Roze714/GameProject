#pragma once
#include"../Player/Player.h"
#include"../Enemy/Enemy1/EnemyManager.h"
#include"../Enemy/Enemy2/EnemyManager2.h"
#include"../Enemy/Enemy3/EnemyManager3.h"
#include"../Enemy/Enemy4/EnemyManager4.h"
#include"../Shot/ShotManager.h"



// 各種オブジェクトの当たり判定
class CCollisionManager{
public:
	// プレイヤーの弾と敵の当たり判定
	static void CheckHitShotToEnemy(
		CShotManager& shot, CEnemyManager& enemy);

	// プレイヤーと敵の当たり判定
	static void CheckHitPlayerToEnemy(
		CPlayer& player, CEnemyManager& enemy);


	// プレイヤーの弾と敵2の当たり判定
	static void CheckHitShotToEnemy2(
		CShotManager& shot, CEnemyManager2& enemy2);

	// プレイヤーと敵2の当たり判定
	static void CheckHitPlayerToEnemy2(
		CPlayer& player, CEnemyManager2& enemy2);


	// プレイヤーの弾と敵3の当たり判定
	static void CheckHitShotToEnemy3(
		CShotManager& shot, CEnemyManager3& enemy3);

	// プレイヤーと敵3の当たり判定
	static void CheckHitPlayerToEnemy3(
		CPlayer& player, CEnemyManager3& enemy3);


	// プレイヤーの弾と敵4の当たり判定
	static void CheckHitShotToEnemy4(
		CShotManager& shot, CEnemyManager4& enemy4);

	// プレイヤーと敵4の当たり判定
	static void CheckHitPlayerToEnemy3(
		CPlayer& player, CEnemyManager4& enemy4);

};

