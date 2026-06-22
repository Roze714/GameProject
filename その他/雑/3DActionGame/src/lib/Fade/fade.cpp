#include"fade.h"
#include<DxLib.h>

//定義関連-----------------------
#define FADE_SPEED	(10)		//
#define FADE_SIZE_X	(640.0f)	//画像サイズ(横)
#define FADE_SIZE_Y	(480.0f)	//画像サイズ(縦)
//-------------------------------

Fade::Fade()
{
	InitFade();
}

Fade::~Fade()
{
}

//---------------------
//フェードの初期化
//---------------------
void Fade::InitFade()
{
	g_fade.m_state = FADE_NON;
	g_fade.m_count = 0;
}

//---------------------
//フェード処理更新
//---------------------
void Fade::UpdateFade()
{
	switch (g_fade.m_state)
	{
	case FADE_IN:
		//徐々に数字を減らして明るくする
		g_fade.m_count -= FADE_SPEED;
		if (g_fade.m_count <= 0)
		{
			g_fade.m_count = 0;
			g_fade.m_state = FADE_NON;
		}
		break;
	case FADE_OUT:
		//徐々に数字を増やして暗くする
		g_fade.m_count += FADE_SPEED;
		if (g_fade.m_count >= 255)
		{
			g_fade.m_count = 255;
			g_fade.m_state = FADE_OUT_WAIT;
		}
		break;
	}
}

//---------------------
//フェード用の画像描画
//---------------------
void Fade::DrawFade()
{
	switch (g_fade.m_state)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		//まずはここでアルファ値をセットする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, g_fade.m_count);

		//フェード用の黒い四角を表示
		DrawBox(0, 0, FADE_SIZE_X, FADE_SIZE_Y,
			GetColor(0, 0, 0), TRUE);
		
		//ほかの画像に影響を出さないよう、初期設定に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	}
}


//フェードインリクエスト
void Fade::RequestFadeIn()
{
	//徐々に明るくするので、最初はMAXに
	g_fade.m_count = 255;
	g_fade.m_state = FADE_IN;
}

//フェードアウトリクエスト
void Fade::RequestFadeOut()
{
	//徐々に暗くするので、最初は透明の0に
	g_fade.m_count = 0;
	g_fade.m_state = FADE_OUT;
}

//フェードインが終了したか
bool Fade::IsEndFadeIn()
{
	//フェードイン時はまだやっている
	if (g_fade.m_state == FADE_IN)
	{
		return false;
	}
	//他はすべて少なくともフェードインではない
	else return true;
}

//フェードアウトが終了したか
bool Fade::IsEndFadeOut()
{
	//フェードアウト時はまだやっている
	if (g_fade.m_state == FADE_OUT)
	{
		return false;
	}
	//他はすべて少なくともフェードアウトではない
	else return true;
}

