#pragma once
#include<DxLib.h>

//弾管理用構造体
typedef struct {
	VECTOR m_pos;		//座標
	int m_hndl;			//画像ハンドル
	bool m_isActive;	//生存フラグ
}SHOT_DATA;