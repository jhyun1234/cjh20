#include <iostream> 
// 템플릿을 사용하여 다양한 데이터 타입을 저장할 수 있도록 한다.

using namespace std;
template <typename T>

class CLinkedQueue
{
private:
	// 노드 구조체 정의
	struct Node
	{
		T data;
		Node* next;
		Node(T val) : data(val), next(nullptr) {}
	};

	Node* tail;
	int countofData;

public:
	// 생성자 빈 큐로 초기화
	CLinkedQueue() :tail(nullptr), countofData(0) {}

	// 소멸자 큐의 모든 메모리 해제
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

		if (isEmpty()) // 큐가 비어있으면, 새 노드가 유일한 노드가 된다.
		{
			tail = newNode;
			tail->next = tail; // 자기 자신을 가리킨다.
		}
		else
		{
			newNode->next = tail->next; // 새 노드가 현재 머리(front)를 가리킨다.
			tail->next = newNode; // 이전 꼬리가 새 노드를 가리킴
			tail = newNode; // 새 노드가 새로운 꼬리가 된다.
		}
		countofData++;
	}

	//dequeue는 데이터를 빼서 돌려줘야 하므로 제거된 데이터의 타입인 T를 반환 타입으로 가진다.
	T dequeue()
	{
		if (isEmpty())
			return 0;

		Node* frontNode = tail->next; // 삭제할 노드
		T frontData = frontNode->data; // 반환할 데이터 저장

		if (tail == tail->next)// 큐에 노드가 하나만 있는 경우
		{
			tail = nullptr;
		}
		else
		{
			tail->next = frontNode->next; // 꼬리가 새로운 머리를 가리키도록 함
		}

		delete frontNode; // 이전 머리 노드 메모리 해제
		countofData--;
		return frontData; // 삭제된 데이터 반환

	}

	void printData()
	{
		if (isEmpty())
		{
			cout << "큐가 비어있음" << endl;
			return;
		}
		Node* cur = tail->next; // 머리부터 시작
		do
		{
			cout << cur->data << endl;
			cur = cur->next;
		} while (cur != tail->next); // 한 바퀴 돌아 다시 머리로 오면 종료
	}
};

int main()
{
	CLinkedQueue<int> queue;
	queue.enqueue(1); // queue에 int형 정수를 넣는다.
	queue.enqueue(2); 
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.printData(); // 출력 1 2 3 4 5 
	cout << endl;

	queue.dequeue(); // 삭제 2번 
	queue.dequeue(); 
	cout << endl;

	queue.printData(); // 출력 3 4 5 
	
	cout << endl;
	while (!queue.isEmpty())
	{
		cout << queue.dequeue() << endl; // 출력 3 4 5 
	}


	return 0;

}

