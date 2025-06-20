/*
* �˰��� ��ǥ ����
* - ���� �����ϰ� Ž���ϱ�
* - �ܼ��� ���. �����͸� ���Ľ�Ų��.
* - k��° ������? �������� �ϳ��� ���
* - k��° ū��? ���������� �ϳ��� ���
*/

#include <iostream>
#include <vector>
#include <utility> // pair<int>
#include <map> // insert {people �ε���, ��}
#include <algorithm>

// ����ȯ�� ������ �����ص帳�ϴ�. vector<int>
// ���� �����ؾ��ϴ� ȯ�ڰ� 1������ �����մϴ�.

// Ʈ���� ���� ����� �����ؼ� ���� ū���� ã�� ���¸� �����ϸ� ���?

void EmergencyExample()
{
	std::vector<int> people = { 10,5,7,25,4,27,9 };

	std::vector<int> answer;
	answer.assign(people.size(), 0);
	
	//answer.push_back() // �ε������� +1 ����.
	
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

	// people ����

	// sheets �� ���ڿ� ����մ� �ε���
	//int key = sheets.find(answer[answer.size() - 1])->first; 

	std::sort(people.begin(), people.end());

	// answer�� ����ִ� ���� ū ��?

	//answer[key] = 1;

	/*
	* Tree ��Ʈ ����
	* Tree ������ ������ ���
	* Ideal. Ʈ���� �����͸� ���� �� ���������� ������ �Ǵ°� �ƴѰ�?
	* ä�� ���� ������ ����Ʈ������ �ϳ��� ��Ģ�� ������ �غ���.
	* Heap : ����Ʈ���� �θ��Ʈ�� ���� ū������ �Ѵ�. 
	* ���� ���� �ִ� ��尡 ���� ū �� : maxHeap
	* ���� ���� �ִ� ��尡 ���� ���� �� : minHeap
	* hepify() - Ʈ���� �������� �������ϴ� �ڵ� �Լ�
	* heapSort() - �� ����
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