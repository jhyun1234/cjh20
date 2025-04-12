#include <iostream>
#include <vector>
#include <string>

using namespace std;
void Hello(char* name);
void Hello1(string& name);
struct Node
{
	int data;
	Node* next;
};

class IntaddNodeFirst
{
private:
	Node* head;
public:
	// 생성자
	IntaddNodeFirst() : head(nullptr)
	{

	}
	// 연결 리스트에 첫 번째에 새 노드를 추가하는 함수
	void add(int data)
	{
		// 새 노드 생성
		Node* newNode = new Node;
		newNode->data = data;
			
		// 새 노드를 첫 번째 노드로 설정하고 기존 첫 번째 노드를 새 노드의 다음 노드로 연결
		newNode->next = head;
		head = newNode;
	}

	void showprint()
	{
		Node* now = head;
		while (now != nullptr)
		{
			cout << now->data << endl;
			now = now->next;
		}
	}
};

class IntaddNodeLast
{
private:
	Node* head;

public:
	IntaddNodeLast() : head(nullptr)
	{

	}

	void addNode(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		// 새 노드는 마지막 노드이므로 다음 노드를 가리키는 포인터는 nullptr
		newNode->next = nullptr;

		// 연결 리스트가 비어있으면 새 노드를 첫 번째 노드로 설정	
		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		// 연결 리스트의 마지막 노드를 찾아서 새 노드를 연결
		Node* nowNode = head;
		while (nowNode->next != nullptr)
		{
			nowNode = nowNode->next;
		}
		// 마지막 노드의 다음 노드를 새 노드로 설정
		nowNode->next = newNode;

	}
	void showprint()
	{
		Node* nowNode = head;
		while (nowNode != nullptr)
		{
			cout << nowNode->data << endl;
			nowNode = nowNode->next;
		}
	}


};

class DeleteFirstNode
{
private:
	Node* head;

public:
	DeleteFirstNode() : head(nullptr)
	{

	}

	// 연결 리스트의 첫 번째에 새 노드를 추가하는 함수
	void addNode2(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}

	// 연결 리스트의 첫 번째 노드를 삭제하는 함수
	void DeleteFirst()
	// 연결 리스트가 비어있으면 삭제할 노드가 없으므로 함수 종료
	{
		if (head == nullptr)
			return;
	    // 삭제할 첫 번째 노드를 임시 포인터에 저장
	    Node* temp = head;
	    
	    // 두 번째 노드를 첫 번째 노드로 설정
	    head = head->next;
	    
	    delete temp;
	}

	void showNode()
	{
		Node* nowNode = head;
		while (nowNode != nullptr)
		{
			cout << nowNode->data << endl;
			nowNode = nowNode->next;
		}
	}
};

class DeleteLastNode
{
private:
	Node* head;
public:
	DeleteLastNode() : head(nullptr)
	{

	}

	// 연결 리스트 마지막에 새 노드를 추가하는 함수
	void addNode3(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node* nowNode = head;
		while (nowNode->next != nullptr)
		{
			nowNode = nowNode->next;
		}
		nowNode->next = newNode;

	}
	// 연결 리스트의 마지막 노드를 삭제하는 함수
	void DeleteNode()
	{
		// 연결 리스트가 비어있으면 삭제할 노드가 없으므로 함수 종료
		if (head == nullptr)
		{
			return;
		}

		// 연결 리스트에 노드가 하나만 있으면 첫 번째 노드를 삭제
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		// 마지막 노드와 그 이전 노드를 찾음
		Node* nowNode = head;
		Node* previous = nullptr;
		while (nowNode->next != nullptr)
		{
			previous = nowNode;
			nowNode = nowNode->next;
		}

		// 마지막 노드 삭제(메모리 해제)
		delete nowNode;

		// 이전 노드의 다음 노드를 nullptr로 설정하여 연결 리스트의 끝을 표시
		previous->next = nullptr;
	}

	void showNode()
	{
		Node* nowNode = head;
		while (nowNode != nullptr)
		{
			cout << nowNode->data << endl;
			nowNode = nowNode->next;
		}
	}


};

class ReverseList 
{
private:
	Node* head;

public:
	ReverseList() : head(nullptr) {}

