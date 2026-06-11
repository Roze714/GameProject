#include"scene.h"
#include"scenegame.h"
#include"scenetitle.h"
#include"../../lib/Fade/fade.h"
#include"sceneresult.h"


enum tagScene {
	SCENE_TITLE,	//タイトル画面
	SCENE_GAME,		//ゲーム本編
	SCENE_RESULT,	//リザルト画面
	SCENE_NUM
};



typedef struct {
	tagScene m_state;			//現在のシーン番号管理
}SCENE_DATA;

//グローバル変数を作成
static SCENE_DATA g_scene;

//--------------------
//データの初期化
//---------------------
void InitScene()
{
	g_scene.m_state = SCENE_TITLE;

	InitTitle();
	InitGame();
	
}
 

int StepScene()
{
	int ret = 0;

	switch (g_scene.m_state)
	{
	case SCENE_TITLE:
		
		if (StepTitle() == 1)
		{
			g_scene.m_state = SCENE_GAME;
		}
		break;
	case SCENE_GAME:
		
		if (StepGame() != 0)
		{
			g_scene.m_state = SCENE_RESULT;
		}
		break;
	case SCENE_RESULT:
		if (StepResult() != 0)
		{
			g_scene.m_state = SCENE_TITLE;
		}

		break;
	}

	
	UpdateFade();




	return ret;

}

void DrawScene()
{
	switch (g_scene.m_state)
	{
	case SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE_GAME:
		DrawGame();
		break;

	case SCENE_RESULT:
		DrawResult();
		break;

		
	}
	DrawFade();
}