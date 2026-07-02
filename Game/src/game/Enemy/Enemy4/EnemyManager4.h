#pragma once
#include"Enemy4.h"

// 敵の最大数
static const int ENEMY4_NUM = 150;

// 敵全体を管理するクラス
class CEnemyManager4 {
private:
	CEnemy4 m_Enemy4[ENEMY4_NUM];		// 敵
	int m_waitCount;					// 敵が出るまでの時間

public:
	// コンストラクタ
	CEnemyManager4();


	// 初期化
	void Init();

	// ロード
	void Load();

	// 終了
	void Exit();

	// 毎フレーム呼ぶ処理
	void Step();

	// モデルの更新
	void Updete();

	// 描画
	void Draw();

	// 敵をリクエスト
	void Request();

	// 敵1体分の情報
	// @id	:	配列番号
	CEnemy4& GetShot(int id) { return m_Enemy4[id]; }
};



