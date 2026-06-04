#pragma once

//定義関連---------------------------
enum tagSoung {
	BGMID_TITLE,		//タイトル画面のBGM
	BGMID_GAME,			//ゲーム本編のBGM
	SEID_EXPLOSION,		//爆発効果音

	SOUND_NUM			//BGM,SEの総数
};
//

//音楽全体の管理用構造体
typedef struct {
	int m_hndl[SOUND_NUM];
}SOUND_MANAGER;

//サウンドデータの初期化関数
void InitSound();
//サウンド読込関数
void LoadSound();
//終了前に行う必要がある処理
void ExitSound();

//音楽停止
//@soundID		:	上記 enumのどれかを渡す
void RequestSound(int soundID, int type);
//音楽停止
//@soundID		:	上記 enumのどれかを渡す
void StopSound(int soundID);
//すべての音楽停止
void StopAllSound();