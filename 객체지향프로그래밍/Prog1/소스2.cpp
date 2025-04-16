#include<iostream>

using namespace std;
int main()
{
	/*
	int a[5];
	int b[5];  // 500 400 300 200 100
	int c[5];

	int i=0;
	for (i=0; i < 5; i++)
	{
		a[i] = 10*(i+1);
		cout << a[i] << endl;
	}
	cout << endl;
	for (i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	cout << endl;
	int j = 4;
	for (; j >= 0; j--)
	{
		b[j] = 100 * (j + 1);
		cout << b[j] << endl;
	}
	cout << endl;
	for (i = 0; i < 5; i++)
	{
		b[i] = 100 * (5 - i);
		cout << b[i] << endl;
	}

	c[j] = a[i] + b[i];
	for (j = 0; j < 5; j++)
	{
		cout << c[j] << endl;
	}
	*/
	//int high;
	//if(high>c[0]) // 비교해서 큰 값이 생기면 그 값을 저장 
	//if(high>c[1])
	// if(high <c[1]) high = c[i];
	
	// 1. 실수를 100개 저장
	// 2. 0.2씩 차이가 나게하는 배열을 만들어라
	// 3. 처음 시작값은 키보드로 부터 입력을 받아라(정수, 실수가 되어도 됨)
	// 4. 다 저장한 뒤 합을 구해라

	double input=1;
	double aa[100] = {};
	double bb = 0;
	double sum = 0;
	cout << "정수 or 실수 입력" << endl;
	
	cin >> input;
	for (int i = 0; i < 100; i++)
	{
		aa[i] = input + bb;
		bb += 0.2f;
		cout << i << " " << aa[i] << endl;
	}
	
	/*
	for (int i = 0; i < 100; i++)
	{
		aa[i] = input + (i * 0.2f);
		cout <<i <<" "<< aa[i] << endl;
	}
	*/

	for (int i = 0; i < 100; i++)
	{
		sum += aa[i];
	}
	cout << "합 : " <<sum<< endl;
	

	double temp=0;
	temp = aa[99];
	aa[99] = aa[0];
	aa[0] = temp;

	cout << aa[99] <<" "<< aa[0] << endl;


	return 0;
}