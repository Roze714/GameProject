#pragma once
#include <DxLib.h>

#define ENEMY_MAX (10)

//敵画像表示用構造体
typedef struct {
	VECTOR m_pos;		//表示する座標
	int m_shotWait;		//弾を撃つ待ち時間
	bool m_isActive;	//生存フラグ
	
}ENEMY_DATA;


//敵を管理するマネージャー構造体
typedef struct {
	ENEMY_DATA m_enemy[ENEMY_MAX];	//敵の基本情報格納
	int m_hndl;						//画像ハンドル保存
	int m_waitCount;				//敵再登場まで待ち時間
	float Wait_count;
}ENEMY_MANAGER;


//敵用データの初期化
void InitEnemy();
//敵画像データをロード
void LoadEnemy();
//敵の毎フレーム処理を行う
void StepEnemy();
//敵表示関数
void DrawEnemy();
//終了前に行う必要がある処理関数
void ExitEnemy();


