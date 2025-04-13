#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	// ��带 ���� ����� ���� ������ �߰�
	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
protected:
	Node* head;

public:
	LinkedList() : head(nullptr)
	{

	}

	virtual ~LinkedList() 
		// virtual : ��� ���迡�� �Ҹ��ڰ� �ùٸ��� ȣ��ǵ��� ����
	{
		while (!is_empty()) // ����Ʈ�� �� ������
		{
			pop_front(); // �� �� ��带 ��� ����
		}
	}


	void push_front(int data)
	{
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}

	void pop_front()
	{

		if (is_empty())
		{
			return; // ����Ʈ�� ��������� �ƹ��͵� ���� ����
		}

		Node* temp = head; // ������ ��带 �ӽ� ����
		head = head->next; // head�� ���� ���� �̵�
		delete temp; // ���� head ��� �޸� ����

	}

	// ����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�
	bool is_empty() const
	{
		// const : ��� ����(head)�� �������� ����
		return head == nullptr; // head�� nullptr�̸� ����ִ� ��
	}


	// �� �� ����� �����͸� ��ȯ�ϴ� �Լ�
	int get_front_data() const
	{
		return head->data;
	}

	void print_list()
	{
		cout << " List: ";
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << "->";
			current = current->next;
		}
		cout << "nullptr" << endl;
	}

};

class Stack :public LinkedList
{
public:
	// ������ push
	void push(int data)
	{
		cout << "stack push" << data << endl;
		push_front(data);
	}
	// ������ pop
	void pop()
	{
		if (is_empty())
		{
			cout << "����ִ� ���ÿ��� pop �� �� ����" << endl;
			return;
		}
		pop_front(); // �θ� Ŭ���� pop_front ȣ��
	}
	int top() const
	{
		return get_front_data();
	}
	bool empty() const
	{
		return is_empty(); // �θ� Ŭ������ is_empty ȣ��
	}

};

int main()
{
	Stack stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	cout << "���� top : ";
	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack �������" << endl;
	}
	stack.pop();
	cout << "���� top : ";
	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack �������" << endl;
	}
	stack.pop();
	cout << "���� top : ";
	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack �������" << endl;
	}

	stack.pop();
	cout << "���� top : ";
	stack.pop();

	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack �������" << endl;
	}
}