#include <iostream>
#include <vector>
#include <algorithm>

#pragma region ���� ����
/*
* ���� ����
* - Ư�� ���� ���ĵ� ��ġ�� �ű�� ���
* = �տ��� ���� �����͸� �����Ѵ�.
*/

void InsertSort(int arr[], int n)
{
	// �� �� cycle ��ƾ� �ϳ���?
	 
	for (int i = 1; i < n;i++)
	{
		// ���� key�� ���� �����ΰ�?
		int key = arr[i];

		// key�� �� ������ ����� �񱳸� �ض�.
		int j = i - 1;

		// while() ������ true�� �� �߰�ȣ{} �ڵ带 �����϶�.
		while (j>=0 && arr[j]>key) // j�� ���� key ���� ���� �� �Ǵ� �ε����� ���� 0���� Ŭ��
		{			
			arr[j + 1] = arr[j]; // ���ʿ� �����Ϳ� ���� ���� �������� ��ġ�� �����ض�
			j--; // ���� key�� ��ġ
		}

		arr[j + 1] = key;
	}


}

void InsetSort(std::vector<int>& nums)
{
	// �� �� cycle ���ƾ� �ϳ���?
	int n = nums.size();
	for (int i = 1; i < n;i++) // j�� ���� 0���� ũ�ų� ���� ���� �ɴ� key�� ���� ���ʿ� �ִ� ������ ���� ����
	{
		// ���� key�� ���� �����ΰ�?
		int key = nums[i];
		int j = i - 1;
		// key ���ʿ� �ִ� ��� �����͵�� ���ؼ� ��ġ�� ã�� ������ �� ��ġ�� ����.
		while (j >= 0 && nums[j] > key)
		{
			// ������ ���ʰ� Ű�� ����ִ� ���� �����ϰ�
			// index�� �������� �̵��ؼ� ���� ���� �� ���Ѵ�.
			nums[j + 1] = nums[j];
			j--;
		}

		// ��ġ�� ã���� �ش� ��ġ�� key�� �����϶�
		nums[j + 1] = key; // ���ҽ� -1
	}
}

/*
* ���� - ���� ��쿡 ��ġ ������ �߻��ϴ� ���� �ƴ϶�, while ���ǿ� �ش� �� ���� ��ġ ����(swap)�� �߻��Ѵ�.
* �����̳� �����Ͱ� ���ĵǾ� ���� ���� ���� �ӵ��� ������
* ����Ŭ : n
* while() 1~n ũ�⸦ ���� �� �ִ�
* �ּ��� ��� O(n) ���, �־��� ���(0(N^2))
* 
* ���� : n�� ������ ����ؼ� �ð��� �ɸ���.
*/

/*
* log �ð��� �󸶳� ������?
* 2^10 = 1024 // �뷫 1000
* 2^20 = 2^10 * 2^10 // 1,000,000 �뷫 �鸸
* log2(2^20) = 20; n��(�鸸 ��) log n�� (20��)
* 
* �ð��� �����ϰ� �ϱ� ���ؼ��� logn���� ǥ���ϴ� ����� ã�´�.
* "���� ����" �˰���
*/

/*
* 1 2 3 4 5 6 7 8 9 10 0(n^2) 100
* 
* 1 2 3 4 5   = 5^2 = 25
* 6 7 8 9 10  = 5^2 = 25	50
*/

#pragma endregion

#pragma region �W ����

/*
* ������ pivot�� ���Ѵ�. ���� ������ ���� �ǹ����� �Ѵ�.
* pivot �ǹ� : ������
* ���� ���� �˰���, ������ �ϱ� ���� �����̴�.
* Ư¡ : ���� ���� �˰����� ����ϰ� �ִ�. ��� �Լ��� �����ȴ�.
* ��� 0(n * logn) �ð��� ���´�.
* O(n^2) ���� ������� �˰��� ���ϼ���. (����, ����, ����)
* O(n log n) ���� ������� �˰��� ���ϼ���. (�� ����)
*/

