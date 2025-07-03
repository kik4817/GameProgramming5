/*
* 콘솔 창 색을 변경하는 기능들
* ANSI ESCAPE 문자의 색을 변경하는 기능을 만들어봅니다.
*/

#include <iostream>
#include <Windows.h>

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
		cout << BG << textColor << message << Color::RESET << endl;
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
	cout << "로딩 진행 현황을 그려준다." << endl;
	for (int i = 0;i < 20;i++)
	{
		PrintProgressBar(i, 20);
		cout << endl;		
		cout.flush();
		Sleep(100);
		system("cls");
	}

	// vector자료구조에 진행현황을 그림으로 저장을 했다가 갱신을 하는 방식. 
}

void DrawBox()
{
	/*
	* 상자는 위, 중간, 아래 부분으로 구분이 됩니다.
	* 반복문을 이요해서 표현해보세요.
	*/
	cout << Color::BG_CYAN<<"+----------+"<< Color::RESET << endl;
	cout << Color::BG_CYAN<<"|"<< Color::RESET<< "          " << Color::BG_CYAN << "|" << Color::RESET<<endl;
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << "           ";
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << endl;
	
	cout << Color::BG_CYAN<<"+----------+"<< Color::RESET << endl;
}

int main()
{
	//ExampleColor();

	//LoadingAnimation();

	// 노란색 글자에 밑줄이 그어진 문자
	cout << Color::BG_BLUE << Color::GREEN << "==== TITLE ====" << Color::RESET << endl;
	
	Color::Print(Color::BG_BLUE, Color::GREEN, "==== TITLE2 ====");

	// 로딩바, 메뉴 표시, UI표현

	Printmenu();

	// 제목 Color클래스를 사용해서
	// 1. 게임 시작
	// 2. 게임 설정

	DrawBox();
}