#pragma once
#include<DxLib.h>

#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../Enemy/Enemy1/EnemyManager.h"
#include"../Enemy/Enemy2/EnemyManager2.h"
#include"../Field/Field.h"
#include"../System/SoundManager.h"
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
		NONE,		// 継続中
		RESULT,		// リザルト

	};


	CPlayer			m_Player;					// プレイヤー
	CShotManager	m_Shot;						// 弾
	CEnemyManager	m_Enemy;					// 敵
	CEnemyManager2	m_Enemy2;					// 敵2
	CCameraManager	m_CameraManager;			// カメラ
	CField			m_Field;					// フィールド
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


