#include <iostream> 
// ���ø��� ����Ͽ� �پ��� ������ Ÿ���� ������ �� �ֵ��� �Ѵ�.

using namespace std;
template <typename T>

class CLinkedQueue
{
private:
	// ��� ����ü ����
	struct Node
	{
		T data;
		Node* next;
		Node(T val) : data(val), next(nullptr) {}
	};

	Node* tail;
	int countofData;

public:
	// ������ �� ť�� �ʱ�ȭ
	CLinkedQueue() :tail(nullptr), countofData(0) {}

	// �Ҹ��� ť�� ��� �޸� ����
	~CLinkedQueue()
	{
		while (!isEmpty())
		{
			dequeue();
		}
	}

	bool isEmpty()
	{
		return tail == nullptr;
	}

	int getsize()
	{
		return countofData;
	}

	void enqueue(T data)
	{
		Node* newNode = new Node(data);

		if (isEmpty()) // ť�� ���������, �� ��尡 ������ ��尡 �ȴ�.
		{
			tail = newNode;
			tail->next = tail; // �ڱ� �ڽ��� ����Ų��.
		}
		else
		{
			newNode->next = tail->next; // �� ��尡 ���� �Ӹ�(front)�� ����Ų��.
			tail->next = newNode; // ���� ������ �� ��带 ����Ŵ
			tail = newNode; // �� ��尡 ���ο� ������ �ȴ�.
		}
		countofData++;
	}

	//dequeue�� �����͸� ���� ������� �ϹǷ� ���ŵ� �������� Ÿ���� T�� ��ȯ Ÿ������ ������.
	T dequeue()
	{
		if (isEmpty())
			return 0;

		Node* frontNode = tail->next; // ������ ���
		T frontData = frontNode->data; // ��ȯ�� ������ ����

		if (tail == tail->next)// ť�� ��尡 �ϳ��� �ִ� ���
		{
			tail = nullptr;
		}
		else
		{
			tail->next = frontNode->next; // ������ ���ο� �Ӹ��� ����Ű���� ��
		}

		delete frontNode; // ���� �Ӹ� ��� �޸� ����
		countofData--;
		return frontData; // ������ ������ ��ȯ

	}

	void printData()
	{
		if (isEmpty())
		{
			cout << "ť�� �������" << endl;
			return;
		}
		Node* cur = tail->next; // �Ӹ����� ����
		do
		{
			cout << cur->data << endl;
			cur = cur->next;
		} while (cur != tail->next); // �� ���� ���� �ٽ� �Ӹ��� ���� ����
	}
};

int main()
{
	CLinkedQueue<int> queue;
	queue.enqueue(1); // queue�� int�� ������ �ִ´�.
	queue.enqueue(2); 
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.printData(); // ��� 1 2 3 4 5 
	cout << endl;

	queue.dequeue(); // ���� 2�� 
	queue.dequeue(); 
	cout << endl;

	queue.printData(); // ��� 3 4 5 
	
	cout << endl;
	while (!queue.isEmpty())
	{
		cout << queue.dequeue() << endl; // ��� 3 4 5 
	}


	return 0;

}

