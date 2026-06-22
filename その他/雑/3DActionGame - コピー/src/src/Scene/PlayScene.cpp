#include <DxLib.h>
#include"PlayScene.h"
#include"../Collision/CollisionManager.h"
#include "Common.h"
//定義関連===================
//===========================


//----------------------
//コンストラクタ
//----------------------
CPlayScene::CPlayScene()
{
	m_Scene = INIT;
}


//----------------------
//デストラクタ
//----------------------

CPlayScene::~CPlayScene()
{
	Exit();
}

//-------------
//初期化
//-------------
void CPlayScene::Init()
{

	m_CameraManager.Init();		//カメラ
	m_Field.Init();				//ステージ
	m_Player.Init();			//プレイヤー
	m_Shot.Init();				//弾
	m_Enemy.Init();				//敵
	m_Goal.Init();				//ゴール
	m_Item.Init();				//アイテム

}

//-------------
//データのロード
//-------------
void CPlayScene::Load()
{

	

	m_Player.Load();		//プレイヤー
	m_Shot.Load();			//弾
	m_Enemy.Load();			//敵
	m_Field.Load();			//ステージ
	m_Goal.Load();			//ゴール
	m_Item.Load();			//アイテム
	

}


//---------------------
//更新
//---------------------
int  CPlayScene::Step()
{
	if (m_CameraManager.GetID() == CameraManager::ID_PLAY)
	{
		m_Player.Step(m_Shot);	//プレイヤー
		m_Shot.Step();			//弾
		m_Enemy.Step();			//敵
		m_Field.Step();			//ステージ
		m_Goal.Step();			//ゴール
		m_Item.Step();			//アイテム
	}

	//カメラ切り替え
	if (CheckHitKey(KEY_INPUT_C))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_DEBUG);			//デバッグ用
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_PLAY);			//ゲーム中
	}

	//当たり判定処理
	CollisionManager::CheckHitShotToEnemy(m_Shot, m_Enemy);
	CollisionManager::CheckHitPlayerToEnemy(m_Player, m_Enemy);
	//プレイヤーの生存フラグが消えたら、ゲーム終了へ
	if (m_Player.IsActive() == false)
	{
		m_Scene = END;
	}


	m_Player.Updete();		//プレイヤー
	m_Enemy.Updete();		//敵
	m_Shot.Updete();		//弾
	m_Field.Updete();		//ステージ
	m_Goal.Updete();		//ゴール
	m_Item.Updete();		//アイテム

	//カメラ更新処理
	m_CameraManager.Step(m_Player.GetPos(), m_Player.GetPosY());
	m_CameraManager.Updete();

}




//----------------------
//描画処理
//----------------------
void CPlayScene::Draw()
{
	m_Field.Draw();		//ステージ
	m_Player.Draw();	//プレイヤー
	m_Shot.Draw();		//弾
	m_Enemy.Draw();		//敵
	m_Goal.Draw();		//ゴール
	m_Item.Draw();		//アイテム
}


//-------------
//終了処理
//-------------
void CPlayScene::Exit()
{
	m_Enemy.Exit();				//敵
	m_Player.Exit();			//プレイヤー
	m_Shot.Exit();				//弾
	m_Field.Exit();				//ステージ
	m_Goal.Exit();				//ゴール
	m_Item.Exit();				//アイテム
}


