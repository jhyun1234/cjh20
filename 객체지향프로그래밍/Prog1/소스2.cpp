#include <iostream>
using namespace std;


int main()
{
	/*
	int sum = 0;
	for (int i = 0; i <= 10; i++)
	{
		sum += i;
		cout << sum << endl;
	}


	int a = 1;
	int b = 2;
	int c;

	c = a++ + +b; // 1+2 
	cout << c << endl; // 3
	c = ++a + b--;  //   3 + 2
	cout << c << endl;  
	c = ++a + b++; // 4+1
	cout << c << endl;
	*/
	
	// �ݺ��� �� ���°�? , ���� ����, ���� ����
	

	// && || ! �� �����ڿ� ���� �����ϱ�
	// �� ���� �� �� ���̿����ؼ� ���� �����̸� �� ���� ������ �����ʴ´�.
	

	// 0�� ���� ������ ������ �Է¹޴´�.
	// ������ ��� ������ ���� �� �ִ�.
	// ����� � �Էµƴ��� , ������ � �Էµƴ��� o
	// 1~10 ������ ���ڰ� � �Էµƴ��� o
	// 10~20 ������ ���ڰ� � �Էµƴ��� o
	// 20 �̻��� ���ڰ� � �Էµƴ���
	// -1~-10 �̸��� ���ڰ� � �Էµƴ���
	// -10~-20 �̸��� ���ڰ� � �Էµƴ���
	// -20 �̸��� ���ڰ� � �Էµƴ���
	// ¦���� �� , Ȧ���� ��

	int input=1;

	int ten_under_count = 0;
	int twenty_under_count = 0;
	int twenty_over = 0;

	int minus_ten_count = 0;
	int minus_twenty_count = 0;
	int minus_twenty_under = 0;

	int even_num_sum = 0;
	int odd_num_sum = 0;

	int countP = 0;
	int countM = 0;

	int Psum = 0;
	int Msum = 0;

	while (input != 0)
	{
		cin >> input;
		cout << "�Էµ� ���� :" <<input << endl;
		if (input > 0)
		{
			countP++;
		}
		
		else if (input < 0)
		{
			countM++;
		}
		if (input >= 1)
		{
			Psum += input;
		}
		else
		{
			Msum += input;
		}

		if (input % 2 == 0)
		{
			even_num_sum += input;
		}
		else
		{
			odd_num_sum += input;
		}
		
		
		if (input >= 1 && input < 10)
		{
			ten_under_count++;
		}
		else if (input >= 10 && input < 20)
		{
			twenty_under_count++;
		}
		else if (input >=20)
		{
			twenty_over++;
		}
		
		if (input <= -1 && input > -10)
		{
			minus_ten_count++;
		}
		else if (input <= -10 && input > -20)
		{
			minus_twenty_count++;
		}
		else if(input <=-20)
		{
			minus_twenty_under++;
		}

		
	}
	cout<<endl;
	cout << "�Էµ� ����� ���� : " << countP << endl;
	cout << "�Էµ� ������ ���� : " << countM << endl;
	cout << "�Էµ� 1�̻� 10 �̸��� ���� ���� : " << ten_under_count << endl;
	cout << "�Էµ� 10�̻� 20 �̸��� ���� ���� : " << twenty_under_count << endl;
	cout << "�Էµ� 20 �̻��� ���� ���� : " << twenty_over << endl;
	cout << "�Էµ� -1���� -10 �̸��� ���� ���� : " << minus_ten_count << endl;
	cout << "�Էµ� -10���� -20 �̸��� ���� ���� : " << minus_twenty_count << endl;
	cout << "�Էµ� -20 ������ ���� ���� : " << minus_twenty_under << endl;
	cout << "�Էµ� ������ ¦���� �� : " << even_num_sum << endl;
	cout << "�Էµ� ������ Ȧ���� �� : " << odd_num_sum << endl;
	cout << "�Էµ� ������ ����� �� : " << Psum << endl;
	cout << "�Էµ� ������ ������ �� : " << Msum << endl;




 
	return 0;
}