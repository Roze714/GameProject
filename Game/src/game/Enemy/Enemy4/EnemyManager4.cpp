#include "EnemyManager4.h"

//定義関連--------------
//	敵のモデルパス
static const char ENEMY4_MODEL_PATH[]
= { "data/model/enemy/SphereChanBig.x" };
//	敵再出現時間
static const int WAIME_TIME = 10;
//----------------------

//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CEnemyManager4::CEnemyManager4()
{
	Init();
}

//------------------------------------------------
//		初期化
//------------------------------------------------
void CEnemyManager4::Init()
{
	for (int i = 0; i < ENEMY4_NUM; i++)
		m_Enemy4[i].Init();
	m_waitCount = 0;
}

//------------------------------------------------
//		更新
//------------------------------------------------
void  CEnemyManager4::Step()
{
	for (int i = 0; i < ENEMY4_NUM; i++)
		m_Enemy4[i].Step();
	// 敵を出現する
	m_waitCount--;
	if (m_waitCount <= 0)
	{
		Request();
		m_waitCount = WAIME_TIME;
	}
}

//------------------------------------------------
//		敵の更新
//------------------------------------------------
void CEnemyManager4::Updete()
{
	for (int i = 0; i < ENEMY4_NUM; i++)
		m_Enemy4[i].Updete();
}

//------------------------------------------------
//		ロード
//------------------------------------------------
void CEnemyManager4::Load()
{
	//	オリジナルモデル読み込み
	int iHndl = MV1LoadModel(ENEMY4_MODEL_PATH);
	//	モデルを複製
	for (int i = 0; i < ENEMY4_NUM; i++)
		m_Enemy4[i].Load(iHndl);
	
	//	オリジナル削除
	MV1DeleteModel(iHndl);
}

//------------------------------------------------
//		終了
//------------------------------------------------
void CEnemyManager4::Exit()
{
	for (int i = 0; i < ENEMY4_NUM; i++)
		m_Enemy4[i].Exit();
}

//------------------------------------------------
//		描画
//------------------------------------------------
void CEnemyManager4::Draw()
{
	for (int i = 0; i < ENEMY4_NUM; i++)
		m_Enemy4[i].Draw();
}

//------------------------------------------------
//		敵をリクエスト
//------------------------------------------------
void CEnemyManager4::Request()
{
	// 横はランダム、奥行きは固定
	VECTOR pos = { (float)GetRand(200) - 0.0f,0.0f,0.0f };
	// 速度は手前に進むだけ
	VECTOR speed = { 0.0f,0.0f,0.0f };
	for (int i = 0; i < ENEMY4_NUM; i++)
	{
		// 敵を発射
		if (m_Enemy4[i].Request(pos, speed))
		{
			// 一発発射が出来たら終了
			break;
		}
	}
}

