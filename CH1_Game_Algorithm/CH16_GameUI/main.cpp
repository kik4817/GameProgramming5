/*
* 콘솔 창 색을 변경하는 기능들
* ANSI ESCAPE 문자의 색을 변경하는 기능을 만들어봅니다.
*/

#include <iostream>
#include <Windows.h>
#include <queue>
#include <string>
#include "InventoryDP.h"

using namespace std;

/*
* 목표 : 숫자로 표기를 하는 것이 아니라, 사람이 알아보기 쉽도록 클래스 만들자.
* Helper 클래스 
* ex) Color::White, Color::BG_White, Color::UnderLine
*/

// 30~39 글자색, 40~44 배경색

class Color
{
public:
	static const string RESET;
	static const string UNDERLINE;

	static const string BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE;

	static const string BG_BLACK,BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE;

	static void Print(const string& BG, const string& textColor, const string& message)
	{
		cout << BG << textColor << message << Color::RESET;
	}
};

const string Color::RESET = "\33[0m";

const string Color::UNDERLINE = "\33[4m";

const string Color::BLACK = "\33[30m";
const string Color::RED = "\33[31m";
const string Color::GREEN = "\33[32m";
const string Color::YELLOW = "\33[33m";
const string Color::BLUE = "\33[34m";
const string Color::MAGENTA = "\33[35m";
const string Color::CYAN = "\33[36m";
const string Color::WHITE = "\33[37m";

const string Color::BG_BLACK = "\33[40m";
const string Color::BG_RED = "\33[41m";
const string Color::BG_GREEN = "\33[42m";
const string Color::BG_YELLOW = "\33[43m";
const string Color::BG_BLUE = "\33[44m";
const string Color::BG_MAGENTA = "\33[45m";
const string Color::BG_CYAN = "\33[46m";
const string Color::BG_WHITE = "\33[47m";

void ExampleColor()
{
	cout << "색 넣기" << endl;
	cout << "\033[30m" << "글자" << "\033[0m" << endl; // 글자 검정
	cout << "\033[31m" << "글자" << "\033[0m" << endl; // 글자 빨강
	cout << "\033[32m" << "글자" << "\033[0m" << endl; // 글자 초록
	cout << "\033[33m" << "글자" << "\033[0m" << endl; // 글자 노랑
	cout << "\033[34m" << "글자" << "\033[0m" << endl; // 글자 파랑 
	cout << "\033[35m" << "글자" << "\033[0m" << endl; // 글자 보라
	cout << "\033[36m" << "글자" << "\033[0m" << endl; // 글자 하늘
	cout << "\033[37m" << "글자" << "\033[0m" << endl; // 글자 흰색

	cout << "\033[40m" << "글자" << "\033[0m" << endl; // 글자 검정
	cout << "\033[41m" << "글자" << "\033[0m" << endl; // 배경 빨강
	cout << "\033[42m" << "글자" << "\033[0m" << endl; // 배경 초록
	cout << "\033[43m" << "글자" << "\033[0m" << endl; // 배경 노랑
	cout << "\033[44m" << "글자" << "\033[0m" << endl; // 배경 파랑
	cout << "\033[45m" << "글자" << "\033[0m" << endl; // 배경 보라
	cout << "\033[46m" << "글자" << "\033[0m" << endl; // 배경 하늘
	cout << "\033[47m" << "글자" << "\033[0m" << endl; // 배경 흰색

	cout << "\033[4m" << "글자" << "\033[0m" << endl; // 밑줄

	cout << endl;
}

void Printmenu()
{
	cout << "==== 메뉴 ====" << endl;
	
	cout << Color::BG_CYAN<<"1." << Color::MAGENTA << "새로운 게임" << Color::RESET << endl;
	cout << Color::BG_BLUE << Color::RED << "2." << Color::RESET << Color::BG_RED << "불러오기" << Color::RESET << endl;
	//cout << "3." << "설정" << endl;
	Color::Print(Color::BG_GREEN, Color::BLACK, "3.설정");
	cout << endl;
	cout << "4." << "종료" << endl;
}

void PrintProgressBar(int current, int total, int width = 30)
{
	float progress = (float)current / total;
	int filled = (int)(width * progress);

	for (int i = 0; i < filled;i++)
	{
		cout << Color::GREEN << "▶";
	}

	for (int i = filled; i < width; i++)
	{
		cout << Color::WHITE << "▷";
	}

	cout << Color::RESET << (int)(progress * 100)<<"%";
}

void LoadingAnimation()
{
	const int total = 20;
	const int width = 20;

	cout << "로딩 진행 현황을 그려준다." << endl;
	for (int i = 0;i < total;i++) // i<=total -> 100%
	{
		system("cls");
		PrintProgressBar(i, total, width);
		cout << endl;		
		cout.flush();
		Sleep(50);		
	}

	// vector자료구조에 진행현황을 그림으로 저장을 했다가 갱신을 하는 방식. 
}

/*
* gotoXY(int x, int y)
*/

