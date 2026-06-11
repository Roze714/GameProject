#pragma once
#include<DxLib.h>

// デバックカメラを管理するクラス
class CDebugCamera{
private:
	
	VECTOR m_vPos;				// 座標
	VECTOR m_vRot;				// 回転角度
	

public:

	// コンストラクタ
	CDebugCamera();
	

	// 初期化
	void Init();

	// カメラの座標設定
	void Step();

	// カメラの更新
	void Updete();
};

