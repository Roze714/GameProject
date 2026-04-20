#include"ScenePlay.h"
#include"../Collision/CollisionManager.h"
//定義関連===================
//===========================


//----------------------
//コンストラクタ
//----------------------
ScenePlay::ScenePlay()
{
	m_Scene = INIT;
}


//----------------------
//デストラクタ
//----------------------

ScenePlay::~ScenePlay()
{
	Exit();
}
//----------------------
//実行処理
//----------------------
int ScenePlay::Loop()
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
void ScenePlay::Draw()
{
	
}

//----------------------
// //初期化
//----------------------
void ScenePlay::Init()
{
	
	
}

//----------------------
//終了処理
//----------------------
void ScenePlay::Exit()
{
	
}

//----------------------
//データのロード
//----------------------
void ScenePlay::Load()
{
	
}

//---------------------
//更新
//---------------------
void  ScenePlay::Step()
{
	
}

