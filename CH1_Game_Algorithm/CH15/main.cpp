/*
* 1. ���̵� � ������� �����ߴ°�?
* 2. �ڷᱸ���� � ������ �����ߴ��� ������ �����غ�����
*/

#include <iostream>
#include <algorithm>
#include <vector>


#pragma region Q1

// ATM ����(���� 11399��) 
// ATM�� ������� ���� ���� �ֽ��ϴ�.
// n���� ����� ��� ��ٸ� �ð��� �ּ��� �ð��� �Ƿ���
// ��� �ؾ��ұ�? �׸��� �� �ð��� �� ������ ���� ������ּ���.

/*
* int -> "people" (��ٸ��� ��� ����, ��� �ؾ��� �ð�, ����)
*/

// ���� �Է�  || ���� ���
// 3,1,4,3,2 ||  32

struct client
{
	int waitId;
	int waitTime;
};

void Solve1()
{
	std::cout << "\n==== ATM���� Ǯ�� ====" << std::endl;
	int n = 5; // �� �ο� ��
	int totalTime = 0; // ��� �ο��� ��ٸ� �ð�
	// ������ �ο� ���� ��ٸ��� �ð��� ������ �����ؾ� �Ѵ� -> �ڷᱸ�� -> vector<int>
	// 1. vector<int> waitTimetavle; ������ ������ �߰��غ�����
	// 2. ������ Ǯ�� ����� �����غ�����
	std::vector<int> waitTimeTable;

	waitTimeTable.push_back(3);
	waitTimeTable.push_back(1);
	waitTimeTable.push_back(4);
	waitTimeTable.push_back(3);
	waitTimeTable.push_back(2);

	std::vector<int> clients(waitTimeTable.size(), -1);
	
	/*
	std::vector<client> clients(waitTimeTable.size());
	clients[0].waitId = 1;
	clients[0].waitTime = waitTimeTable[0];
	*/

	// client���� ��ٸ� �ð��� ������ �ؾ��Ѵ�.
	// �־��� �����͵��� ���� ���� ��� �ǳ�?
	// ���̵�� : ���� ���� ������ �����͸� ���Ľ�Ų��.
	// ���� ��Ų �� �ݺ������� �����ش�.

	// clients���� �ð��� ���� ������ �������ֱ�.
	std::sort(waitTimeTable.begin(), waitTimeTable.end());

	// 1. ó�� ����ϴ� ���
	clients[0] = waitTimeTable[0];

	for (int i = 1;i < waitTimeTable.size();i++)
	{
		clients[i] = clients[i - 1] + waitTimeTable[i];
	}

	//clients[0] = 3
	//clients[1] = clients[0] + waitTimeTable[1];
	//clients[2] = clients[1] + 4;
	//clients[3] = clients[2] + 3;
	//clients[4] = clients[3] + 2;

	for (int t : clients)
	{
		totalTime += t;
	}

	// �־��� �����ʹ�� ���� ���� ��F�� �ǳ�?

	std::cout << n << "���� ������� ��� ��ٸ��� �ð��� �ּҰ� �Ǵ� �ð� " << totalTime << std::endl;

}


#pragma endregion

#pragma region Q2

// �賶�� ���� ��� ����(���� 12865��)
// ������ n�� ���� �� �ִ� ���԰� k�� �־����ϴ�.
// ���Ը� �ִ������� ����� �� �ִ��� ��ġ�� ������ ���� ���� ������ּ���.

// �Է� ����  ||  ���
//  4   7    ||  14
//  6   13
//  4   8
//  3   6
//  5   12

