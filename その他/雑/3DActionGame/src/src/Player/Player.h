#pragma once
#include <DxLib.h>
#include"../Shot/ShotManager.h"
#include"../../lib/input/input.h"
class Player
{
private:
	//プレイヤーの状態
	enum tagPlayerState {
		PLAYER_NORMAL,		//待機・移動状態
		PLAYER_JUMP,		//ジャンプ状態

		PLAYER_NUM			//状態の総数
	};

		VECTOR m_vPos;				//座標
		VECTOR m_vRot;				//回転角度
		VECTOR m_vSpeed;			//移動速度
		float m_Radius;				//半径
		bool m_isActive;			//生存フラグ
		tagPlayerState m_eState;	//プレイヤーの状態
		int m_iHndl;				//モデルハンドル
		float jumpPow;				//ジャンプ

public:

	//コンストラクタ
	Player();
	~Player();

	//初期化
	//@vPos			:座標
	//@vRotY		:回転角度
	void Init();
	
	//ロード
	void Load();
	
	//終了
	void Exit();

	//毎フレーム呼ぶ処理
	void Step(ShotManager& shot);
	
	//モデルの更新
	void Updete();

	//描画
	void Draw();

	//ヒット後の処理
	void HitCalc();

	//生存情報所得
	bool IsActive() { return m_isActive; }
	void SetActive(bool accept) { m_isActive = accept; }


	//プレイヤーの座標を取得
	VECTOR GetPos() { return m_vPos; }
	//プレイヤーの回転角度(Y軸)を取得
	float GetPosY() { return m_vRot.y; }

	//当たり判定の座標用
	VECTOR GetCenter();
	//当たり判定の半径サイズを取得
	float GetRadius() { return m_Radius; }

};


