#pragma once
#include<DxLib.h>
#include "SceneBase.h"
#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Field/Field.h"
#include"../System/SoundManager.h"
#include"../BackGround/BackGround.h"

class CSceneGame : public CSceneBase 
{
private:
	enum tagScene
	{
		INIT,	//データの初期化
		LOAD,	//データの読み込み
		LOOP,	//データの繰り返し
		END		//データの終了
	};

	CPlayer m_Player;					//プレイヤー
	CEnemyManager m_Enemy;				//敵
	CBackGround m_BackGround;			//背景
	tagScene m_SceneID;					//シーン保存
	int m_Hndl;

public:
	////コンストラクタ・デストラクタ
	//CSceneGame();
	//~CSceneGame();

	//繰り返し行う処理
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
	int Step();
};

