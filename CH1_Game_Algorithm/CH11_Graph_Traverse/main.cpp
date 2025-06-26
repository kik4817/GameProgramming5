#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
* 1. DFS
*	- 그래프가 모두 연결이 되어 있는가? connected Graph
*	- 핵심 아이디어 : 그래프(점,선)
*	- 점의 갯수가 고정되어 있다.
*	- 만약에 점 사이에 연결된 길이 없다면 순회하면서 만나 점의 갯구를 증가시키는 결과 값, 점의 수가 다르게 나올 것이다.
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
			if (!visited[i]) //if(visited[i] == flase) 만약에 방문을 했다면 DFS 실행하지마세요
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
			int cVertex = stack.top();
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

	// 모든 그래프가 연결되어 있나요?

	void DFSCount(int& count, int startV)
	{
		// DFS - stack
		//stack<int> s;
		//s.push(startV);
		visited[startV] = true;
		count++; // 출력 대신 count 증가

		for (int e : adj[startV])
		{
			if (!visited[e])
			{
				visited[e] = true;
				//count++;
				DFSCount(count, e);
			}
		}
	}

	bool IsConnected(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		int count = 0;
		// DFS 순회하면서 출력 대신에 count수를 증가시켜라.
		DFSCount(count, startV);
		return count == V;
	}

	void CheckGraphIsConnected()
	{
		if (IsConnected(0))
		{
			cout << "모든 그래프가 연결되었습니다." << endl;
		}

		else
		{
			cout << "연결되지 않은 그래프가 존재합니다." << endl;
			cout << "-1";
		}
	}

	// 경로 찾기 (최소의 거리를 찾는 문제) - BFS, 다익스트라(비용이 있을 때 길을 찾는 방법), 프림
	// start > end

	vector<int> refindPath(vector<int>& parent, int start, int end)
	{
		vector<int> path;

		if (parent[end] == -1 && start != end) // parent -1로 초기화. 접근을 못한다? 길을 못찾았다.
		{
			return path; // 경로가 없는 데이터를 반환
		}

		int current = end;
		while (current != -1)
		{
			path.insert(path.begin(), current);
			current = parent[current];
		}

		return path;
	}

	vector<int> findShortestPath(int start, int end)
	{
		if (start == end) return { start }; // 길이 1개일때

		fill(visited.begin(), visited.end(), false);

		vector<int> parent(V, -1); // 목표 지정까지의 배열을 저장한다.
		vector<int> distance(V, -1); // 최소 거리를 저장하는 배열
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			// while 강제 종료해야하는 조건
			if (end == c) break; // 현재 노드가 목표 지점에 도착했을때

			// 도착을 안했으면?
			for (int e : adj[c])
			{
				if (!visited[e])
				{
					visited[e] = true;
					q.push(e);
					parent[e] = c;
					distance[e] = distance[c] + 1;
				}
			}
		}

		//return parent;
		return refindPath(parent, start, end);
	}

};

int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	//g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.CheckGraphIsConnected();

	cout << endl;

	vector<int> temp = g.findShortestPath(0, 5);
	cout << "0에서 5로 이동하는 최소 거리" << endl;
	for (auto& e : temp)
	{
		cout << "->" << e;
	}

	
}