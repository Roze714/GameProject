#include"SceneGame.h"
#include"../Collision/CollisionManager.h"

//定義関連-------------------------
//---------------------------------


//---------------------------------
//		コンストラクタ
//---------------------------------
SceneGame::SceneGame()
{
	m_SceneID = INIT;
}

//---------------------------------
//		デストラクタ
//---------------------------------
SceneGame::~SceneGame()
{
	Exit();
}

//---------------------------------
//		繰り返し行う処理
//---------------------------------
int SceneGame::Loop()
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
void SceneGame::Draw()
{
	m_Field.Draw();
	m_Player.Draw();
	m_Enemy.Draw();
}

//---------------------------------
//		初期化
//---------------------------------
void SceneGame::Init(void)
{
;
	m_Field.Init();
	m_Player.Init();
	m_Enemy.Init();
}

//-------------
//終了処理
//-------------
void SceneGame::Exit()
{
	m_Enemy.Exit();
	m_Player.Exit();
	
	m_Field.Exit();
}

//-------------
//データのロード
//-------------
void SceneGame::Load()
{
	m_Player.Load();
	m_Enemy.Load();
	m_Field.Load();
}

//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
void SceneGame::Step()
{
	
		m_Player.Step();
		m_Enemy.Step();
		m_Field.Step();
	


	
	
	CollisionManager::CheckHitPlayerToEnemy(m_Player, m_Enemy);
	//プレイヤーの生存フラグが消えたら、ゲーム終了へ
	if (m_Player.IsActive() == false)
	{
		m_SceneID = END;
	}


	m_Player.Updete();
	m_Enemy.Updete();
	
	m_Field.Updete();
	
}






