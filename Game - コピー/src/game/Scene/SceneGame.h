#pragma once
#include<DxLib.h>

#include"../Player/Player.h"
#include"../Camera/CameraManager.h"
#include"../Enemy/EnemyManager.h"
#include"../Field/Field.h"
#include"../System/SoundManager.h"


class SceneGame
{
private:
	enum tagScene
	{
		INIT,	//データの初期化
		LOAD,	//データの読み込み
		LOOP,	//データの繰り返し
		END		//データの終了
	};

	Player m_Player;					//プレイヤー
	EnemyManager m_Enemy;				//敵
	Field m_Field;						//背景
	tagScene m_SceneID;		//シーン保存
	int m_Hndl;

public:
	//コンストラクタ・デストラクタ
	SceneGame();
	~SceneGame();

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
	void Step();
};

