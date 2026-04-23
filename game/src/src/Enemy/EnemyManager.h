#pragma once
#include"Enemy.h"

//敵の最大数
static const int ENEMY_NUM=50;

//敵全体を管理するクラス
class EnemyManager
{
private:
	Enemy m_enemy[ENEMY_NUM];		//敵
	int m_waitCount;				//敵が出るまでの時間

public:
	//コンストラクタ
	EnemyManager();


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
	void Request();

	//敵1体分の情報
	//@id:配列番号
	Enemy& GetShot(int id) { return m_enemy[id]; }
};



