#include"Field.h"
#include<math.h>




//定義関連-----------------------------
//プレイヤーのモデルパス
static const char* MODEL_PATH[] = {
	"data/model/field/field.x" ,
	"data/model/sky/sky.mv1",
};
//--------------------------------------


//----------------------
//コンストラクタ
//----------------------
Field::Field()
{
	Init();
}

//----------------------
//デストラクタ
//----------------------
Field::~Field()
{
	Exit();
}

//----------------------
//初期化
//----------------------
void Field::Init()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		m_Hndl[i] = -1;
	}
	m_skyRotY = 0.0f;
}

//----------------------
//ロード
//----------------------
void Field::Load()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		if (m_Hndl[i] == -1)
		{
			m_Hndl[i] = MV1LoadModel(MODEL_PATH[i]);
		}
	}

	VECTOR scale[OBJECT_NUM] = {
		{0.1f,0.1f,0.1f},{20.0f,20.0f,20.0f}
	};
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		MV1SetScale(m_Hndl[i], scale[i]);
	}
}

//----------------------
//終了時に破棄
//----------------------
void Field::Exit()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		if (m_Hndl[i] != -1)
		{
			// モデル削除
			MV1DeleteModel(m_Hndl[i]);
			m_Hndl[i] = -1;
		}
	}
}
//----------------------
//毎フレーム呼ぶ処理
//----------------------
void Field::Step()
{
	//天球回転用
	m_skyRotY += 0.01f;
}

//----------------------
//モデルの更新
//----------------------
void Field::Updete()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		VECTOR rot = { 0.0f,m_skyRotY,0.0f };
		MV1SetRotationXYZ(m_Hndl[SKY], rot);
	}
	
}

//----------------------
//描画
//----------------------
void Field::Draw()
{
	for (int i = 0; i < OBJECT_NUM; i++)
	{
		MV1DrawModel(m_Hndl[i]);
	}
}


