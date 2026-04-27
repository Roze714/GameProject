#include"Item.h"
#include<math.h>
#include"../System/SoundManager.h"
#define DEBUG

//定義関連-----------------------------
static const VECTOR ZERO = { 0.0f,0.0f ,0.0f };
//当たり判定

static const char GOAL_MODEL_PATH[]
= { "data/model/item/Magic wand.dx" };



//static const char GOAL_MODEL_PATH[]
//= { "data/model/item/Magic wand.x" };
//--------------------------------------


//----------------------
//コンストラクタ
//----------------------
Item::Item()
{
	Init();
}

//----------------------
//デストラクタ
//----------------------
Item::~Item()
{
	Exit();			//念のためモデルデータを破棄
}

//----------------------
//初期化
//----------------------
void Item::Init()
{
	m_vPos = ZERO;
	m_iHndl = -1;
	m_Radius = 3.0f;
	m_isActive = false;			//最初は表示しない
}

//----------------------
//ロード
//----------------------
void Item::Load()
{
	if (m_iHndl == -1)
	{
		m_iHndl = MV1LoadModel(GOAL_MODEL_PATH);
	}

}

//----------------------
//終了時に破棄
//----------------------
void Item::Exit()
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
void Item::Step()
{
	//呼び出されていない場合は終了
	if (!m_isActive)return;
	
}

//----------------------
//モデルの更新
//----------------------
void Item::Updete()
{
	//座標を設定する
	MV1SetPosition(m_iHndl, m_vPos);
	
}

//----------------------
//描画
//----------------------
void Item::Draw()
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
VECTOR Item::GetCenter()
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
void Item::HitCalc()
{
	
	//生存フラグを消す
	m_isActive = false;
}



