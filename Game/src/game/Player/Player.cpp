#include"Player.h"
#include<math.h>
#define DEBUG


//定義関連-----------------------------
static const VECTOR ZERO = { 0.0f,0.0f };
//プレイヤーのモデルパス
static const char PLAYER_MODEL_PATH[] =
{ "data/model/player/player.pmx" };
//移動速度
static const float PL_SPEED = 1.0f;
//--------------------------------------


//----------------------
//コンストラクタ
//----------------------
Player::Player()
{
	Init();
}

//----------------------
//デストラクタ
//----------------------
Player::~Player()
{
	Exit();
}

//----------------------
//初期化
//----------------------
void Player::Init()
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
void Player::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = MV1LoadModel(PLAYER_MODEL_PATH);
	}
}

//----------------------
//終了時に破棄
//----------------------
void Player::Exit()
{
	if (m_iHndl != -1)
	{
		// モデル削除
		MV1DeleteModel(m_iHndl);		
		m_iHndl = -1;
	}
}

//----------------------
//毎フレーム呼ぶ処理
//----------------------
void Player::Step()
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

//----------------------
//モデルの更新
//----------------------
void Player::Updete()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
}

//----------------------
//描画
//----------------------
void Player::Draw()
{

	MV1DrawModel(m_iHndl);

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
VECTOR Player::GetCenter()
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
void Player::HitCalc()
{
	//生存フラグを消す
	m_isActive = false;
}

