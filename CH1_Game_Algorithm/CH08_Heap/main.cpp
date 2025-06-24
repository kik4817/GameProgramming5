/*
* 0, k��° ���� ã�� ���� ����, delete temp �����ϴ� ��
* 1. Heap Ư���� ��Ģ�� ���� �ִ� �ڷᱸ���� ���� �����غ���
* 2. k��° �����ϴ� ���� �� ���� ã�� �� �ֳ�. -> ���� ����
*/

// k��° ���� ã��

// 1. vector, array ���ڸ� ���Ľ�Ų �Ŀ� ���� ũ�ų�(����) ���� ã�´�.(���� �˰��� �ð�)
// 2. ��ü ������ n���� ������ n-1�� �񱳸� �ؾ��Ѵ�. (��� ����� ���� Ž��, ���� Ž��)
// 3. �ð� logN�� �ɸ��� ����� ������?(-> �������� ���� �鸸�� �̻�(ó���ؾ��� �����Ͱ� ������) �� �� ��� �ؾ� �ϳ�?
// ���࿡ ó���ؾ��� �����Ͱ� ������, (10 -> 1)

// Tree (���������� �����Ͱ� ����� ��� ȿ�������� �ʴ�.)
// 1. ������ �ذ��ϱ� ���� �ϳ��� ������� Ʈ�� ���·� ���� ������ �ϴ� �����͸� �־��.(Ʈ���� ���ʴ�� �����Ѵ�. ���� ���� Ʈ��)
// 2. root �������� ���� ū �� ( ���� ���� ��)�� �����ϵ��� ��Ģ�� �����Ѵ�.
// ���� ��Ģ�� ���� �ڷᱸ�� ��(heap)�̶�� �θ���. maxHeap, minHeap

#include <iostream>
#include <queue>
#include <algorithm>

void PrioitQueue()
{
	std::priority_queue<int> pq;

	// heap �ڷᱸ���� ������� Ŭ�����Դϴ�.
}

// MaxHeap ������ ���� MinHeap�� ���� �����غ��� (1)�ڽ��� �� ����غ�����!!

#pragma region MaxHeap

class MaxHeap
{
private:

	struct Node
	{
		int value;
		Node* leftNode;
		Node* rightNode;
		Node* parentNode;

		Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr), parentNode(nullptr) {}
	};

	Node* root;
	int size;

	/*
	* (*node).value
	* node->value
	*/

	/*
	* �θ� ��带 �������� ū �༮�� �ٲٸ� �ȵȳ���?
	* heap�� Ư¡�� �����Ͱ� ���� �� heap�� ������ �����ϰ� �ִ� ����
	* ���� ���� �༮�� ��Ģ�� �µ��� �����ϸ� �ȴ�.
	*/

	void heapifyup(Node* node) // ���� �߰��� ��� node
	{
		// node�� �θ� ��带 �����ͷ� ����Ű�� �ִ�. node->parentNode->value		node->value

		// while(1�� ���� && 2�� ����)
		// 1. �߰��� ���� �θ� ����� ���� ���ϴ� �ڵ带 ��������. ���� �߰��� ��尡 �� Ŭ��
		// 2. ���� �߰��� ����� �θ� ��尡 �����ϸ� ��� �����ϼ���

		// node->parentNode ���� ��

		while (node->parentNode != nullptr && node->value > node->parentNode->value) // ������ �ϱ� ���� ����
		{
			// �˰��� ����� �߰����ش�����, �θ� ���� �ڱ� ��带 swap���ش�
			// swap�Ŀ� node�� �θ� ���� �������ش�. (�θ� ��带 ����Ű�� �ִ� ���� �����Ѵ�.)
			std::swap(node->value, node->parentNode->value);
			node = node->parentNode;
		}
	}

	Node* findLastNode() // ��带 ������ �� ��Ģ1�� ������Ű�� ���ؼ� ���� ������ ��带 ã�´�.
	{
		if (!root) return nullptr; // �����Ͱ� 1���� ���� ��� �������� ������.

		std::queue<Node*> q;
		q.push(root);
		Node* lastNode = nullptr;

		while (!q.empty())
		{
			lastNode = q.front();
			q.pop();
			if (lastNode->leftNode)
			{
				q.push(lastNode->leftNode);
			}
			if (lastNode->rightNode)
			{
				q.push(lastNode->rightNode);
			}			
		}

		return lastNode;
	}

	void heapifydown(Node* node)
	{
		// ��Ʈ�� �ø� ������ ��带 �� �ڽ� ���(����, ������) �߿��� ū ���� ��ü�Ѵ�.
		// �ڽ��� ����, ������ ��庸�� �ڱⰡ �� ũ�ų�, �� �̻� �ڽ��� ���� �� ���� �ݺ��ض�.

		while (node)
		{
			Node* largest = node; // ���� ��尡 ���� ũ��(����)

			if (node->leftNode && node->leftNode->value > largest->value)
			{
				largest = node->leftNode;
			}

			if (node->rightNode && node->rightNode->value > largest->value)
			{
				largest = node->rightNode;
			}

			// ���ʰ� ������ �߿��� ū ���� �ٲ��.
			if (largest = node) // ���࿡ ������ �ȵ�����
			{
				break;
			}

			std::swap(node->value, largest->value);
			node = largest;
		}
	}

	void deleteNode(Node* node)
	{
		if (!node) return;

		deleteNode(node->leftNode);
		deleteNode(node->rightNode);
		delete node;
	}
	
