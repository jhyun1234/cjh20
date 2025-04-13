#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;
class Stack
{
private:
	vector<char> vec; // ���ڿ� �����͸� ������ vector ��ü

public:
	Stack() {};
	~Stack() {};

	void push(int value);

	void pop();

	int top() const;

	bool empty() const;
	// ���ؿ� ����� �������� ������ ��ȯ�ϴ� �Լ�
	size_t size() const;
};

#endif // !STACK_H#pragma once
