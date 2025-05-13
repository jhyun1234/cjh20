#include<iostream>
#include<queue>
#include<string>

using namespace std;
struct Node
{
	string position;
	Node* first;
	Node* second;
};

struct tree
{
	Node* root;

	static tree create_structure(const string& pos)
	{
		tree tree;
		tree.root = new Node{ pos,NULL,NULL };
		return tree;
	}

	static Node* find(Node* root, const string& value)
	{
		if (root == NULL)
			return NULL;

		if (root->position == value)
			return root;

		auto firstFound = tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return tree::find(root->second, value);
	}


	bool addSubordinate(const string& manager, const string& subordinate)
	{
		auto managerNode = tree::find(root, manager);

		if (!managerNode)
		{
			cout << manager << "��(��) ã�� �� �����ϴ� : " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			cout << manager <<  " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}
		
		if (!managerNode->first)
		{
			managerNode->first = new Node{ subordinate,NULL,NULL };
		}
		else
		{
			managerNode->second = new Node{ subordinate,NULL,NULL };
		}
		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << endl;

		return true;

	}

	static void levelOrder(Node* start)
	{
		if (!start)
			return;
		queue<Node*> q;
		q.push(start);


		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				auto current = q.front();
				q.pop();

				cout << current->position << " , ";
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}
			cout << endl;
		}
	}




};
int main()
{
	auto tree = tree::create_structure("CEO");

	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");

	tree.levelOrder(tree.root);
}
