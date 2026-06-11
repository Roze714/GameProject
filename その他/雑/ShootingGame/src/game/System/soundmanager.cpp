#include"soundmanager.h"
#include<DxLib.h>

//定義関連-------------------------
//ロードする予定の音楽のパスを管理
static const char* SOUND_PATH[SOUND_NUM] = {
	"data/sound/title.mp3",			//タイトル
	"data/sound/bgm00.mp3",			//ゲーム本編
	"data/sound/se_explore.mp3",	//爆発
};
//----------------------------------

//グローバル変数を作成
SOUND_MANAGER g_soundManager;

//---------------------------------
//サウンドデータの初期化関数
//---------------------------------
void InitSound()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		g_soundManager.m_hndl[i] = -1;
	}
}
//------------------------
//サウンド読込関数
//---------------------------
void LoadSound()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (g_soundManager.m_hndl[i] == -1)
		{
			//パスは既に定義されているものをループして読み込みする
			g_soundManager.m_hndl[i] = LoadSoundMem(SOUND_PATH[i]);
		}
	}
}
//--------------------------------
//終了前に行う必要がある処理関数
//---------------------------------
void ExitSound()
{

	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (g_soundManager.m_hndl[i] != -1)
		{
			DeleteSoundMem(g_soundManager.m_hndl[i]);
			g_soundManager.m_hndl[i]= -1;
		}
	}
}

//-----------------
//音楽再生
//----------------
void RequestSound(int soundID, int type)
{
	PlaySoundMem(g_soundManager.m_hndl[soundID],type);
}

//----------------
//音楽停止
//----------------
void StopSound(int soundID)
{
	StopSoundMem(g_soundManager.m_hndl[soundID]);
}

//------------------
//すべての音楽停止
//-------------------
void StopAllSound()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		StopSound(i);
	}
}