#include <iostream>
#include <vector>
#include <algorithm>

/*
* Ž�� �˰���(Greedy)
* ���� Ǯ�� ����� �ϳ��̴�
* ������ �ظ� ã�� ���ؼ� ���� ��Ȳ���� ���� �ּ��� ����� ����ؼ� �����ϴ� ����Դϴ�. 
*/

/*
* 1��, 2��, 3��
* 
* ���� �Ž����ֱ� ����
* n���� �������θ� �Ž��� ����ϴµ� ������ ���� 
* 500��, 100��, 50��, 10���� �ִ�. �� �� ������ �ּ����� ������ �Ž����ְ� ���� ��
* n���� �Ž����ֱ� ���� ������ �ּ� ���� n�� ��ȯ���ּ���.
*/

// 1260���� �������θ� �Ž������ �� �� �ּ������� ������ �ַ��� ��F�� �ϸ� �ɱ�?
// ���� ��Ȳ���� ���� �ּ��� ��������(IDEA)(Greedy)
// 500�� a, 100�� b, 50�� c, 10�� d a+b+c+d ��ȯ
// 500 * 2 + 100 * 2 + 50 * 1 + 10 * 1 = 2+2+1+1 = 6
int CoinBack(int amount) // amount �Ž��� ��� �� �ѱݾ�
{
	// amount ������ ������ ��ġ�� ��Ȱ�� �ؾ��Ѵ�.
	// ��� �������� ����ؼ� a,b,c,d ǥ���ϰ� �� ���� �����غ�����.
	
	//������ ������ ����ϱ�

	/*
	* ���� ��ǥ : �ݺ��Ǵ� �κ��� �ݺ������� ǥ���ϸ� �ڵ尡 ���ݴ� ���� ���ص� �� �ִ�
	* vector<int> �Ž��� �� ���� �����Ѵ�. ����Ǿ� �ִ� ������ ����ؼ� �ݺ����� �ۼ��Ѵ�.
	*/

	/*
	* vector int �����ϴ� ���� �ƴ϶� coin �ڷ����� ���� ǥ���غ�����.
	*/

	struct Coin
	{
		int value;
		int count;

		Coin(int _value) : value(_value), count(0) {}
	};

	std::vector<int> coins = { 500,100,50,10 }; // ������ �����͸� �����ϼ���.
	
	// CoinWallet�̸����� Coin�� ������ ���ÿ� �߰��غ�����.
	std::vector<Coin> coinWallet;
	// coinWallet.emplace_back(500);
	// coinWallet.emplace_back(100);
	
	int totalCount2 = 0;
	
	for (int coin : coins)
	{
		coinWallet.emplace_back(coin);
	}

	for (auto& elem : coinWallet)
	{
		int num = amount / elem.value;
		elem.count = num;
		totalCount2 += num;
		amount = amount % elem.value;

		std::cout << elem.value << "���� �� : " << elem.count << std::endl;
	}
	std::cout << "������ �� ���� : " << totalCount2 << std::endl;

	// �ݵ�� coins �ڷᱸ���� ���� ū ������� ������ �Ǿ��־�� �Ѵ�.
	// ������������ ���Ľ�Ű�� �ڵ�.

	int totalCount = 0;

	for (int coin : coins)
	{
		int num = amount / coin;
		totalCount += num;
		amount = amount % coin; // amount %= coin;
		std::cout << coin << "���� �� : " << num << std::endl;
	}
	std::cout << "������ �� ���� : " << totalCount << std::endl;
	

	//int remain = amount; // ù ���� �ݾ�
	//// ù��°.. ���� ������ ��ġ�� ū �༮���� �Ž����ش�.
	//int a = remain / 500; // 500���� ����
	//std::cout << "500���� �� : " << a << std::endl;
	//remain = remain - 500 * a; // ���� �ݾ�
	//
	//int b = remain / 100; // 100���� ����
	//std::cout << "100���� �� : " << b << std::endl;
	//remain = remain - 100 * b;
	//
	//int c = remain / 50;
	//std::cout << "50���� �� : " << c << std::endl;
	//remain = remain - 50 * c;
	//
	//int d = remain / 10;
	//std::cout << "10���� �� : " << d << std::endl;
	//remain = remain - 10 * d;
	//
	//int totalCount = a + b + c + d;
	//std::cout << "������ �� ���� : " << totalCount << std::endl;
	
	return totalCount;
}

