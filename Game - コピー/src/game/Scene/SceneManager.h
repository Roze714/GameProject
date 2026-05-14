#pragma once
#include "../Common.h"

class CSceneBase;

class CSceneManager
{
private:
	enum tagSCENE
	{
		INIT,
		LOAD,
		STEP,
		EXIT,

		NUM
	};

	CSceneBase* m_Base;								// 各シーンを格納
	int	m_State;									// 現在の状態
	int m_Next;										// 次に移動するシーン
	void (CSceneManager::* m_Step[SCENEID_NUM])();	// シーンを関数ポインタで管理するためのもの



public:
	//コンストラクタ・デストラクタ
	CSceneManager();
	~CSceneManager();


	//		実行処理
	//	@戻り値	:	0=そのまま　1=ゲーム終了
	int Loop();
	//		描画
	void Draw();

private:
	//		初期化
	void Init();
	//		データロード
	void Load();
	//		実行処理
	void Step();
	//		終了処理
	void Exit();

	//		次のシーンを作成
	void CreateScene();

};



