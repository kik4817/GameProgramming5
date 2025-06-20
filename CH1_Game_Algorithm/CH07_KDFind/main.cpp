/*
* 알고리즘 대표 문제
* - 수를 정렬하고 탐색하기
* - 단순한 방법. 데이터를 정렬시킨다.
* - k번째 작은수? 왼족부터 하나씩 출력
* - k번째 큰수? 오른족부터 하나씩 출력
*/

#include <iostream>
#include <vector>
#include <utility> // pair<int>
#include <map> // insert {people 인덱스, 값}
#include <algorithm>

// 응급환자 순서를 제공해드립니다. vector<int>
// 먼저 진료해야하는 환자가 1번부터 시작합니다.

// 트리에 저장 방식을 응용해서 가장 큰수를 찾는 형태를 구현하면 어떨까?

void EmergencyExample()
{
	std::vector<int> people = { 10,5,7,25,4,27,9 };

	std::vector<int> answer;
	answer.assign(people.size(), 0);
	
	//answer.push_back() // 인덱스값에 +1 들어간다.
	
	std::map<int, int> sheets;
	//sheets.insert({ 0, people[0] });
	//sheets.insert({ 1, people[1] });
	//sheets.insert({ 2, people[2] });
	//sheets.insert({ 3, people[3] });
	//sheets.insert({ 4, people[4] });
	//sheets.insert({ 5, people[5] });
	//sheets.insert({ 6, people[6] });

	for (int i = 0; i < people.size();i++)
	{
		sheets.insert({ i,people[i] });
	}

	// people 정렬

	// sheets 각 숫자에 들어잇는 인덱스
	//int key = sheets.find(answer[answer.size() - 1])->first; 

	std::sort(people.begin(), people.end());

	// answer에 들어있는 가장 큰 수?

	//answer[key] = 1;

	/*
	* Tree 노트 삭제
	* Tree 균형이 안잡힌 경우
	* Ideal. 트리에 데이터를 넣을 때 균형잡히게 넣으면 되는거 아닌가?
	* 채워 넣은 다음에 서브트리들이 하나의 규칙을 갖도록 해보자.
	* Heap : 서브트리의 부모노트가 가장 큰수여야 한다. 
	* 가장 위에 있는 노드가 가장 큰 수 : maxHeap
	* 가장 위에 있는 노드가 가장 작은 수 : minHeap
	* hepify() - 트리를 힙순서로 재정렬하는 코드 함수
	* heapSort() - 힙 정렬
	*/

	for (int i = 0;i < people.size();i++)
	{

		auto it = sheets.find(people[people.size() - 1-i]);
		int key = it->first;
		answer[key] = i + 1;
	}

	//answer = people;

	std::cout << "[";
	for (int i = 0; i < answer.size();i++)
	{
		std::cout << answer[i] << " ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
	EmergencyExample();
}