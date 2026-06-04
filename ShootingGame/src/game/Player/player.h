#pragma once

#include "../Shot/shot.h"

#define PL_SHOT_MAX (30)					//打てる球の最大数

//プレイヤー画像表示用構造体
typedef struct {
	bool m_isActive;
	int m_hndl;
	int m_shotHndl;					//弾を撃つ待ち時間
	VECTOR m_pos;					//表示する座標
	SHOT_DATA m_shot[PL_SHOT_MAX];	//弾を管理するための構造体
}PLAYER_DATA;




//データの初期化
void InitPlayer();
//画像データをロード
void LoadPlayer();
//毎フレーム処理を行う
void StepPlayer();
//画像描画
void DrawPlayer();
//終了前に行う
void ExitPlayer();