void gotoXY(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*
* DrawBox를 내가 원하는 좌표에 그릴 수 이ㅆ도록 아래 함수를 수정해보세요 
* gotoXY를 이용하세요. 탑, 몸통, 바디
*/

void DrawBox(int width, int height) // 가로, 세로
{	

	// 머리
	cout << Color::BG_CYAN << "+";
	//-------
	for (int i = 0; i < width;i++)
	{
		cout << "-";
	}
	cout << "+"<<Color::RESET << endl;

	// 바디
	for (int y = 0;y < height;y++)
	{
		// 왼쪽 벽
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");

		// 공백
		for (int i = 0; i < width;i++)
		{
			cout << " ";
		}

		// 오른쪽 벽
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");
		cout << endl;
	}
	
	// 마지막	
	cout << Color::BG_CYAN << "+";
	//-------
	for (int i = 0; i < width;i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;
}

void DrawBox(int px, int py, int width, int height, const ItemW& item)
{
	/*
	* 상자는 위, 중간, 아래 부분으로 구분이 됩니다.
	* 반복문을 이요해서 표현해보세요.
	*/

	// 머리
	gotoXY(px, py);
	cout << Color::BG_CYAN << "+";
	//-------
	for (int i = 0; i < width;i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;

	// 중간	
	for (int y = 0;y < height;y++) 
	{
		gotoXY(px, py + 1 + y); // py+=1			py + 1 + y
		// 왼쪽 벽
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");

		// item의 정보를 출력
		string content = "";

		if (y == 1)
		{
			content = "이름 : " + item.GetName();
		}
		else if (y == 2)
		{
			content = "무게 : " + to_string(item.GetWeight());
		}
		else if (y == 3)
		{
			content = "가치 : " + to_string(item.GetValue());
		}

		if (!content.empty())
		{
			cout << Color::CYAN << content << Color::RESET;

			for (int i = content.length();i < width;i++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int i = 0;i < width;i++)
			{
				cout << " ";
			}
		}

		// 공백
		for (int i = 0; i < width;i++)
		{
			cout << "";
		}

		// 오른쪽 벽
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");
		cout << endl;
	}

	// 마지막
	gotoXY(px, py + height + 1); // py+=1		py + height + 1
	cout << Color::BG_CYAN << "+";
	//-------
	for (int i = 0; i < width;i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;
}

void Test(const ItemW& item)
{
	cout << item.GetName() << endl;
}

void ProcedualDrawBox(int startX, int startY, vector<ItemW>& items)
{
	queue<ItemW> itemQueue;

	//itemQueue.push(ItemW("롱소드", 80, 50));
	//itemQueue.push(ItemW("숏소드", 20, 18));
	//itemQueue.push(ItemW("나이프", 5, 2));
	//itemQueue.push(ItemW("롱소드", 80, 50));
	//itemQueue.push(ItemW("숏소드", 20, 18));
	//itemQueue.push(ItemW("나이프", 5, 2));	
	//itemQueue.push(ItemW("롱소드", 80, 50));
	//itemQueue.push(ItemW("숏소드", 20, 18));
	//itemQueue.push(ItemW("나이프", 5, 2));

	for (auto& Item : items)
	{
		itemQueue.push(Item);
	}

	// ctrl + r + r
	int currentRow = 0; // 현제 그려야할 도형의 x좌표
	int currentCol = 0; // 현제 그려야할 도형의 y좌표

	const int Box_Width = 20;
	const int Box_Height = 10;
	const int Box_RowSpacing = 5;
	const int Box_ColSpacing = 5;

	while (!itemQueue.empty())
	{
		ItemW currentItem = itemQueue.front();
		itemQueue.pop();
		Test(currentItem);
		// ItemW 타입을 사용하는 함수를 만들어보세요.

		int boxX = startX + (currentRow * (Box_RowSpacing + Box_Width));
		int boxY = startY + (currentCol * (Box_ColSpacing + Box_Height));

		// 좌표를 수정해주는 코드를 작성하세요. 3*3 박스로 아이템 그려지도록 코드를 만들어보세요.

		
		DrawBox(boxX, boxY, Box_Width, Box_Height, currentItem);

		currentRow++;
		if (currentRow >= 3)
		{
			currentRow = 0;
			currentCol++;
		}

		Sleep(100);
	}
}

int main()
{
	//ExampleColor();


	// 노란색 글자에 밑줄이 그어진 문자
	cout << Color::BG_BLUE << Color::GREEN << "==== TITLE ====" << Color::RESET << endl;
	
	Color::Print(Color::BG_BLUE, Color::GREEN, "==== TITLE2 ====");
	cout << endl;

	// 로딩바, 메뉴 표시, UI표현

	Printmenu();

	// 제목 Color클래스를 사용해서
	// 1. 게임 시작
	// 2. 게임 설정
	//LoadingAnimation();
	system("cls");

	//ItemW item("롱소드", 10, 10);
	//	
	//for (int i = 0; i < 3;i++)
	//{
	//	DrawBox(5+25*i, 8, 20, 10, item);

	//}
	//
	//// 가로 세로
	//// 어떤 좌표 작성 겹치지 않고 그릴 수 있는지
	////DrawBox(28,8, 20,10);

	InventoryM inventory(7);

	// 6,4,3,5
	ItemW A("A", 6, 13);
	ItemW B("B", 4, 8);
	ItemW C("C", 3, 6);
	ItemW D("D", 5, 12);

	std::vector<ItemW> selectableTable{ A,B,C,D };

	std::pair<int, std::vector<ItemW>> bestItem = inventory.findBestItem(7, selectableTable);
	//auto bestItem = inventory.findBestItem(7, selectableTable);

	std::cout << "주어진 아이템의 최대 가치 : " << bestItem.first << std::endl;

	std::vector<ItemW> ItemC = bestItem.second;

	ProcedualDrawBox(5,5, ItemC);
	
}