/*
* �ڡڡ� Ž���� �ڷᱸ���� �����ؼ� �����غ��� �ڡڡ�
* - vector : ����Ž��, ����Ž��
*  - ���� : ����ϴ� �����̳ʰ� ������ �Ǿ� �־���Ѵ�.
*   - ��� ���� �����̳��� Ư¡ : ������ �� �ٷ� ����, ������ ���� ������ �� ��ȿ�����̴�.
*
* - list : ������ ���� ������ ��� �� �� �ִ�.
*  - mid index�� ���� target��
*   - 0 -> mid ���������� Ž�� �� mid ���� ��ȯ�Ѵ�.
* ���� : logN�ð��� Ȯ��������, ����ϱ� ���� �ڷᱸ���� �������� �ʴ�.
* ���� �����̳� : set, map // Ʈ�� ������ ������ �Ǿ��ִ�.
*/

/*
* Tree �ڷᱸ��
* �����͸� ��� �����ϴ� �����ΰ�?
* ��� ���·� �����͸� ������ �Ѵ�. value ����Ǿ� �ִ� node �ּҸ� �����Ѵ�. 
*/

/*
* Tree ��ȸ ���
* 
* 1. ���� ��ȸ pre-order  : NLR
* 2. ���� ��ȸ in-oreder  : LNR
* 3. ȣ�� ��ȸ post-oredr : LRN
*/

/*
* BST (Binary Search Tree) ���� �˻� Ʈ��
* - �ڱ� �ڽŰ�, ����, �������� �����ϴ� ��带 ������ �ִ�.
* - Node�������� ���ʰ� �������� ���� ���� �� �ִ�.
* - ���� ���� �������� ū ���� ���������� ������ �ϸ� ��Ģ���� ���´�.
* - Ư���� ��Ģ�� ���� Ŭ������ ���� �����͸� ����غ���.
*/

/*
* ���� �����̳� ����� ���� - Ž�� �� ������ ȿ�������� �ʴ�.
* ���� �����̳� - "Tree �ڷ� ����"
* "BST" - ���� �˻� �˰������� �ڷᱸ���� ǥ���� ��.
* ���� : Ʈ���� �� ������ ����� ��� O(n) �ð���ŭ �ɸ���.
*/

