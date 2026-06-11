#pragma once
#include"ScenePlay.h"
#include"SceneTitle.h"
#include"SceneResult.h"


// シーン全体を管理するクラス
class CSceneManager{
private:
	enum tagSCENE
	{
		TITLE,			// タイトル
		PLAY,			// ゲーム中
		RESULT,			// リザルト

		NUM
	};
	CSceneTitle			m_SceneTitle;			// タイトル
	CScenePlay			m_ScenePlay;			// ゲーム中
	CSceneResult		m_SceneResult;			// リザルト
	
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

