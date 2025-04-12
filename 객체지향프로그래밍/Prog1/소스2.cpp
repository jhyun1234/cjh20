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
	
	// 반복문 왜 쓰는가? , 전위 증감, 후위 증감
	

	// && || ! 논리 연산자에 대한 정리하기
	// 논리 곱은 둘 다 참이여야해서 앞이 거짓이면 그 뒤의 연산은 하지않는다.
	

	// 0이 들어올 때까지 정수를 입력받는다.
	// 정수에 양수 음수가 있을 수 있다.
	// 양수가 몇개 입력됐는지 , 음수가 몇개 입력됐는지 o
	// 1~10 까지의 숫자가 몇개 입력됐는지 o
	// 10~20 까지의 숫자가 몇개 입력됐는지 o
	// 20 이상의 숫자가 몇개 입력됐는지
	// -1~-10 미만의 숫자가 몇개 입력됐는지
	// -10~-20 미만의 숫자가 몇개 입력됐는지
	// -20 미만의 숫자가 몇개 입력됐는지
	// 짝수의 합 , 홀수의 합

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
		cout << "입력된 정수 :" <<input << endl;
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
	cout << "입력된 양수의 갯수 : " << countP << endl;
	cout << "입력된 음수의 갯수 : " << countM << endl;
	cout << "입력된 1이상 10 미만의 정수 갯수 : " << ten_under_count << endl;
	cout << "입력된 10이상 20 미만의 정수 갯수 : " << twenty_under_count << endl;
	cout << "입력된 20 이상의 정수 갯수 : " << twenty_over << endl;
	cout << "입력된 -1이하 -10 미만의 정수 갯수 : " << minus_ten_count << endl;
	cout << "입력된 -10이하 -20 미만의 정수 갯수 : " << minus_twenty_count << endl;
	cout << "입력된 -20 이하의 정수 갯수 : " << minus_twenty_under << endl;
	cout << "입력된 정수중 짝수의 합 : " << even_num_sum << endl;
	cout << "입력된 정수중 홀수의 합 : " << odd_num_sum << endl;
	cout << "입력된 정수중 양수의 합 : " << Psum << endl;
	cout << "입력된 정수중 음수의 합 : " << Msum << endl;




 
	return 0;
}