#pragma once
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int* ptr = &a;
	int* ptr2;
	int& ref = *ptr;   // 참조 변수를 통해 a의 값을 바꿀 수 있다.
	cout << ptr << endl;
	*ptr = 30; // 이때의 * 는 연산자이다. 
	cout << *ptr << endl; // 30 
	cout << a << endl; // 30
	ref = 40;
	cout << ref << endl; // 40
	cout << a << endl; // 40
	cout << endl;

	// 이중 포인터
	int** ptr1 = &ptr;
	cout << ptr1 << endl; // ptr1의 주소
	cout << *ptr1 << endl; // *ptr1이 가리키는 값(ptr의 주소)
	cout << **ptr1 << endl; // **ptr1이 가리키는 값(a의 값)

	// 배열 변수
	cout << endl;
	int arr[3] = { 1,2,3 };

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	arr[0] = 10;
	cout << arr[0] << endl;
	cout << sizeof(arr) << endl; // 4바이트 자료형인 int형을 3개를 가지고 있기 때문에 12가 나온다.
	for (int i = 0; i < 3; i++) // for문을 통해 순회하며 arr배열의 주소값을 출력하게 한다.
	{
		cout << &arr[i] << endl; // 결과적으로 4바이트만큼 띄워서 출력이 될것이다.
	}


	int a1;
	double d1;
	char c1;

	// sizeof()
	// 특정 데이터 타입이 얼마나 많은 메모리를 사용하는지 알 수 있다.
	// 배열 전체의 크기를 바이트 단위로 얻을 수 있다.
	// 이를 통해 배열의 요소 개수를 계산할 수 있다.
	// 구조체와 클래스가 메모리에서 차지하는 총 크기를 알 수 있다.
	cout << "int 자료형의 크기: " << sizeof(int) << " 바이트" << std::endl;
	cout << "double 자료형의 크기: " << sizeof(double) << " 바이트" << std::endl;
	cout << "char 자료형의 크기: " << sizeof(char) << " 바이트" << std::endl;
	cout << "int 변수 a1의 크기: " << sizeof(a1) << " 바이트" << std::endl;
	cout << "double 변수 d1의 크기: " << sizeof(d1) << " 바이트" << std::endl;
	cout << "char 변수 c1의 크기: " << sizeof(c1) << " 바이트" << std::endl;
	cout << "배열 arr 크기: " << sizeof(arr) << " 바이트" << std::endl;

	unsigned char c2;
	cout << "unsigned char c2의 크기" << sizeof(c2) << endl;
	// char 자료형은 일반적으로 1바이트(8비트)의 크기를 가지고 있다.
	// unsigned 키워드가 붙어있기 때문에 부호가 없는 (non-negative) 정수형이다.음수 값을 표현할 수 없다.
	// 8비트로 표현할 수 있는 모든 비트를 값의 크기를 나타내는 데 사용하므로, 0부터 255까지의 정수 값을 표현한다.
	// 
	// 사용하는 이유 
	// 일반적으로 -128부터 127까지의 값을 표현하거나
	// 0부터 255까지의 값을 표현할 수 있다. 
	// 어떤 범위를 가지는지는 컴파일러 및 플랫폼에 따라 다르다.
	// 그렇기 때문에 확실하게 양의 정수만 표현하기 위해서 unsigned 를 사용한다.
	// 예시) 이미지 처리 데이터의 픽셀 값은 0~255 사이의 값을 가지므로 unsigned를 사용해야 한다.

	return 0;
}
