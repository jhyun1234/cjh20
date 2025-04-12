#include <iostream>
using namespace std;
int main()
{
	int a = 10; // a 라는 변수를 선언 그 안에 10이라는 값을 저장
	int b = 21;
	cout<<"Hello World!\n"<< endl; 
	cout<<"Hello \t World!"<< endl; // /t 를 사용하면 띄어쓰기 기능이 있다.
	cout<<"Hello "<< "World!" << endl;
	cout<<"Hello"<< "World!" << endl; // 연속으로 출력

    
	cout << 5 << endl; // 상수 5의 값을 출력
	// 어디에 저장될까? -> CPU의 레지스터 라는 곳에서 처리가 된다고 함
	

	cout << "a:"<< a << endl; // 정수 a 의 값을 출력한다.
	cout << "a:10" << endl; // a:10 이라는 문자열을 출력한다.
	cout << "a"<<":10" << endl;  // a :10 이라는 문자열을 출력한다.

	// 출력은 동일하게 보이지만 출력을 어떤 방식으로 하는지에 따라서 달라진다.

	cout << a + 5 << endl; // 그저 a에 5를 더한 값을 보여줘
	cout << "a + 5" << endl; // a+5 문자열이 출력된다.

	cout << a + b << endl; 
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a % b << endl;
	cout << a / (double)b << endl; // 실수로 나옴 메모리에는 int 4 바이트를 
								//	할당하지만 계산할 때는 일시적으로 실수로 사용된다.
								// 이렇게 바꾼 b를 저장하려면 어떻게 해야할까?
	// 먼저 나눈값을 저장할 변수를 선언해야 한다.
	// 실수를 저장하기 위해서니 double로 선언하겠다.
	double newb = a / (double)b;
	cout << newb << endl;
	b = newb;
	cout << b; // 0이 출력되는 모습을 볼 수 있음
	// 왜 0이 나올까? 
	// b 는 처음에 int로 선언되었기 때문에 실수는 처리하지 못한다.
	// 그렇기 때문에 소수점은 출력하지 못하기 때문에 0 으로 출력이 된다.
	// 소수점을 출력하기 위해서는 double로 다시 선언을 해야한다.
	


	return 0;
}