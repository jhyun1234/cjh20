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
	
	

	// && || ! �� �����ڿ� ���� �����ϱ�
	// �� ���� �� �� ���̿����ؼ� ���� �����̸� �� ���� ������ �����ʴ´�.
	// && (AND) : ���� �ǿ����ڰ� false�̸�, ��ü ����� ������ false�̹Ƿ�
	// ������ �ǿ����ڴ� �ƿ� �������� �ʴ´�.
	// || (OR) : ���� �ǿ����ڰ� true�̸�, ��ü ����� ������ true�̹Ƿ�
	// ������ �ǿ����ڴ� �ƿ� �������� �ʴ´�.
	// ! (NOT) : �ǿ������� ����(��/����)�� �ݴ�� �����´�. ���� �������� ������ ������  

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

	int input=1; // �Է� ���� ����

	int ten_under_count = 0; // 10�̸��� ���� �Է� ī��Ʈ Ȯ�� ���� ����
	int twenty_under_count = 0; // 20�̸��� ���� �Է� ī��Ʈ Ȯ�� ���� ����
	int twenty_over = 0; // 20 �̻��� ���� �Է� ī��Ʈ Ȯ�� ���� ����

	int minus_ten_count = 0; // -10�̸��� ���� �Է� ī��Ʈ Ȯ�� ���� ����
	int minus_twenty_count = 0;// -20�̸��� ���� �Է� ī��Ʈ Ȯ�� ���� ����
	int minus_twenty_under = 0;// -20 �̻��� ���� �Է� ī��Ʈ Ȯ�� ���� ����

	int even_num_sum = 0; // ¦���� �� ���� ����
	int odd_num_sum = 0; // Ȧ���� �� ���� ����
	 
	int countP = 0;  // ��� �Է� ī��Ʈ ���� ����
	int countM = 0; // ���� �Է� ī��Ʈ ���� ����
	 
	int Psum = 0; // ��� �� ���� ����
	int Msum = 0; // ���� �� ���� ����

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




	int score = 0;
	cin >> score;
	if (score >= 95)
	{
		cout << "A+" << endl;
	}
	else if (score >= 90)
	{
		cout << "A" << endl;
	}
	else if (score >= 85)
	{
		cout << "B+" << endl;
	}
	else if (score >= 80)
	{
		cout << "B" << endl;
	}
	else if (score >= 75)
	{
		cout << "C+" << endl;
	}
	else if (score >= 70)
	{
		cout << "C" << endl;
	}
	else if (score >= 65)
	{
		cout << "D+" << endl;
	}
	else if (score >= 60)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "F" << endl;
	}

	int num = 0;
	cin >> num;
	if (num < 0)
	{
		cout << ~num + 1 << endl; // 2�� ���� ǥ���� 
	}
	else
	{
		cout << num << endl;
	}


	int num2 = 0;
	int num3 = 0;
	int num4 = 0;

	int max, min;
	cin >> num2 >> num3 >> num4;

	// ù ��° ���ڸ� �ʱ� max�� min���� ����
	max = num2;
	min = num2;

	if (num3 > max)
	{
		max = num3; // num3�� �� ũ�� max�� num3�� ����
	}
	if (num3 < min)
	{
		min = num3; // ���� ������� num3�� ����
	}

	if (num4 > max)
	{
		max = num4;
	}
	if (num4 < min)
	{
		min = num4;
	}

	cout << "max : " << max << endl;
	cout << "min : " << min << endl;


 
	return 0;
}