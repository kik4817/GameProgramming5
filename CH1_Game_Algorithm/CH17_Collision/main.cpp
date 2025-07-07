#include <iostream>
#include <vector>
#include <cmath> // sqrt

using namespace std;

/*
* �浹 : 
* �� 
* �� 
* �� : �簢���� ����, ���
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

// ���� 1. �� �簢���� ��ġ�� "��Ĩ�ϴ�" ����� �ϰ�
// �׷��� ������ "��ġ�� �ʽ��ϴ�" ����� �ϴ� �Լ��� ������ּ���.

/*
* ��ǥ�� ���ϴ� �ڵ带 �����غ�����.
* �� ���� ������ �� ��ġ�� �ʴ��� Ȯ���� �� �ִ��� �����غ�����.
*/

/*
* AABB �浹
* Axis Aligned Bounding Box
*/

bool collisionCheck(Rectangle r1, Rectangle r2)
{
	bool x_overlap = (r1.x + r1.width >= r2.x) && (r1.x <= r2.x + r2.width);
	bool y_overlap = (r1.y + r1.height >= r2.y) && (r1.y <= r2.y + r2.height);
	
	bool isCollision = x_overlap && y_overlap;

	if (isCollision) // ��ĥ ��
	{
		cout << "��Ĩ�ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "��ġ�� �ʽ��ϴ�." << endl;
		return false;
	}
}

// ���� �浹
// Circle Collision Detection
// �� ���� ����, ������
// ���� ������ �Ÿ� (distance) d = (��Ÿ��� ���Ǹ� �̿��ؼ� ���ϼ���)
// d(<,=,>) r1 + r2; �浹�޴��� ���ߴ��� �Ǵ�.

struct Circle
{
	double x;
	double y;
	double radius;
	Circle(double _x, double _y, double _radius) : x(_x), y(_y), radius(_radius) {}
};

// Detection �Լ�, Ŭ����, � ������� �浹 üũ�� �Ұų�?

bool circleCheck(Circle c1, Circle c2)
{
	// ����
	double dx = c1.x - c2.x; // ����� ���� ������ ���ش�. Ÿ���� ������ ���� �� �־���Ѵ�.
	double dy = c1.y - c2.y;

	double distanceSq = (dx * dx) + (dy * dy);

	// ���� - ����
	//(c1.radius + c2.radius) * (c1.radius + c2.radius)

	// sqrt(distacnesq) - �������� ���� ��
	bool isCollision = sqrt(distanceSq) <= (c1.radius + c2.radius);

	if (isCollision)
	{
		cout << "��Ĩ�ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "��ġ�� �ʽ��ϴ�." << endl;
		return false;
	}
}

// CH16 DrawBox CH17�� �����ͼ� �׷����ϴ�.
// �� �簢���� ��ġ���� ������ Ȯ���� �ϰ�
// ���࿡ �� �簢���� ��ġ�� �浹�� ������Ʈ�� �׸��� ����� �ڵ带 �ۼ��غ�����.

class Bullet
{
public:
	Rectangle collider;
	bool isCollision;
	Bullet(Rectangle _col)
		: collider(_col), isCollision(false) {}

	void IsCollisionCheck(const Bullet& other)
	{		
		if (collisionCheck(collider, other.collider)) // �浹���� ��
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

	// ���� �浹 ��� ����

	Bullet bullet(r1);
	Bullet bullet2(r2);

	bullet.IsCollisionCheck(bullet2);
	
	if (bullet.isCollision)
	{
		cout << "�׸��� ������." << endl;
	}
	else
	{
		cout << "�׸��ϴ�." << endl;
	}
}