#include "EnemyManager2.h"

//定義関連--------------
//	敵のモデルパス
static const char ENEMY2_MODEL_PATH[]
= { "data/model/enemy/SphereChanBig.x" };
//	敵再出現時間
static const int WAIME_TIME2 = 10;
//----------------------

//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CEnemyManager2::CEnemyManager2()
{
	Init();
}

//------------------------------------------------
//		初期化
//------------------------------------------------
void CEnemyManager2::Init()
{
	for (int i = 0; i < ENEMY2_NUM; i++)
		m_enemy2[i].Init();
	m_waitCount2 = 0;
}

//------------------------------------------------
//		更新
//------------------------------------------------
void  CEnemyManager2::Step()
{
	for (int i = 0; i < ENEMY2_NUM; i++)
		m_enemy2[i].Step();
	// 敵を出現する
	m_waitCount2--;
	if (m_waitCount2 <= 0)
	{
		Request();
		m_waitCount2 = WAIME_TIME2;
	}
}

//------------------------------------------------
//		敵の更新
//------------------------------------------------
void CEnemyManager2::Updete()
{
	for (int i = 0; i < ENEMY2_NUM; i++)
		m_enemy2[i].Updete();
}

//------------------------------------------------
//		ロード
//------------------------------------------------
void CEnemyManager2::Load()
{
	//	オリジナルモデル読み込み
	int iHndl = MV1LoadModel(ENEMY2_MODEL_PATH);
	//	モデルを複製
	for (int i = 0; i < ENEMY2_NUM; i++)
		m_enemy2[i].Load(iHndl);
	
	//	オリジナル削除
	MV1DeleteModel(iHndl);
}

//------------------------------------------------
//		終了
//------------------------------------------------
void CEnemyManager2::Exit()
{
	for (int i = 0; i < ENEMY2_NUM; i++)
		m_enemy2[i].Exit();
}

//------------------------------------------------
//		描画
//------------------------------------------------
void CEnemyManager2::Draw()
{
	for (int i = 0; i < ENEMY2_NUM; i++)
		m_enemy2[i].Draw();
}

//------------------------------------------------
//		敵をリクエスト
//------------------------------------------------
void CEnemyManager2::Request()
{
	// 横はランダム、奥行きは固定
	VECTOR pos = { (float)GetRand(200) - 100.0f,0.0f,200.0f };
	// 速度は手前に進むだけ
	VECTOR speed = { 0.0f,0.0f,-2.5f };
	for (int i = 0; i < ENEMY2_NUM; i++)
	{
		// 敵を発射
		if (m_enemy2[i].Request(pos, speed))
		{
			// 一発発射が出来たら終了
			break;
		}
	}
}

