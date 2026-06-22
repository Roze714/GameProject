#pragma once
#include<DxLib.h>

#include "SceneBase.h"
#include"../Player/Player.h"
#include"../Shot/ShotManager.h"
#include"../Camera/CameraManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Field/Field.h"
#include"../System/SoundManager.h"
#include"../../lib/input/input.h"
#include"../Goal/Goal.h"
#include"../Item/Item.h"

class CPlayScene : public CSceneBase
{
private:
	enum tagScene {
		INIT,	//データの初期化
		LOAD,	//データの読み込み
		LOOP,	//データの繰り返し
		END		//データの終了
	};
	
	Player			m_Player;				//プレイヤー
	Input			m_Input;				//入力
	ShotManager		m_Shot;					//弾
	EnemyManager	m_Enemy;				//敵
	CameraManager	m_CameraManager;		//カメラ
	Field			m_Field;				//背景
	Goal			m_Goal;					//ゴール
	tagScene		m_Scene;				//状態
	Item			m_Item;					//アイテム

public:
	//コンストラクタ・デストラクタ
	CPlayScene();
	~CPlayScene();

	//初期化
	void Init();
	//終了処理
	void Exit();
	//データのロード
	void Load();
	//毎フレーム呼ぶ処理
	int Step();

	
	//描画処理
	void Draw();

private:
	

};


