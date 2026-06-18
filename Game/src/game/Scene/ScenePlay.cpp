#include"ScenePlay.h"
#include"../Collision/CollisionManager.h"


//定義関連----------------------------------------
//------------------------------------------------

//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CScenePlay::CScenePlay()
{
	m_Scene = INIT;
}

//------------------------------------------------
//		デストラクタ
//------------------------------------------------
CScenePlay::~CScenePlay()
{
	Exit();
}

//------------------------------------------------
//		実行処理
//------------------------------------------------
int CScenePlay::Loop()
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
		//CSoundManager::Play(CSoundManager::BGM_GAME, DX_PLAYTYPE_LOOP);
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

//------------------------------------------------
//		描画処理
//------------------------------------------------
void CScenePlay::Draw()
{
	m_Field.Draw();
	m_Player.Draw();
	m_Shot.Draw();
	m_Enemy.Draw();
	m_Enemy2.Draw();
}

//------------------------------------------------
//		初期化
//------------------------------------------------
void CScenePlay::Init()
{
	m_Hndl = -1;
	m_CameraManager.Init();
	m_Field.Init();
	m_Player.Init();
	m_Shot.Init();
	m_Enemy.Init();
	m_Enemy2.Init();
}

//------------------------------------------------
//		終了処理
//------------------------------------------------
void CScenePlay::Exit()
{
	m_Enemy.Exit();
	m_Enemy2.Exit();
	m_Player.Exit();
	m_Shot.Exit();
	m_Field.Exit();

}

//------------------------------------------------
//		データのロード
//------------------------------------------------
void CScenePlay::Load()
{
	m_Player.Load();
	m_Shot.Load();
	m_Enemy.Load();
	m_Enemy2.Load();
	m_Field.Load();
}

//------------------------------------------------
//		更新
//------------------------------------------------
void CScenePlay::Step()
{

	if (m_CameraManager.GetID() == CCameraManager::ID_PLAY)
	{
		m_Player.Step(m_Shot);
		m_Shot.Step();
		m_Enemy.Step();
		m_Enemy2.Step();
		m_Field.Step();
	}

	// カメラ切り替え
	if (CheckHitKey(KEY_INPUT_N))
	{
		m_CameraManager.ChangeCamera(CCameraManager::ID_DEBUG);
	}
	if (CheckHitKey(KEY_INPUT_M))
	{
		m_CameraManager.ChangeCamera(CCameraManager::ID_PLAY);
	}

	// 当たり判定処理
	CCollisionManager::CheckHitShotToEnemy(m_Shot, m_Enemy);
	CCollisionManager::CheckHitPlayerToEnemy(m_Player, m_Enemy);

	CCollisionManager::CheckHitShotToEnemy2(m_Shot, m_Enemy2);
	CCollisionManager::CheckHitPlayerToEnemy2(m_Player, m_Enemy2);

	
	// プレイヤーの生存フラグが消えたら、ゲーム終了へ
	if (m_Player.IsActive() == false)
	{
		m_SceneID = END;
	}

	m_Player.Updete();
	m_Enemy.Updete();
	m_Enemy2.Updete();
	m_Shot.Updete();
	m_Field.Updete();

	// カメラ更新処理
	m_CameraManager.Step(m_Player.GetPos(), m_Player.GetPosY());
	m_CameraManager.Updete();
}

