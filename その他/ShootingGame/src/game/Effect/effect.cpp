#include"effect.h"

//定義関連------------------------
#define ANIM_NUM	(10)
#define ANIM_SPEED	(0.25f)		//額初アニメーションの再生速度(小さいほど遅い)
////------------------------------

//爆発エフェクト表示用構造体
typedef struct {
	VECTOR m_pos;					//表示する座標
	float m_animCount;				//現在何枚目の画像を表示するか(小数点以下を切り捨て)
	int m_hndl[ANIM_NUM];			//画像ハンドル(今回は複数の画像を管理)
	bool m_isActive;				//エフェクト表示フラグ
}EXPLOTION_DATA;


//爆発エフェクト用にグローバル変数を作成
static EXPLOTION_DATA g_explosion;

//---------------------------------
//爆発エフェクト用データの初期化関数
//---------------------------------
void InitExplosion()
{
	for (int i = 0; i < ANIM_NUM; i++)
	{
		g_explosion. m_hndl[i] = -1;
	}
	g_explosion. m_pos = { 0.0f,0.0f,0.0f };
	g_explosion. m_animCount = 0.0f;
	g_explosion. m_isActive = false;
}


//---------------------------------
//爆発エフェクト画像読込関数
//---------------------------------
void LoadExplosion()
{
	//爆発エフェクトの画像をロード
	if (g_explosion.m_hndl[0] == -1)
	{
		//この変数successは書かなくてもOK!
		//画像が表示されない場合はこの変数の中身が「-1」になっている
		int succeess = LoadDivGraph("data/graphics/game/effect_explosion00.png",
			10, 10, 1, 180, 180, g_explosion.m_hndl);
	}
}


//----------------------------------
//爆発エフェクトの毎フレーム更新処理関数
//----------------------------------
void StepExplosion()
{
	//爆発エフェクトのアニメーション
	//表示フラグがオンの時しかやらない
	if (g_explosion.m_isActive == true)
	{
		g_explosion.m_animCount += ANIM_SPEED;
		//想定枚数を超えた場合はエフェクトを消す
		if (g_explosion.m_animCount >= ANIM_NUM)
		{
			g_explosion.m_isActive = false;
		}
	}
}

//----------------------
//爆発エフェクト表示関数
//----------------------
void DrawExplosion()
{
	//爆発エフェクト画像表示
	if (g_explosion.m_isActive == true)
	{
		//現在表示すべき画像の枚数はこれで計算する
		int nowHndl = g_explosion.m_hndl[(int)g_explosion.m_animCount];
		DrawRotaGraph((int)g_explosion.m_pos.x, (int)g_explosion.m_pos.y,
			1.0, 0.0, nowHndl, TRUE);
		
	}
}

//-----------------------------------
//終了前に行う必要がある処理関数
//------------------------------------
void ExitExplosion()
{
	//爆発エフェクトの画像破棄
	//ハンドルが-1でなければ、何かしらロードがされているはず
	if (g_explosion.m_hndl[0] != -1)
	{
		//すべての画像を1枚ずつ破棄する
		for (int i = 0; i < ANIM_NUM; i++)
		{
			DeleteGraph(g_explosion.m_hndl[i]);
			g_explosion.m_hndl[i] = -1;
		}
	}
}

//----------------------------
//爆発エフェクト呼び出し
//-----------------------------
void RequestExplosion(VECTOR pos)
{
	//エフェクト表示に必要な情報を１回セットする
	g_explosion.m_isActive = true;
	g_explosion.m_pos = pos;
	g_explosion.m_animCount = 0.0f;
}