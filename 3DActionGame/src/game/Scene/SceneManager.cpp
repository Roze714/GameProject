#include <DxLib.h>
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneGameClear.h"
#include "SceneGameover.h"
#include "../../lib/Fade/Fade.h"
//#include "../System/SoundManager.h"



//----------------------
//コンストラクタ
//----------------------
CSceneManager::CSceneManager() : m_Base(nullptr), m_State(INIT), m_Next(SCENEID_TITLE)
{
	// 関数ポインタに適切な関数を設定
	m_Step[INIT] = &CSceneManager::Init;
	m_Step[LOAD] = &CSceneManager::Load;
	m_Step[STEP] = &CSceneManager::Step;
	m_Step[EXIT] = &CSceneManager::Exit;
	CreateScene();	// 最初のシーン作成
	////音の管理
	//SoundManager::Init();
	//SoundManager::Load();
}

//----------------------
//デストラクタ
//----------------------

CSceneManager::~CSceneManager()
{
	if (m_Base != nullptr)
		delete m_Base;
	//SoundManager::Exit();
}

//-------------------------------
//		実行処理
//-------------------------------
int CSceneManager::Loop()
{
	int ret = -1;

	// 各種処理の呼び出し
	(this->*m_Step[m_State])();


	return ret;
}

//----------------------
//更新処理
//----------------------
void CSceneManager::Draw()
{
	// 基本的にm_baseはnullにならないが、心配ならnullチェックを
	m_Base->Draw();
}

//-------------------------------
//		初期化
//-------------------------------
void CSceneManager::Init()
{
	m_Base->Init();
	m_State = LOAD;
}

//-------------------------------
//		データロード
//-------------------------------
void CSceneManager::Load()
{
	m_Base->Load();
	m_State = STEP;
	CFade::GetInstance()->RequestFade(4.0f, true);
}



//-------------------------------
//		実行処理
//-------------------------------
void CSceneManager::Step()
{

	m_Next = m_Base->Step();
	if (m_Next != -1)
	{
		m_State = EXIT;
		CFade::GetInstance()->RequestFade(4.0f, false);
	}
}


//-------------------------------
//		終了処理
//-------------------------------
void CSceneManager::Exit()
{
	m_Base->Exit();
	CreateScene();	// 次のシーンを作成
	m_State = INIT;
}

//-------------------------------
//		次のシーンを作成
//-------------------------------
void CSceneManager::CreateScene()
{
	// 古いシーン削除
	if (m_Base != nullptr)
		delete m_Base;

	// 新しいシーン作成
	switch (m_Next)
	{
	case SCENEID_TITLE:
		m_Base = new CSceneTitle;
		break;
	case SCENEID_GAME:
		m_Base = new CSceneGame;
		break;
	case SCENEID_GAMEOVER:
		m_Base = new CSceneGameover;
		break;
	case SCENEID_GAMECLEAR:
		m_Base = new CSceneGameClear;
		break;
	default:
		// ここはエラー対策の処理を入れてもOK
		break;
	}

	m_Next = -1;
}

