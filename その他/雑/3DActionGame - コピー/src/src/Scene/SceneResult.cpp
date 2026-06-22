#include"SceneResult.h"
#include"../Collision/CollisionManager.h"
//定義関連===================
//===========================


//----------------------
//コンストラクタ
//----------------------
ResultScene::ResultScene()
{
	m_Scene = INIT;
}


//----------------------
//デストラクタ
//----------------------

ResultScene::~ResultScene()
{
	Exit();
}
//----------------------
//実行処理
//----------------------
int ResultScene::Loop()
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
void ResultScene::Draw()
{
	
}

//-------------
//初期化
//-------------
void ResultScene::Init()
{
	
}

//-------------
//終了処理
//-------------
void ResultScene::Exit()
{
	
}

//-------------
//データのロード
//-------------
void ResultScene::Load()
{
	
}

//---------------------
//更新
//---------------------
void  ResultScene::Step()
{
	
}



