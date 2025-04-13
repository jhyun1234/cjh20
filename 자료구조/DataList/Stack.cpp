#include"Stack.h"
#include<iostream>
#include<vector>
using namespace std;
void Stack::push(int val)
{
	// vector�� �� �ڿ� ��Ҹ� �߰��ϴ� push_back() �Լ���
	// ������ push�� ������ ����
	vec.push_back(val);

}

void Stack::pop()
{
	if (vec.empty())
	{
		cout << "����ִ� ���ÿ��� pop�� �� �� ����" << endl;
		return;
	}
	vec.pop_back();
}

int Stack::top() const
{
	if (vec.empty())
	{
		cout << "����ִ� ���ÿ��� top�� ����" << endl;
	}
	// ������� �ʴٸ� vector�� �� ������ ��� back()�� ������ top��
	return vec.back();
}

bool Stack::empty() const
{
	return vec.empty();
}

size_t Stack::size() const
{
	return vec.size();
}

