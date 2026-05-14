#include"Player.h"
#include<math.h>
#define DEBUG


//定義関連-----------------------------
static const VECTOR ZERO = { 0.0f,0.0f };
//プレイヤーのイラストパス
static const char PLAYER_ILLUSTRATION_PATH[] =
{ "data/Image/game/player.png" }; 
//移動速度
static const float PL_SPEED = 1.0f;
//--------------------------------------


//----------------------
//コンストラクタ
//----------------------
CPlayer::CPlayer()
{
	Init();
}

//----------------------
//デストラクタ
//----------------------
CPlayer::~CPlayer()
{
	Exit();
}

//----------------------
//初期化
//----------------------
void CPlayer::Init()
{
	m_vPos = ZERO;
	m_vSpeed = ZERO;
	m_eState = PLAYER_NORMAL;
	m_isActive = true;
	m_Radius = 3.0f;
	m_iHndl = -1;
	//float jumpPow = 0.0f;
	m_vPos = ZERO;




}

//----------------------
//ロード
//----------------------
void CPlayer::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = LoadGraph(PLAYER_ILLUSTRATION_PATH);
	}
}

//----------------------
//終了時に破棄
//----------------------
void CPlayer::Exit()
{
	if (m_iHndl != -1)
	{
		// イラスト削除
		DeleteGraph(m_iHndl);
		m_iHndl = -1;
	}
}

//----------------------
//毎フレーム呼ぶ処理
//----------------------
void CPlayer::Step()
{
	
	//プレイヤーの移動
	float speed = 0.0f;			//実際の進む速度

	//前進
	if (CheckHitKey(KEY_INPUT_UP))
	{
		speed = -PL_SPEED;
	}
	//後退
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		speed = PL_SPEED;
	}

	//移動速度を三角関数で計算する
	m_vSpeed.x = sinf(m_vRot.y) * speed;
	m_vSpeed.y = 0.0f;
	m_vSpeed.z = cosf(m_vRot.y) * speed;
	//計算した速度を座標に足し算する
	m_vPos = VAdd(m_vPos, m_vSpeed);

	
}

////----------------------
////モデルの更新
////----------------------
//void CPlayer::Updete()
//{
//	MV1SetPosition(m_iHndl, m_vPos);
//	MV1SetRotationXYZ(m_iHndl, m_vRot);
//}

//----------------------
//描画
//----------------------
void CPlayer::Draw()
{

	//MV1DrawModel(m_iHndl);

#ifdef DEBUG
	//当たり判定を目視できる
	DrawSphere3D(GetCenter(), m_Radius,
		16, GetColor(255, 0, 0),
		GetColor(255, 0, 0), FALSE);
#endif // DEBUG

}

//----------------------
//当たり判定の座標用
//----------------------
VECTOR CPlayer::GetCenter()
{
	//基本は物体の座標の位置
	VECTOR res = m_vPos;
	//高さだけ足元から球の半径分上げる
	res.y += m_Radius;

	return res;

}

//----------------------
//ヒット後の処理
//----------------------
void CPlayer::HitCalc()
{
	//生存フラグを消す
	m_isActive = false;
}