	void addNode(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node* now = head;
		while (now->next!=nullptr)
		{
			now = now->next;
		}
		now->next = newNode;
	}

	void reverse()
	{
		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void showNode()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}


};


struct Node2 {
	int data; // 데이터
	Node2* left; // 왼쪽 가지
	Node2* right; // 오른쪽 가지
};

// 나무 탐색 클래스
class Traverser {
public:
	// 나무 만들기 
	Node2* createTree() {
		// 루트 노드는 데이터 1을 가지고, 왼쪽 자식은 데이터 2, 오른쪽 자식은 데이터 3을 가진다.
		Node2* root = new Node2{ 1, new Node2{2, nullptr, nullptr}, new Node2{3, nullptr, nullptr} };
		return root; // 만들어진 나무의 루트 노드를 반환한다.
	}

	// 나무 탐색 함수 (중간부터 방문)
	// 중위 순회(inorder traversal)를 사용하여 나무를 탐색한다.
	// 왼쪽 자식 -> 현재 노드 -> 오른쪽 자식 순서로 방문한다.
	void traverse(Node2* node, vector<int>& result) {
		if (node == nullptr) {
			return; // 현재 노드가 비어있으면 탐색을 종료.
		}
		traverse(node->left, result); // 왼쪽 자식 노드를 재귀적으로 탐색한다
		result.push_back(node->data); // 현재 노드의 데이터를 결과 벡터에 저장한다.
		traverse(node->right, result); // 오른쪽 자식 노드를 재귀적으로 탐색한다.
	}

	// 나무 탐색 결과 확인 함수
	// 실제 탐색 결과와 예상 결과를 비교하여 탐색이 제대로 되었는지 확인한다.
	bool CheckTraverse(Node2* root, const vector<int>& expectedResult) {
		vector<int> realResult; // 실제 탐색 결과를 저장할 벡터
		traverse(root, realResult); // 실제 탐색을 수행하고 결과를 저장한다.

		// 실제 결과와 예상 결과의 크기가 다르면 탐색 실패
		if (realResult.size() != expectedResult.size()) {
			return false;
		}
		// 실제 결과와 예상 결과를 순서대로 비교
		for (size_t i = 0; i < realResult.size(); ++i) {
			if (realResult[i] != expectedResult[i]) {
				return false; // 하나라도 다르면 탐색 실패
			}
		}

		return true; // 모든 요소가 일치하면 탐색 성공
	}
};
class AfterNList {
private:
	Node* head; // 연결 리스트의 첫 번째 노드를 가리키는 포인터

public:
	// 생성자: 연결 리스트를 초기화한다.
	AfterNList() : head(nullptr) {}

	// 연결 리스트의 마지막에 새 노드를 추가하는 함수
	void append(int data) {
		Node* newNode = new Node; // 새 노드 생성
		newNode->data = data; // 새 노드에 데이터 저장
		newNode->next = nullptr; // 새 노드의 다음 노드를 nullptr로 설정 (마지막 노드)

		// 연결 리스트가 비어있으면 새 노드를 첫 번째 노드로 설정
		if (head == nullptr) {
			head = newNode;
			return;
		}

		// 연결 리스트의 마지막 노드를 찾아서 새 노드를 연결
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	// 연결 리스트의 n번째 노드 다음에 새 노드를 추가하는 함수
	void addAfterN(int n, int data) {
		// 연결 리스트가 비어있으면 추가할 수 없으므로 함수 종료
		if (head == nullptr) {
			cout << "연결 리스트가 비어있습니다." << endl;
			return;
		}

		Node* newNode = new Node; // 새 노드 생성
		newNode->data = data; // 새 노드에 데이터 저장
		newNode->next = nullptr; // 새 노드의 다음 노드를 nullptr로 설정

		// n번째 노드를 찾음
		Node* current = head;
		int count = 0;
		while (current != nullptr && count < n) {
			current = current->next;
			count++;
		}
		// n번째 노드를 찾지 못했으면 에러 메시지 출력 후 함수 종료
		if (current == nullptr) {
			cout << "n번째 노드를 찾을 수 없습니다." << endl;
			return;
		}
		// 새 노드를 n번째 노드 다음에 삽입
		newNode->next = current->next;
		current->next = newNode;
	}
	// 연결 리스트의 모든 노드를 출력하는 함수
	void printList() {
		Node* current = head; // 현재 노드를 가리키는 포인터 (초기에는 첫 번째 노드)
		while (current != nullptr) {
			cout << current->data << " "; // 현재 노드의 데이터 출력
			current = current->next; // 현재 노드를 다음 노드로 이동
		}
		cout << endl; // 줄바꿈
	}
};

class DeleteNList {
private:
	Node* head; // 연결 리스트의 첫 번째 노드를 가리키는 포인터

public:
	// 생성자: 연결 리스트를 초기화한다..
	DeleteNList() : head(nullptr) {}

