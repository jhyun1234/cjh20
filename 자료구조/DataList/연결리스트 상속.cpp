#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	// 노드를 쉽게 만들기 위해 생성자 추가
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
		// virtual : 상속 관계에서 소멸자가 올바르게 호출되도록 보장
	{
		while (!is_empty()) // 리스트가 빌 때까지
		{
			pop_front(); // 맨 앞 노드를 계속 삭제
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
			return; // 리스트가 비어있으면 아무것도 하지 않음
		}

		Node* temp = head; // 삭제할 노드를 임시 저장
		head = head->next; // head를 다음 노드로 이동
		delete temp; // 이전 head 노드 메모리 해제

	}

	// 리스트가 비어있는지 확인하는 함수
	bool is_empty() const
	{
		// const : 멤버 변수(head)를 변경하지 않음
		return head == nullptr; // head가 nullptr이면 비어있는 것
	}


	// 맨 앞 노드의 데이터를 반환하는 함수
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
	// 스택의 push
	void push(int data)
	{
		cout << "stack push" << data << endl;
		push_front(data);
	}
	// 스택의 pop
	void pop()
	{
		if (is_empty())
		{
			cout << "비어있는 스택에서 pop 할 수 없음" << endl;
			return;
		}
		pop_front(); // 부모 클래스 pop_front 호출
	}
	int top() const
	{
		return get_front_data();
	}
	bool empty() const
	{
		return is_empty(); // 부모 클래스의 is_empty 호출
	}

};

int main()
{
	Stack stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	cout << "현재 top : ";
	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack 비어있음" << endl;
	}
	stack.pop();
	cout << "현재 top : ";
	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack 비어있음" << endl;
	}
	stack.pop();
	cout << "현재 top : ";
	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack 비어있음" << endl;
	}

	stack.pop();
	cout << "현재 top : ";
	stack.pop();

	if (!stack.empty())
	{
		cout << stack.top() << endl;
	}
	else
	{
		cout << "stack 비어있음" << endl;
	}
}