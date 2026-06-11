#include"SceneManager.h"
//#include"../System/SoundManager.h"
#include"../../lib/Fade/fade.h"



//------------------------------------------------
//		コンストラクタ
//------------------------------------------------
CSceneManager::CSceneManager()
{
	m_ID = TITLE;
	//// 音の管理
	//SoundManager::Init();
	//SoundManager::Load();
}

//------------------------------------------------
//		デストラクタ
//------------------------------------------------

CSceneManager::~CSceneManager()
{
	//SoundManager::Exit();
}

//------------------------------------------------
//		毎フレーム呼ぶ処理
//------------------------------------------------
int CSceneManager::Loop()
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
		if (m_ScenePlay.Loop() != 0)
		{
			m_ID = RESULT;
		}
		break;
	case RESULT:
		if (m_SceneResult.Loop() != 0)
		{
			m_ID = TITLE;
		}
		break;
	
	}
	
	// フェードの更新
	CFade::GetInstance()->Update();


	return result;
}
//------------------------------------------------
//		更新処理
//------------------------------------------------
void CSceneManager::Draw()
{
	switch (m_ID)
	{
	case TITLE:
		m_SceneTitle.Draw();
		break;

	case PLAY:
		m_ScenePlay.Draw();
		break;

	case RESULT:
		m_SceneResult.Draw();
		break;
	}
}

