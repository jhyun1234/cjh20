#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

// void fun()  ��ȯ �ڷ��� ,�Լ���(�Լ��� �޴� �Է� �����͵�)
//{
	// �Լ��� ����� ���� �Ѵ�.
//}

class MyClass
{
private:
	int data;
	string name;

public:
	MyClass() : data(NULL), name("") {}

	MyClass(int d, const string& n) :data(d), name(n)
	{
		cout << "MyClass�� �����ڸ� ������� ��ü�� �������." << endl;
	}

	MyClass(const MyClass& other) : data(other.data), name(other.name)
	{
		cout << "MyClass ��ü ���� ����" << endl;
	}

	~MyClass()
	{

		cout << "MyClass �Ҹ����" << endl;
	}

};
void Hello1(); // �Լ� ����
void Hello2(int a);
int main()
{
	Hello2(10);
	Hello1(); // �Լ� ȣ��
	Hello2(20);
	Hello1();
	Hello2(30);
	Hello1();

	for (int i = 0; i < 3; i++)
	{
		Hello1();
		Hello2(i);
	}
	MyClass my(10, "ex");
	MyClass my2 = my;
	MyClass my3;
	return 0;
}

void Hello1() // �Լ� ���� 
{
	cout << "Hello World" << endl;
	cout << endl;
}

void Hello2(int a) // �Լ� ���� 
{
	cout << "Hello World" << endl;
	cout << a << endl;
	cout << endl;
}
