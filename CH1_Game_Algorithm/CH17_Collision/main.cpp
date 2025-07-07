#include <iostream>
#include <vector>
#include <cmath> // sqrt

using namespace std;

/*
* 충돌 : 
* 점 
* 선 
* 면 : 사각형의 넓이, 경계
* bounding box
*/

struct Rectangle
{
	int x;
	int y;
	int width;
	int height;
	Rectangle(int _x, int _y, int _width, int _height)
		: x(_x), y(_y), width(_width), height(_height) {}
};

// 문제 1. 두 사각형이 겹치면 "겹칩니다" 출력을 하고
// 그렇지 않으면 "겹치지 않습니다" 출력을 하는 함수를 만들어주세요.

/*
* 좌표를 비교하는 코드를 구현해보세요.
* 몇 개를 비교했을 때 겹치지 않는지 확인할 수 있는지 생각해보세요.
*/

/*
* AABB 충돌
* Axis Aligned Bounding Box
*/

bool collisionCheck(Rectangle r1, Rectangle r2)
{
	bool x_overlap = (r1.x + r1.width >= r2.x) && (r1.x <= r2.x + r2.width);
	bool y_overlap = (r1.y + r1.height >= r2.y) && (r1.y <= r2.y + r2.height);
	
	bool isCollision = x_overlap && y_overlap;

	if (isCollision) // 켭칠 때
	{
		cout << "겹칩니다." << endl;
		return true;
	}
	else
	{
		cout << "겹치지 않습니다." << endl;
		return false;
	}
}

// 구형 충돌
// Circle Collision Detection
// 두 원의 원점, 반지름
// 원점 사이의 거리 (distance) d = (피타고라스 정의를 이요해서 구하세요)
// d(<,=,>) r1 + r2; 충돌햇는지 안했는지 판단.

struct Circle
{
	double x;
	double y;
	double radius;
	Circle(double _x, double _y, double _radius) : x(_x), y(_y), radius(_radius) {}
};

// Detection 함수, 클래스, 어떤 방식으로 충돌 체크를 할거냐?

bool circleCheck(Circle c1, Circle c2)
{
	// 조건
	double dx = c1.x - c2.x; // 고로의 길이 제곱을 해준다. 타잎이 음수가 사용될 수 있어야한다.
	double dy = c1.y - c2.y;

	double distanceSq = (dx * dx) + (dy * dy);

	// 제곱 - 제곱
	//(c1.radius + c2.radius) * (c1.radius + c2.radius)

	// sqrt(distacnesq) - 제곱안한 수를 비교
	bool isCollision = sqrt(distanceSq) <= (c1.radius + c2.radius);

	if (isCollision)
	{
		cout << "겹칩니다." << endl;
		return true;
	}
	else
	{
		cout << "겹치지 않습니다." << endl;
		return false;
	}
}

// CH16 DrawBox CH17에 가져와서 그려봅니다.
// 두 사각형이 겹치는지 눈으로 확인을 하고
// 만약에 두 사각형이 겹치면 충돌한 오브젝트를 그리지 말라고 코드를 작성해보세요.

class Bullet
{
public:
	Rectangle collider;
	bool isCollision;
	Bullet(Rectangle _col)
		: collider(_col), isCollision(false) {}

	void IsCollisionCheck(const Bullet& other)
	{		
		if (collisionCheck(collider, other.collider)) // 충돌했을 때
		{
			isCollision = true;
		}
		else
		{
			isCollision = false;
		}
	}
};

int main()
{
	Rectangle r1(3,3,6,6);
	Rectangle r2(15,3,4,4);
	collisionCheck(r1,r2);

	Circle c1(1, 1, 3);
	Circle c2(5, 5, 2);
	circleCheck(c1, c2);

	// 게임 충돌 사용 예시

	Bullet bullet(r1);
	Bullet bullet2(r2);

	bullet.IsCollisionCheck(bullet2);
	
	if (bullet.isCollision)
	{
		cout << "그리지 마세요." << endl;
	}
	else
	{
		cout << "그립니다." << endl;
	}
}