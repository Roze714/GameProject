#pragma once
#include<DxLib.h>

class PlayCamera
{
private:
	VECTOR m_cameraPos;			//カメラの視点
	VECTOR m_targetPos;			//注視点
	VECTOR m_upVec;				//カメラ上方向

public:
	//コンストラクタ
	PlayCamera();
	

	//初期化
	void Init();


	//ニアーファー設定
	void SetNearFar(float n, float f);

	//カメラの座標設定
	//@focus:プレイヤーの座標
	//@rotY:プレイヤーの角度
	void Step(VECTOR focus, float m_vRotY);

	//カメラの更新
	void Updete();
};



