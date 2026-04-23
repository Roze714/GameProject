#include "DebugCamera.h"
#include<math.h>




static const VECTOR ZERO = { 0.0f,0.0f ,0.0f };
static const float MOVE_SPEED = 1.0f;
static const float ROT_SPEED = 0.1f;



//----------------------
//コンストラクタ
//----------------------
DebugCamera::DebugCamera()
{
	m_vPos = ZERO;
	m_vRot = ZERO;
	
}

//-------------
//初期化
//-------------
void DebugCamera::Init()
{
	m_vPos = ZERO;
	m_vRot = ZERO;

}



//---------------------
//カメラの座標計算
//---------------------
void  DebugCamera::Step()
{
	//カメラの回転処理=======================
	//上下
	if (CheckHitKey(KEY_INPUT_UP))
	{
		m_vRot.x -= ROT_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_vRot.x += ROT_SPEED;
	}
	//左右
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_vRot.y += ROT_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_vRot.y -= ROT_SPEED;
	}
	//=======================================
	
	//カメラの移動処理=======================
	//前進
	if (CheckHitKey(KEY_INPUT_W))
	{
		//カメラの角度がオール０度の時に進む速度
		VECTOR defaultDir = { 0.0f,0.0f,MOVE_SPEED };
		//上記を行列に変換
		MATRIX dir = MGetTranslate(defaultDir);
		//X軸回転行列
		MATRIX rotX = MGetRotX(m_vRot.x);
		//Y軸回転行列
		MATRIX rotY = MGetRotY(m_vRot.y);
		//各行列を合成していく
		MATRIX res = MMult(dir, rotX);
		res = MMult(res, rotY);

		//行列から異動情報だけを取り出す
		VECTOR move;
		move.x = res.m[3][0];
		move.y = res.m[3][1];
		move.z = res.m[3][2];
		//計算結果をカメラの現在の座標に足す
		m_vPos = VAdd(m_vPos, move);

	}
	//=======================================
}

//カメラの更新
void  DebugCamera::Updete()
{
	SetCameraPositionAndAngle(m_vPos,
		m_vRot.x, m_vRot.y, m_vRot.z);
}


