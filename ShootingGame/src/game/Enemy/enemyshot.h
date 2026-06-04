#pragma once
#include<DxLib.h>

//定義関連-----------------------
#define ENEMY_SHOT_MAX (50)//敵の弾最大数
// ------------------------------

//弾管理用構造体
typedef struct {
	VECTOR m_pos;		//座標
	VECTOR m_speed;		//移動速度
	bool m_isActive;	//生存フラグ
}ENEMYSHOT_DATA;

//敵全体の弾管理構造体
typedef struct {
	ENEMYSHOT_DATA m_shot[ENEMY_SHOT_MAX];		//敵の弾情報
	int m_hndl;									//玉の画像ハンドル
}ENEMYSHOT_MANAGER;

//敵の弾用データの初期化関数
void InitEnemyShot();
//敵の弾画像読込関数
void LoadEnemyShot();
//敵の弾の毎フレーム更新処理関数
void StepEnemyShot();
//敵の弾表示関数
void DrawEnemyShot();
//終了前に行う必要がある処理関数
void ExitEnemyShot();

//	敵の弾発射
//	@pos	:	弾の発射位置
void RequestEnemyShot(VECTOR pos);
