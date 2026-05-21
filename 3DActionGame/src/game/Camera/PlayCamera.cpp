#include "PlayCamera.h"
#include<math.h>

static const VECTOR ZERO = { 0.0f,0.0f ,0.0f };
//カメラとプレイヤーの距離
static const float CAMERA_LENGTH=40;
//カメラの高さ(今回は固定)
static const float CAMERA_OFFSET_Y=50;
//カメラの注視点の高さ(今回は固定)
static const float FORCUS_OFFSET_Y=30;
//----------------------
//コンストラクタ
//----------------------
PlayCamera::PlayCamera()
{
	m_cameraPos = ZERO;
	m_targetPos = ZERO;
	m_upVec = ZERO;
}

//-------------
//初期化
//-------------
void PlayCamera::Init()
{
	m_cameraPos = ZERO;
	m_targetPos = ZERO;
	m_upVec = { 0.0f,0.1f,0.0f };
}

//---------------------
//ニアーファー設定
//---------------------
void PlayCamera::SetNearFar(float n,float f)
{
	SetCameraNearFar(n, f);
}

//---------------------
//更新
//---------------------
void  PlayCamera::Step(VECTOR focus, float m_vRotY)
{
	//カメラの位置を設定する
	VECTOR v;
	v.x = sinf(m_vRotY) * CAMERA_LENGTH;
	v.y = CAMERA_OFFSET_Y;
	v.z = cosf(m_vRotY) * CAMERA_LENGTH;
	m_cameraPos = VAdd(focus, v);

	m_targetPos = focus;
	m_targetPos.y += FORCUS_OFFSET_Y;
	SetCameraPositionAndTargetAndUpVec(m_cameraPos, m_targetPos, m_upVec);

}

//カメラの更新
void  PlayCamera::Updete()
{
}