/*
* ���� ����ϴ°�? data�� ������ 10�� ���� �Ѿ��, 10�� * 10�� = 10 ~ ���� 0.00001 * 10��
* �������� ������ ���� �� ����Ѵ�.
* 
* ���� : ���ĵǾ� �ִ� �����Ϳ��� quickSort ����� ��� O(n^2) �ð��� �ɸ���
* 1 2 3 4 5
* �˰��� ������ quickSort �������� �� �ð��� �ʰ��ߴ�.
* ���ĵǾ� �ִ� ���̽��� ���� �� ��ȿ�����̴�.
*/

void quickSort(int data[], int start, int end)
{
	if (start >= end) // �����Ͱ� 1���� ���� ��, ��� �Լ��� ������ ���� ���� return ǥ��
	{
		return;
	}

	int pivot = start; // ������ �Ǵ� ��
	int i = start + 1; // ���ʿ��� ������ ��ġ
	int j = end;       // �����ʿ��� ������ ��ġ
	int temp;          // swap ����ϱ� ���� �ӽ� ����

	while (i <= j) // ���� �ε����� ������ �ε����� �߿� ���� �� ���� �ݺ�
	{		
		while(data[i] <= data[pivot]) // �ǹ����� ū ���� ���� �� (i�� ���� �������ִ� �ڵ�)
		{
			//(���� �� ��� i�� �����ض�)
			i++;
		}
		while (j> start && data[j] >= data[pivot]) // �ǹ����� ���� ���� ������ (j�� ���� �������ִ� �ڵ�)
		{
			//(j�� ���� �������ִ� �ڵ�)
			j--;
		}
	}

	// i > j // ���� �ε����� ������ �ε��� ���� ũ�� (�����ȴ�)
	if (i > j)
	{
		temp = data[j];
		data[j] = data[i];
		data[i] = temp;

		//std::swap(data[pivot], data[j]);
	}
	else // �������� �ʾ��� ��
	{
		temp = data[j];
		data[j] = data[i];
		data[i] = temp;

		//std::swap(data[i], data[j]);
	}

	// ��� �Լ�

	// quicksoft(���� ��Ʈ) quicksoft(������ ��Ʈ)
	quickSort(data, start, j-1); // ����
	quickSort(data, j+1, end);   // ������
}

void quickSort(std::vector<int>& data, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int n = data.size();
	int pivot = start;
	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		while (data[i] <= data[pivot])
		{
			i++;
		}
		while (j > start && data[j] >= data[pivot])
		{
			j--;
		}

		if (i > j)
		{
			std::swap()
		}
	}
}


#pragma endregion

#pragma region �׽�Ʈ

void Test1()
{
	std::cout << "���� ���� �迭 ����" << std::endl;

	int arr1[10] = { 1,5,9,1,2,4,6,8,7,0 };

	InsertSort(arr1, 10);

	for (int i = 0;i < 10;i++)
	{
		std::cout << arr1[i] << " ";
	}

	std::cout << "\n\n���� ���� vector ����" << std::endl;
	std::vector<int> nums1 = { 3,5,9,1,2,4,6,8,7,0 };
	InsetSort(nums1);

	for (int num : nums1)
	{
		std::cout << num << " ";
	}
}

void Test2()
{
	std::cout << "\n\n�� ���� �迭 ����" << std::endl;
	int arr2[10] = { 1,5,9,3,2,4,6,8,7,0 };
	quickSort(arr2, 0, 9);

	for (int i = 0;i < 10;i++)
	{
		std::cout << arr2[i] << " ";
	}

	std::cout << "\n\n�� ���� vector ����" << std::endl;
	std::vector<int> nums2 = { 3,5,9,1,2,4,6,8,7,0 };
	InsetSort(nums2);

	for (int num : nums2)
	{
		std::cout << num << " ";
	}
}

#pragma endregion

int main()
{
	//Test1();
	Test2();
}