public:

	MaxHeap() : root(nullptr), size(0) {}

	void insert(int value)
	{
		Node* newNode = new Node(value);

		if (root) // �����Ͱ� 0���� ���, ���� ���� �����Ͱ� ��Ʈ�� �ȴ�.
		{
			root = newNode;
			size = 1;
			return;
		}

		// ��Ʈ�� ������ ���, ��Ģ1�� ���� ������� ��尡 ����� �� �ְ� ������ �ۼ��ϼ���
		// ���ʿ� �����Ͱ� ������ -> ���ʿ� ������ �ֱ�
		// ���ʿ� �����Ͱ� ������? -> �����ʿ� ������ �ֱ�

		std::queue<Node*> q; // FIFO
		q.push(root);

		while (!q.empty()) // q�� �����Ͱ� ���� ���� �ݺ��ϼ���.
		{
			Node* currentNode = q.front();
			q.pop();

			if (!currentNode->leftNode) // ���ʿ� �����Ͱ� ������-> ���� ������ �ֱ�.
			{
				currentNode->leftNode = newNode; // ���� ����� ���� �ڽĿ� ���ο� �����͸� �־���.
				newNode->parentNode = currentNode; // �ڽ��� �θ� �������ش�.
				break;
			}
			// ���ʿ� �����Ͱ� ������?
			if (!currentNode->rightNode) // �����ʿ��� �����Ͱ� ������ -> ������ ������ �ֱ�
			{
				currentNode->rightNode = newNode;
				newNode->parentNode = currentNode;
				break;
			}
			// root�� ���̻� ����� ��尡 ���� �� ���� �ݺ��ϱ� ���ؼ� ����� ������ �߰����ִ� �ڵ�.
			q.push(currentNode->leftNode);
			q.push(currentNode->rightNode);
		}
		size++;
		heapifyup(newNode);

	}

	int extractMax() // �ִ밪�� �����϶�. front, pop
	{
		if (!root) return -1; // -1 �����ϸ� ������ �ִ� �ſ���
		
		int maxValue = root->value;

		if (size == 1) // 1���� ���� ���� 1���� ���ְ� �ִ밪�� ��ȯ�Ѵ�.
		{
			delete root;
			root = nullptr;
			size = 0;
			return maxValue;
		}

		// 1. ������ ��带 ã������
		Node* lastNode = findLastNode();
		if (!lastNode) return -2; // if(-1) ������ 0, (-2) ������ ��带 ã�� �ڵ尡 ������ �ֽ��ϴ�.

		// 2. ������ ��带 root ���� �̵���Ų �� �ٽ� heap ������ ������ �����ϼ���
		root->value = lastNode->value; // ���� �ؿ��ִ� ��带 �����״µ�, ���� root���� ������ ���� ����ִ�.

		// ����� ���ؼ� ����Ű�� �ִ� ���� ������ ���
		if (lastNode->parentNode)
		{
			// �θ� ��忡�� ���ʰ� ������ �߿��� ū ���� �θ��� ���� �ø��� �ʹ�.
			// lastNode�� ���� root�� �ö����ϱ� ���� lastNode�� �մ� �ּҸ� nullptr�� �ٲٱ�
			if (lastNode->parentNode->leftNode == lastNode) // ������ ��尡 �θ����� ���ʿ� �ִ� ���
			{
				lastNode->parentNode->leftNode == nullptr;
			}
			else // ������ ��尡 �θ� ����� �����ʿ� �մ� ���
			{
				lastNode->parentNode->rightNode == nullptr;
			}

			delete lastNode;
			size--;
			heapifydown(root);

			return maxValue;
		}
	}

	std::vector<int> toArray()
	{
		std::vector<int> result;

		// ������ ������ �ڷᱸ���� vector�� ��ȯ�غ�����
		// while queue�ڷ����� ����ؼ� �����͸� Ž���ϴ� ������ �ڵ�

		if (root) return result; // ����ó��

		std::queue<Node*> q;
		q.push(root); // root�� nullptr

		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();
			result.push_back(node->value);

			if (node->leftNode);
			{
				q.push(node->leftNode);
			}

			if (node->rightNode);
			{
				q.push(node->rightNode);
			}

		}

		return result;
	}


};

