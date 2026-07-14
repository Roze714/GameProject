#include "EnemyManager.h"

//定義関連--------------
//	敵のモデルパス
static const char ENEMY_MODEL_PATH[] = 
{ "data/model/Character/Enemy1/character-l.mv1" };


//	敵再出現時間
static const int WAIME_TIME = 10;
//----------------------

//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CEnemyManager::CEnemyManager()
{
	Init();
}

//------------------------------------------------
//		初期化
//------------------------------------------------
void CEnemyManager::Init()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_Enemy[i].Init();
	m_waitCount = 0;
}

//------------------------------------------------
//		更新
//------------------------------------------------
void  CEnemyManager::Step()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_Enemy[i].Step();
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
void CEnemyManager::Updete()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_Enemy[i].Updete();
}

//------------------------------------------------
//		ロード
//------------------------------------------------
void CEnemyManager::Load()
{
	//	オリジナルモデル読み込み
	int iHndl = MV1LoadModel(ENEMY_MODEL_PATH);
	//	モデルを複製
	for (int i = 0; i < ENEMY_NUM; i++)
		m_Enemy[i].Load(iHndl);
	//	オリジナル削除
	MV1DeleteModel(iHndl);
}

//------------------------------------------------
//		終了
//------------------------------------------------
void CEnemyManager::Exit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_Enemy[i].Exit();
}

//------------------------------------------------
//		描画
//------------------------------------------------
void CEnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_Enemy[i].Draw();
}

//------------------------------------------------
//		敵をリクエスト
//------------------------------------------------
void CEnemyManager::Request()
{
	// 横はランダム、奥行きは固定
	VECTOR pos = { (float)GetRand(200) - 100.0f,0.0f,200.0f };
	// 速度は手前に進むだけ
	VECTOR speed = { 0.0f,0.0f,-4.0f };
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		// 敵を発射
		if (m_Enemy[i].Request(pos, speed))
		{
			// 一発発射が出来たら終了
			break;
		}
	}
}

