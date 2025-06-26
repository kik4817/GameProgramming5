#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

/*
* 1. DFS
*	- �׷����� ��� ������ �Ǿ� �ִ°�? connected Graph
*	- �ٽ� ���̵�� : �׷���(��,��)
*	- ���� ������ �����Ǿ� �ִ�.
*	- ���࿡ �� ���̿� ����� ���� ���ٸ� ��ȸ�ϸ鼭 ���� ���� ������ ������Ű�� ��� ��, ���� ���� �ٸ��� ���� ���̴�.
*/

class Graph
{
	int V; // ���� ���� (����, ���)
	//int[y][x] map;
	vector<vector<int>> adj; // �� ������ ������ ���� �����ϴ� 2���� �迭

	vector<bool> visited;    // �ѹ� ������ ���� �ô�(��ȴ�)

	void DFS(int v)
	{
		// v�湮, visited = true
		visited[v] = true;
		cout << v << " ";

		for (auto& i : adj[v])
		{
			// adj B, C, D ("B")->DFS����, ��� ���
			if (!visited[i]) //if(visited[i] == flase) ���࿡ �湮�� �ߴٸ� DFS ��������������
				DFS(i); // DFS(B) -> DFS(C) -> DFS(D)
		}
	}

	void DFSIter(int v)
	{
		// �湮�� ���� ture ��ȯ�մϴ�.

		// ��� �Լ� ����� ������� �ʰ� �ݺ��� ����ؼ� ǥ���غ�����
		stack<int> stack;
		stack.push(v);

		while (!stack.empty())
		{
			int cVertex = stack.top();
			stack.pop();

			// stack : �����͸� ���� �� ���� �������� ���� �����͸� ���� �����϶�
			// �ݺ��� �������� �����͸� �����ϰ� ����� �ش�.
			if (!visited[cVertex] == false)
			{
				visited[cVertex] == true;
				cout << cVertex << " ";

			}

			// �̿� ���
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
		q.push(start); // �׷����� ���� ��带 ����

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			cout << c << " ";

			// c�� ����Ǿ� �ִ� ��带 �����ϴ� �ڵ� adj[c]
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
		// 1. ��� �Լ��� Ż�� ������ �ۼ��غ����� (q�� empty�϶�)
		// BFS �ݺ������ �ڵ带 ���⿡ �����ͺ�����
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

	// ������, ���� ����, 2����� �迭�� v�� ���� ��ŭ ��� 0���� �ʱ�ȭ
	Graph(int vertices) : V(vertices)
	{
		adj.resize(V);
		visited.resize(V, false); // �湮�� ���ѻ��·� ����
	}

	void addEdge(int u, int v) // �ֹ���, �ܹ��� ����
	{
		adj[u].push_back(v); // u�� 1, v�� 2 - 1�� ���� ����� �� :2
		adj[v].push_back(u); // �ֹ���
	}

	void PrintGraph()
	{
		for (int i = 0;i < V;i++)
		{
			cout << "����" << i << "�� ������ ����Ʈ : ";
			for (auto& elem : adj[i])
			{
				cout << "->" << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		// �湮�� ������ ���½�Ų��.
		fill(visited.begin(), visited.end(), false);

		cout << "DFS ��� ��� Ž�� ��� (���� ���� : " << startV << ")" << endl;
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "DFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")" << endl;
		DFS(startV);
		cout << endl;
	}

	void BFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false); // �湮 ������ �ʱ�ȭ �ϴ� �ڵ�

		cout << "BFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")" << endl;
		BFSIter(startV);
		cout << endl;
	}

	void BFSTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);

		cout << "BFS ��� ��� Ž�� ��� (���� ���� : " << startV << ")" << endl;
		BFS(startV);
		cout << endl;
	}

	// ��� �׷����� ����Ǿ� �ֳ���?

	void DFSCount(int& count, int startV)
	{
		// DFS - stack
		//stack<int> s;
		//s.push(startV);
		visited[startV] = true;
		count++; // ��� ��� count ����

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
		// DFS ��ȸ�ϸ鼭 ��� ��ſ� count���� �������Ѷ�.
		DFSCount(count, startV);
		return count == V;
	}

	void CheckGraphIsConnected()
	{
		if (IsConnected(0))
		{
			cout << "��� �׷����� ����Ǿ����ϴ�." << endl;
		}

		else
		{
			cout << "������� ���� �׷����� �����մϴ�." << endl;
			cout << "-1";
		}
	}

	// ��� ã�� (�ּ��� �Ÿ��� ã�� ����) - BFS, ���ͽ�Ʈ��(����� ���� �� ���� ã�� ���), ����
	// start > end

	vector<int> refindPath(vector<int>& parent, int start, int end)
	{
		vector<int> path;

		if (parent[end] == -1 && start != end) // parent -1�� �ʱ�ȭ. ������ ���Ѵ�? ���� ��ã�Ҵ�.
		{
			return path; // ��ΰ� ���� �����͸� ��ȯ
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
		if (start == end) return { start }; // ���� 1���϶�

		fill(visited.begin(), visited.end(), false);

		vector<int> parent(V, -1); // ��ǥ ���������� �迭�� �����Ѵ�.
		vector<int> distance(V, -1); // �ּ� �Ÿ��� �����ϴ� �迭
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			// while ���� �����ؾ��ϴ� ����
			if (end == c) break; // ���� ��尡 ��ǥ ������ ����������

			// ������ ��������?
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
	cout << "0���� 5�� �̵��ϴ� �ּ� �Ÿ�" << endl;
	for (auto& e : temp)
	{
		cout << "->" << e;
	}

	
}