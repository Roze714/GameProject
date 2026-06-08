#pragma once
#include <DxLib.h>

class Shot
{
private:
	VECTOR m_vPos;				//座標
	VECTOR m_vSpeed;			//移動速度
	float m_Radius;				//半径
	int m_iHndl;				//モデルハンドル
	bool m_isActive;			//生存フラグ
public:

	//コンストラクタ・デストラクタ
	Shot();
	~Shot();

	//初期化
	//@vPos			:座標
	//@vRotY		:回転角度
	void Init();
	
	//ロード
	void Load(int orginHndl);
	
	//終了
	void Exit();

	//毎フレーム呼ぶ処理
	void Step();
	
	//モデルの更新
	void Updete();

	//描画
	void Draw();

	//球をリクエスト
	//@pos:どこから発射するか
	//@speed:どの方向に飛んでいくか
	//@return:生成成功か失敗か
	bool Request(const VECTOR& pos,
		const VECTOR& speed);
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


