#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;
class Stack
{
private:
	vector<char> vec; // 문자열 데이터를 저장할 vector 객체

public:
	Stack() {};
	~Stack() {};

	void push(int value);

	void pop();

	int top() const;

	bool empty() const;
	// 스텍에 저장된 데이터의 개수를 반환하는 함수
	size_t size() const;
};

#endif // !STACK_H#pragma once
