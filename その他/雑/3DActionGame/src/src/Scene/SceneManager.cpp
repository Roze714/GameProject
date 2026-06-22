#include"SceneManager.h"
#include"../System/SoundManager.h"

//----------------------
//コンストラクタ
//----------------------
SceneManager::SceneManager()
{
	m_ID = TITLE;
	//音の管理
	SoundManager::Init();
	SoundManager::Load();
}


//----------------------
//デストラクタ
//----------------------

SceneManager::~SceneManager()
{
	SoundManager::Exit();
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
		if (m_TitleScene.Loop() != 0)
		{
			m_ID = PLAY;
		}
		break;
	case PLAY:
		if (m_PlayScene.Loop() !=0)
		{
			m_ID = RESULT;
		}
		break;
	case RESULT:
		if (m_ResultScene.Loop() != 0)
		{
			m_ID = TITLE;
		}
		break;
	}


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
		m_TitleScene.Draw();
		break;
	case PLAY:
		m_PlayScene.Draw();
		break;
	case RESULT:
		m_ResultScene.Draw();
		break;
	}
}




