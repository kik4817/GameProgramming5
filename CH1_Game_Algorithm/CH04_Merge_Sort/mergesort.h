#pragma once

/*
* 어떻게 코드를 구현해보면 좋을까?
*/

/*
* 병합 정렬
* 핵심 개념 : 일단 나눠라! 절반씩 나누어서 1개가 될 때까지
*           나누어진 것끼리 정렬해서 합친다.
*/

/*
* 나눈다 = mergesort
* 합친다 = merge
*/

/*
*	삽입 정렬
* 
* 장점 : 정렬되어 있을 수록 빠르다
* 단점 : n의 크기가 크면 클 수록 비효율적이다. 
*      100만 데이터 이하, 정렬되어 있는 편항(biased)이 있을 때 사용하면 장점이 있다.
*
* 
*	퀵 정렬
* 
* 장점 : 대중적으로 많이 사용한다. stl sort
*		대부분의 경우에 n logn 시간을 보장한다.
* 단점 : worst case에 O(n^2)
* 
*	개선한 퀵 sort. pivot - 맨 왼쪽, 알고리즘
* 
* 
*	병합 정렬
* 
* 장점 : 평균적으로 nlogn 시간을 보장한다.
* 단점 : sorted 저장을 위한 배열을 사용하기 때문에, 추가적인 메모리를 사용한다.
* 
* 
* algorithm 헤더 sort(begin(), end());
*/

#include <iostream>
#include <vector>

void merge(int arr[], int n, int left, int mid, int right)
{
	// 1. 정렬된 데이터를 따로 저장할 배열 공간을 정의 합니다.(sorted array 정렬 배열)

	//int sortedArray[n] = { 0 }; //const int n
	std::vector<int> sorted; // 왼쪽과 오른쪽을 비교해서 정렬시킨 값을 저장할 임시 컨테이너
	sorted.assign(n, 0);     // n개의 공간에 데이터가 0으로 초기화된 가변배열을 선언
	int i = left;            // 왼쪽에서 시작하는 인덱스 번호
	int j = mid + 1;         // 오른쪽에서 시작하는 인덱스 번호
	int k = left;            // 정렬된 인덱스에서 가장 첫번째 인덱스 번호
	
	// 2. arr 배열안에 들어있는 값 left 인덱스 값과 right 인덱스 비교 작은 값을 sorted 넣으세요
	// left 작은 경우, right 작은 경우
	
	while (i<=mid && j<=right) // 왼쪽 또는 오른쪽 인덱스가 남아 있을 때만 실행하세요.
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

	// 3. i가 남았을때, ㅓ가 남았을 때 나머지를 가득 채우세요

	if (i > mid) // i를 다 사용한 경우, 남은 인덱스가 j만 있을 경우
	{
		for (int t = j;t <= right;t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else // j를 다 사용한 경우, 1만 남았을 때
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}

	// 4. sorted 현제 정렬된 상태. arr 원본 데이터에 정렬된 데이터를 옮겨준다.
	for (int t = left; t <= right;t++)
	{
		arr[t] = sorted[t];
	}
}

void mergesort(int arr[], int n, int left, int right)
{
	// 재귀적으로 mergesort
	
	// 왼쪽부분 mergesort
	// 오른쪽부분 mergesort

	// merge

	if (left < right) // 만약에 left == right 같다 원소가 1개이다.
	{
		int mid = (left+ right)/2; //(left, right사용해서 정의해보세요)
		mergesort(arr, n, left, mid); // 왼쪽 부분
		mergesort(arr, n, mid + 1, right); // 오른쪽 부분

		merge(arr, n, left, mid, right);
	}
}