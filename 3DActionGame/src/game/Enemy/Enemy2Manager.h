#pragma once
#include"Enemy2.h"

//敵の最大数
static const int ENEMY2_NUM = 150;

//敵全体を管理するクラス
class Enemy2Manager
{
private:
	Enemy2 m_Enemy2[ENEMY2_NUM];		//敵
	int m_waitCount;				//敵が出るまでの時間

public:
	//コンストラクタ
	Enemy2Manager();


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

	//敵をリクエスト
	void Request();

	//敵1体分の情報
	//@id:配列番号
	Enemy2& GetShot(int id) { return m_Enemy2[id]; }
};



