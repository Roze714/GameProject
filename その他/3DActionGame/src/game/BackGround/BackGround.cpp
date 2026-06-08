#include "background.h"



//定義関数--------------------------------
#define BACKGROUND_SIZE_X (640.0f)
#define BACKGROUND_SIZE_Y (480.0f)
#define MOVE_SPEED (3.0f);
//背景のイラストパス
static const char BACKGROUND_ILLUSTRATION_PATH[] =
{ "data/Image/game/background00.jpg" };

//----------------------------------------

//コンストラクタ
CBackGround::CBackGround()
{
	Init();
}

//デストラクタ
CBackGround::~CBackGround()
{
}



//----------------
//データの初期化
//---------------
void CBackGround::Init()
{
	m_Hndl = -1;
	m_Pos.x =BACKGROUND_SIZE_X	* 0.5f;
	m_Pos.y =BACKGROUND_SIZE_Y * 0.5f;
}

//画像データをロード
void CBackGround::Load()
{
	if (m_Hndl == -1)
	{
		m_Hndl = LoadGraph(BACKGROUND_ILLUSTRATION_PATH);
	}
}

//----------------------------------
//背景データの毎フレーム更新処理関数
//----------------------------------
void CBackGround::Step()
{

	//背景の座標を毎フレーム下に移動させる
	m_Pos.y += MOVE_SPEED;

	//画像が特定の場所よりも下に来たら、画面サイズ分戻してやる
	if (m_Pos.y >= BACKGROUND_SIZE_Y * 0.5 + BACKGROUND_SIZE_Y)
	{
		//画像1枚分元に戻す
		m_Pos.y -= BACKGROUND_SIZE_Y;
	}
}

//----------------------
//画像描画
//----------------------
void CBackGround::Draw()
{
	//2D画像表示
	//背景画像表示
	DrawRotaGraph((int)m_Pos.x, (int)m_Pos.y,
		1.0, 0.0, m_Hndl, TRUE);

	//2毎目の背景画像、メインの背景の上に表示
	DrawRotaGraph((int)m_Pos.x, (int)(m_Pos.y- BACKGROUND_SIZE_Y),
		1.0, 0.0, m_Hndl, TRUE);
}

//終了前に行う
void CBackGround::Exit()
{
	//ハンドルが-1でなければ、何かしらロードがされているはず
	if (m_Hndl != -1)
	{
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}
}