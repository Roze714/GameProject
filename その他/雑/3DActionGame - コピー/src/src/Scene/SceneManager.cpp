#include"SceneManager.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ClearScene.h"
#include "GameoverScene.h"
#include "../../lib/Fade/Fade.h"

#include"../System/SoundManager.h"

//----------------------
//コンストラクタ
//----------------------
CSceneManager::CSceneManager() : m_base(nullptr), m_state(STATEID_INIT), m_next(SCENEID_TITLE)
{
	
	// 関数ポインタに適切な関数を設定
	m_step[STATEID_INIT] = &CSceneManager::Init;
	m_step[STATEID_LOAD] = &CSceneManager::Load;
	m_step[STATEID_STEP] = &CSceneManager::Step;
	m_step[STATEID_EXIT] = &CSceneManager::Exit;
	CreateScene();	// 最初のシーン作成

	//音の管理
	SoundManager::Init();
	SoundManager::Load();
}


//----------------------
//デストラクタ
//----------------------

CSceneManager::~CSceneManager()
{
	if (m_base != nullptr)
		delete m_base;

	SoundManager::Exit();
}
//----------------------
//毎フレーム呼ぶ処理
//----------------------
int CSceneManager::Loop()
{
	int ret = -1;

	// 各種処理の呼び出し
	(this->*m_step[m_state])();


	return ret;
}
//----------------------
//更新処理
//----------------------
void CSceneManager::Draw()
{
	// 基本的にm_baseはnullにならないが、心配ならnullチェックを
	m_base->Draw();
}


//初期化
void CSceneManager::Init()
{
	m_base->Init();
	m_state = STATEID_LOAD;
}
//データロード
void CSceneManager::Load()
{
	m_base->Load();
	m_state = STATEID_STEP;
}
//実行処理
void CSceneManager::Step()
{
	m_next = m_base->Step();
	if (m_next != -1)
	{
		m_state = STATEID_EXIT;
	}
}
//終了処理
void CSceneManager::Exit()
{
	m_base->Exit();
	CreateScene();	// 次のシーンを作成
	m_state = STATEID_INIT;
}

//次のシーンを作成
void CSceneManager::CreateScene()
{
	// 古いシーン削除
	if (m_base != nullptr)
		delete m_base;

	// 新しいシーン作成
	switch (m_next)
	{
	case SCENEID_TITLE:
		m_base = new CTitleScene;
		break;
	case SCENEID_GAME:
		m_base = new CPlayScene;
		break;
	case SCENEID_GAMEOVER:
		m_base = new CGameoverScene;
		break;
	case SCENEID_CLEAR:
		m_base = new CClearScene;
		break;
	default:
		// ここはエラー対策の処理を入れてもOK
		break;
	}

	m_next = -1;

}

