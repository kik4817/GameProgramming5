/*
* 게임에서 위치를 표현하는 방법 (20)
* map 2차원 배열.
* 미로 찾기 (maze), AI 존재 탈추구 까지 이동하는 코드를 작성하세요.
*/

#include <iostream>
#include <vector>
#include <windows.h>

#define SIZE 10

// 0 : 이동할 수 있는 공간, 1 : 벽
// 입구를 (x,y) = (1,0)
// 출구를 (x,y) = (9,5)
int maze[SIZE][SIZE] =
{
	{1,0,1,0,0,0,0,1,0,0},
	{1,0,1,0,0,1,0,1,0,0},
	{1,0,1,0,0,1,0,1,1,0},
	{1,0,1,1,1,1,0,0,0,0},
	{1,0,0,1,0,0,0,0,0,0},
	{1,0,0,1,0,1,0,1,1,0},
	{1,0,1,1,0,1,0,0,1,0},
	{1,0,0,0,0,1,0,0,1,0},
	{1,0,1,1,1,0,0,0,1,0},
	{1,0,1,0,0,0,0,0,1,0}
};
// maze[y][x] 의 값이 0이면 '  ' ■

// 방향 (상,하,좌,우)
// 상 : x의 변화? 0, y의 변화? -1
// 하 : x의 변화? 0, y의 변화? 1
// 좌 : x -1, y 1

const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

struct Monster
{
	int x, y;
	int prev_x, prev_y;
	int step;
	std::vector<int> direction;

	Monster() = default;
	Monster(int x, int y, std::vector<int> direction) : x(x), y(y), direction(direction) 
	{
		prev_x = x;
		prev_y = y;
		step = 0;
	}
};

void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	// 이중 반복문을 사용해보세요
	for (int y = 0;y < SIZE;y++)
	{
		for (int x = 0;x < SIZE;x++)
		{
			if (maze[y][x] == 0)
			{
				std::cout << " ";
			}
			else if (maze[y][x] == 1)
			{
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}

#pragma region 이동할 길을 만들어 둔다.

	//std::vector<int> direction = { 1,1,1,1,1,1,1,3,3,3,0,0,0,3,3,3,3 };
	//int sx = 1; int sy = 0;
	//GoToXY(sx, sy);
	//std::cout << "M";

	//// direction 숫자를 받아와서 GotoXY의 좌표를 변경해보세요

	//int pre_x = sx;
	//int pre_y = sy;

	//for (int i = 0;i < direction.size();i++)
	//{
	//	// 잔상이 남는 현상을 래결해보세요 system("cls")
	//	// pre_x, pre_y; 이전 위치값을 저장하고, 이전 위치를 빈 공간으로 그리는 코드
	//	// std::cout<<"  "

	//	GoToXY(pre_x, pre_y);
	//	std::wcout << " ";

	//	int dir = direction[i];
	//	sx += dx[dir];
	//	sy += dy[dir];
	//	pre_x = sx;
	//	pre_y = sy;
	//	GoToXY(sx, sy);
	//	std::cout << "M";
	//	Sleep(500);
	//}
#pragma endregion

#pragma region 길을 따라 이동하는 몬스터
// 1. 정해진 깅르 따라 몬스터가 차례대로 나오는 코드를 작성해보세요

// vector<int> path = {} // 위의 direction과 같다
	std::vector<int> path = { 1,1,1,1,1,1,1,3,3,3,0,0,0,3,3,3,3 };
	int monster_count = 5;
	int interval = 2;
	int steps = path.size() + monster_count; // 전체 몬스터의 이동 거리
	int sx = 1; int sy = 0;

	std::vector<Monster> monsters;

	for(int i =0;i<steps;i++) // 몬스터의 시작과 방향
	{
		if (i % interval == 0 && monsters.size()<monster_count)
		{
			monsters.emplace_back(sx, sy, path);
		}
	}	

	GoToXY(sx, sy);
	std::cout << "M";

	// direction 숫자를 받아와서 GotoXY의 좌표를 변경해보세요

	int pre_x = sx;
	int pre_y = sy;

	for (int i = 0; i < monsters.size();i++)
	{
		Monster& monster = monsters[i];

		if (monster.step >= monster.direction.size()) continue;
		// 잔상이 남는 현상을 래결해보세요 system("cls")
		// pre_x, pre_y; 이전 위치값을 저장하고, 이전 위치를 빈 공간으로 그리는 코드
		// std::cout<<"  "

		GoToXY(monster.prev_x, monster.prev_y);
		std::wcout << " ";

		int dir = monster.direction[monster.step];
		monster.x += dx[dir];
		monster.y += dy[dir];
		monster.prev_x = monster.x;
		monster.prev_y = monster.y;
		monster.step++;

		GoToXY(monster.x, monster.y);
		std::cout << "M";
		Sleep(500);
	}

// 2. 여러가지 몬스터가 각자의 방향으로 움직이는 코드를 작성해보세요


// 3. 맵에 따라서 도착지점을 자동으로 찾아주는 코드를 작성하기(길찾기 문제 DFS, BFS)

#pragma endregion

}

