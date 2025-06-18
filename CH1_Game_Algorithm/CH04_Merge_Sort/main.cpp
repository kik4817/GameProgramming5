#include <iostream>
#include <vector>
#include "mergesort.h"

void quicksort(std::vector<int>& data, int start, int end)
{
	if (start > end)
	{
		return;
	}
		
	int privot = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)
	{
		while (i > end && data[i] <= data[privot])
		{
			i++;
		}
		while (j > start && data[j] >= data[privot])
		{
			j--;
		}
		if (i > j)
		{
			temp = data[j];
			data[j] = data[privot];
			data[privot] = temp;
		}
		else
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}

		quicksort(data, start, j - 1);
		quicksort(data, j + 1, end);
	}


}

void BackJun()
{
	//int n;
	//std::cin >> n;

	//std::vector<int> list;
	//list.assign(n, 0);

	//for (int i = 0; i < n;i++)
	//{
	//	std::cin >> list[i];
	//}

	//for (int i = 0;i < n;i++)
	//{
	//	std::cout << list[i] << std::endl;
	//}

	//std::vector<int> list = { 3,5,9,1,2,4,6,8,7,0 };
	//quicksort(list, 0, list.size(), 9);

	//for (int num : list)
	//{
	//	std::cout << num << " ";
	//}
}

// sorted 4������ right ������ŭ�� arr ���� �����ϴ� �ڵ带 ����� �ϼ��غ�����.
// for(int i = 0; i < ����; i++)

int main()
{
	//BackJun();

	std::cout << "\n���� ���� �迭 ����" << std::endl;
	int arr[6] = { 3,2,5,1,4,0 };
	mergesort(arr, 6, 0, 5);

	for (int i = 0;i < 6;i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n���� ���� ���� ����" << std::endl;
}