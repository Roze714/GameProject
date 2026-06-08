#pragma once
#include <DxLib.h>


class CField
{
private:
	enum tag0bject {
		FIELD,		//フィールド
		SKY,		//天球

		OBJECT_NUM			//オブジェクト総数
	};
	int m_Hndl[OBJECT_NUM];				//モデルハンドル
	float m_skyRotY;
	
public:

	//コンストラクタ
	CField();
	~CField();

	//初期化
	void Init();
	//ロード
	void Load();
	//終了
	void Exit();
	//毎フレーム呼ぶ処理
	void Step();
	//モデルの更新
	void Updete();
	//描画
	void Draw();

	
};


