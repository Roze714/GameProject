#pragma once
#include <DxLib.h>

class Item
{
private:
	VECTOR m_vPos;				//座標
	float m_Radius;				//半径
	int m_iHndl;				//モデルハンドル
	bool m_isActive;			//生存フラグ
public:

	//コンストラクタ・デストラクタ
	Item();
	~Item();

	//初期化
	//@vPos			:座標
	void Init();

	//ロード
	void Load();

	//終了
	void Exit();

	//毎フレーム呼ぶ処理
	void Step();

	//モデルの更新
	void Updete();

	//描画
	void Draw();

	//生存情報所得
	bool IsActive() { return m_isActive; }
	void SetActive(bool accept) { m_isActive = accept; }

	//座標所得
	VECTOR GetPosition() { return m_vPos; }
	//当たり判定の座標用
	VECTOR GetCenter();
	//当たり判定の半径サイズを取得
	float GetRadius() { return m_Radius; }

	//ヒット後の処理
	void HitCalc();
};


