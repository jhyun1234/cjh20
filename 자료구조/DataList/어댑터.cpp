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
				cout << "스택 비어있음, 짝 맞는 여는 괄호 없음" << endl;
				return false; // 짝 안 맞음
			}
			// 스택이 비어있지 않으면, 맨 위(top)의 여는 괄호 확인
			char topchar = parstack.top(); // std::stack의 top 사용

			// 현재 닫는 괄호(ch)와 스택 top의 여는 괄호(topchar)가 올바른 짝인지 확인
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
			// 짝이 맞으면 스택에서 pop (여는 괄호 제거)
			if (match) {
				parstack.pop(); // std::stack의 pop 사용
				cout << "    짝 맞음 ('" << topchar << "' 와 '" << ch << "')"<< endl;
			}
			// 짝이 맞지 않으면 잘못된 괄호 순서이므로 오류
			else {
				cout << "   괄호 짝 불일치 (Top: '" << topchar << "', Found: '" << ch << "')" << endl;
				return false; // 짝 안 맞음
			}
		}
	}
	// 문자열 끝까지 확인 후 최종 검사
	// 스택이 최종적으로 비어있어야 모든 괄호의 짝이 맞는것
	if (parstack.empty())
	{
		cout << "스택 비어있음" << endl;
		return true;
	}
	else
	{
		cout << "스택에 짝 못찾은 여는 괄호 남음" << parstack.top() << endl;
		return false;
	}
}

int main()
{
	string Input;
	getline(cin, Input);
	cout << "결과 : " << Parentheses2(Input) << endl;
	return 0;
}