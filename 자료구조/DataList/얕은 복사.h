#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Myclass {
public:
	int data;
	vector<int>* vec; // 객체를 가리키는 포인터
	// vector<int>는 동적 배열과 유사한 기능을 제공하는 컨테이너


	Myclass(int d) : data(d), vec(new vector<int>{ 1,2,3 }) {
		// 생성자,		data를 초기화, vec에 새로운 vector<int> 객체를 할당한다.	 

	}

	// 얕은 복사 생성자
	Myclass(const Myclass& other) : data(other.data), vec(other.vec) {
		// 복사할 원본 객체를 상수 참조로 받는다.
		// 참조를 사용하면 불필요한 객체 복사를 방지한다.
		// const를 사용하면 원본 객체가 변경되지 않도록 보장한다.

		// data(other.data) : 원본 객체의 data 멤버 변수를 복사한다.
		// vec(other.vec) : 원본 객체의 vec 멤버 변수(포인터)를 복사한다.
		// 포인터는 메모리 주소를 저장하므로, 원본 객체와 복사된 객체는 같은
		// vector<int> 객체를 가리키게 된다.
	}
	~Myclass() {}

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
	Myclass obj2 = obj1; // 얕은복사

	obj2.data = 20;
	obj2.vec->push_back(4); // 공유하는 벡터에 요소 추가

	cout << "obj1 : " << endl;
	obj1.printData();
	cout << "obj2 : " << endl;
	obj2.printData();


	return 0;
}