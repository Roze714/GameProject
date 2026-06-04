#include<DxLib.h>
#include "../../game/Enemy/enemy.h"

//これも追加しておくと、フレームレート事態の変更が可能になる
#define FRAME_RATE (60)								//1秒あたりのフレーム数
#define FRAME_RATE_MILLI_SECOND (1000/FRAME_RATE)	//何ミリ秒で1フレームか

extern ENEMY_MANAGER g_enemyManager;


//FPSを表示するのにしようとするデータがまとまった構造体
typedef struct {
	double m_frameRate;		//実際のFPS
	int m_nowTime;			//現在にPC時間
	int m_prevTime;			//1秒前のPC時間
	int m_prevDrawTime;		//1秒前の描画したPC時間
	int m_count;			//カウント用
} FpsData;

//ゲーム中ずっと使うので、グローバル変数を作成
static FpsData g_fps = { 0.0 };



void InitFps()
{
	//基本的に0で初期化
	g_fps.m_frameRate = 0.0f;
	g_fps.m_nowTime = 0;
	//ここで現在カウントを取得しておく
	g_fps.m_prevTime=g_fps.m_prevDrawTime=GetNowCount();
	g_fps.m_count = 0;
}

//-----------------------
//次のフレームに進めていいか
//------------------------
bool IsNextFrame()
{
	//最新の時間を取得し、更新する
	g_fps.m_nowTime = GetNowCount();
	//前回の時間から今回までの差分を計算
	int difTime = g_fps.m_nowTime - g_fps.m_prevTime;

	//前回の時間から指定したフレーム分、時間が経過したかチェック
	if (difTime >= FRAME_RATE_MILLI_SECOND)
	{
		return true;
	}
	else return false;
}

//-----------------
//FPS表示関数
//-----------------
void StepFps()
{
	//ここまで来たら時間を更新
	g_fps.m_prevTime = g_fps.m_nowTime;
}

//-----------------
//FPS表示関数
//-----------------
void PrintFps(void)
{
	//まずカウントを増やす
	g_fps.m_count++;
	//最新の時間を取得
	int difTime = g_fps.m_nowTime - g_fps.m_prevDrawTime;
	
	//1秒ごとにフレームレートを再計算
	if (difTime >= 1000)
	{
		//カウントは60,000になっているのが理想
		float frameCount = (float)(g_fps.m_count * 1000);
		//表示する	fpsを更新
		g_fps.m_frameRate = frameCount / difTime;
		//カウントは０に初期化
		g_fps.m_count = 0;
		//ひとつ前の時間を更新
		g_fps.m_prevDrawTime = g_fps.m_nowTime;
	}


	//FPSは常に表示を続ける
	DrawFormatString(16, 16, GetColor(255, 0, 0), "FPS:%.21f", g_fps.m_frameRate);
	DrawFormatString(16, 42, GetColor(255, 0, 0), "%f", g_enemyManager.m_waitCount / 60);
	////　文字の表示　引数は「横の位置」「縦の位置」「色」「文字」
	//DrawFormatString(32, 32, GetColor(255, 0, 0), "%f", g_fps.m_frameRate);

}



