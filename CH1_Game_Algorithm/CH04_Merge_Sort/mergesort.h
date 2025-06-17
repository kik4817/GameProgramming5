#pragma once

/*
* ��� �ڵ带 �����غ��� ������?
*/

/*
* ���� ����
* �ٽ� ���� : �ϴ� ������! ���ݾ� ����� 1���� �� ������
*           �������� �ͳ��� �����ؼ� ��ģ��.
*/

/*
* ������ = mergesort
* ��ģ�� = merge
*/

/*
*	���� ����
* 
* ���� : ���ĵǾ� ���� ���� ������
* ���� : n�� ũ�Ⱑ ũ�� Ŭ ���� ��ȿ�����̴�. 
*      100�� ������ ����, ���ĵǾ� �ִ� ����(biased)�� ���� �� ����ϸ� ������ �ִ�.
*
* 
*	�� ����
* 
* ���� : ���������� ���� ����Ѵ�. stl sort
*		��κ��� ��쿡 n logn �ð��� �����Ѵ�.
* ���� : worst case�� O(n^2)
* 
*	������ �� sort. pivot - �� ����, �˰���
* 
* 
*	���� ����
* 
* ���� : ��������� nlogn �ð��� �����Ѵ�.
* ���� : sorted ������ ���� �迭�� ����ϱ� ������, �߰����� �޸𸮸� ����Ѵ�.
* 
* 
* algorithm ��� sort(begin(), end());
*/

#include <iostream>
#include <vector>

void merge(int arr[], int n, int left, int mid, int right)
{
	// 1. ���ĵ� �����͸� ���� ������ �迭 ������ ���� �մϴ�.(sorted array ���� �迭)

	//int sortedArray[n] = { 0 }; //const int n
	std::vector<int> sorted; // ���ʰ� �������� ���ؼ� ���Ľ�Ų ���� ������ �ӽ� �����̳�
	sorted.assign(n, 0);     // n���� ������ �����Ͱ� 0���� �ʱ�ȭ�� �����迭�� ����
	int i = left;            // ���ʿ��� �����ϴ� �ε��� ��ȣ
	int j = mid + 1;         // �����ʿ��� �����ϴ� �ε��� ��ȣ
	int k = left;            // ���ĵ� �ε������� ���� ù��° �ε��� ��ȣ
	
	// 2. arr �迭�ȿ� ����ִ� �� left �ε��� ���� right �ε��� �� ���� ���� sorted ��������
	// left ���� ���, right ���� ���
	
	while (i<=mid && j<=right) // ���� �Ǵ� ������ �ε����� ���� ���� ���� �����ϼ���.
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}

	// 3. i�� ��������, �ð� ������ �� �������� ���� ä�켼��

	if (i > mid) // i�� �� ����� ���, ���� �ε����� j�� ���� ���
	{
		for (int t = j;t <= right;t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else // j�� �� ����� ���, 1�� ������ ��
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}

	// 4. sorted ���� ���ĵ� ����. arr ���� �����Ϳ� ���ĵ� �����͸� �Ű��ش�.
	for (int t = left; t <= right;t++)
	{
		arr[t] = sorted[t];
	}
}

void mergesort(int arr[], int n, int left, int right)
{
	// ��������� mergesort
	
	// ���ʺκ� mergesort
	// �����ʺκ� mergesort

	// merge

	if (left < right) // ���࿡ left == right ���� ���Ұ� 1���̴�.
	{
		int mid = (left+ right)/2; //(left, right����ؼ� �����غ�����)
		mergesort(arr, n, left, mid); // ���� �κ�
		mergesort(arr, n, mid + 1, right); // ������ �κ�

		merge(arr, n, left, mid, right);
	}
}