/*
* Ʈ�� �ڷᱸ���� ���
* ��� : ��(value), ���� ��� �ּ�, ������ ��� �ּ�, Ʈ���� �⺻ ��Ҹ� �����ϴ� ������ ����
* �θ� ��� : ������ ����� ���� ����� ���
* �ڽ� ��� : �θ� ����� ������ ���� ����� ���
* ��Ʈ ��� : Ʈ���� �ֻ����� �ִ� ���, �θ� ��尡 �����ϴ�.
* ���� ��� : Ư�� ��忡�� ��Ʈ������ ��ο� �ִ� ��� ����
* �ļ� ��� : Ư�� ����� ��� �ڽĵ��� ������ ����
* 
* -�˰��� Ʈ�� �ڵ� ���� �� ���Ǵ� ���
* ����(level) : ��Ʈ�� ������ �Ÿ��� ���մϴ�. ��Ʈ�� 0�� ��ȯ�մϴ�.
* ���� : Ʈ������ ���� ���� ���� ���Ѵ�.
* ���� : Ư�� ��忡�� ��Ʈ������ �����Դϴ�.
* ���� ���� : Ʈ�� ������ �ļյ�� ������ �Ǵٸ� Ʈ���Դϴ�.
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

// Ʈ���� ������� ��尡 ������ �־����ϴ�. ���� ��ȸ�� ������� ���� ����� �ۼ��غ�����

#pragma region Ʈ�� ��ȸ�ϴ� ���

class Tree
{
public:
	void preOrder(Node* root) // ��� ������� �����.
	{
		if (root == nullptr)  // ��� Ż�� ����
		{
			return;
		}

		// NLR

		std::cout << root->value << " "; // N
		preOrder(root->leftNode); // L�� �ִ� ��忡 ���� preOrder �����ϼ���
		preOrder(root->rightNode);// R�� �ִ� ��忡 ���� preOrder �����ϼ���
	}
	void inOrder(Node* root)
	{
		if (root == nullptr)  // ��� Ż�� ����
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
		if (root == nullptr)  // ��� Ż�� ����
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

#pragma region ��� ���� ����

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

	std::cout << "\nƮ���� ���� ��ȸ ��� : ";
	tree.preOrder(root);

	std::cout << "\nƮ���� ���� ��ȸ ��� : ";
	tree.inOrder(root);

	std::cout << "\nƮ���� ȣ�� ��ȸ ��� : ";
	tree.postOrder(root);
}

#pragma endregion

#pragma region BST ����

// root���� ���� �����͸� �����մϴ�.
// root���� insert���� ������ �������� ũ�� ���������� �����մϴ�.
// ��� �����͸� ���� �� ������ȸ ������� �����͸� ������ ������������ �����Ͱ� ������ �˴ϴ�.

class BST
{	
private:

	Node* root;

	Node* insert(Node* node, int value)
	{
		// �����Ͱ� 0�� �� ��
		if (node == nullptr)
		{
			return new Node(value);
		}

		// node ������? ����, ũ��? ������
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

	Node* findMin(Node* node)
	{
		if (node == nullptr||node->leftNode==nullptr)
		{ 
			return node; 
		}
		
		return findMin(node->leftNode);
	}

	Node* findMax(Node* node)
	{
		if (node == nullptr || node->rightNode == nullptr)
		{
			return node;
		}

		return findMax(node->rightNode);
	}

	Node* deleteNode(Node* node, int target) // ����, �����͸� ã�� ������ ������ �����.
	{
		if (node == nullptr) { return nullptr; }

		if (node->value > target) // ���� ���� �̵��ϼ���.
		{
			node->leftNode = deleteNode(node->leftNode, target);
		}

		else if (node->value < target) // ������ ���� �̵��ϼ���.
		{
			node->rightNode = deleteNode(node->rightNode, target);
		}
		
		else // ���� �����͸� ã�� ���. �� ��带 �������ּ���.
		{
			// ã�Ҵ�. �����ض�.
			
			//if (node->rightNode == nullptr && node->leftNode == nullptr);
			//if (node->leftNode == nullptr);
			//if (node->rightNode == nullptr);
			// �� �Ʒ��ʿ� �����ϰ� ǥ�� ��

			// �ڽ��� 0 ~ 1�� �ΰ��
			if (node->leftNode == nullptr || node->rightNode == nullptr)
			{
				Node* temp = node->leftNode != nullptr ? node->leftNode : node->rightNode; // ����, ������ üũ

				if (temp == nullptr) // �ڽ��� ���� ���
				{
					temp = node;
					node = nullptr;
				}

				else
				{					
					node = temp;
				}
			}

			else // �ڽ��� ���� ���
			{
				// �����ʿ��� ���� ���� ���� ã�ڴ�. findMin();

				Node* temp = findMin(node->rightNode);
				node->value = temp->value;
				node->rightNode = deleteNode(node->rightNode, temp->value);

				// �������� ���� ���� ���� ã����. findMax();
				
				//Node* temp = findMax(node->leftNode);
				//node->value = temp->value;
				//node->leftNode = deleteNode(node->leftNode, temp->value);
			}
		}

		return node;

		//if (node->value == target) {} // ���ȿ� ����ִ� ���� target������ �� ��带 �����ּ���.		

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

	// ���� ��ȸ�� root�� �д� �ڵ带 ��������

	void inOrder()
	{
		inOrder(root);
		//std::cout << std::endl;
	}

	void DeleteNode(int value)
	{
		root = deleteNode(root, value);
	}

};

#pragma endregion

int main()
{
	NodeConnect();
	
	// std::cout<<"\n���� Ʈ�� ������ �Է� ����" BST bst. bst.insert(4,2,6,9,7,1)
	std::cout << "\n���� Ʈ�� ������ �Է� ����" << std::endl;

	BST bst;
	bst.insert(4);
	bst.insert(2);
	bst.insert(6);
	bst.insert(9);
	bst.insert(7);
	bst.insert(1);
	bst.inOrder();
	
	std::cout << "\n6������ ������ ��� ����" << std::endl;
	bst.DeleteNode(6);
	bst.inOrder();
	
	
}