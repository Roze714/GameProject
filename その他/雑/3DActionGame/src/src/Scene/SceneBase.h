#pragma once
#include"PlayScene.h"
#include"SceneTitle.h"
#include"SceneResult.h"
class SceneBase
{
protected:
	enum tagSCENE
	{
		INIT,		//初期化
		LOAD,		//読み込み
		MAIN,		//実行
		END,		//破棄
	};
	tagSCENE m_State;

public:
	//コンストラクタ・デストラクタ
	SceneBase();
	virtual ~SceneBase();

	//繰り返し行う
	int Loop();


	//描画
	virtual void Draw();
	//初期化
	virtual void Init();
	//読み込み
	virtual void Load();
	//毎フレーム呼ぶ処理
	virtual void Step();
	//終了処理
	virtual void Exit();
};



