#include <iostream>
using namespace std;


int main()
{
	/*
	int score = 0;
	cin >> score;
	if (score >= 95)
	{
		cout << "A+" << endl;
	}
	else if (score >= 94)
	{
		cout << "A+" << endl;
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
		cout << ~num+1 << endl;
	}
	else
	{
		cout << num << endl;
	}
	
	*/

	int num2 = 0;
	int num3 = 0;
	int num4 = 0;

	int max, min = 0;
	cin >> num2;
	cin >> num3;
	cin >> num4;
	if (num2 > num3 && num2 > num4 && num3>num4)
	{
		max = num2;
		min = num4;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}
	else if (num3 > num2 && num3 > num4 && num2>num4)
	{
		max = num3;
		min = num4;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}
	else if(num4>num3 && num4>num2 &&num3>num2)
	{
		max = num4;
		min = num2;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}

	return 0;
}