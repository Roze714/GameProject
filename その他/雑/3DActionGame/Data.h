#pragma once

class Data
{
public:
	Data() { m_score = 0; }
	~Data(){}

	//スコア操作
	static int GetScora() { return m_score; };
	static void SetScora(int scora) { m_score = scora; }
	static void AddScora(int scora) { m_score += scora; }

private:
	static int m_score;		//ゲームスコア

};
int Data::m_score;


//Data::Data()
//{
//}
//
//Data::~Data()
//{
//}