	// 연결 리스트의 마지막에 새 노드를 추가하는 함수
	void append(int data) {
		Node* newNode = new Node; // 새 노드 생성
		newNode->data = data; // 새 노드에 데이터 저장
		newNode->next = nullptr; // 새 노드의 다음 노드를 nullptr로 설정 (마지막 노드)

		// 연결 리스트가 비어있으면 새 노드를 첫 번째 노드로 설정
		if (head == nullptr) {
			head = newNode;
			return;
		}

		// 연결 리스트의 마지막 노드를 찾아서 새 노드를 연결
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	// 연결 리스트의 n번째 다음 노드를 제거하는 함수
	void deleteAfterN(int n) {
		// 연결 리스트가 비어있으면 제거할 노드가 없으므로 함수 종료
		if (head == nullptr) {
			cout << "연결 리스트가 비어있습니다." << endl;
			return;
		}

		// n번째 노드를 찾음
		Node* current = head;
		int count = 0;
		while (current != nullptr && count < n) {
			current = current->next;
			count++;
		}

		// n번째 노드를 찾지 못했거나 n번째 다음 노드가 없으면 에러 메시지 출력 후 함수 종료
		if (current == nullptr || current->next == nullptr) {
			cout << "n번째 다음 노드를 찾을 수 없습니다." << endl;
			return;
		}

		// n번째 다음 노드를 제거
		Node* temp = current->next; // 제거할 노드를 임시로 저장
		current->next = temp->next; // n번째 노드의 다음 노드를 제거할 노드의 다음 노드로 연결
		delete temp; // 제거할 노드 메모리 해제
	}
	// 연결 리스트의 모든 노드를 출력하는 함수
	void printList() {
		Node* current = head; // 현재 노드를 가리키는 포인터 (초기에는 첫 번째 노드)
		while (current != nullptr) {
			cout << current->data << " "; // 현재 노드의 데이터 출력
			current = current->next; // 현재 노드를 다음 노드로 이동
		}
		cout << endl; // 줄바꿈
	}
};

class GetSize
{
private:
	Node* head; // 연결 리스트의 첫 번째 노드를 가리키는 포인터
public:
	// 생성자 리스트 초기화
	GetSize() : head(nullptr) {}

	// 연결 리스트의 마지막에 새 노드를 추가하는 함수
	void add(int data)
	{
		Node* newNode = new Node; // 새 노드 생성
		newNode->data = data; // 새 노드에 데이터 저장
		newNode->next = nullptr; // 새 노드의 다음 노드를 nullptr로 설정(마지막 노드)
		
		// 연결 리스트가 비어있으면 새 노드를 첫 번째 노드로 설정
		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		// 연결 리스트의 마지막 노드를 찾아서 새 노드를 연결
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	// 연결 리스트에 저장된 데이터의 개수를 반환하는 함수
	int getsize()
	{
		int count = 0;// 데이터 개수를 저장할 변수 초기화
		Node* current = head;// 현재 노드를 가리키는 포인터(초기에는 첫 번째 노드)

		// 연결 리스트의 모든 노드를 순회하면서 데이터 개수를 증가
		while (current != nullptr)
		{
			count++; // 데이터 개수 증가
			current = current->next; // 다음 노드로 이동
		}
		return count; // 데이터 개수 반환
	}

	void print()
	{
		Node* current = head;// 현재 노드를 가리키는 포인터
		while (current != nullptr)
		{
			cout << current->data << " "; // 현재 노드의 데이터 출력
			current = current->next; // 현재 노드를 다음 노드로 이동
		}
		cout << endl;
	}
};

class FindNum
{
private:
	Node* head;

public:
	FindNum() :head(nullptr) {}

