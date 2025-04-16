#include <iostream>

using namespace std;

int main()
{
	int a = 1;
	int sum = 0;
	while (a != 0)
	{
		cout << "숫자 입력 : " << endl;
		cin >> a;

		if (a > 0)
		{
			sum += a;
		}

	}
	cout << "합 : " << sum << endl;


	int n;
	int sum2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num > 0)
			sum2 += num;
	}
	cout << "합 : " << sum2 << endl;

}