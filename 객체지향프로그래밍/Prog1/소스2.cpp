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
	//if(high>c[0]) // ���ؼ� ū ���� ����� �� ���� ���� 
	//if(high>c[1])
	// if(high <c[1]) high = c[i];
	
	// 1. �Ǽ��� 100�� ����
	// 2. 0.2�� ���̰� �����ϴ� �迭�� ������
	// 3. ó�� ���۰��� Ű����� ���� �Է��� �޾ƶ�(����, �Ǽ��� �Ǿ ��)
	// 4. �� ������ �� ���� ���ض�

	double input=1;
	double aa[100] = {};
	double bb = 0;
	double sum = 0;
	cout << "���� or �Ǽ� �Է�" << endl;
	
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
	cout << "�� : " <<sum<< endl;
	

	double temp=0;
	temp = aa[99];
	aa[99] = aa[0];
	aa[0] = temp;

	cout << aa[99] <<" "<< aa[0] << endl;


	return 0;
}