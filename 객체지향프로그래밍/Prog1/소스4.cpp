#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	int ages[5] = { 10, 40, 30 };

	cout << ages[0] << endl; // 출력 1
	cout << ages[1] << endl; // 출력 2
	cout << ages[3] << endl; // 출력 3
	cout << ages[5] << endl; // 출력 4

	// ages[0] 의 값은 10 
	// ages[1] 의 값은 40 
	// ages[3] 의 값은 0 
	// ages[5] 는 배열에서 정한 그 이상의 메모리 주소에
	// 접근하려고 하니 쓰레기값이 나온다.
	

	int ages1[] = { 10, 40, 30 };

	cout << ages1[0]<<" "<<sizeof(ages1[0]) << endl; // 출력 1
	cout << ages1[1] <<" "<< sizeof(ages1[1]) << endl; // 출력 2
	cout << ages1[3] <<" "<< sizeof(ages1[3]) << endl; // 출력 3

	// ages1[0] 의 값은 10  사이즈는 4바이트이다. int형의 배열을 잡았기 때문에 4바이트가 할당된다.
	// ages1[1] 의 값은 40  똑같은 이유
	// ages1[3] 의 값은 쓰레기값이 나온다. 쓰레기값이 나오는건 ages1[3]은 메모리의 범위를 벗어나버렸기
	// 때문이고 사이즈가 나오는 것처럼 보이는 이유는 ages1[3]의 표현식의 타입이 int 이기 때문이다.


	char grades[] = { 'A', 'B', 'C', 'D', 'F' };      // 문자 배열 
	char name[] = { 'P', 'e', 't', 'e', 'r', '\0' }; // 문자열 배열

	cout << grades[0] << endl; // 출력 1
	cout << name[0] << endl;   // 출력 2

	// grades[0] 의 문자는 배열의 0번째에 위치한 A가 출력이 된다.
	// name[0] 의 문자는 배열의 0번째에 위치한 P가 출력이 된다.

	cout << name[5] << endl;   // 출력 3
	cout << grades[5] << endl; // 출력 4

	// name[5]는 널문자 \0 를 출력하고 있다. 
	// grades[5]는 위의 문제와 동일하게 메모리의 범위를 벗어나 접근을 시도하기 때문에
	// 정의되지 않은 행동을 해서 아무것도 나오지 않는것처럼 보이는것이다.

	cout << name << endl;      // 출력 5
	cout << grades << endl;    // 출력 6

	// name은 배열에 \0 널문자가 포함되어 있어 널문자를 만나서 제대로 종료가 됐지만
	// grades은 널문자 \0 가 없기 때문에 계속해서 읽을려는 시도를 하기 때문에 정의되지않은 행동을 한다.
	// 그렇기 때문에 이상한 문자들이 출력이 된다.


	cout << sizeof(grades) << endl; 
	cout << sizeof(name) << endl;

	// 사이즈가 다른 이유는 name에는 \0문자를 포함해서 사이즈가 6이된다.
	// grades의 사이즈는 5로 출력이된다.

	int a = 20203324;  
	cout << a % 3; // 시험자리 1 

	return 0;
}