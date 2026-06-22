#pragma once
#include<DxLib.h>


class TitleScene
{
private:
	
	enum tagScene {
		INIT,		//データの初期化
		LOAD,		//データの読み込み
		STARTWAIT,
		MAIN,
		ENDWAIT,
		END,		//データの終了

		NUM
		
	};

	tagScene m_Scene;					//状態
	int m_Hndl;



public:
	//コンストラクタ・デストラクタ
	TitleScene();
	~TitleScene();

	
	//実行処理
	int Loop();
	//描画処理
	void Draw();
	//初期化
	void Init();
	//毎フレーム呼ぶ処理
	int  Step();
	//終了処理
	void Exit();
	//ロード
	void Load();



};


