#include "background.h"
#include <DxLib.h>

//定義関数----------------
#define BACKGROUND_SIZE_X (640.0f)
#define BACKGROUND_SIZE_Y (480.0f)
#define MOVE_SPEED (3.0f);

//------------------------
//背景データを表示するために必要な構造体
//------------------------
typedef struct {
	int m_hndl;			//画像ハンドル保存
	VECTOR m_pos;		//表示する座標
}BG_DATA;

//背景用にグローバル変数を作成
static BG_DATA g_bg;

//----------------
//データの初期化
//---------------
void InitBG()
{
	g_bg.m_hndl = -1;
	g_bg.m_pos.x =BACKGROUND_SIZE_X	* 0.5f;
	g_bg.m_pos.y =BACKGROUND_SIZE_Y * 0.5f;
}
//画像データをロード
void LoadBG()
{
	if (g_bg.m_hndl == -1)
	{
		g_bg.m_hndl = LoadGraph("data/graphics/game/background00.jpg");
	}
}

//----------------------------------
//背景データの毎フレーム更新処理関数
//----------------------------------
void StepBG()
{

	//背景の座標を毎フレーム下に移動させる
	g_bg.m_pos.y += MOVE_SPEED;

	//画像が特定の場所よりも下に来たら、画面サイズ分戻してやる
	if (g_bg.m_pos.y >= BACKGROUND_SIZE_Y * 0.5 + BACKGROUND_SIZE_Y)
	{
		//画像1枚分元に戻す
		g_bg.m_pos.y -= BACKGROUND_SIZE_Y;
	}
}

//----------------------
//画像描画
//----------------------
void DrawBG()
{
	//2D画像表示
	//背景画像表示
	DrawRotaGraph((int)g_bg.m_pos.x, (int)g_bg.m_pos.y,
		1.0, 0.0, g_bg.m_hndl, TRUE);

	//2毎目の背景画像、メインの背景の上に表示
	DrawRotaGraph((int)g_bg.m_pos.x, (int)(g_bg.m_pos.y- BACKGROUND_SIZE_Y),
		1.0, 0.0, g_bg.m_hndl, TRUE);
}

//終了前に行う
void ExitBG()
{
	//ハンドルが-1でなければ、何かしらロードがされているはず
	if (g_bg.m_hndl != -1)
	{
		DeleteGraph(g_bg.m_hndl);
		g_bg.m_hndl = -1;
	}
}