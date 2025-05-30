#include<iostream>


using namespace std;

struct T
{
	int a, b;
};
void print(T&); // 이 함수를 쓰려고 하면 선언만 되어있으니 링크단계에서 오류가 생긴다.
void print1(T t);


int main()
{
	T s;
	s.a = 10;
	s.b = 20;
	
	T t;
	
	print1(s);
	t = s;
	// t = &a; error
	// cout << t << endl; << 이 연산자는 기본 자료형만 지원한다. T의 만들어진 t 객체는 연산자가 지원하지 않는다. 
	cout << t.a << endl; 

	print(t);
}
void print(T& t)
{
	t.a = 100;
	cout << t.a << " " << t.b << endl;
}
void print1(T t)
{
	cout << t.a << " " << t.b << endl;
}
void print(const T& t)
{
	// t.a = 100; error가 나는 이유는 const를 사용하기 때문
	cout << t.a << " " << t.b << endl;
}
