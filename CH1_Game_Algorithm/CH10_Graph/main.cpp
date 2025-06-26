/*
* 1. 정렬 (데이터 순서 대로 나열)
* 2. 탐색 (데이터의 수정 및 삭제)
* 
* - vector 정렬 시키고 이진 탐색
* - Tree 자료 구조, 이진 검색 트리
* - Heap (우선순위 큐 priority_queue)
* 
* - Graph 탐색
*/

/*
* 그래프가 무엇일까?
* - 점(vertex)과 간선(edge)으로 표현한 자료구조이다.
* - <기준>
* 1. 방향(Direction)이 존재하는가 안하는가?
* 2. 순환(Cycle)이 존재하는가?
* 3. 가중치(weight)가 존재하는가?
* 
* Tree : DAG(방향이 존재하고, ACycle 순환이 없는, Graph 그래프)
*/

/*
* 그래서 그래프를 어떻게 표현할 것인가?
* 1. 2차원 배열 (Matrix방식)
* 2. 각 정점에서 연결된 데이터를 자료구조 표현하는 방식
*/

#include <iostream>
#include <vector>
#include <stack> // DFS - stack 표현한다. LIFO
#include <queue> // BFS - queue 표현한다. FIFO

using namespace std;

/*
* 그래프를 Matrix로 표현했을 때 실제로 어덯게 점과 선이 연결되어있는지 알 수 있다.
*   A B C D
* A 0 1 1 1
* B 1 0 1 1
* C 1 1 0 0
* D 1 1 0 0
*/

/*
* A('A'-'0') : (연결된 데이터) B - C - D
* B : A - C - D
* C : A - B
* D : A - B
*/

/*
* 프로그래밍으로 그래프 표현할 수 있게 되었습니다.
* 연결되어 있는 그래프를 탐색을 하는 방법?
* [1] 깊이 우선 탐색 (Depth First Search)
* [2] 너비 우선 탐색 (Breadth First Search) queue를 이용
*/

/*
* 게임 속에서 점과 선으로 연결되어 잇는 이미지를 하나 찾아보세요.
* 점과 선을 그래프로 표현하는 것을 아무 주제나 선택해보세요. 실행해보세요
*/

/*
* 그래프의 탐색 방법(순회)
* 
* - DFS 깊이 우선 탐색 
*	- Stack구현 : 세로
*
* - BFS 너비 우선 탐색
*	- Queue구현 : 가로
*/

/*
* 언제 DFS와 BFS를 사용할 수 있는가?
* - (1) 그래프를 탐색할 때 쉽게 구현할 수 있는 것을 선택하세요.(둘 다 사용할 수 있다.)
* - (2) DFS - 그래프가 순회를 하고 있는지 파악할 때
* - (3) BFS - 특정 위치 까지 최소의 거리로 도달하는 방법을 구할 때
*/

class Graph
{
	int V; // 점의 갯수 (도시, 노드)
	//int[y][x] map;
	vector<vector<int>> adj; // 각 점에서 인접한 점을 저장하는 2차원 배열

	vector<bool> visited;    // 한번 지나간 길은 봤다(들렸다)
	
	void DFS(int v)
	{
		// v방문, visited = true
		visited[v] = true;
		cout << v << " ";

		for (auto& i : adj[v])
		{
			// adj B, C, D ("B")->DFS실행, 재귀 방식
			if(!visited[i]) //if(visited[i] == flase) 만약에 방문을 했다면 DFS 실행하지마세요
			DFS(i); // DFS(B) -> DFS(C) -> DFS(D)
		}
	}

	void DFSIter(int v)
	{
		// 방문한 점은 ture 변환합니다.

		// 재귀 함수 방식을 사용하지 않고 반복문 사용해서 표현해보세요
		stack<int> stack;
		stack.push(v);

		while (!stack.empty())
		{
			int cVertex =  stack.top();
			stack.pop();

			// stack : 데이터를 삽입 후 가장 마지막에 들어온 데이터를 먼저 실행하라
			// 반복문 역순으로 데이터를 실행하게 만들어 준다.
			if (!visited[cVertex] == false)
			{
				visited[cVertex] == true;
				cout << cVertex << " ";
				
			}

			// 이웃 노드
			for (int i = adj[cVertex].size() - 1; i >= 0; i--)
			{
				int neighbor = adj[cVertex][i];
				if (visited[neighbor] == false)
				{
					stack.push(neighbor);
				}
			}

			//for (auto& elem : adj[cVertex])
			//{				
			//	if (!visited[elem])
			//	{
			//		stack.push(elem);
			//		visited[elem] = true;
			//		cout << elem << " ";
			//	}
			//}			
		}
	}