// ȸ�ǽ� ���� ����
// ȸ�ǽ��� �����ϴ� �ð��� ������ �ð��� ������ �����ϵ��� �� ���� n�� �־����ϴ�.

// ȸ�ǿ� ����� �� �� 5�����, {0,5}{1,3}{2,6}{7,10}{6,9}
// �� ȸ�ǽ��� �ִ�� �����ϴ� ����� ã�ƺ�����.
// �ִ�� ������ �� ����� ������ �� �ֳ���?
// � ������� ���� �� �ּ����� ���� ������ �� ������?

// ���� 1911 ����

/*
* (1) ���۽ð��� ���� ���� ������ �����Ѵ�.
* (2) ������ �ð��� ���� ���� ������ �����Ѵ�.
* (ù���� ���ҷ� ����Ѵ�.)
*/

int meetingCount(int n)
{

	// ���۽ð��� ������ �ð��� �տ� ������ �ڿ� ������ �� ������ �����ؼ� ǥ���غ�����.
	std::vector<std::pair<int, int>> meeting{ {4,1},{5,3},{6,0}, {7,5},{8,3},{10,6}, {11,8},{12,8},{13,2}, {14,12} };
	
	// ������ �ð� ������ �����Ѵ�. ������ �ð��� key���� first�� �����Ͽ���.
	std::sort(meeting.begin(), meeting.end());

	// ���� ��Ű�� �� ���� �����

	for (auto& i : meeting)
	{
		std::cout << i.first << "," << i.second << "||";
	}

	// {������ �ð�, ���� �ð�}
	// count�� 1�� ���� �����ش�
	// time ���� ȸ�ǿ��� �����ϴ� �ð�
	// ���� ���õ� ȸ�ǿ��� ������ �ð��� ���߿� ���õ� ȸ���� ���۽ð��� ���Ѵ�.
	// time �� ���õ� ȸ���� ������ �ð����� �������ָ� �ȴ�.

	int count = 1;
	int time = meeting[0].first; // ù��° ������ ������ �ð�

	for (int i = 1; i < n;i++)
	{
		// ���� ���õ� �ð�[��] ������ ���� �߿��� ���� �ð� ?? ��� �񱳸� ���� ���ϼ���
		if (time <= meeting[i].second) 
		{
			// ���� 1���� ��Ű����
			count++;
			// time�� ���õ� �ð����� �����ϼ���
			time = meeting[i].first;
		}
	}

	return 0;
}

/*
* ���� �ð�, ������ �ð��� '��' ������ ����� �մϴ�. 3600 - 1800 = 1800;
* ��� �� �ʸ� �ٽ� '��' '��' '��'�� ��ȯ�ؼ� ����ϴ� �ڵ带 ��������.
* 
* [n�� m�� s��] ������ִ� �ڵ带 �ۼ��غ�����
*/

#include <chrono>

void FormatTime(int value)
{
	// 2167 -> �� �� �� ��ȯ�ϴ� �ڵ带 ��������
	// value -> ��, ��, �� ����� ����

	struct TimeV
	{
		int value;
		int count;

		std::string nameformat;

		TimeV(int _value, std::string _name) : value(_value), nameformat(_name) {}

		void Print()
		{
			std::cout << count << nameformat;
		}
	};

	std::vector<TimeV> times;
	times.emplace_back(3600, "��");
	times.emplace_back(60, "��");
	times.emplace_back(1, "��");

	for (auto& time : times)
	{
		int num = value / time.value;
		time.count = num;
		value %= time.value;
	}
	

	std::cout << times[0].count << "��" << times[1].count << "��" << times[2].count << "��" << std::endl;
}

int main()
{
	std::cout << "���� �Ž����ֱ� ���� : 1260���� ��ȯ���ּ���" << std::endl;
	std::cout << "=== ����� ===" << std::endl;
	CoinBack(1260);

	// 500�� : a, 100�� : b, 50�� : c, 10�� : d

	std::cout << "\n\nȸ�ǽ� ����" << std::endl;
	//meetingCount(11);
	std::cout << "���� : " << meetingCount(10);

	std::cout << "���� �ð����� ��ȯ�ϴ� ����" << std::endl;
	FormatTime(2162);
}