	// 리스트의 마지막에 새 노드를 추가하는 함수
	void add(int data)
	{
		Node* newNode = new Node; // 새 노드 생성
		newNode->data = data; // 새 노드에 데이터 저장
		newNode->next = nullptr; // 새 노드의 다음 노드를 nullptr로 저장(마지막 노드)
		
		// 연결 리스트가 비어있으면 새 노드를 첫 번째 노드로 설정
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		// 연결 리스트의 마지막 노드를 찾아서 새 노드를 연결
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	// 연결 리스트에 저장된 데이터 중 주어진 숫자가 있는지 확인하는 함수
	bool findN(int number)
	{
		Node* current = head;
		
		// 연결 리스트의 모든 노드를 순회하면서 주어진 숫자를 찾음
		while (current != nullptr)
		{
			if (current->data == number)
			{
				return true; // 주어진 숫자를 찾았으면 true 반환
			}
			current = current->next;
		}
		return false; // 주어진 숫자를 못찾았으면 false 반환
	}

	void print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};
template <typename T>
class Templatecalss {
public:
	// 템플릿 함수 정의
	void print(T value) {
		cout << "Value: " << value << endl;
	}
};


// 다항식의 항을 나타내는 구조체
struct DATA {
	int coefficient; // 계수
	int exponent;    // 지수
	DATA* next;      // 다음 항을 가리키는 포인터
};

class polynomial
{
private:
	DATA* head; // 다항식의 첫 번째 항을 가리키는 포인터
	
public:
	// 생성자 : 다항식을 초기화 한다.
	polynomial() : head(nullptr) {}

	// 소멸자 : 다항식의 모든 항을 메모리에서 해제한다.
	~polynomial()
	{
		DATA* current = head;
		while (current != nullptr)
		{
			DATA* temp = current;
			current = current->next;
			delete temp;
		}
	}

	// 다항식에 항을 추가하는 함수
	void addDATA(int coefficient, int expoent)
	{
		// 새 항을 생성한다.
		DATA* newDATA = new DATA{ coefficient,expoent,nullptr };

		// 다항식이 비어있으면 새 항을 첫 번재 항으로 설정한다.
		if (head == nullptr)
		{
			head = newDATA;
			return;
		}

		// 새 항을 삽입할 위치를 찾는다.
		DATA* current = head;
		DATA* prev = nullptr;
		while (current != nullptr && current->exponent > expoent)
		{
			prev = current;
			current = current->next;
		}

		// 새 항을 삽입한다.
		if (prev == nullptr)
		{
			// 새 항을 첫 번째 항으로 삽입하는 경우
			newDATA->next = head;
			head = newDATA;
		}
		else
		{
			// 새 항을 중간 또는 마지막 항으로 삽입하는 경우
			newDATA->next = current;
			prev->next = newDATA;
		}

	}

