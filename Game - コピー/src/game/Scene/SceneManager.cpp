#include"SceneManager.h"
//#include"../System/SoundManager.h"
#include"../../lib/Fade/fade.h"



//----------------------
//コンストラクタ
//----------------------
SceneManager::SceneManager()
{
	m_ID = TITLE;
	////音の管理
	//SoundManager::Init();
	//SoundManager::Load();
}

//----------------------
//デストラクタ
//----------------------

SceneManager::~SceneManager()
{
	//SoundManager::Exit();
}

//----------------------
//毎フレーム呼ぶ処理
//----------------------
int SceneManager::Loop()
{
	int result = 0;
	switch (m_ID)
	{
	case TITLE:
		if (m_SceneTitle.Loop() != 0)
		{
			m_ID = PLAY;
		}
		break;
	case PLAY:
		if (m_SceneGame.Loop() != 0)
		{
			m_ID = GAMECLEAR;
		}
		else if (m_SceneGame.Loop() !=0)
		{
			m_ID = GAMEOVER;
		}
		break;
	case GAMECLEAR:
		if (m_SceneGameClear.Loop() != 0)
		{
			m_ID = TITLE;
		}
		break;
	case GAMEOVER:
		if (m_SceneGameOver.Loop() != 0)
		{
			m_ID = TITLE;
		}

		break;
	}
	
	//フェードの更新
	CFade::GetInstance()->Update();


	return result;
}
//----------------------
//更新処理
//----------------------
void SceneManager::Draw()
{
	switch (m_ID)
	{
	case TITLE:
		m_SceneTitle.Draw();
		break;

	case PLAY:
		m_SceneGame.Draw();
		break;

	case GAMECLEAR:
		m_SceneGameClear.Draw();
		break;

	case GAMEOVER:
		m_SceneGameOver.Draw();
		break;
	}
}

