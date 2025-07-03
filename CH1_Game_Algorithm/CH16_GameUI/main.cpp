/*
* �ܼ� â ���� �����ϴ� ��ɵ�
* ANSI ESCAPE ������ ���� �����ϴ� ����� �����ϴ�.
*/

#include <iostream>
#include <Windows.h>

using namespace std;

/*
* ��ǥ : ���ڷ� ǥ�⸦ �ϴ� ���� �ƴ϶�, ����� �˾ƺ��� ������ Ŭ���� ������.
* Helper Ŭ���� 
* ex) Color::White, Color::BG_White, Color::UnderLine
*/

// 30~39 ���ڻ�, 40~44 ����

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
	cout << "�� �ֱ�" << endl;
	cout << "\033[30m" << "����" << "\033[0m" << endl; // ���� ����
	cout << "\033[31m" << "����" << "\033[0m" << endl; // ���� ����
	cout << "\033[32m" << "����" << "\033[0m" << endl; // ���� �ʷ�
	cout << "\033[33m" << "����" << "\033[0m" << endl; // ���� ���
	cout << "\033[34m" << "����" << "\033[0m" << endl; // ���� �Ķ� 
	cout << "\033[35m" << "����" << "\033[0m" << endl; // ���� ����
	cout << "\033[36m" << "����" << "\033[0m" << endl; // ���� �ϴ�
	cout << "\033[37m" << "����" << "\033[0m" << endl; // ���� ���

	cout << "\033[40m" << "����" << "\033[0m" << endl; // ���� ����
	cout << "\033[41m" << "����" << "\033[0m" << endl; // ��� ����
	cout << "\033[42m" << "����" << "\033[0m" << endl; // ��� �ʷ�
	cout << "\033[43m" << "����" << "\033[0m" << endl; // ��� ���
	cout << "\033[44m" << "����" << "\033[0m" << endl; // ��� �Ķ�
	cout << "\033[45m" << "����" << "\033[0m" << endl; // ��� ����
	cout << "\033[46m" << "����" << "\033[0m" << endl; // ��� �ϴ�
	cout << "\033[47m" << "����" << "\033[0m" << endl; // ��� ���

	cout << "\033[4m" << "����" << "\033[0m" << endl; // ����

	cout << endl;
}

void Printmenu()
{
	cout << "==== �޴� ====" << endl;
	
	cout << Color::BG_CYAN<<"1." << Color::MAGENTA << "���ο� ����" << Color::RESET << endl;
	cout << Color::BG_BLUE << Color::RED << "2." << Color::RESET << Color::BG_RED << "�ҷ�����" << Color::RESET << endl;
	//cout << "3." << "����" << endl;
	Color::Print(Color::BG_GREEN, Color::BLACK, "3.����");
	cout << "4." << "����" << endl;
}

void PrintProgressBar(int current, int total, int width = 30)
{
	float progress = (float)current / total;
	int filled = (int)(width * progress);

	for (int i = 0; i < filled;i++)
	{
		cout << Color::GREEN << "��";
	}

	for (int i = filled; i < width; i++)
	{
		cout << Color::WHITE << "��";
	}

	cout << Color::RESET << (int)(progress * 100)<<"%";
}

void LoadingAnimation()
{
	cout << "�ε� ���� ��Ȳ�� �׷��ش�." << endl;
	for (int i = 0;i < 20;i++)
	{
		PrintProgressBar(i, 20);
		cout << endl;		
		cout.flush();
		Sleep(100);
		system("cls");
	}

	// vector�ڷᱸ���� ������Ȳ�� �׸����� ������ �ߴٰ� ������ �ϴ� ���. 
}

void DrawBox()
{
	/*
	* ���ڴ� ��, �߰�, �Ʒ� �κ����� ������ �˴ϴ�.
	* �ݺ����� �̿��ؼ� ǥ���غ�����.
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

	// ����� ���ڿ� ������ �׾��� ����
	cout << Color::BG_BLUE << Color::GREEN << "==== TITLE ====" << Color::RESET << endl;
	
	Color::Print(Color::BG_BLUE, Color::GREEN, "==== TITLE2 ====");

	// �ε���, �޴� ǥ��, UIǥ��

	Printmenu();

	// ���� ColorŬ������ ����ؼ�
	// 1. ���� ����
	// 2. ���� ����

	DrawBox();
}