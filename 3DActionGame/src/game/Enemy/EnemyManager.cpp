#include "EnemyManager.h"

//定義関連--------------
static const char ENEMY_MODEL_PATH[]
= { "data/model/enemy/enemy.pmx" };
//敵再出現時間
static const int WAIME_TIME = 10;
//----------------------

//----------------------
//コンストラクタ
//----------------------
EnemyManager::EnemyManager()
{
	Init();
}

//-------------
//初期化
//-------------
void EnemyManager::Init()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Init();
	m_waitCount = 0;
}

//---------------------
//更新
//---------------------
void  EnemyManager::Step()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Step();
//敵を出現する
	m_waitCount--;
	if (m_waitCount <= 0)
	{
		Request();
		m_waitCount = WAIME_TIME;
	}
}

//---------------------
//敵の更新
//---------------------
void EnemyManager::Updete()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Updete();
}

//---------------------
//ロード
//---------------------
void EnemyManager::Load()
{
	//オリジナルモデル読み込み
	int iHndl = MV1LoadModel(ENEMY_MODEL_PATH);
	//モデルを複製
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Load(iHndl);
	
	//オリジナル削除
	MV1DeleteModel(iHndl);
}

//---------------------
//終了
//---------------------
void EnemyManager::Exit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Exit();
}

//---------------------
//描画
//---------------------
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Draw();
}

//------------------------------------------
////敵をリクエスト
//------------------------------------------
void EnemyManager::Request()
{
	//横はランダム、奥行きは固定
	VECTOR pos = { (float)GetRand(200) - 200.0f,0.0f,200.0f };
	//速度は手前に進むだけ
	VECTOR speed = { 3.0f,0.0f,-1.5f };
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//敵を発射
		if (m_enemy[i].Request(pos, speed))
		{
			//一発発射が出来たら終了
			break;
		}
	}
}

