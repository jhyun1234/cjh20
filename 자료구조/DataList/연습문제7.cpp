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
			cout << manager << "을(를) 찾을 수 없습니다 : " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			cout << manager <<  " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << endl;
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
		cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << endl;

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

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	tree.levelOrder(tree.root);
}
