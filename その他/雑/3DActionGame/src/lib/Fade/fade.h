#pragma once

class Fade
{
public:
	
//フェードの各種の状態
	enum tagFadeState {
		FADE_NON,		//フェードなし
		FADE_IN,		//フェードイン中(徐々に画面が出現)
		FADE_OUT,		//フェードアウト中(徐々に画面が消える)
		FADE_OUT_WAIT,	//フェードアウト後の真っ暗状態
	};

	//フェード処理用構造体
	typedef struct {
		tagFadeState m_state;		//現在のフェード状況
		int m_count;				//フェード時間のカウント
	}FADE_DATA;

	FADE_DATA g_fade;


	//コンストラクタ・デストラクタ
	Fade();
	~Fade();

private:
//　フェードの初期化
void InitFade();
//　フェード処理関数
void UpdateFade();
//　フェード用の画像描画
void DrawFade();

//フェードインリクエスト
void RequestFadeIn();
//フェードアウトリクエスト
void RequestFadeOut();
//フェードインが終了したか
bool IsEndFadeIn();
//フェードアウトが終了したか
bool IsEndFadeOut();

};







