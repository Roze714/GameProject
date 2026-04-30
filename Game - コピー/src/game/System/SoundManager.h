#pragma once
#include<DxLib.h>
#include<vector>
using namespace std;


//BGM・SEを管理するクラス
class SoundManager
{
public:
	enum tagID{
		BGM_GAME,		//BGMゲーム本編
		SE_PESHOT,		//SEプレイヤーの弾
		SE_EXPLOSION,	//SE爆発音

		SOUND_NUM
	};



private:
	static vector<int> m_hndl;		//音楽ハンドル


public:
	


	//初期化
	static void Init();

	//ロード
	static void Load();

	//終了
	static void Exit();

	//音楽再生
	//id		再生する音楽
	//type		DX_PLAYTYPE_BACK=1回再生
	//			DX_PLAYTYPE_LOOP=繰り返し再生
	//isStart	true＝最初から再生，false=途中から再生
	//
	static bool Play(tagID id,
		int type = DX_PLAYTYPE_BACK, bool isStart = true);

	//音楽を再生中か
	static bool IsPlay(tagID id);
		
	//音楽停止
	static int Stop(tagID id);

	//全音楽停止
	static void StopAll();


	
};



