#include <iostream>
using namespace std;


int main()
{
	
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
		cout << ~num+1 << endl; // 2�� ���� ǥ���� 
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

	cout << "max : " <<max<< endl;
	cout << "min : " << min<<endl;


	return 0;
}