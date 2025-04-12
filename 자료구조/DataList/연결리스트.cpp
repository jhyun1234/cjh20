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
	// ������
	IntaddNodeFirst() : head(nullptr)
	{

	}
	// ���� ����Ʈ�� ù ��°�� �� ��带 �߰��ϴ� �Լ�
	void add(int data)
	{
		// �� ��� ����
		Node* newNode = new Node;
		newNode->data = data;
			
		// �� ��带 ù ��° ���� �����ϰ� ���� ù ��° ��带 �� ����� ���� ���� ����
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
		// �� ���� ������ ����̹Ƿ� ���� ��带 ����Ű�� �����ʹ� nullptr
		newNode->next = nullptr;

		// ���� ����Ʈ�� ��������� �� ��带 ù ��° ���� ����	
		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		// ���� ����Ʈ�� ������ ��带 ã�Ƽ� �� ��带 ����
		Node* nowNode = head;
		while (nowNode->next != nullptr)
		{
			nowNode = nowNode->next;
		}
		// ������ ����� ���� ��带 �� ���� ����
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

	// ���� ����Ʈ�� ù ��°�� �� ��带 �߰��ϴ� �Լ�
	void addNode2(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}

	// ���� ����Ʈ�� ù ��° ��带 �����ϴ� �Լ�
	void DeleteFirst()
	// ���� ����Ʈ�� ��������� ������ ��尡 �����Ƿ� �Լ� ����
	{
		if (head == nullptr)
			return;
	    // ������ ù ��° ��带 �ӽ� �����Ϳ� ����
	    Node* temp = head;
	    
	    // �� ��° ��带 ù ��° ���� ����
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

	// ���� ����Ʈ �������� �� ��带 �߰��ϴ� �Լ�
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
	// ���� ����Ʈ�� ������ ��带 �����ϴ� �Լ�
	void DeleteNode()
	{
		// ���� ����Ʈ�� ��������� ������ ��尡 �����Ƿ� �Լ� ����
		if (head == nullptr)
		{
			return;
		}

		// ���� ����Ʈ�� ��尡 �ϳ��� ������ ù ��° ��带 ����
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		// ������ ���� �� ���� ��带 ã��
		Node* nowNode = head;
		Node* previous = nullptr;
		while (nowNode->next != nullptr)
		{
			previous = nowNode;
			nowNode = nowNode->next;
		}

		// ������ ��� ����(�޸� ����)
		delete nowNode;

		// ���� ����� ���� ��带 nullptr�� �����Ͽ� ���� ����Ʈ�� ���� ǥ��
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
	int data; // ������
	Node2* left; // ���� ����
	Node2* right; // ������ ����
};

// ���� Ž�� Ŭ����
class Traverser {
public:
	// ���� ����� 
	Node2* createTree() {
		// ��Ʈ ���� ������ 1�� ������, ���� �ڽ��� ������ 2, ������ �ڽ��� ������ 3�� ������.
		Node2* root = new Node2{ 1, new Node2{2, nullptr, nullptr}, new Node2{3, nullptr, nullptr} };
		return root; // ������� ������ ��Ʈ ��带 ��ȯ�Ѵ�.
	}

	// ���� Ž�� �Լ� (�߰����� �湮)
	// ���� ��ȸ(inorder traversal)�� ����Ͽ� ������ Ž���Ѵ�.
	// ���� �ڽ� -> ���� ��� -> ������ �ڽ� ������ �湮�Ѵ�.
	void traverse(Node2* node, vector<int>& result) {
		if (node == nullptr) {
			return; // ���� ��尡 ��������� Ž���� ����.
		}
		traverse(node->left, result); // ���� �ڽ� ��带 ��������� Ž���Ѵ�
		result.push_back(node->data); // ���� ����� �����͸� ��� ���Ϳ� �����Ѵ�.
		traverse(node->right, result); // ������ �ڽ� ��带 ��������� Ž���Ѵ�.
	}

	// ���� Ž�� ��� Ȯ�� �Լ�
	// ���� Ž�� ����� ���� ����� ���Ͽ� Ž���� ����� �Ǿ����� Ȯ���Ѵ�.
	bool CheckTraverse(Node2* root, const vector<int>& expectedResult) {
		vector<int> realResult; // ���� Ž�� ����� ������ ����
		traverse(root, realResult); // ���� Ž���� �����ϰ� ����� �����Ѵ�.

		// ���� ����� ���� ����� ũ�Ⱑ �ٸ��� Ž�� ����
		if (realResult.size() != expectedResult.size()) {
			return false;
		}
		// ���� ����� ���� ����� ������� ��
		for (size_t i = 0; i < realResult.size(); ++i) {
			if (realResult[i] != expectedResult[i]) {
				return false; // �ϳ��� �ٸ��� Ž�� ����
			}
		}

		return true; // ��� ��Ұ� ��ġ�ϸ� Ž�� ����
	}
};
class AfterNList {
private:
	Node* head; // ���� ����Ʈ�� ù ��° ��带 ����Ű�� ������

public:
	// ������: ���� ����Ʈ�� �ʱ�ȭ�Ѵ�.
	AfterNList() : head(nullptr) {}

	// ���� ����Ʈ�� �������� �� ��带 �߰��ϴ� �Լ�
	void append(int data) {
		Node* newNode = new Node; // �� ��� ����
		newNode->data = data; // �� ��忡 ������ ����
		newNode->next = nullptr; // �� ����� ���� ��带 nullptr�� ���� (������ ���)

		// ���� ����Ʈ�� ��������� �� ��带 ù ��° ���� ����
		if (head == nullptr) {
			head = newNode;
			return;
		}

		// ���� ����Ʈ�� ������ ��带 ã�Ƽ� �� ��带 ����
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	// ���� ����Ʈ�� n��° ��� ������ �� ��带 �߰��ϴ� �Լ�
	void addAfterN(int n, int data) {
		// ���� ����Ʈ�� ��������� �߰��� �� �����Ƿ� �Լ� ����
		if (head == nullptr) {
			cout << "���� ����Ʈ�� ����ֽ��ϴ�." << endl;
			return;
		}

		Node* newNode = new Node; // �� ��� ����
		newNode->data = data; // �� ��忡 ������ ����
		newNode->next = nullptr; // �� ����� ���� ��带 nullptr�� ����

		// n��° ��带 ã��
		Node* current = head;
		int count = 0;
		while (current != nullptr && count < n) {
			current = current->next;
			count++;
		}
		// n��° ��带 ã�� �������� ���� �޽��� ��� �� �Լ� ����
		if (current == nullptr) {
			cout << "n��° ��带 ã�� �� �����ϴ�." << endl;
			return;
		}
		// �� ��带 n��° ��� ������ ����
		newNode->next = current->next;
		current->next = newNode;
	}
	// ���� ����Ʈ�� ��� ��带 ����ϴ� �Լ�
	void printList() {
		Node* current = head; // ���� ��带 ����Ű�� ������ (�ʱ⿡�� ù ��° ���)
		while (current != nullptr) {
			cout << current->data << " "; // ���� ����� ������ ���
			current = current->next; // ���� ��带 ���� ���� �̵�
		}
		cout << endl; // �ٹٲ�
	}
};

class DeleteNList {
private:
	Node* head; // ���� ����Ʈ�� ù ��° ��带 ����Ű�� ������

public:
	// ������: ���� ����Ʈ�� �ʱ�ȭ�Ѵ�..
	DeleteNList() : head(nullptr) {}

	// ���� ����Ʈ�� �������� �� ��带 �߰��ϴ� �Լ�
	void append(int data) {
		Node* newNode = new Node; // �� ��� ����
		newNode->data = data; // �� ��忡 ������ ����
		newNode->next = nullptr; // �� ����� ���� ��带 nullptr�� ���� (������ ���)

		// ���� ����Ʈ�� ��������� �� ��带 ù ��° ���� ����
		if (head == nullptr) {
			head = newNode;
			return;
		}

		// ���� ����Ʈ�� ������ ��带 ã�Ƽ� �� ��带 ����
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	// ���� ����Ʈ�� n��° ���� ��带 �����ϴ� �Լ�
	void deleteAfterN(int n) {
		// ���� ����Ʈ�� ��������� ������ ��尡 �����Ƿ� �Լ� ����
		if (head == nullptr) {
			cout << "���� ����Ʈ�� ����ֽ��ϴ�." << endl;
			return;
		}

		// n��° ��带 ã��
		Node* current = head;
		int count = 0;
		while (current != nullptr && count < n) {
			current = current->next;
			count++;
		}

		// n��° ��带 ã�� ���߰ų� n��° ���� ��尡 ������ ���� �޽��� ��� �� �Լ� ����
		if (current == nullptr || current->next == nullptr) {
			cout << "n��° ���� ��带 ã�� �� �����ϴ�." << endl;
			return;
		}

		// n��° ���� ��带 ����
		Node* temp = current->next; // ������ ��带 �ӽ÷� ����
		current->next = temp->next; // n��° ����� ���� ��带 ������ ����� ���� ���� ����
		delete temp; // ������ ��� �޸� ����
	}
	// ���� ����Ʈ�� ��� ��带 ����ϴ� �Լ�
	void printList() {
		Node* current = head; // ���� ��带 ����Ű�� ������ (�ʱ⿡�� ù ��° ���)
		while (current != nullptr) {
			cout << current->data << " "; // ���� ����� ������ ���
			current = current->next; // ���� ��带 ���� ���� �̵�
		}
		cout << endl; // �ٹٲ�
	}
};

class GetSize
{
private:
	Node* head; // ���� ����Ʈ�� ù ��° ��带 ����Ű�� ������
public:
	// ������ ����Ʈ �ʱ�ȭ
	GetSize() : head(nullptr) {}

	// ���� ����Ʈ�� �������� �� ��带 �߰��ϴ� �Լ�
	void add(int data)
	{
		Node* newNode = new Node; // �� ��� ����
		newNode->data = data; // �� ��忡 ������ ����
		newNode->next = nullptr; // �� ����� ���� ��带 nullptr�� ����(������ ���)
		
		// ���� ����Ʈ�� ��������� �� ��带 ù ��° ���� ����
		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		// ���� ����Ʈ�� ������ ��带 ã�Ƽ� �� ��带 ����
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	// ���� ����Ʈ�� ����� �������� ������ ��ȯ�ϴ� �Լ�
	int getsize()
	{
		int count = 0;// ������ ������ ������ ���� �ʱ�ȭ
		Node* current = head;// ���� ��带 ����Ű�� ������(�ʱ⿡�� ù ��° ���)

		// ���� ����Ʈ�� ��� ��带 ��ȸ�ϸ鼭 ������ ������ ����
		while (current != nullptr)
		{
			count++; // ������ ���� ����
			current = current->next; // ���� ���� �̵�
		}
		return count; // ������ ���� ��ȯ
	}

	void print()
	{
		Node* current = head;// ���� ��带 ����Ű�� ������
		while (current != nullptr)
		{
			cout << current->data << " "; // ���� ����� ������ ���
			current = current->next; // ���� ��带 ���� ���� �̵�
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

	// ����Ʈ�� �������� �� ��带 �߰��ϴ� �Լ�
	void add(int data)
	{
		Node* newNode = new Node; // �� ��� ����
		newNode->data = data; // �� ��忡 ������ ����
		newNode->next = nullptr; // �� ����� ���� ��带 nullptr�� ����(������ ���)
		
		// ���� ����Ʈ�� ��������� �� ��带 ù ��° ���� ����
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		// ���� ����Ʈ�� ������ ��带 ã�Ƽ� �� ��带 ����
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	// ���� ����Ʈ�� ����� ������ �� �־��� ���ڰ� �ִ��� Ȯ���ϴ� �Լ�
	bool findN(int number)
	{
		Node* current = head;
		
		// ���� ����Ʈ�� ��� ��带 ��ȸ�ϸ鼭 �־��� ���ڸ� ã��
		while (current != nullptr)
		{
			if (current->data == number)
			{
				return true; // �־��� ���ڸ� ã������ true ��ȯ
			}
			current = current->next;
		}
		return false; // �־��� ���ڸ� ��ã������ false ��ȯ
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
	// ���ø� �Լ� ����
	void print(T value) {
		cout << "Value: " << value << endl;
	}
};


// ���׽��� ���� ��Ÿ���� ����ü
struct DATA {
	int coefficient; // ���
	int exponent;    // ����
	DATA* next;      // ���� ���� ����Ű�� ������
};

class polynomial
{
private:
	DATA* head; // ���׽��� ù ��° ���� ����Ű�� ������
	
public:
	// ������ : ���׽��� �ʱ�ȭ �Ѵ�.
	polynomial() : head(nullptr) {}

	// �Ҹ��� : ���׽��� ��� ���� �޸𸮿��� �����Ѵ�.
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

	// ���׽Ŀ� ���� �߰��ϴ� �Լ�
	void addDATA(int coefficient, int expoent)
	{
		// �� ���� �����Ѵ�.
		DATA* newDATA = new DATA{ coefficient,expoent,nullptr };

		// ���׽��� ��������� �� ���� ù ���� ������ �����Ѵ�.
		if (head == nullptr)
		{
			head = newDATA;
			return;
		}

		// �� ���� ������ ��ġ�� ã�´�.
		DATA* current = head;
		DATA* prev = nullptr;
		while (current != nullptr && current->exponent > expoent)
		{
			prev = current;
			current = current->next;
		}

		// �� ���� �����Ѵ�.
		if (prev == nullptr)
		{
			// �� ���� ù ��° ������ �����ϴ� ���
			newDATA->next = head;
			head = newDATA;
		}
		else
		{
			// �� ���� �߰� �Ǵ� ������ ������ �����ϴ� ���
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
	// ���� ����Ʈ�� ù ��°�� ��� �߰�
	cout << "ó�� �κп� Node�� �߰��ϱ�" << endl;
	IntaddNodeFirst List;
	List.add(1);
	List.add(2);
	List.add(3);

	List.showprint();

	IntaddNodeLast List1;
	cout << endl;

	// ���� ����Ʈ�� �������� ��� �߰�
	cout << "������ �κп� Node�� �߰��ϱ�" << endl;
	List1.addNode(1);
	List1.addNode(2);
	List1.addNode(3);

	List1.showprint();

	cout << endl;
	// ���� ����Ʈ�� ù ��° ��� ����
	cout << "ù ��° Node ����" << endl;
	DeleteFirstNode List2;

	List2.addNode2(1);
	List2.addNode2(2);
	List2.addNode2(3);

	List2.DeleteFirst();

	List2.showNode();

	cout << endl;
	// ���� ����Ʈ�� ������ ��� ����
	cout << "������ Node ����" << endl;

	DeleteLastNode List3;
	List3.addNode3(1);
	List3.addNode3(2);
	List3.addNode3(3);

	List3.DeleteNode();

	List3.showNode();


	// traverse �Լ��� ��� ����
	Traverser traverser;
	Node2* tree = traverser.createTree(); // ���� �����

	// ���� Ž�� ��� (�߰����� �湮)
	vector<int> expectedResult = { 2, 1, 3 };

	// Ž�� ��� Ȯ��
	if (traverser.CheckTraverse(tree,expectedResult)) {
		cout << "Ž�� ����!" << endl;
	}
	else {
		cout << "Ž�� ����!" << endl;
	}


	// �������� Ž���ϴ� ���Ḯ��Ʈ
	ReverseList relist;
	relist.addNode(10);
	relist.addNode(20);
	relist.addNode(30);

	cout << "���� ��" << endl;
	relist.showNode();

	relist.reverse();

	cout << "���� ��" << endl;
	relist.showNode();


	cout << endl;

	AfterNList myList; // ���� ����Ʈ ��ü ����

	// ���� ����Ʈ�� ��� �߰�
	myList.append(10);
	myList.append(20);
	myList.append(30);
	myList.append(40);

	// ���� ����Ʈ ��� (�߰� ��)
	cout << "�߰� ��: ";
	myList.printList(); // ��� ���: 10 20 30

	// 2��° ��� ������ 25 �߰�
	myList.addAfterN(2, 25);

	// ���� ����Ʈ ��� (�߰� ��)
	cout << "�߰� ��: ";
	myList.printList(); // ��� ���: 10 20 30 25
	cout << endl;

	DeleteNList deleteList;
	// ���� ����Ʈ�� ��� �߰�
	deleteList.append(10);
	deleteList.append(20);
	deleteList.append(30);
	deleteList.append(40);

	// ���� ��
	deleteList.printList();
	// 2�� ° ��� ����
	deleteList.deleteAfterN(2);

	// ���
	deleteList.printList();


	// �̸� ��� �Լ�
	char name[256];
	Hello(name);
	cout << "�Է¹��� �̸� : " << name << endl;

	string name1;
	Hello1(name1);
	cout << "�Է¹��� �̸� : " << name << endl;


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
	stringtemp.print("�ȳ��ϼ���");


	// ���׽� ��ü ����
	polynomial poly;

	// ���׽Ŀ� �� �߰�
	poly.addDATA(1, 2);
	poly.addDATA(3, 4);
	poly.addDATA(5, 6);
	poly.addDATA(7, 8);

	// ���׽� ���

	poly.printpolynomial();
	cout << endl;
	// getsize class

	GetSize getsize;
	getsize.add(10);
	getsize.add(20);
	getsize.add(30);

	// ����Ʈ�� ����� ������ ���� ���
	cout << "������ ���� : " << getsize.getsize() << endl;
	getsize.print();
	cout << endl;

	// ����Ʈ�� ������ ���� ã��

	FindNum find;
	find.add(100);
	find.add(200);
	find.add(300);
	find.add(400);

	// ����Ʈ�� 200�� �ִ��� Ȯ��
	if (find.findN(200))
	{
		cout << "200�� ����Ʈ�� �ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "200�� ����Ʈ�� �����ϴ�." << endl;
	}
	// ����Ʈ�� 500�� �ִ��� Ȯ��
	if (find.findN(500))
	{
		cout << "500�� ����Ʈ�� �ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "500�� ����Ʈ�� �����ϴ�." << endl;
	}
	find.print();

	return 0;
}

void Hello(char* name) {
	// �̸� �Է¹ޱ�
	cout << "�̸��� �Է��ϼ���: ";
	cin.getline(name, 256); // �ִ� 255�ڱ��� �Է¹���
}
void Hello1(string& name)
{
	cout << "�̸��� �Է��ϼ���: ";
	getline(cin, name);
}