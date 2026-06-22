#pragma once
#include<DxLib.h>



class ResultScene
{
private:
	enum tagScene {
		INIT,	//データの初期化
		LOAD,	//データの読み込み
		LOOP,	//データの繰り返し
		END		//データの終了
	};

	
	
	tagScene m_Scene;	//状態

public:
	//コンストラクタ・デストラクタ
	ResultScene();
	~ResultScene();

	//実行処理
	int Loop();
	//描画処理
	void Draw();

private:
	//初期化
	void Init();
	//終了処理
	void Exit();
	//データのロード
	void Load();
	//毎フレーム呼ぶ処理
	void Step();

};