	void BFSIter(int start)
	{
		queue<int> q;
		visited[start] = true;
		q.push(start); // 그래프의 시작 노드를 삽입

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			cout << c << " ";

			// c에 연결되어 있는 노드를 접근하는 코드 adj[c]
			for (int& e : adj[c])
			{
				if (!visited[e])
				{
					visited[e] = true;
					q.push(e);
				}
			}
		}
	}

	void BFSRecursive(queue<int>& q)
	{
		// 1. 재귀 함수의 탈출 조건을 작성해보세요 (q가 empty일때)
		// BFS 반복방식의 코드를 여기에 가져와보세요
		if (q.empty()) { return; }

		// front, pop, push

		int c = q.front();
		q.pop();
		cout << c << " ";

		for (int& e : adj[c])
		{
			if (!visited[e])
			{
				visited[e] = true;
				q.push(e);
			}
		}

		BFSRecursive(q);
	}

	void BFS(int start)
	{
		queue<int> q;
		q.push(start);
		visited[start] = true;
		BFSRecursive(q);
	}

public:

	// 생성자, 점의 갯수, 2차우너 배열을 v의 갯수 만큼 모두 0으로 초기화
	Graph(int vertices) : V(vertices)
	{
		adj.resize(V);
		visited.resize(V, false); // 방문을 안한상태로 변경
	}

	void addEdge(int u, int v) // 쌍방향, 단방향 연결
	{		
		adj[u].push_back(v); // u가 1, v가 2 - 1번 점에 연결된 값 :2
		adj[v].push_back(u); // 쌍방향
	}

	void PrintGraph()
	{
		for (int i = 0;i < V;i++)
		{
			cout << "정점" << i << "의 인접한 리스트 : ";
			for (auto& elem : adj[i])
			{
				cout << "->" << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		// 방문한 경험을 리셋시킨다.
		fill(visited.begin(), visited.end(), false);

		cout << "DFS 재귀 방식 탐색 결과 (시작 지점 : " << startV << ")" << endl;
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "DFS Iterative 방식 탐색 결과 (시작 지점 : " << startV << ")" << endl;
		DFS(startV);
		cout << endl;
	}

	void BFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false); // 방문 경험을 초기화 하는 코드

		cout << "BFS Iterative 방식 탐색 결과 (시작 지점 : " << startV << ")" << endl;
		BFSIter(startV);
		cout << endl;
	}

	void BFSTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "BFS 재귀 방식 탐색 결과 (시작 지점 : " << startV << ")" << endl;
		BFS(startV);
		cout << endl;
	}
};

class GraphMatrix
{
	int V;
	vector<vector<int>> adj;

public:

	GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {} // v * v 2차원 배열을 0으로 초기화

	void addEdge(int u, int v)
	{
		adj[u][v] = 1; // 단 방향
		adj[v][u] = 1; // 쌍방향
	}

	void PrintGrahp()
	{
		cout << "인접 행렬" << endl;
		for (int i = 0;i < V;i++)
		{
			for (int j = 0;j < V;j++)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph g(6);
	//g.addEdge(0, 1);
	//g.addEdge(0, 2);
	//g.addEdge(0, 3);
	//g.addEdge(1, 2);
	//g.addEdge(1, 3);
	//----------------
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.DFSTraverse(3);
	g.DFSIterTraverse(3);
	g.BFSIterTraverse(0);
	g.BFSTraverse(0);

	cout << endl;

	g.PrintGraph();

	cout << endl;

	GraphMatrix gm(4);
	gm.addEdge(0, 1);
	gm.addEdge(0, 2);
	gm.addEdge(0, 3);
	gm.addEdge(1, 2);
	gm.addEdge(1, 3);
	gm.PrintGrahp();

}