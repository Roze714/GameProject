#include"PlayScene.h"
#include"../Collision/CollisionManager.h"
//定義関連===================
//===========================


//----------------------
//コンストラクタ
//----------------------
PlayScene::PlayScene()
{
	m_Scene = INIT;
}


//----------------------
//デストラクタ
//----------------------

PlayScene::~PlayScene()
{
	Exit();
}
//----------------------
//実行処理
//----------------------
int PlayScene::Loop()
{
	int result = 0;
	switch (m_Scene)
	{
	case INIT:
		Init();
		m_Scene = LOAD;
		break;
	case LOAD:
		Load();
		//SoundManager::Play(SoundManager::BGM_GAME, DX_PLAYTYPE_LOOP);
		m_Scene = LOOP;
		break;
	case LOOP:
		Step();
		break;
	case END:
		Exit();
		m_Scene = INIT;
		result = 1;
		break;
			
	}
	return result;

}
//----------------------
//描画処理
//----------------------
void PlayScene::Draw()
{
	m_Field.Draw();
	m_Player.Draw();
	m_shot.Draw();
	m_Enemy.Draw();
	m_Goal.Draw();
}

//-------------
//初期化
//-------------
void PlayScene::Init()
{
	m_CameraManager.Init();
	m_Field.Init();
	m_Player.Init();
	m_shot.Init();
	m_Enemy.Init();
	m_Goal.Init();
}

//-------------
//終了処理
//-------------
void PlayScene::Exit()
{
	m_Enemy.Exit();
	m_Player.Exit();
	m_shot.Exit();
	m_Field.Exit();
	m_Goal.Exit();
}

//-------------
//データのロード
//-------------
void PlayScene::Load()
{
	m_Player.Load();
	m_shot.Load();
	m_Enemy.Load();
	m_Field.Load();
	m_Goal.Load();
}

//---------------------
//更新
//---------------------
void  PlayScene::Step()
{
	if (m_CameraManager.GetID() == CameraManager::ID_PLAY)
	{
		m_Player.Step(m_shot);
		m_shot.Step();
		m_Enemy.Step();
		m_Field.Step();
		m_Goal.Step();
	}


	if (CheckHitKey(KEY_INPUT_C))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_DEBUG);
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_PLAY);
	}

	//当たり判定処理
	CollisionManager::CheckHitShotToEnemy(m_shot, m_Enemy);
	CollisionManager::CheckHitPlayerToEnemy(m_Player, m_Enemy);
	//プレイヤーの生存フラグが消えたら、ゲーム終了へ
	if (m_Player.IsActive()==false)
	{
		m_Scene = END;
	}


	m_Player.Updete();
	m_Enemy.Updete();
	m_shot.Updete();
	m_Field.Updete();
	m_Goal.Updete();
	//カメラ更新処理
	m_CameraManager.Step(m_Player.GetPos(), m_Player.GetPosY());
	m_CameraManager.Updete();
	
}


