#pragma once
#include"ScenePlay.h"
#include"SceneTitle.h"
#include"SceneGameClear.h"
#include"SceneGameOver.h"

// シーン全体を管理するクラス
class CSceneManager{
private:
	enum tagSCENE
	{
		TITLE,			// タイトル
		PLAY,			// ゲーム中
		GAMECLEAR,		// ゲームクリア
		GAMEOVER,		// ゲームオーバー

		NUM
	};

	CSceneTitle			m_SceneTitle;			// タイトル
	CScenePlay			m_ScenePlay;			// ゲーム中
	CSceneGameClear		m_SceneGameClear;		// ゲームクリア
	CSceneGameOver		m_SceneGameOver;		// ゲームオーバー
	
	tagSCENE			m_ID;					// シーンID


public:
	// コンストラクタ・デストラクタ
	CSceneManager();
	~CSceneManager();

	// 繰り返し行う
	int Loop();

	// 描画
	void Draw();
};

