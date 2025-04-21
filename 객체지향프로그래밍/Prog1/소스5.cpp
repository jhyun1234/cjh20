#include <iostream>

using namespace std;
long long fib(int n);
int main()
{
	// Problems
	// 문제 1
	cout << "1번 ";
	int arr[5] = {};
	for (int i = 0; i < 5; i++)
	{
		arr[i] += 0 * i;
		cout << arr[i] << " "; // 0 0 0 0 0 출력
	}
	cout << endl;
	// 문제 2
	cout << "2번 ";
	int arr2[] = { 87,92,89,98,78 };
	for (int i = 1; i < 5; i++)
	{
		arr2[0] += arr2[i];
		cout << arr2[i] << " ";
	}
	cout << arr2[0] << endl; // 444출력
	
	// 문제 3
	cout << "3번 ";
	int arr3[10] = {};
	int input = 0;
	cin >> input;
	for (int i = 0; i < 10; i++)
	{
		arr3[i] += input + (i * 10);
		cout << arr3[i] << " ";
	}
	// 10 입력시 0번째 배열에 10출력확인 이후 10씩 증가
	cout << endl;

	// 문제 4
	cout << "4번 ";
	char str[] = {'H','e','l','l','o','\0','W','o','r','l','d','\0'};
	for (int i = 0; i < 12; i++)
	{
		cout << str[i] <<" ";
	}
	cout << endl;

	// 문제 6
	cout << "6번 ";
	char str2[] = { 'G','a','m','e','\0',
		'E','n','g','i','n','e','e','r','i','n','g','\0',
	'M','a','j','o','r' };
	int numofstr2 = 0;
	cout << sizeof(str2) / sizeof(str2[0])<<"개" << endl;

	cout << endl;

	// 문제 7
	cout << "7번 ";
	int count_a = 0;
	int count_e = 0;
	for (int i = 0; i < 22; i++)
	{
		if (str2[i] == 'a')
		{
			count_a++;
		}
		else if (str2[i] == 'e')
		{
			count_e++;
		}

	}
	cout << count_a <<" "<< count_e << endl;

	cout << endl;
	// 문제 8 , 9
	// 8번 문제를 풀기 위해서 함수를 사용 
	cout << "8번 " << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << i << "번째" << fib(i) << endl;

	}
	cout << endl;
	// 문제 10
	cout << "10번 " << endl;
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << "*";
		}
		cout << endl;
		
	}
	// 문제 10-2 역순 별 찍기
	cout << "10-2번 " << endl;
	for (int i = num; i > 0; i--)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;

	}
	cout << endl;
	// 문제 11
	cout << "11번 "<<endl;
	for (int i =1; i <= num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < i; k++)
		{
			cout << "*";
		}
		cout << endl;

	}
	cout << endl;
	// 문제 12
	

	// 문제 13



}
long long fib(int n) {
	
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		// 재귀 호출: F(n) = F(n-1) + F(n-2)
		return fib(n - 1) + fib(n - 2);
	}
}