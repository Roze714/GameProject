#pragma once
#include"Shot.h"

//プレイヤーの弾の最大数
static const int PL_SHOT_NUM=50;

//弾全体を管理するクラス
class ShotManager
{
private:
	Shot m_playerShot[PL_SHOT_NUM];

public:
	//コンストラクタ
	ShotManager();


	//初期化
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

	//弾をリクエスト
	//@pos:どこから発射するか
	//@speed:どの方向に飛んでいくか
	//@return:生成成功か失敗か
	void RequestPlayerShot(const VECTOR& pos,
		const VECTOR& speed);


	//弾1発分の情報
	//@id:配列番号
	Shot& GetShot(int id) { return m_playerShot[id]; }
};



