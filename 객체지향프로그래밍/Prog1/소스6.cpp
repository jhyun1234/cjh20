#include <iostream>

using namespace std;

int sum(int a, int b);
float sum(float a, float b);
void swap(int &a, int &b);
void swap(float *a, float *b);
int Arr(int arr[], int a);
int SumArr(int arr[], int size);
// 함수의 입력값이 있는것과 없는것에 대해서
// 입력값이 있으면 무조건 return 값이 있어야 하는가? NO
// 자료형을 명시해서 함수를 만든다면 무조건 return 값이 있어야 하는가? YES
// default 파라미터 기본적으로 가지고 함수안에 직접 집어넣은값
// 함수 오버로드 함수의 이름이 같아도 자료형이 다르거나 파라미터의 자료형이 다르면 가능하다.
// call by value 값의 변경이 원하지 않을경우 새롭게 저장공간을 할당해야함
// call by ref 값의 변경을 원할경우
int main()
{
	/*
	cout << "두 정수의 합 int" << endl;
	int var1, var2 = 0;
	cin >> var1 >> var2;
	cout<<sum(var1,var2)<<endl;
	// sum(30) error 디폴트 파라미터는 뒤쪽으로 놔둬라 , 중간에 빈값이 있으면 안된다.
	cout << "두 실수의 합 float" << endl;
	float c, d = 0;
	cin >> c >> d;
	cout << sum(c, d) << endl;

	cout << "두 정수의 값 교환" << endl;
	int a, b = 0;
	float e, f = 0;

	cin >> a >> b;
	swap(a, b);
	cout << a<<" "<< b << endl;
	cout << "두 실수의 값 교환" << endl;
	cin >> e >> f;
	swap(&e, &f);
	cout << e <<" "<<  f << endl;
	
	cout << "배열에 넣을 값 입력 후 합과 배열의 사이즈 출력" << endl;
	int arr[5] = {};
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++)
	{

		cout <<arr[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i];

	}
	cout << sum << endl;
	cout << sizeof(arr) << endl;
	*/

	
	// 첫 번째 배열
	int farry[5];

	SumArr(farry, 5);

	// 두 번째 배열

	int searry[10];

	// searry의 앞부분(0~4)을 farry 값으로 복사
	for (int i = 0; i < 5; i++)
	{
		searry[i] = farry[i];
	}

	// searry의 뒷부분(5~9) 사용자 입력받기
	int toinput = 5;
	cout << "뒷부분 입력 : " << toinput << endl;
	for (int i = 5; i < 10; i++)
	{
		cin >> searry[i];
	}

	// 총합
	int total = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << searry[i] << " ";
		total += searry[i];
	}
	cout << " 총합 : "<<total << endl;


	return 0;
}

int sum(int a, int b)
{
	return a + b;
}

float sum(float a, float b) // 자료형이 다르면 같은 함수 이름을 사용해도 된다.
{
	return a + b;
}

void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;

}

void swap(float* a, float* b)
{
	float temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Arr(int arr[],int size) // 주소를 전달함과 동시에 데이터를 몇개를 전달해야 하는지도 알아야 한다.
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	cout << endl;
	cout << sum << endl;
	cout << sizeof(arr) << endl;  // 8 이 나오는 이유는 포인터 변수의 크기 때문이다.
	return sum;
}

int SumArr(int arr[], int size)
{
	int sum = 0;
	cout << "배열에 들어갈 원소 입력 " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "원소들의 합 계산 출력" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		sum += arr[i]; // 합계 누적
	}
	cout << endl;

	// 합 출력
	cout << sum << endl;
	return sum;
}