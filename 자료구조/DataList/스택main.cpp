#include"StackChar.h"
#include<iostream>
#include<string>
using namespace std;

// �ùٸ� ��ȣ�̸� true �ƴϸ� false ��ȯ

bool Parentheses(const string& par)
{
	Stack parStack; // ������ Stack Ŭ������ ��ü ����

	
	// ���ڿ��� ��� ���ڸ� �ϳ��� Ȯ��
	for (char ch : par)
	{
		// 1. ���� ��ȣ (
		if (ch == '(' || ch=='{'||ch=='[')
		{
			// ���ÿ� Ǫ��
			parStack.push(ch); // ���� ��ȣ�� ���ÿ� ����
		}
		else if (ch == ')' || ch == '}' || ch == ']')
		{
			if (parStack.empty())
			{
				cout << "�´� ¦�� ����" << endl;
				return false;
			}
			char topchar;
			topchar = parStack.top();
			// �ݴ� ��ȣ ch �� ���� top�� ���� ��ȣ�� �ùٸ� ¦���� Ȯ��
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
				parStack.pop(); // ¦�� �����Ƿ� ���ÿ��� ����
				cout << "    ¦ ���� ('" << topchar << "' �� '" << ch << "'). pop ���� "<< endl;
			}
			else
			{
				cout << "��ȣ ¦ ����ġ Top :" << topchar <<"Input : "<<ch<<endl;
				return false;
			}
		}
		
	}

	// ���ڿ� ������ Ȯ�� �� ���� �˻�
	// ������ ���������� ����־�� ��� ��ȣ�� ¦�� �´°�
	if (parStack.empty())
	{
		cout << "���� �������" << endl;
		return true;
	}
	else
	{
		cout << "���ÿ� ¦ ��ã�� ���� ��ȣ ����" << parStack.top() << endl;
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
		cout << "���� top : " << stack.top() << endl; // 300 
	}
	else
	{
		cout << "������ �������" << endl;
	}

	stack.pop(); // 100
	stack.pop(); // 200
	stack.pop(); // 300

	if (!stack.empty())
	{
		cout << "���� top : " << stack.top() << endl;
	}
	else
	{
		cout << "������ �������" << endl;
	}
	*/

	string Input;
	getline(cin, Input);
	cout << "��� : " << Parentheses(Input) << endl;
	return 0;
}