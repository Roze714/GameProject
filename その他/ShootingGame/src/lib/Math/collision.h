#pragma once

#include<DxLib.h>

//点と四角の当たり判定
//dotPos		:	点の座標
//squarePos		:	四角形の中心座標
//width			:	四角形の横幅
//height		:	四角形の縦幅
//@return		:	true=当たった	false=当たっていない
bool CheckHitDotToSquare(VECTOR dotPos, VECTOR squarePos,
	int width, int height);

bool CheckHitCircleToCircle(VECTOR dotPos, VECTOR squarePos,
	int width, int height);
