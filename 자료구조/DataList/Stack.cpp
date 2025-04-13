#include"Stack.h"
#include<iostream>
#include<vector>
using namespace std;
void Stack::push(int val)
{
	// vector의 맨 뒤에 요소를 추가하는 push_back() 함수가
	// 스택의 push와 동일한 역할
	vec.push_back(val);

}

void Stack::pop()
{
	if (vec.empty())
	{
		cout << "비어있는 스택에서 pop을 할 수 없음" << endl;
		return;
	}
	vec.pop_back();
}

int Stack::top() const
{
	if (vec.empty())
	{
		cout << "비어있는 스택에는 top이 없음" << endl;
	}
	// 비어있지 않다면 vector의 맨 마지가 요소 back()가 스택의 top임
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

