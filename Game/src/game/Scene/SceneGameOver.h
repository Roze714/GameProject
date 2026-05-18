#pragma once
#include<DxLib.h>
#include "SceneBase.h"


//	@memo	:	継承後も基本はpublicは増やさない
class CSceneGameover : public CSceneBase
{
private:

	int m_Hndl;

public:
	//コンストラクタ・デストラクタ
	CSceneGameover();
	//~CSceneGameover();

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

	////	繰り返し行う処理
	//int Loop();

};

