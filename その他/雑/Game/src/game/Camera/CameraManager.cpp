#include "CameraManager.h"


//カメラとプレイヤーの距離
static const float CAMERA_LENGTH=40;
//カメラの高さ(今回は固定)
static const float CAMERA_OFFSET_Y=50;
//カメラの注視点の高さ(今回は固定)
static const float FORCUS_OFFSET_Y=30;


//----------------------
//コンストラクタ
//----------------------
CameraManager::CameraManager()
{
	//初期カメラはプレイカメラ
	m_id = ID_PLAY;
}

//-------------
//初期化
//-------------
void CameraManager::Init()
{
	//それぞれのカメラを初期化
	m_Play.Init();
	m_Debug.Init();
	m_Play.SetNearFar(1.0f, 5000.0f);
}

//---------------------
//更新
//---------------------
void  CameraManager::Step(VECTOR focus, float m_vRotY)
{
	switch (m_id)
	{
	//メインカメラ
	case ID_PLAY:
		m_Play.Step(focus, m_vRotY);
		break;
	//デバッグ用カメラ
	case ID_DEBUG:
		m_Debug.Step();
		break;
	}
}

//カメラの更新
void  CameraManager::Updete()
{
	switch (m_id)
	{
		//メインカメラ
	case ID_PLAY:
		m_Play.Updete();
		break;
		//デバッグ用カメラ
	case ID_DEBUG:
		m_Debug.Updete();
		break;
	}
}



