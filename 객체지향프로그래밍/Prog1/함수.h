#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

// void fun()  반환 자료형 ,함수명(함수가 받는 입력 데이터들)
//{
	// 함수의 기능이 들어가야 한다.
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
		cout << "MyClass의 생성자를 만들었고 객체를 만들었음." << endl;
	}

	MyClass(const MyClass& other) : data(other.data), name(other.name)
	{
		cout << "MyClass 객체 복사 됐음" << endl;
	}

	~MyClass()
	{

		cout << "MyClass 소멸됐음" << endl;
	}

};
void Hello1(); // 함수 선언
void Hello2(int a);
int main()
{
	Hello2(10);
	Hello1(); // 함수 호출
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

void Hello1() // 함수 정의 
{
	cout << "Hello World" << endl;
	cout << endl;
}

void Hello2(int a) // 함수 정의 
{
	cout << "Hello World" << endl;
	cout << a << endl;
	cout << endl;
}
