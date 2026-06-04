#include"collision.h"

//----------------------------
//点と四角の当たり判定
//----------------------------
bool CheckHitDotToSquare(VECTOR dotPos, VECTOR squarePos,
	int width, int height)
{
	//四角形の上下左右それぞれの座標を計算する
	float up = squarePos.y - height * 0.5f;
	float down = squarePos.y + height * 0.5f;
	float left = squarePos.x - width * 0.5f;
	float right = squarePos.x + height * 0.5f;

	//4つの端をそれぞれチェックして、すべての条件を満たしたらヒット!
	if (dotPos.x >= left && dotPos.x <= right
		&& dotPos.y >= up && dotPos.y <= down)
	{
		return true;
	}
	else return false;
}


bool CheckHitCircleToCircle(VECTOR dotPos, VECTOR squarePos,
	int width, int height)
{
	//四角形の上下左右それぞれの座標を計算する
	float up = squarePos.y - height * 0.5f;
	float down = squarePos.y + height * 0.5f;
	float left = squarePos.x - width * 0.5f;
	float right = squarePos.x + height * 0.5f;

	//4つの端をそれぞれチェックして、すべての条件を満たしたらヒット!
	if (dotPos.x >= left && dotPos.x <= right
		&& dotPos.y >= up && dotPos.y <= down)
	{
		return true;
	}
	else return false;
}