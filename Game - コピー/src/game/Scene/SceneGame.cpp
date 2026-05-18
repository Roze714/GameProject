#include <DxLib.h>
#include"SceneGame.h"
#include "../Common.h"
#include"../Collision/CollisionManager.h"

//static const char FILE_NAME[] = "data/Image/game/game.png";

//定義関連-------------------------
//---------------------------------


//---------------------------------
//		コンストラクタ
//---------------------------------
CSceneGame::CSceneGame()
{
	m_SceneID = INIT;
}

//---------------------------------
//		デストラクタ
//---------------------------------
CSceneGame::~CSceneGame()
{
	Exit();
}


//---------------------------------
//		繰り返し行う処理
//---------------------------------
int CSceneGame::Loop()
{
	int result = 0;
	switch (m_SceneID)
	{
	case INIT:
		Init();
		m_SceneID = LOAD;
		break;
	case LOAD:
		Load();
		SoundManager::Play(SoundManager::BGM_GAME, DX_PLAYTYPE_LOOP);
		m_SceneID = LOOP;
		break;
	case LOOP:
		Step();
		break;
	case END:
		Exit();
		m_SceneID = INIT;
		result = 1;
		break;

	}
	return result;
}


//---------------------------------
//		描画処理
//---------------------------------
void CSceneGame::Draw()
{

	m_Field.Draw();
	m_Player.Draw();
	m_Shot.Draw();
	m_Enemy.Draw();
	m_Goal.Draw();
}


//-------------------------------
//		初期化
//-------------------------------
void CSceneGame::Init()
{
	m_Hndl = -1;
	m_CameraManager.Init();
	m_Field.Init();
	m_Player.Init();
	m_Shot.Init();
	m_Enemy.Init();
	m_Goal.Init();
	
	
}

//-------------
//終了処理
//-------------
void CSceneGame::Exit()
{
	m_Enemy.Exit();
	m_Player.Exit();
	m_Shot.Exit();
	m_Field.Exit();
	m_Goal.Exit();

}

//-------------------------------
//		データロード
//-------------------------------
void CSceneGame::Load()
{
	m_Player.Load();
	m_Shot.Load();
	m_Enemy.Load();
	m_Field.Load();
	m_Goal.Load();
}

//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int CSceneGame::Step()
{


	if (m_CameraManager.GetID() == CameraManager::ID_PLAY)
	{
		m_Player.Step(m_Shot);
		m_Shot.Step();
		m_Enemy.Step();
		m_Field.Step();
		m_Goal.Step();
	}

	
	
	if (CheckHitKey(KEY_INPUT_N))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_DEBUG);
	}
	if (CheckHitKey(KEY_INPUT_M))
	{
		m_CameraManager.ChangeCamera(CameraManager::ID_PLAY);
	}


	m_Player.Updete();
	m_Enemy.Updete();
	m_Shot.Updete();
	m_Field.Updete();
	m_Goal.Updete();
	//カメラ更新処理
	m_CameraManager.Step(m_Player.GetPos(), m_Player.GetPosY());
	m_CameraManager.Updete();

	

	int ret = -1;
	if (CheckHitKey(KEY_INPUT_X))
		ret = SCENEID_GAMECLEAR;
	if (CheckHitKey(KEY_INPUT_C))
		ret = SCENEID_GAMEOVER;
	return ret;


	//当たり判定処理
	CollisionManager::CheckHitShotToEnemy(m_Shot, m_Enemy);
	CollisionManager::CheckHitPlayerToEnemy(m_Player, m_Enemy);
	//プレイヤーの生存フラグが消えたら、ゲーム終了へ
	if (m_Player.IsActive() == false)
	{
		m_SceneID = END;
	}
}