#pragma endregion

#pragma region MinHeap

class MinHeap
{

};

#pragma endregion

/*
* RPG����, �������̵�, 5����Ƽ.[����, ����, �ü�, ������, ������]
* ������ �������� ��ų�� ����� �� ���� ���� ��׷ΰ� �����մϴ�.
* �� 5���� ���� ���� ���� ������ �켱������ �����ϴ��� ã�� ������ �ۼ��غ�����
* �̶� ������ Ư�� ������ ������ �� ���� �� ������ ��׷δ� 0���� �ʱ�ȭ�� �˴ϴ�.
*		   1��    2��   3��   4��   5��
* ����   :  10     5     8    7     6 {�����ϰų�, �������� ��ų�� ���� �� ��ġ�� ����)
* ����   : 
* �ü�   : 
* ������ : 
* ������ : 
* 
* [������ ��ų�� �����ϴ� ����]
* ���� : ��Ƽ������ ���� ���� �������ΰ�? ���� ���� �� �������ΰ�?
* 
* (1) n���� ���� ���� �켱������ �� ����ū ������ ����Ѵ�.
* (2) Heap �ڷᱸ���� ����ؼ� x��° ������ ã�´�.
* 
* ������ ������ �������� 1�� �ݽ��� ȿ�����̴�.
* 
*/

int main()
{
	MaxHeap mxHeap;

	std::cout << "���� ū ���� ã�� Heap ������ �Է�" << std::endl;

	mxHeap.insert(7);
	mxHeap.insert(3);
	mxHeap.insert(5);
	mxHeap.insert(11);

	std::cout << "Heap�ڷᱸ���� Ʈ�� ���� ������� ����ϴ� ����" << std::endl;
	std::vector<int> tempV = mxHeap.toArray();

	for (auto& data : tempV)
	{
		std::cout << data << " ";
	}

	std::cout << "���� ū ���� ��ȯ�ϰ� �ٽ� Heap ���� �ϴ� ����" << std::endl;
	int maxValue = mxHeap.extractMax(); // 1��° ū ��
	int k = 2;
	int kthValue;
	for (int i = 0;i < k - 1;i++)
	{
		kthValue = mxHeap.extractMax(); // 2��°�� ū �� kthValue ����ȴ�.
	}

	// k��° ū ���� ã�ƶ�

	std::cout << "k��°�� ū ���� : " << kthValue << std::endl;
}