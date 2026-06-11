#pragma once

#include<Dxlib.h>

//爆発エフェクト用データの初期化関数
void InitExplosion();
//爆発エフェクト画像読込関数
void LoadExplosion();
//爆発エフェクトの毎フレーム更新処理関数
void StepExplosion();
//爆発エフェクト表示関数
void DrawExplosion();
//終了前に行う必要がある処理関数
void ExitExplosion();

//	爆発エフェクト呼び出し
//	@pos		:		エフェクトの表示場所
void RequestExplosion(VECTOR pos);