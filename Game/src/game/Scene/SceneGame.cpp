#include <DxLib.h>
#include"SceneGame.h"
#include "../Common.h"


#include"../Collision/CollisionManager.h"

static const char FILE_NAME[] = "data/Image/game/game.png";


//定義関連-------------------------
//---------------------------------


////---------------------------------
////		コンストラクタ
////---------------------------------
//CSceneGame::CSceneGame()
//{
//}
//
////---------------------------------
////		デストラクタ
////---------------------------------
//CSceneGame::~CSceneGame()
//{
//}

//-------------------------------
//		初期化
//-------------------------------
void CSceneGame::Init()
{
	m_Hndl = -1;
	m_Field.Init();
	m_Player.Init();
	m_Enemy.Init();;
}

//-------------------------------
//		データロード
//-------------------------------
void CSceneGame::Load()
{
	if (m_Hndl == -1)
		m_Hndl = LoadGraph(FILE_NAME);

	m_Player.Load();
	m_Enemy.Load();
	m_Field.Load();
}

//---------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------
int CSceneGame::Step()
{

	int ret = -1;
	if (CheckHitKey(KEY_INPUT_X))
		ret = SCENEID_GAMECLEAR;
	if (CheckHitKey(KEY_INPUT_C))
		ret = SCENEID_GAMEOVER;
	return ret;


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

//---------------------------------
//		描画処理
//---------------------------------
void CSceneGame::Draw()
{
	m_Field.Draw();
	m_Player.Draw();
	m_Enemy.Draw();
	DrawGraph(0, 0, m_Hndl, TRUE);
}

//-------------
//終了処理
//-------------
void CSceneGame::Exit()
{
	m_Enemy.Exit();
	m_Player.Exit();

	m_Field.Exit();

	if (m_Hndl != -1)
	{
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}

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



