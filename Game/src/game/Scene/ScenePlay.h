#pragma once
#include<DxLib.h>

#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Field/Field.h"
#include"../System/SoundManager.h"
#include"../Goal/Goal.h"
#include"../Shot/ShotManager.h"

//プレイシーンを管理するクラス
class CScenePlay{
private:
	enum tagScene {
		INIT,	// データの初期化
		LOAD,	// データの読み込み
		LOOP,	// データの繰り返し
		END		// データの終了
	};



	enum tagResult {
		NONE,   // 継続中
		CLEAR,  // ゲームクリア
		OVER    // ゲームオーバー
	};


	CPlayer			m_Player;					// プレイヤー
	CShotManager	m_Shot;						// 弾
	CEnemyManager	m_Enemy;					// 敵
	CCameraManager	m_CameraManager;			// カメラ
	CField			m_Field;					// フィールド
	CGoal			m_Goal;						// ゴール
	tagScene		m_SceneID;					// シーン保存
	int m_Hndl;


	tagResult		m_Result = NONE;
	tagScene		m_Scene;					// 状態

public:
	// コンストラクタ・デストラクタ
	CScenePlay();
	~CScenePlay();

	// 実行処理
	int Loop();

	// 描画処理
	void Draw();

private:
	// 初期化
	void Init();

	// 終了処理
	void Exit();

	// データのロード
	void Load();

	// 毎フレーム呼ぶ処理
	void Step();

};


