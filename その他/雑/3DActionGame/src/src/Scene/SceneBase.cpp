#include"SceneBase.h"
#include"PlayScene.h"
#include"SceneTitle.h"
#include"SceneResult.h"
#include"../System/SoundManager.h"

//----------------------
//コンストラクタ
//----------------------
SceneBase::SceneBase()
{
	Init();

}


//----------------------
//デストラクタ
//----------------------

SceneBase::~SceneBase()
{
	Exit();
}
//----------------------
//毎フレーム呼ぶ処理
//----------------------
int SceneBase::Loop()
{
	int result = -1;

	switch (m_State)
	{
	case INIT:
		Init();

		m_State = LOAD;
		break;
	case LOAD:
		Load();

		m_State = MAIN;
		break;
	case MAIN:
		Step();
		break;
	case END:
		Exit();

		m_State = INIT;
		result = 0;
		break;
	}


	return result;
}

//描画
void  SceneBase::Draw()
{

}
//初期化
void  SceneBase::Init()
{


}
//読み込み
void  SceneBase::Load()
{

}
//毎フレーム呼ぶ処理
void  SceneBase::Step()
{

}
//終了処理
void  SceneBase::Exit()
{

}

