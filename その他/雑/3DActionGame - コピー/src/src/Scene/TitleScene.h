#pragma once
#include"SceneBase.h"

//	タイトルクラス
//	@memo	:	継承後も基本はpublicは増やさない
class CTitleScene : public CSceneBase
{
private:
	int m_Hndl;



public:
	//コンストラクタ・デストラクタ
	CTitleScene();
	~CTitleScene();

	
	//		初期化
	void Init();
	//		データロード
	void Load();
	//		実行処理
	//	@戻り値	:	次のシーン(-1なら変更なし)
	int Step();
	//		描画
	void Draw();
	//		終了処理
	void Exit();

};


