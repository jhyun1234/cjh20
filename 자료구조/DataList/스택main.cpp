#include"StackChar.h"
#include<iostream>
#include<string>
using namespace std;

// 올바른 괄호이면 true 아니면 false 반환

bool Parentheses(const string& par)
{
	Stack parStack; // 만들어둔 Stack 클래스의 객체 생성

	
	// 문자열의 모든 문자를 하나씩 확인
	for (char ch : par)
	{
		// 1. 여는 괄호 (
		if (ch == '(' || ch=='{'||ch=='[')
		{
			// 스택에 푸쉬
			parStack.push(ch); // 여는 괄호를 스택에 넣음
		}
		else if (ch == ')' || ch == '}' || ch == ']')
		{
			if (parStack.empty())
			{
				cout << "맞는 짝이 없음" << endl;
				return false;
			}
			char topchar;
			topchar = parStack.top();
			// 닫는 괄호 ch 와 스택 top의 여는 괄호가 올바른 짝인지 확인
			bool match = false;
			if (ch == ')' && topchar == '(')
			{
				match = true;
			}
			else if (ch == '}' && topchar == '{')
			{
				match = true;
			}
			else if (ch == ']' && topchar == '[')
			{
				match = true;
			}
			
			if (match)
			{
				parStack.pop(); // 짝이 맞으므로 스택에서 제거
				cout << "    짝 맞음 ('" << topchar << "' 와 '" << ch << "'). pop 실행 "<< endl;
			}
			else
			{
				cout << "괄호 짝 불일치 Top :" << topchar <<"Input : "<<ch<<endl;
				return false;
			}
		}
		
	}

	// 문자열 끝까지 확인 후 최종 검사
	// 스택이 최종적으로 비어있어야 모든 괄호의 짝이 맞는것
	if (parStack.empty())
	{
		cout << "스택 비어있음" << endl;
		return true;
	}
	else
	{
		cout << "스택에 짝 못찾은 여는 괄호 남음" << parStack.top() << endl;
		return false;
	}


}



int main()
{
	/*
	Stack stack;

	stack.push(100);
	stack.push(200);
	stack.push(300);


	if (!stack.empty())
	{
		cout << "현재 top : " << stack.top() << endl; // 300 
	}
	else
	{
		cout << "스택이 비어있음" << endl;
	}

	stack.pop(); // 100
	stack.pop(); // 200
	stack.pop(); // 300

	if (!stack.empty())
	{
		cout << "현재 top : " << stack.top() << endl;
	}
	else
	{
		cout << "스택이 비어있음" << endl;
	}
	*/

	string Input;
	getline(cin, Input);
	cout << "결과 : " << Parentheses(Input) << endl;
	return 0;
}