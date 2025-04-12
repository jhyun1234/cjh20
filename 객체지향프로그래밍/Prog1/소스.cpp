#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(int i) // 함수 정의, 선언
{
	cout << "함수 호출" << endl;
	cout << i << endl;
}

int main(int argc, char const* argv[])
{
	/*
	int a = 10;
	int b;
	cin >> b; // b 값 입력받음
	
	
	print(a); // a에 저장된 10의 값이 print함수로 감
	cout << endl;

	print(b=b-a); // b에 5를 입력하면 -5가 b에 저장된다.
	// 출력값은 -5이다.
	cout << endl;

	print(a = a - b); 
	// 출렵값은 15
	cout << endl;

	cout << a << endl;
	print(a - 10);
	// 출력값은 5
	cout << endl;

	print(b - 5);
	// 출력값 -10
	cout << endl;
	print(10);
	// 함수에 상수를 전달했기 때문에 출력값은 10이다. 
	
	
	
	cout << (a > 6) << endl; // 참과 거짓을 판별해서 0(false) 또는 1(true)을 반환함.
	// true는 컴퓨터에서 어떤 연산의 결과가 참이면 1이라고 출력한다.1말고 다른 값도 다 참임
	cout << (a - 11 > 6) << endl;
	cout << (a - 11 < 6) << endl;
	cout << ((a - b) >= 10) << endl; // ()는 연산자중에서 제일 먼저 연산을 해야한다.

	int c, d;
	int* ptr1 = &c; 
	int* ptr2 = &d;
	cout << (ptr1 - ptr2) << endl;
	// 포인터 연산도 가능하다.
	// 결과값은 -4가 나온다.
	// 왜 -4가 나오냐면 ptr2의 주소번지가 ptr1의 주소번지보다 더 높기 때문이다.
	// 메모리 상에서 d가 c보다 높은 주소에 위치
	// ptr1을 먼저 선언을 했는데 왜 4가 아니고 -4가 나오는지는 컴퓨터마다 다르다.
	// 컴파일러가 변수를 메모리에 배치하는 방식, 순서, 정렬을 위한 간격 등이 다를 수 있음
	//결과가 - 4라는 것은 d의 주소와 c의 주소 사이에 int 타입 요소 4개만큼의 공간 차이가 있고,
	// c가 d보다 메모리 주소가 낮다는 것을 의미한다.
	// 이 '4'라는 값은 컴파일러가 변수 c와 d를 메모리에 어떻게 배치했는지에 
	// 따라 결정된 상대적인 거리일 뿐, 절대적인 규칙은 아니다.

	int e = 0;
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		print(e);
	}
	*/
	// 입력되는 숫자만큼 출력되는것은 동적 or 정적일까?
	// 입력되는 숫자만큼 함수가 호출되는것은 동적으로 처리가 된다.
	// 프로그램이 실행되는 도중에 값을 받아서 호출하기 때문에 동적으로 처리가 된다.
	
	/*

	int i = 0; // 반복횟수를 정하기 위한 변수 선언
	cin >> i;
	
	do 
	{	
		cin >> i;
		cout << "Hello World" << endl;
		// i++;
	} while (i!=0); // 컴퓨터는 0을 false로 판단하기 때문에 i=0이면 i는 false이기때문에 한 번만 출력된다.
	// 계속조건
	
	
	while (i!=0)
	{
		cin >> i;
		cout << i << endl;
		cout << "Hello Wrold!" << endl;
	}
	
	int i1 = 0;
	for (; i1 < 5; i1++)
	{
		cout << "Hello World!" << endl;
	}
	cout << i1 << endl;
	// 초기화칸은 비워둘 수 있다. 왜냐하면 루프 시작에 필요한 변수 i1의 초기화(int i1 = 0;)가 
	// 이미 for문 바깥에서 이루어졌기 때문이다. 
	// 그래서 for문 자체에서는 별도의 초기화를 할 필요가 없는 거다. 
	// 세미콜론은 반드시 있어야 한다.
	*/
	// 첫 번째 do while , while 비교
	// string을 통해 입력을 받음, 입력된 문자열의 길이가 15이상이면 프로그램이 종료가 되게끔 작성
	
	string str;
	
	do
	{
		getline(cin, str);
		cout << str << endl;
		cout << str.length() << endl;
	} while (str.length()<=15);
	
	
	while (str.length() <= 15)
	{
		getline(cin,str);
		cout << str << endl;
		cout << str.length() << endl;
	}
	

	// 두 번째 do while , while 비교
	
	// do while은 한 번은 무조건 실행해야 한다.
	// 처음부터 조건을 거짓으로 설정을 하고 결과를 확인하면
	int i2 = 100;
	do
	{
		i2++;
	} while (i2<100);
	cout <<"i2 : "<< i2 << endl;
	// 결과값은 i는 101이 나온다.
	int ii = 100;
	while (ii < 100)
	{
		ii++;
	}
	cout <<"ii :"<< ii << endl;
	// ii는 100이 출력되게 된다.


	// 세 번째 do while , while 비교
	// 입력을 받을 때는 do while은 별도로 초기화를 하지 않아도 된다.
	// 하지만, while은 먼저 조건을 검사하기 때문에 0으로 초기화 하지 않아야하는
	// 번거로움이 존재한다.
	// 사용자 입력 값에 따라 반복 여부 결정 (0 입력 시 종료)
	int input;
	do {
		cout << "숫자 입력: ";
		cin >> input; // 먼저 입력을 받음
		cout << "입력값: " << input << endl;
	} while (input!= 0); // 입력값이 0인지 검사
	cout << input<< endl;

	cout << endl;

	int input1 = -1; // while 루프에 진입하기 위해 0이 아닌 값으로 초기화
	// 또는 입력을 루프 전에 한 번 받아야 함
	// 만약 input_while을 0으로 초기화했다면 아래 루프는 실행되지 않음.
	// 만약 while을 사용하려면 보통 이렇게 먼저 입력받는 경우가 많음
	// cin >> input_while;

	while (input1!= 0) { // 먼저 조건을 검사
		cout << "숫자 입력: ";
		cin >> input1;
		cout << "입력값: " << input1 << endl;
	}
	cout <<input1 << endl;
	
	
	// 네 번째 do while , while 비교 


	int* ptr = nullptr; // 포인터가 아무것도 가리키지 않음 
	int counter = 0;
	do {
		// 일단 루프 안으로 들어와서 실행!
		cout << "do-while 루프 안 실행 횟수: " << ++counter<< endl;
		// 여기서 ptr이 가리키는 값을 사용하려고 하면 위험
		// 이 예제에서는 그냥 루프가 도는지만 확인.

		// 루프 종료를 위해 조건을 바꾸지 않음 (어차피 ptr!= nullptr 조건은 거짓)
	} while (ptr!= nullptr); // 조건을 나중에 검사 (nullptr != nullptr -> 거짓)

	cout << counter << "번 실행됨." << endl;

	cout << endl;


	int* ptr5 = nullptr; // 포인터가 아무것도 가리키지 않음
	int counter2 = 0;
	// 조건을 먼저 검사(nullptr != nullptr -> 거짓)
	while (ptr5!= nullptr) {
		// 조건이 처음부터 거짓이므로 이 안은 절대 실행되지 않음.
		cout << "while 루프 안 실행 횟수: " << ++counter2<< endl;
	}
	cout << counter2 << "번 실행됨." << endl;


	// 다섯 번째 do while, while 비교

	int arr[] = { 1,2,3,4,5 };
	int *num = arr;
	int count = 0;
	do
	{
		++count; 
		cout << "*num이 가리키는 값 : " << *num << endl;
		// num이 가리키는 값(주소값 X)
		num++;
		// 주소 1 증가
		// 실행횟수 체크
	} while (*num == 0);
	cout << count <<"번 실행"<< endl;
	// 무조건 한 번 실행을 했기 때문에 실행 횟수가 1번

	cout << endl;

	int* num2 = arr;
	int count2 = 0;
	while (*num2 == 0)
	{
		++count2;
		cout << "*num이 가리키는 값 :" << *num2 << endl;
		num2++;
	}
	cout << count2 << "번 실행" << endl;
	// 조건이 애초에 거짓이기 때문에 실행 횟수가 0번

	return 0;
	
}

