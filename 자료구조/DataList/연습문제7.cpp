#include<iostream>
#include<queue>
#include<string>

using namespace std;
struct Node
{
	string position; // ��å�Է� ���ڿ�
	Node* first;
	Node* second;
};
struct tree
{
	Node* root;

	// static �Լ�: �� �Լ��� Ư�� tree '��ü'�� ���ϴ� ���� �ƴ϶�, tree '����ü ��ü'�� ���Ѵ�.
	// ���� tree::create_structure() �� ���� Ŭ����(����ü) �̸����� �ٷ� ȣ���� �� �ִ�.
	static tree create_structure(const string& pos) // Ʈ���� ��Ʈ ��带 �����ϴ� �Լ�
	{
		tree tree; // tree Ÿ���� ���� ���� tree�� �����Ѵ�.
		tree.root = new Node{ pos,NULL,NULL }; // ���� ������ Node�� tree�� root�� �����Ѵ�.
		return tree; // ������ tree ��ü�� ��ȯ
	}


	// Ʈ���� Ž���Ͽ� Ư�� ���� ���� ��带 ã�� �Լ�
	// static �Լ��̹Ƿ� tree::find() �� ���� ȣ���Ѵ�.
	static Node* find(Node* root, const string& value)
	{				// Ž���� ������ ��� ������ , ã�� ��

		// ���� ��尡 NULL�̸�(�ش� ��ο� ��尡 ������) ���� ã�� ���� ���̹Ƿ� NULL ��ȯ 
		if (root == NULL)
			return NULL;

		// ���� ����� position ���� ã������ ���� ��ġ�ϸ� ��带 ã�� ���̹Ƿ� ���� ��� ������ ��ȯ
		if (root->position == value)
			return root;

		// ���� ����Ʈ���� Ž���� �õ�
		// tree::find(root->first, value): ���� ����� first �ڽ��� ��Ʈ�� �Ͽ� find �Լ��� ��� ȣ���Ѵ�.
		// auto firstFound: ��ȯ�Ǵ� Node* Ÿ���� �����͸� �����Ѵ�.
		auto firstFound = tree::find(root->first, value);

		// ���� first ����Ʈ������ ���� ã�Ҵٸ�
		if (firstFound != NULL)
			return firstFound; // ã�� ��� �����͸� ��� ��ȯ�ϰ� Ž���� �����Ѵ�.
		
		// first ����Ʈ������ ã�� ���ߴٸ�, ������(second) ����Ʈ������ Ž���� �õ� ã���� ���� ��ȯ�ϰ� Ž�� ����
		return tree::find(root->second, value);
	}

	// ��ü ��� �Լ��� ��ü�� ������ ��, �ش� ��ü�� ���Ͽ� �����Ѵ�.
	bool addSubordinate(const string& manager, const string& subordinate) // manager ��å �Ʒ� subordinate ��å �߰�
	{
		// ���� manager �θ� �ش��ϴ� ��带 Ʈ������ ã�´�.
		// find �Լ��� static�̹Ƿ� tree::find() ���·� ȣ���ϰ�, �� Ʈ���� root���� Ž�� �����Ѵ�.
		auto managerNode = tree::find(root, manager);

		// manager ��带 ã�� ���ߴٸ�
		if (!managerNode) // managerNode�� NULL�� ���
		{
			cout << manager << "��(��) ã�� �� �����ϴ� : " << endl;
			return false;
		}

		// manager ��带 ã������ �̹� �ڽ��� �� �� ��� �� �ִٸ� �� �߰��� �� ����.
		if (managerNode->first && managerNode->second) // first�� second ������ �� �� NULL�� �ƴ� ���
		{
			cout << manager <<  " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}
		
		// manager �Ʒ��� �߰��� �ڸ��� �ִٸ� subordinate ��带 �����ϰ� �����Ѵ�.
		if (!managerNode->first) // manager�� first �ڸ��� ����ִٸ� (first �����Ͱ� NULL�̶��)
		{
			// ���ο� Node�� �����ϰ� subordinate ��å���� �ʱ�ȭ�Ͽ� first �ڽ����� �����Ѵ�.
			managerNode->first = new Node{ subordinate,NULL,NULL };
		}
		else // manager�� first �ڸ��� �� �ִٸ� (second �ڸ��� �������)
		{

			managerNode->second = new Node{ subordinate,NULL,NULL };
		}
		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << endl;

		return true; // �߰� ������ �˸�

	}

	// Ʈ���� ���� ����(���� ����)�� ��ȸ�ϸ� ��带 �湮�ϴ� �Լ�
	// Queue �ڷᱸ����	����ϸ� ����
	static void levelOrder(Node* start) // ��ȸ�� ������ ��� ������(start)
	{
		// ���� ��尡 NULL�̸� ��ȸ�� Ʈ���� �����Ƿ� ����
		if (!start)
			return;
		// Node �����͸� ������ ť(Queue)�� ����.
		queue<Node*> q;
		// ��ȸ ���� ��带 ť�� �ִ´�.
		q.push(start);

		// ť�� �� ������ �ݺ�. ť�� ��� ��� ��带 �湮�� ���̴�.
		while (!q.empty())
		{
			// ���� ť�� ����ִ� ����� ������ �����Ѵ�. �� ������ ���� ������ �ִ�	����� ���̴�.
			int size = q.size();

			// ���� ������ �ִ� ��� ��带 ó���ϱ� ���� size ��ŭ �ݺ��Ѵ�.
			for (int i = 0; i < size; i++)
			{
				// ť�� �� �տ� �ִ� ��带 �����´�.(���Ŵ� ���� ����)
				auto current = q.front();
				// ť���� �� ���� ��带 �����Ѵ�.
				q.pop();

				// ���� ��带 �湮�Ͽ� ó���Ѵ�.(position ���� ����Ѵ�.)
				cout << current->position << " , ";

				// ���� ����� first �ڽ��� �ִٸ� ť�� �� �ڿ� �ִ´�.(���� �������� �湮 ����)
				if (current->first)
					q.push(current->first);
				// ���� ����� second �ڽ��� �ִٸ� ť�� �� �ڿ� �ִ´�.(���� �������� �湮 ����)
				if (current->second)
					q.push(current->second);
			}
			// ���� ������ ��� ��� ó���� ������ �ٹٲ��Ͽ� ���� ���� ��� ����� �����Ѵ�.
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
