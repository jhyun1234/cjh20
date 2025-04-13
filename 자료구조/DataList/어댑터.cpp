#include <iostream> 
#include <string>   
#include <stack>
using namespace std;
bool Parentheses2(const string& par)
{
	stack<char> parstack;

	for (char ch : par)
	{
		if (ch == '(' || ch == '{' || ch == '[')
		{
			parstack.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']')
		{
			if (parstack.empty())
			{
				cout << "���� �������, ¦ �´� ���� ��ȣ ����" << endl;
				return false; // ¦ �� ����
			}
			// ������ ������� ������, �� ��(top)�� ���� ��ȣ Ȯ��
			char topchar = parstack.top(); // std::stack�� top ���

			// ���� �ݴ� ��ȣ(ch)�� ���� top�� ���� ��ȣ(topchar)�� �ùٸ� ¦���� Ȯ��
			bool match = false;
			if (ch == ')' && topchar == '(') {
				match = true;
			}
			else if (ch == '}' && topchar == '{') {
				match = true;
			}
			else if (ch == ']' && topchar == '[') {
				match = true;
			}
			// ¦�� ������ ���ÿ��� pop (���� ��ȣ ����)
			if (match) {
				parstack.pop(); // std::stack�� pop ���
				cout << "    ¦ ���� ('" << topchar << "' �� '" << ch << "')"<< endl;
			}
			// ¦�� ���� ������ �߸��� ��ȣ �����̹Ƿ� ����
			else {
				cout << "   ��ȣ ¦ ����ġ (Top: '" << topchar << "', Found: '" << ch << "')" << endl;
				return false; // ¦ �� ����
			}
		}
	}
	// ���ڿ� ������ Ȯ�� �� ���� �˻�
	// ������ ���������� ����־�� ��� ��ȣ�� ¦�� �´°�
	if (parstack.empty())
	{
		cout << "���� �������" << endl;
		return true;
	}
	else
	{
		cout << "���ÿ� ¦ ��ã�� ���� ��ȣ ����" << parstack.top() << endl;
		return false;
	}
}

int main()
{
	string Input;
	getline(cin, Input);
	cout << "��� : " << Parentheses2(Input) << endl;
	return 0;
}