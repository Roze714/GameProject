#pragma once
#include<DxLib.h>

#include"../Player/Player.h"
#include"../Enemy/EnemyManager.h"
#include"../System/SoundManager.h"
#include"../BackGround/BackGround.h"
//#include"../Shot/ShotManager.h"

//プレイ管理用クラス
class ScenePlay
{
private:
	enum tagScene {
		INIT,	//データの初期化
		LOAD,	//データの読み込み
		LOOP,	//データの繰り返し
		END		//データの終了
	};



	enum tagResult {
		NONE,   // 継続中
		CLEAR,  // ゲームクリア
		OVER    // ゲームオーバー
	};


	CPlayer			m_Player;				//プレイヤー
	//ShotManager	m_Shot;					//弾
	CEnemyManager	m_Enemy;				//敵
	//Enemy2Manager	m_Enemy2;				//敵2
	CBackGround		m_BackGround;			//背景


	tagScene		m_SceneID;				//シーン保存
	int m_Hndl;
	tagResult		m_Result = NONE;
	tagScene		m_Scene;				//状態

public:
	//コンストラクタ・デストラクタ
	ScenePlay();
	~ScenePlay();

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


