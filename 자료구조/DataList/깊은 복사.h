#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Myclass
{
public:
	int data;
	vector<int>* vec; // 정수형 벡터를 가리키는 포인터 멤버 변수

	// 일반 생성자
	Myclass(int d) : data(d), vec(new vector<int>{ 1,2,3 })
	{

	}
	// 깊은 복사 생성자
	Myclass(const Myclass& other) : data(other.data), vec(new vector<int>(*other.vec))
	{
		// 1. data 멤버 변수는 값을 복사합니다.
		// 2. vec 멤버 변수는 새로운 vector<int> 객체를 할당하고, 
		// 원본 객체의 vec이 가리키는 벡터의 내용을 복사한다.
	}
	~Myclass()
	{
		delete vec; // vec이 가리키는 메모리 해제
	}

	void printData()
	{
		cout << "data : " << data << endl;
		cout << "vec : " << endl;
		for (int i : *vec)
		{
			cout << i << " ";
		}
		cout << endl;
	}

};

int main()
{
	Myclass obj1(10);
	Myclass obj2 = obj1; // 깊은 복사

	obj2.data = 20;
	obj2.vec->push_back(4); // 복사된 벡터에 요소 추가

	cout << "obj1 : " << endl; // obj1의 벡터 요소 값은 그대로 남아 있음
	obj1.printData();
	cout << "obj2 : " << endl;
	obj2.printData();


	return 0;
}