void Solve2()
{
	// 4���� ������ ���´�. ������ ���ǿ��� ���Կ� ��ġ�� ǥ���ǰ� �ִ�.
	// k�� ���� ��ŭ �賶�ȿ� �ִ������� ������ ���� �� ��ġ�� ���� ũ���� �����ϴ� ����� �����غ�����.

	// ���� 12865��
	// 1. n = 4, k = 7 [6,13][4,8][3,6][5,12] �����ͷ� ǥ���غ�����.
	// 2. ���̵�� : ���� ��ġ�ִ� ���ǵ鸸 ��� ���ؼ� ��� �ؾ��ϴ°�?

	std::cout << "\n==== �賶 ���� Ǯ�� ====" << std::endl;

	int n = 4; 
	int k = 7;	
	std::vector<std::pair<int, int>> items{ {6,13},{4,8},{3,6},{5,12} };

	// ���Ժ� ��ġ ��
	// �賶�� 1�� ��, �ִ�� ���� �� �ִ� ��ġ?

	std::vector<int> dp(k+1, 0); // dp[0] ~ dp[7]

	// ���԰� 0 �϶�? �� ���Կ��� �ִ�� ���� �� �ֵ��� ���Ժ� �ְ� ��ġ�� �����ϼ���
	//dp[0] = 0;
	//dp[1] = 0;
	//dp[2] = 0;
	//dp[3] = 6;
	//dp[4] = 8; // ���� ������ ��ġ + ���� ���� �� �ִ� ��ġ
	//dp[5] = 12;
	//dp[6] = 13;
	//dp[7] = 14; // 6+1 : 13, 5+2 : 12, 4+3 : 14

	for (int i = 0;i < 4;i++)
	{
		int weight = items[i].first; // ����
		int value = items[i].second; // ��ġ
		for (int w = k; w>= weight;w--) // 7, 6...
		{
			dp[w] == std::max(dp[w], dp[w - weight] + value);
		}
	}

	std::cout << "������ ���԰� 7���� ���� �� ���� �� �ְ� ��ġ : " << dp[7] << std::endl;


}

#pragma endregion

// �κ��丮 : ���� �ý��� - User ���Ǽ��� ���� �ڵ�. ������ �߿��� ���� ��ġ�ִ� �������� �����ϴ� �ڵ带 ��������

// �̸��� Ŭ���� ���弼�� -> ������ Ŭ���� ���԰���� ��ġ�� ���Եǵ��� ��������
// ������ �����ϴ� �����̳�, �κ��丮, ���԰� �����ϴ� �κ��丮�� �����غ�����

class ItemW
{
	std::string name;
	int weight;
	int value;
public:
	ItemW(std::string _name, int _weight, int _value) : name(_name), weight(_weight), value(_value) {}
	int GetWeight() const { return weight; }
	int GetValue() const { return value; }
	std::string GetName() const { return name; }
};

class InventoryM // ItemW �ڷ����� �����̳ʷ� �����ϼ���
{
private:
	std::vector<ItemW> Items;
	int maxWeight;
	int currentWeight;

public:
	// ������
	InventoryM(int max) : maxWeight(max), currentWeight(0) {}

	// ������ �߰�
	void AddItem(const ItemW& addItem)
	{
		if (CheckWeight(addItem))
		{
			Items.push_back(addItem);
			currentWeight += addItem.GetWeight();
		}
	}

	// �ִ� ���Ժ��� �������� �� ���԰� ���ſ�� false, true

	bool CheckWeight(const ItemW& addItem)
	{
		return maxWeight >= currentWeight + addItem.GetWeight();
	}

	int findBestItem(int targetWeight, std::vector<ItemW>& selectableItems) // findOptionalItemCombination
	{
		// ���� �������� ���Կ� ���ο� ������ ������ ������ �� ������ �����̳� ����
		std::vector<int> dp(targetWeight + 1, 0);

		// selectableItems ����ִ� ����, weight
		// selectableItems ����ִ� ��ġ, value

		for (int i = 0; i < selectableItems.size();i++)
		{
			int weight = selectableItems[i].GetWeight();
			int value = selectableItems[i].GetValue();

			for (int w = targetWeight; w >= weight;w--)
			{
				/*
				* �ش�
				*/
			}
		}

		// ����� ������ ������ �����ؼ� �ٽ� vectro �����ϴ� �ڵ�.
		// while(weight - ����)
		return dp[targetWeight];
	}

	std::vector<ItemW> GetInventory() { return Items; }
};

void InventoryWeightSystem()
{
	// �κ��丮 �����ϰ� ȣ��, 4���� ������ �� �賶�� �����غ�����. �ִ� ���԰� 7�̰�, �������� 4�� ����

	InventoryM inventory(7);

	// 6,4,3,5
	ItemW A("A", 6, 13);
	ItemW B("B", 4, 8);
	ItemW C("C", 3, 6);
	ItemW D("D", 5, 12);

	std::vector<ItemW> selectableTable{ A,B,C,D };
	std::cout << "�־��� �������� �ִ� ��ġ : " << inventory.findBestItem(7, selectableTable) << std::endl;
	
	inventory.AddItem(A);
	inventory.AddItem(B);

	int index = 0;

	for (auto& item : inventory.GetInventory())
	{
		index++;
		std::cout << index << "��° ������" << item.GetName() << " , ���� :  " << item.GetWeight() << std::endl;
	}

}

int main()
{
	Solve1();
	Solve2();
	InventoryWeightSystem();
}