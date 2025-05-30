#include <iostream>
using namespace std;
/**
 * add_10: 입력하는 정수 값에 10을 더해서 반환하는 함수
 * @param {int} in [정수 매개변수]
 * @return {int}
 */
int add_10(int in)  // 1번 Labs main함수 위에 있을 때는 정의와 선언이 동시에 가능
{               // 함수 정의
	return in += 10;
}
int min_value(int x, int y);  // (4) min_value 함수 선언
// sum: 입력 매개변수로 전달받은 두 정수를 더하고 결과를 반환하는 함수
int sum(int a, int b);   // 함수 선언 (function declaration)
float mul(float a, float b);
void increase(int &x);
void swap1(int x, int y); // call of val  
void swap2(int& x, int& y); // call of ref
double div_eq(double x = 10, double y = 10) { return x / y; }
// 디폴트 매개변수는 함수 매개변수에 기본적인 값을 넣어두는것이다.
// 이 함수를 그냥 호출시 디폴트 매개변수에 있는 값으로 변수에 넣어져 계산이 진행된다.
// 함수 호출시 값을 넣을 때 값을 넣으면 그 값으로 계산이 진행된다.
int main(int argc, char const* argv[]) // (2) main 함수 정의
{

	int data;

	cout << "정수를 입력하시요: ";
	cin >> data;

	cout << add_10(data) << endl;  // 함수 호출 


	cout << min_value(3, 5) << endl;   // (1) 함수 호출 
	// 2번 Labs 
	// 2 - 3 - 4 -1 

	// 3번 Labs
	int x = 10, y = 30;

	int result = sum(x, y);  // 함수 호출 (function call)

	cout << x << " + " << y << " = " << result << endl;

	

	
	// 6번 Labs
	float x1, y1;

	cout << "실수 두개를 입력하시오: " << endl;
	cin >> x1 >> y1;

	cout << mul(x1, y1) << endl;
	cout << endl;
	// 7번 Labs
	int x2 = 10;

	increase(x2);

	cout << "출력: " << x2 << endl;
	cout << endl;
	// 8번 Labs
	int x3 = 10, y3 = 20;

	cout << "(출력 1) x: " << x3 << ", y: " << y3 << endl;
	swap1(x3, y3);
	cout << "(출력 2) x: " << x3 << ", y: " << y3 << endl;
	swap2(x3, y3);
	cout << "(출력 3) x: " << x3 << ", y: " << y3 << endl;
	// swap1은 함수 안에서만 값이 바뀌는 call of value이고
	// swap2는 함수 밖에서도 그 값이 영향을 주는 call of ref이다.
	cout << endl;
	// 9번 Labs
	cout << "출력(1): " << div_eq() << endl; // 
	cout << "출력(2): " << div_eq(5) << endl;
	cout << "출력(3): " << div_eq(50, 10) << endl;
	

	return 0;
}
int min_value(int x, int y) { return x > y ? y : x; } // (3) min_value 함수 정의

int sum(int x, int y) { return x + y; }

float mul(float a, float b) {return a * b;}

void increase(int &x) {	x++;} // main함수에 있는 변수의 주소를 전달해야지 
//함수가 그 주소를 읽어서 값을 바꾸면 main함수에도 값이 바뀌기 때문

void swap1(int x, int y) {
	cout << "(swap1 연산 전 출력) x:" << x << ", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap1 연산 후 출력) x:" << x << ", y: " << y << endl;
}

void swap2(int& x, int& y) {
	cout << "(swap2 연산 전 출력) x:" << x << ", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap2 연산 후 출력) x:" << x << ", y: " << y << endl;
}
