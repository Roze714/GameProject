#pragma once
#include<DxLib.h>
#include "SceneBase.h"


class CSceneGameClear : public CSceneBase
{
private:
	
	int m_Hndl;

public:
	//コンストラクタ・デストラクタ
	CSceneGameClear();
	//~CSceneGameClear();

	//		初期化
	void Init();
	//		データロード
	void Load();
	//		毎フレーム呼ぶ処理
	//	@戻り値	:	次のシーン(-1なら変更なし)
	int Step();
	//		描画処理
	void Draw();
	//		終了処理
	void Exit();


	////繰り返し行う処理
	//int Loop();


};




