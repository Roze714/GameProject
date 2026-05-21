#include "ShotManager.h"
#include"../System/SoundManager.h"
//定義関連--------------
static const char PLSHOT_MODEL_PATH[]
= { "data/model/shot/SphereChan.x" };
//----------------------

//----------------------
//コンストラクタ
//----------------------
ShotManager::ShotManager()
{
	
}

//-------------
//初期化
//-------------
void ShotManager::Init()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		m_PlayerShot[i].Init();
}

//---------------------
//更新
//---------------------
void  ShotManager::Step()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		m_PlayerShot[i].Step();
}
//---------------------
//弾の更新
//---------------------
void ShotManager::Updete()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		m_PlayerShot[i].Updete();
}

//---------------------
//ロード
//---------------------
void ShotManager::Load()
{
	//オリジナルモデル読み込み
	int iHndl = MV1LoadModel(PLSHOT_MODEL_PATH);
	//モデルを複製
	for (int i = 0; i < PL_SHOT_NUM; i++)
		m_PlayerShot[i].Load(iHndl);
	//オリジナル削除
	MV1DeleteModel(iHndl);
}

//---------------------
//終了
//---------------------
void ShotManager::Exit()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		m_PlayerShot[i].Exit();
}

//---------------------
//描画
//---------------------
void ShotManager::Draw()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
		m_PlayerShot[i].Draw();
}


//------------------------------------------
////弾をリクエスト
//------------------------------------------
void ShotManager::RequestPlayerShot(
	const VECTOR& pos,const VECTOR& speed)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		//弾を発射
		if (m_PlayerShot[i].Request(pos, speed))
		{
			//ショットの音
			SoundManager::Play(SoundManager::SE_PESHOT);
			//一発発射が出来たら終了
			break;
		}
	}
}



