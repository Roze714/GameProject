#pragma once
#include<DxLib.h>
#include"PlayCamera.h"
#include"DebugCamera.h"

class CameraManager
{
public:
	enum tagCAMERA_ID
	{
		ID_PLAY,		//ゲーム中のカメラ
		ID_DEBUG,		//デバッグ用のカメラ

		ID_NUM
	};

private:
	PlayCamera m_Play;		//プレイヤーカメラ
	DebugCamera m_Debug;	//デバックカメラ
	tagCAMERA_ID m_id;		//現在のカメラID

public:
	//コンストラクタ
	CameraManager();


	//初期化
	void Init();

	//カメラの座標設定
	//@focus:プレイヤーの座標
	//@rotY:プレイヤーの角度
	void Step(VECTOR focus, float m_vRotY);

	//カメラの更新
	void Updete();


	//カメラタイプ変更
	void ChangeCamera(tagCAMERA_ID id) { m_id = id; }
	//カメラのタイプ取得
	tagCAMERA_ID GetID() { return m_id; }


	
};



