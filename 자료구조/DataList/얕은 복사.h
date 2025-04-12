#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Myclass {
public:
	int data;
	vector<int>* vec; // ��ü�� ����Ű�� ������
	// vector<int>�� ���� �迭�� ������ ����� �����ϴ� �����̳�


	Myclass(int d) : data(d), vec(new vector<int>{ 1,2,3 }) {
		// ������,		data�� �ʱ�ȭ, vec�� ���ο� vector<int> ��ü�� �Ҵ��Ѵ�.	 

	}

	// ���� ���� ������
	Myclass(const Myclass& other) : data(other.data), vec(other.vec) {
		// ������ ���� ��ü�� ��� ������ �޴´�.
		// ������ ����ϸ� ���ʿ��� ��ü ���縦 �����Ѵ�.
		// const�� ����ϸ� ���� ��ü�� ������� �ʵ��� �����Ѵ�.

		// data(other.data) : ���� ��ü�� data ��� ������ �����Ѵ�.
		// vec(other.vec) : ���� ��ü�� vec ��� ����(������)�� �����Ѵ�.
		// �����ʹ� �޸� �ּҸ� �����ϹǷ�, ���� ��ü�� ����� ��ü�� ����
		// vector<int> ��ü�� ����Ű�� �ȴ�.
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
	Myclass obj2 = obj1; // ��������

	obj2.data = 20;
	obj2.vec->push_back(4); // �����ϴ� ���Ϳ� ��� �߰�

	cout << "obj1 : " << endl;
	obj1.printData();
	cout << "obj2 : " << endl;
	obj2.printData();


	return 0;
}