#pragma once
#include"SceneGame.h"
#include"SceneTitle.h"
#include"SceneGameClear.h"
#include"SceneGameOver.h"
class SceneManager
{
private:
	enum tagSCENE
	{
		TITLE,			//タイトル
		PLAY,			//ゲーム中
		GAMECLEAR,		//ゲームクリア
		GAMEOVER,		//ゲームオーバー

		NUM
	};
	SceneTitle		m_SceneTitle;			//タイトル
	SceneGame		m_SceneGame;			//ゲーム中
	SceneGameClear	m_SceneGameClear;		//ゲームクリア
	SceneGameOver	m_SceneGameOver;		//ゲームオーバー

	tagSCENE		m_ID;						//シーンID


public:
	//コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();

	//繰り返し行う
	int Loop();
	//描画
	void Draw();
};



