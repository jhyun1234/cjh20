#include<iostream>


using namespace std;

struct T
{
	int a, b;
};
void print(T&); // �� �Լ��� ������ �ϸ� ���� �Ǿ������� ��ũ�ܰ迡�� ������ �����.
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
	// cout << t << endl; << �� �����ڴ� �⺻ �ڷ����� �����Ѵ�. T�� ������� t ��ü�� �����ڰ� �������� �ʴ´�. 
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
	// t.a = 100; error�� ���� ������ const�� ����ϱ� ����
	cout << t.a << " " << t.b << endl;
}