	void printpolynomial()
	{
		DATA* current = head;
		while (current != nullptr)
		{
			cout << current->coefficient << "x^" << current->exponent;
			if (current->next != nullptr)
			{
				cout << "+";
			}
			current = current->next;
		}
		cout << endl;
	}

};




int main()
{
	// 연결 리스트의 첫 번째에 노드 추가
	cout << "처음 부분에 Node를 추가하기" << endl;
	IntaddNodeFirst List;
	List.add(1);
	List.add(2);
	List.add(3);

	List.showprint();

	IntaddNodeLast List1;
	cout << endl;

	// 연결 리스트의 마지막에 노드 추가
	cout << "마지막 부분에 Node를 추가하기" << endl;
	List1.addNode(1);
	List1.addNode(2);
	List1.addNode(3);

	List1.showprint();

	cout << endl;
	// 연결 리스트의 첫 번째 노드 삭제
	cout << "첫 번째 Node 삭제" << endl;
	DeleteFirstNode List2;

	List2.addNode2(1);
	List2.addNode2(2);
	List2.addNode2(3);

	List2.DeleteFirst();

	List2.showNode();

	cout << endl;
	// 연결 리스트의 마지막 노드 삭제
	cout << "마지막 Node 삭제" << endl;

	DeleteLastNode List3;
	List3.addNode3(1);
	List3.addNode3(2);
	List3.addNode3(3);

	List3.DeleteNode();

	List3.showNode();


	// traverse 함수의 기능 구현
	Traverser traverser;
	Node2* tree = traverser.createTree(); // 나무 만들기

	// 예상 탐색 결과 (중간부터 방문)
	vector<int> expectedResult = { 2, 1, 3 };

	// 탐색 결과 확인
	if (traverser.CheckTraverse(tree,expectedResult)) {
		cout << "탐색 성공!" << endl;
	}
	else {
		cout << "탐색 실패!" << endl;
	}


	// 역순으로 탐색하는 연결리스트
	ReverseList relist;
	relist.addNode(10);
	relist.addNode(20);
	relist.addNode(30);

	cout << "변경 전" << endl;
	relist.showNode();

	relist.reverse();

	cout << "변경 후" << endl;
	relist.showNode();


	cout << endl;

	AfterNList myList; // 연결 리스트 객체 생성

	// 연결 리스트에 노드 추가
	myList.append(10);
	myList.append(20);
	myList.append(30);
	myList.append(40);

	// 연결 리스트 출력 (추가 전)
	cout << "추가 전: ";
	myList.printList(); // 출력 결과: 10 20 30

	// 2번째 노드 다음에 25 추가
	myList.addAfterN(2, 25);

	// 연결 리스트 출력 (추가 후)
	cout << "추가 후: ";
	myList.printList(); // 출력 결과: 10 20 30 25
	cout << endl;

	DeleteNList deleteList;
	// 연결 리스트에 노드 추가
	deleteList.append(10);
	deleteList.append(20);
	deleteList.append(30);
	deleteList.append(40);

	// 삭제 전
	deleteList.printList();
	// 2번 째 노드 삭제
	deleteList.deleteAfterN(2);

	// 출력
	deleteList.printList();


	// 이름 출력 함수
	char name[256];
	Hello(name);
	cout << "입력받은 이름 : " << name << endl;

	string name1;
	Hello1(name1);
	cout << "입력받은 이름 : " << name << endl;


	// template class 
	Templatecalss<int> inttemp;
	Templatecalss<float> floattemp;
	Templatecalss<double> doubletemp;
	Templatecalss<short> shorttemp;
	Templatecalss<char> chartemp;
	Templatecalss<string> stringtemp;

	inttemp.print(10);
	floattemp.print(3.342f);
	doubletemp.print(11.45);
	shorttemp.print(123);
	chartemp.print('A');
	stringtemp.print("안녕하세요");


	// 다항식 객체 생성
	polynomial poly;

	// 다항식에 항 추가
	poly.addDATA(1, 2);
	poly.addDATA(3, 4);
	poly.addDATA(5, 6);
	poly.addDATA(7, 8);

	// 다항식 출력

	poly.printpolynomial();
	cout << endl;
	// getsize class

	GetSize getsize;
	getsize.add(10);
	getsize.add(20);
	getsize.add(30);

	// 리스트에 저장된 데이터 개수 출력
	cout << "데이터 개수 : " << getsize.getsize() << endl;
	getsize.print();
	cout << endl;

	// 리스트에 지정한 숫자 찾기

	FindNum find;
	find.add(100);
	find.add(200);
	find.add(300);
	find.add(400);

	// 리스트에 200이 있는지 확인
	if (find.findN(200))
	{
		cout << "200이 리스트에 있습니다." << endl;
	}
	else
	{
		cout << "200이 리스트에 없습니다." << endl;
	}
	// 리스트에 500이 있는지 확인
	if (find.findN(500))
	{
		cout << "500이 리스트에 있습니다." << endl;
	}
	else
	{
		cout << "500이 리스트에 없습니다." << endl;
	}
	find.print();

	return 0;
}

void Hello(char* name) {
	// 이름 입력받기
	cout << "이름을 입력하세요: ";
	cin.getline(name, 256); // 최대 255자까지 입력받음
}
void Hello1(string& name)
{
	cout << "이름을 입력하세요: ";
	getline(cin, name);
}