/*
* �ܼ� â ���� �����ϴ� ��ɵ�
* ANSI ESCAPE ������ ���� �����ϴ� ����� �����ϴ�.
*/

#include <iostream>
#include <Windows.h>
#include <queue>
#include <string>
#include "InventoryDP.h"

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
	cout << endl;
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
	const int total = 20;
	const int width = 20;

	cout << "�ε� ���� ��Ȳ�� �׷��ش�." << endl;
	for (int i = 0;i < total;i++) // i<=total -> 100%
	{
		system("cls");
		PrintProgressBar(i, total, width);
		cout << endl;		
		cout.flush();
		Sleep(50);		
	}

	// vector�ڷᱸ���� ������Ȳ�� �׸����� ������ �ߴٰ� ������ �ϴ� ���. 
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
* DrawBox�� ���� ���ϴ� ��ǥ�� �׸� �� �̤����� �Ʒ� �Լ��� �����غ����� 
* gotoXY�� �̿��ϼ���. ž, ����, �ٵ�
*/

void DrawBox(int width, int height) // ����, ����
{	

	// �Ӹ�
	cout << Color::BG_CYAN << "+";
	//-------
	for (int i = 0; i < width;i++)
	{
		cout << "-";
	}
	cout << "+"<<Color::RESET << endl;

	// �ٵ�
	for (int y = 0;y < height;y++)
	{
		// ���� ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");

		// ����
		for (int i = 0; i < width;i++)
		{
			cout << " ";
		}

		// ������ ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");
		cout << endl;
	}
	
	// ������	
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
	* ���ڴ� ��, �߰�, �Ʒ� �κ����� ������ �˴ϴ�.
	* �ݺ����� �̿��ؼ� ǥ���غ�����.
	*/

	// �Ӹ�
	gotoXY(px, py);
	cout << Color::BG_CYAN << "+";
	//-------
	for (int i = 0; i < width;i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;

	// �߰�	
	for (int y = 0;y < height;y++) 
	{
		gotoXY(px, py + 1 + y); // py+=1			py + 1 + y
		// ���� ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");

		// item�� ������ ���
		string content = "";

		if (y == 1)
		{
			content = "�̸� : " + item.GetName();
		}
		else if (y == 2)
		{
			content = "���� : " + to_string(item.GetWeight());
		}
		else if (y == 3)
		{
			content = "��ġ : " + to_string(item.GetValue());
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

		// ����
		for (int i = 0; i < width;i++)
		{
			cout << "";
		}

		// ������ ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");
		cout << endl;
	}

	// ������
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

	//itemQueue.push(ItemW("�ռҵ�", 80, 50));
	//itemQueue.push(ItemW("���ҵ�", 20, 18));
	//itemQueue.push(ItemW("������", 5, 2));
	//itemQueue.push(ItemW("�ռҵ�", 80, 50));
	//itemQueue.push(ItemW("���ҵ�", 20, 18));
	//itemQueue.push(ItemW("������", 5, 2));	
	//itemQueue.push(ItemW("�ռҵ�", 80, 50));
	//itemQueue.push(ItemW("���ҵ�", 20, 18));
	//itemQueue.push(ItemW("������", 5, 2));

	for (auto& Item : items)
	{
		itemQueue.push(Item);
	}

	// ctrl + r + r
	int currentRow = 0; // ���� �׷����� ������ x��ǥ
	int currentCol = 0; // ���� �׷����� ������ y��ǥ

	const int Box_Width = 20;
	const int Box_Height = 10;
	const int Box_RowSpacing = 5;
	const int Box_ColSpacing = 5;

	while (!itemQueue.empty())
	{
		ItemW currentItem = itemQueue.front();
		itemQueue.pop();
		Test(currentItem);
		// ItemW Ÿ���� ����ϴ� �Լ��� ��������.

		int boxX = startX + (currentRow * (Box_RowSpacing + Box_Width));
		int boxY = startY + (currentCol * (Box_ColSpacing + Box_Height));

		// ��ǥ�� �������ִ� �ڵ带 �ۼ��ϼ���. 3*3 �ڽ��� ������ �׷������� �ڵ带 ��������.

		
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


	// ����� ���ڿ� ������ �׾��� ����
	cout << Color::BG_BLUE << Color::GREEN << "==== TITLE ====" << Color::RESET << endl;
	
	Color::Print(Color::BG_BLUE, Color::GREEN, "==== TITLE2 ====");
	cout << endl;

	// �ε���, �޴� ǥ��, UIǥ��

	Printmenu();

	// ���� ColorŬ������ ����ؼ�
	// 1. ���� ����
	// 2. ���� ����
	//LoadingAnimation();
	system("cls");

	//ItemW item("�ռҵ�", 10, 10);
	//	
	//for (int i = 0; i < 3;i++)
	//{
	//	DrawBox(5+25*i, 8, 20, 10, item);

	//}
	//
	//// ���� ����
	//// � ��ǥ �ۼ� ��ġ�� �ʰ� �׸� �� �ִ���
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

	std::cout << "�־��� �������� �ִ� ��ġ : " << bestItem.first << std::endl;

	std::vector<ItemW> ItemC = bestItem.second;

	ProcedualDrawBox(5,5, ItemC);
	
}