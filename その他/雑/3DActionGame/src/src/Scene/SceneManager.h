#pragma once
#include"PlayScene.h"
#include"SceneTitle.h"
#include"SceneResult.h"
class SceneManager
{
private:
	enum tagSCENE
	{
		TITLE,		//タイトル
		PLAY,		//ゲーム中
		RESULT,		//リザルト

		NUM
	};
	TitleScene m_TitleScene;
	PlayScene m_PlayScene;
	ResultScene m_ResultScene;
	tagSCENE m_ID;


public:
	//コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();

	//繰り返し行う
	int Loop();
	//描画
	void Draw();
};



