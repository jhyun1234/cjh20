#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Myclass
{
public:
	int data;
	vector<int>* vec; // ������ ���͸� ����Ű�� ������ ��� ����

	// �Ϲ� ������
	Myclass(int d) : data(d), vec(new vector<int>{ 1,2,3 })
	{

	}
	// ���� ���� ������
	Myclass(const Myclass& other) : data(other.data), vec(new vector<int>(*other.vec))
	{
		// 1. data ��� ������ ���� �����մϴ�.
		// 2. vec ��� ������ ���ο� vector<int> ��ü�� �Ҵ��ϰ�, 
		// ���� ��ü�� vec�� ����Ű�� ������ ������ �����Ѵ�.
	}
	~Myclass()
	{
		delete vec; // vec�� ����Ű�� �޸� ����
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
	Myclass obj2 = obj1; // ���� ����

	obj2.data = 20;
	obj2.vec->push_back(4); // ����� ���Ϳ� ��� �߰�

	cout << "obj1 : " << endl; // obj1�� ���� ��� ���� �״�� ���� ����
	obj1.printData();
	cout << "obj2 : " << endl;
	obj2.printData();


	return 0;
}