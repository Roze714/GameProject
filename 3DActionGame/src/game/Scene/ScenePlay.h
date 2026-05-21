#pragma once
#include<DxLib.h>

#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Field/Field.h"
#include"../System/SoundManager.h"
#include"../Goal/Goal.h"
#include"../Shot/ShotManager.h"


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


	Player			m_Player;					//プレイヤー
	ShotManager		m_Shot;						//弾
	EnemyManager	m_Enemy;					//敵
	CameraManager	m_CameraManager;			//カメラ
	Field			m_Field;					//フィールド
	Goal			m_Goal;						//ゴール
	tagScene		m_SceneID;					//シーン保存
	int m_Hndl;


	tagResult		m_Result = NONE;
	tagScene		m_Scene;			//状態

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


