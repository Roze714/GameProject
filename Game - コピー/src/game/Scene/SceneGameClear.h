#pragma once
#include<DxLib.h>



class SceneGameClear
{
private:
	enum tagScene
	{
		INIT,		//初期化
		LOAD,		//ロード
		MAIN,
		ENDWAIN,
		END,		//破棄

		NUM
	};

	tagScene m_SceneID;		//シーン保存
	int m_Hndl;

public:
	//コンストラクタ・デストラクタ
	SceneGameClear();
	~SceneGameClear();

	//繰り返し行う処理
	int Loop();

	//描画処理
	void Draw();

private:
	//初期化
	void Init(void);

	////終了処理
	//void Exit();

	//毎フレーム呼ぶ処理
	int Step();
};






