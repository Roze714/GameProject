#pragma once
class CBackGround
{

private:

	int			m_Hndl;			//画像ハンドル保存
	VECTOR		m_Pos;			//表示する座標


public:
	//コンストラクタ・デストラクタ
	CBackGround();
	~CBackGround();

	//データの初期化
	void Init();
	//画像データをロード
	void Load();
	//毎フレーム処理を行う
	void Step();
	//画像描画
	void Draw();
	//終了前に行う
	void Exit();
};


