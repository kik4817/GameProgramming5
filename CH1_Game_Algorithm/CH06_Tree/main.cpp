/*
* ★★★ 탐색과 자료구조를 연관해서 생각해보기 ★★★
* - vector : 선형탐색, 이진탐색
*  - 조건 : 사용하는 컨테이너가 정렬이 되어 있어야한다.
*   - 사용 중인 컨테이너의 특징 : 임의의 값 바로 접근, 랜점한 값을 수정할 때 비효율적이다.
*
* - list : 랜덤한 값의 수정을 즉시 할 수 있다.
*  - mid index의 값과 target비교
*   - 0 -> mid 순차적으로 탐색 후 mid 값을 변환한다.
* 단점 : logN시간을 확보했지만, 사용하기 위한 자료구조가 적합하지 않다.
* 연관 컨테이너 : set, map // 트리 구조로 구현이 되어있다.
*/

/*
* Tree 자료구조
* 데이터를 어떻게 저장하는 형태인가?
* 노드 형태로 데이터를 저장을 한다. value 연결되어 있는 node 주소를 저장한다. 
*/

/*
* Tree 순회 방법
* 
* 1. 전위 순회 pre-order  : NLR
* 2. 중위 순회 in-oreder  : LNR
* 3. 호위 순회 post-oredr : LRN
*/

/*
* BST (Binary Search Tree) 이진 검색 트리
* - 자기 자신과, 왼쪽, 오른쪽을 저장하는 노드를 가지고 있다.
* - Node기준으로 왼쪽과 오른쪽의 값을 비교할 수 있다.
* - 작은 값을 왼쪽으로 큰 값을 오른쪽으로 저장을 하면 규칙성을 갖는다.
* - 특정한 규칙을 갖는 클래스를 만들어서 데이터를 출력해본다.
*/

/*
* 순차 컨테이너 방식의 단점 - 탐색 및 수정이 효율적이지 않다.
* 연관 컨테이너 - "Tree 자료 구조"
* "BST" - 이진 검색 알고리즘으로 자료구조를 표현한 것.
* 단점 : 트리가 한 쪽으로 편향될 경우 O(n) 시간만큼 걸린다.
*/

struct Node
{
	int value;
	Node* leftNode;
	Node* rightNode;

	Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr) {}
};

#include <iostream>
#include <vector>

// 트리로 만들어진 노드가 문제로 주어집니다. 전위 순회로 출력했을 때의 결과를 작성해보세요

#pragma region 트리 순회하는 방식

class Tree
{
public:
	void preOrder(Node* root) // 재귀 방식으로 만든다.
	{
		if (root == nullptr)  // 재귀 탈출 조건
		{
			return;
		}

		// NLR

		std::cout << root->value << " "; // N
		preOrder(root->leftNode); // L에 있는 노드에 가서 preOrder 실행하세요
		preOrder(root->rightNode);// R에 있는 노드에 가서 preOrder 실행하세요
	}
	void inOrder(Node* root)
	{
		if (root == nullptr)  // 재귀 탈출 조건
		{
			return;
		}

		// LNR

		inOrder(root->leftNode);
		std::cout << root->value<< " ";
		inOrder(root->rightNode);
	}
	void postOrder(Node* root)
	{
		if (root == nullptr)  // 재귀 탈출 조건
		{
			return;
		}

		// LRN

		postOrder(root->leftNode);
		postOrder(root->rightNode);
		std::cout << root->value << " ";

	}
};

#pragma endregion

#pragma region 노드 직접 연결

void NodeConnect()
{
	//            [4]
	//        /         \
	//     [2]           [6]
	//    /   \         /
	// [9]     [7]   [1]

	Node* root = new Node(4);
	root->leftNode = new Node(2);
	root->leftNode->leftNode = new Node(9);
	root->leftNode->rightNode = new Node(7);
	root->rightNode = new Node(6);
	root->rightNode->leftNode = new Node(1);

	Tree tree;

	std::cout << "\n트리를 전위 순회 결과 : ";
	tree.preOrder(root);

	std::cout << "\n트리를 중위 순회 결과 : ";
	tree.inOrder(root);

	std::cout << "\n트리를 호위 순회 결과 : ";
	tree.postOrder(root);
}

#pragma endregion

#pragma region BST 구현

// root에서 부터 데이터를 삽입합니다.
// root보다 insert값이 작으면 왼쪽으로 크면 오른쪽으로 저장합니다.
// 모든 데이터를 저장 후 중위순회 방식으로 데이터를 읽으면 오름차순으로 데이터가 정렬이 됩니다.

class BST
{	
private:

	Node* root;

	Node* insert(Node* node, int value)
	{
		// 데이터가 0개 일 때
		if (node == nullptr)
		{
			return new Node(value);
		}

		// node 작으면? 왼쪽, 크면? 오른쪽
		if (node->value > value)
		{
			node->leftNode = insert(node->leftNode, value);
		}
		else if (node->value < value)
		{
			node->rightNode = insert(node->rightNode, value);
		}

		return node;
	}

	void inOrder(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inOrder(node->leftNode);
		std::cout << node->value << " ";
		inOrder(node->rightNode);
	}

public:

	BST()
	{
		root = nullptr;
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	// 준위 순회로 root를 읽는 코드를 만들어보세요

	void inOrder()
	{
		inOrder(root);
		//std::cout << std::endl;
	}

};

#pragma endregion

int main()
{
	NodeConnect();
	
	// std::cout<<"\n이진 트리 데이터 입력 예시" BST bst. bst.insert(4,2,6,9,7,1)
	std::cout << "\n이진 트리 데이터 입력 예시" << std::endl;

	BST bst;
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	bst.insert(9);
	bst.insert(7);
	bst.insert(1);
	bst.inOrder();
	
	
}