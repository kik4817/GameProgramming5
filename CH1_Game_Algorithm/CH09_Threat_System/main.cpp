/*
* RPG게임, 보스레이드, 5인파티.[전사, 도적, 궁수, 마법사, 성직자]
* 각각의 직업들은 스킬을 사용할 때 마다 보스 어그로가 증가합니다.
* 총 5번의 보스 공격 마다 누구를 우선쪽으로 공격하는지 찾는 로직을 작성해보세요
* 이때 보스가 특정 직업을 공격할 때 마다 그 직업의 어그로는 0으로 초기화가 됩니다.
*		   1턴    2턴   3턴   4턴   5턴
* 전사   :  10     5     8    7     6 {강력하거나, 위협적인 스킬일 수록 그 수치가 높다)
* 도적   :
* 궁수   :
* 마법사 :
* 성직자 :
*
* [보스와 스킬을 결정하는 로직]
* 보스 : 파티원에서 누가 가장 위협적인가? 누가 가장 덜 위협적인가?
*
* (1) n개의 직업 마다 우선순위를 비교 가장큰 순위를 출력한다.
* (2) Heap 자료구조를 사용해서 x번째 순위를 찾는다.
*
* 갯수가 적으면 적을수록 1번 반식의 효율적이다.
*
*/

#include <iostream>
#include <vector>
#include <queue>   // queue, pariority_queue
#include <utility> // pair

using namespace std;

// maxHeap, minHeap
// 1번 우선순위 큐를 이용해서 합구조를 작성해봅시다.

bool myLess(int a, int b)
{
	return a < b;
}

bool myGreater(int a, int b)
{
	return a > b;
}

// k번째로 작은 수 구하기, k번째로 큰 수 구하기 우선순위 큐를 사용하면 쉽게 표현할 수 있다.
// logN시간으로 k 번째 작은 수를 찾을 수 있다 -> (k번째 수를 찾는다. 1:1대응 N시간으

class MinHeap // 가장 작은 수가 제일 위에 있는 구조.
{
private:
	priority_queue<int, vector<int>, greater<int>> pq; // 최소값이 제일 위로 올라가는 형태
	//priority_queue<int> pq2; 위에와 같다

public:

	MinHeap() = default;

	// push, pop, empty, top(= extractMax)
	void push(int value) 
	{
		pq.push(value);
	}

	bool isEmpty() const
	{
		return pq.empty();
	}

	const int& top() const // 저장되어있는 가장 위의 값을 참조한다.
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}

		return pq.top();
	}

	int pop() // 복사를 한 후에 자료구조에서 삭제
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		int minValue = pq.top();
		pq.pop();
		return minValue;
	}
};

class MaxHeap
{
private:
	priority_queue<int, vector<int>, less<int>> pq2;

public:

	MaxHeap() = default;

	void push(int value)
	{
		pq2.push(value);
	}

	bool isEmpty() const
	{
		return pq2.empty();
	}
	
	const int& top() const
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		return pq2.top();
	}

	int pop()
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		int maxValue = pq2.top();
		pq2.pop();
		return maxValue;
	}


};

void FindkthExample()
{
	MinHeap myHeap;

	myHeap.push(11);
	myHeap.push(7);
	myHeap.push(5);
	myHeap.push(3);

	cout << "최소 힙의 가장 작은 값 : " << myHeap.top() << endl;

	int k = 3;

	// for 반복문을 k로 표현하여 k번째 수를 찾아보세요

	cout << "k번째 작은 수를 출력하세요." << endl;

	MaxHeap mMaxHeap;

	mMaxHeap.push(11);
	mMaxHeap.push(7);
	mMaxHeap.push(5);
	mMaxHeap.push(3);

	cout << "최대 힙의 가장 큰 값 : " << mMaxHeap.top() << endl;
}

// 전사, 마법사, 궁수, 도적, 성직자
// 전사 : 10, 5, 8, 7, 6

class Character
{
private:
	string name;
	vector<int> threatLevel; // threatLevel {10,5,8,7,6}
	int currentTurn;

public:
	Character(string name, vector<int> TL) : name(name), threatLevel(TL), currentTurn(0) {}

	int getCurrentThreat()
	{
		if (threatLevel.size() <= currentTurn) //return -1; // -1리턴하면 에러로 인식하세요
		{
			throw runtime_error("Out of Range");
		}
		return threatLevel[currentTurn];
	}

	void NextTurn()
	{
		currentTurn++;
	}
	
	void PrintStat()
	{
		cout << name << "(현제 위험도 : " << getCurrentThreat() << ")" << endl;;
	}
};

class Boss
{
public:
	string name;
	int currentTurn;
	priority_queue<int> threatQueue; // priority_queue<int, int> TQ;
	Boss(string name) : currentTurn(0) {}

	void clear()
	{		
		while (!threatQueue.empty())
		{
			threatQueue.pop();
		}
	}

	void UpdateThreatQueue(vector<Character>& party)
	{
		for (auto& character : party)
		{
			clear();

			int threat = character.getCurrentThreat();
			threatQueue.push(threat);
			character.NextTurn(); // 파티의 모든 캐릭터의 턴을 1 증가시킨다.
										// 위협도가 가장 큰수를 저장
		}
	}

	int FindMostThreatCharacter(vector<Character>& party)
	{
		//Character* target = nullptr;

		int MostThreatValue = threatQueue.top();

		return MostThreatValue;
	}

	void Attack()
	{
		// targetr = FIndTarget();
		// character.TakeDamage();
	}
};

void ThreatSystem()
{
	Character a("전사", { 1,2,3,4,5 });
	Character b("도적", { 1,1,1,10,5 });
	Character c("궁수", { 3,3,3,3,3 });
	Character d("마법사", { 0,1,6,6,6 });
	Character e("성직자", { 0,0,10,10,10 });

	//a.PrintStat();

	vector<Character> party;

	party.push_back(a);
	party.push_back(b);
	party.push_back(c);
	party.push_back(d);
	party.push_back(e);

	for (auto& character : party)
	{
		character.PrintStat();
	}

	// 보스가 가장 위협도가 높은 숫자를 찾도록 해보세요
	Boss boss("킹고블린");
	boss.UpdateThreatQueue(party); // 첫번째 턴
	int value = boss.FindMostThreatCharacter(party);
	cout << "첫번째 턴에서 위헙도가 가장 큰 수치 : " << value << endl;

	boss.UpdateThreatQueue(party);
	value = boss.FindMostThreatCharacter(party);
	cout << "두번째 턴에서 위헙도가 가장 큰 수치 : " << value << endl;

	int nextTurnValue = 3;
	
	int currentThreat = 0;
	for (int i = 0; i < nextTurnValue;i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}

	cout << "전사의 3번 후 위협도 : " << currentThreat << endl;
}

int main()
{
	//FindkthExample();
	ThreatSystem();
}