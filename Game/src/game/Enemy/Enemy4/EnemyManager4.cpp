#include "EnemyManager4.h"

//定義関連--------------
//	敵のモデルパス
static const char ENEMY3_MODEL_PATH[]
= { "data/model/enemy/SphereChanBig.x" };
//	敵再出現時間
static const int WAIME_TIME = 10;
//----------------------

//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CEnemyManager3::CEnemyManager3()
{
	Init();
}

//------------------------------------------------
//		初期化
//------------------------------------------------
void CEnemyManager3::Init()
{
	for (int i = 0; i < ENEMY3_NUM; i++)
		m_Enemy3[i].Init();
	m_waitCount = 0;
}

//------------------------------------------------
//		更新
//------------------------------------------------
void  CEnemyManager3::Step()
{
	for (int i = 0; i < ENEMY3_NUM; i++)
		m_Enemy3[i].Step();
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
void CEnemyManager3::Updete()
{
	for (int i = 0; i < ENEMY3_NUM; i++)
		m_Enemy3[i].Updete();
}

//------------------------------------------------
//		ロード
//------------------------------------------------
void CEnemyManager3::Load()
{
	//	オリジナルモデル読み込み
	int iHndl = MV1LoadModel(ENEMY3_MODEL_PATH);
	//	モデルを複製
	for (int i = 0; i < ENEMY3_NUM; i++)
		m_Enemy3[i].Load(iHndl);
	
	//	オリジナル削除
	MV1DeleteModel(iHndl);
}

//------------------------------------------------
//		終了
//------------------------------------------------
void CEnemyManager3::Exit()
{
	for (int i = 0; i < ENEMY3_NUM; i++)
		m_Enemy3[i].Exit();
}

//------------------------------------------------
//		描画
//------------------------------------------------
void CEnemyManager3::Draw()
{
	for (int i = 0; i < ENEMY3_NUM; i++)
		m_Enemy3[i].Draw();
}

//------------------------------------------------
//		敵をリクエスト
//------------------------------------------------
void CEnemyManager3::Request()
{
	// 横はランダム、奥行きは固定
	VECTOR pos = { (float)GetRand(200) - 200.0f,0.0f,000.0f };
	// 速度は手前に進むだけ
	VECTOR speed = { 3.5f,0.0f,3.5f };
	for (int i = 0; i < ENEMY3_NUM; i++)
	{
		// 敵を発射
		if (m_Enemy3[i].Request(pos, speed))
		{
			// 一発発射が出来たら終了
			break;
		}
	}
}

