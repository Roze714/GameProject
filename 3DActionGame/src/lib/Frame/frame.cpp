#include <DxLib.h>
#include "Frame.h"

static const int FRAME_RATE = 60;									//1秒辺りのフレーム数
static const int FRAME_RATE_MILLI_SECOND = 1000 / FRAME_RATE;		//何ミリ秒で1フレームか


double	FrameRate::m_frameRate;
int		FrameRate::m_count;
int		FrameRate::m_updateFrameRateTime;
int		FrameRate::m_currentTime;
int		FrameRate::m_lastTime;


 //-------------------------------------
 //		フレームレート初期化
 //-------------------------------------
 void FrameRate::Init()
 {
	 // データを初期化しておく
	 m_count = 0;
	 m_frameRate = 0.0;
	 m_currentTime = GetNowCount();
	 m_lastTime = m_currentTime;	//とりあえず同じ値を格納
	 m_updateFrameRateTime = m_currentTime;
 }
 //-------------------------------------
 //		フレームを進めていいか判断
 //-------------------------------------
 bool FrameRate::CheckNext()
 {
	 // 現在の時間を取得する
	 m_currentTime = GetNowCount();
	 // 前回の次回から今回までの差分を計算
	 int difTime = m_currentTime - m_lastTime;

	 // 前回の時間から指定フレーム分経過しているかチェック
	 if (difTime >= FRAME_RATE_MILLI_SECOND)return true;
	 else return false;
 }
 //-------------------------------------
 //		フレームレート計算
 //-------------------------------------
 void FrameRate::Calc()
 {
	 // 前回の時間を更新
	 m_lastTime = m_currentTime;
 }
//-------------------------------------
//		FPS表示
//-------------------------------------
 void FrameRate::PrintFps()
 {
	 // 1フレーム進んだと判断
	 m_count++;
	 // 前回の表示時間から今回までの差分を計算
	 int difTime = m_currentTime - m_updateFrameRateTime;

	 // 1描画経過するまで経過はこれ以降実行しない
	 if (difTime>=1000)
	 {
		 float frameCut = (float)(m_count * 1000);
		 //	フレームレートを計算
		 m_frameRate = frameCut / difTime;
		 //	カウント初期化
		 m_count = 0;
		 // フレームレート更新時間を最新に
		 m_updateFrameRateTime = m_currentTime;
	 }

	 //FPSは常に表示を続ける
	 DrawFormatString(1000, 16, GetColor(0, 255, 255),
		"FPS:%21f", m_frameRate);
 }

