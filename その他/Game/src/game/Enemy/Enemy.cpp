#include"Enemy.h"
#include<math.h>
#include"../System/SoundManager.h"
#define DEBUG

//定義関連-----------------------------
static const VECTOR ZERO = { 0.0f,0.0f };
//移動速度
float ENEMY_SPEED = 2.0f;
//当たり判定
float RADIUS = 3.0;
//--------------------------------------


//----------------------
//コンストラクタ
//----------------------
Enemy::Enemy()
{
	Init();
	
}

//----------------------
//デストラクタ
//----------------------
Enemy::~Enemy()
{
	Exit();			//念のためモデルデータを破棄
}

//----------------------
//初期化
//----------------------
void Enemy::Init()
{
	m_vPos = ZERO;
	m_iHndl = -1;
	m_Radius = RADIUS;
	m_isActive = false;			//最初は表示しない
}

//----------------------
//ロード
//----------------------
void Enemy::Load(int orginHndl)
{
	if (m_iHndl == -1)
	{
		m_iHndl = MV1DuplicateModel(orginHndl);
	}
}

//----------------------
//終了時に破棄
//----------------------
void Enemy::Exit()
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
void Enemy::Step()
{
	//呼び出されていない場合は終了
	if (!m_isActive)return;
	
	//現在の座標に速度を加算する
	m_vPos = VAdd(m_vPos, m_vSpeed);

	//範囲外に出たら敵を削除
	float length = 500.0f;
	if (m_vPos.x<-length || m_vPos.x>length
		|| m_vPos.z<-length || m_vPos.z>length)
	{
		m_isActive = false;
	}
}

//----------------------
//モデルの更新
//----------------------
void Enemy::Updete()
{
	//座標を設定する
	MV1SetPosition(m_iHndl, m_vPos);
	
}

//----------------------
//描画
//----------------------
void Enemy::Draw()
{
	if (m_isActive)
	{
		MV1DrawModel(m_iHndl);


#ifdef DEBUG
		//当たり判定を目視できる
		DrawSphere3D(GetCenter(), m_Radius,
			16, GetColor(255, 0, 0),
			GetColor(255, 0, 0), FALSE);
#endif // DEBUG

		
	}
}

//----------------------
//敵をリクエスト
//----------------------
bool Enemy::Request(const VECTOR& pos, const VECTOR& speed)
{
	//すでに発砲されている弾は失敗
	if (m_isActive)return false;

	//必要な情報を渡す
	m_isActive = true;
	m_vPos=pos;
	m_vSpeed = speed;

	return true;
}

//----------------------
//当たり判定の座標用
//----------------------
VECTOR Enemy::GetCenter()
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
void Enemy::HitCalc()
{
	//エネミー爆発音
	SoundManager::Play(SoundManager::SE_EXPLOSION);
	//生存フラグを消す
	m_isActive = false;
}

