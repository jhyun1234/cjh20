#include <iostream>

using namespace std;
void increase10(int *val);
void increase11(int& val);
int Sum(int val1, int val2);
void Swap(int* val1, int* val2);
int Maxvalue(int arr[], int size);
int Minvalue(int arr[], int size);
int Middlevalue(int arr[], int size);
int main()
{
	int c = 10;
	increase11(c);
	increase10(&c);

	int a = 10;
	// const a = 10;
	// a = 30; error const를 붙이면 값을 변경할 수 없다.
	
	const int& b=a;
	// 참조변수 앞에도 const를 붙일 수 있다.
	// b = 50; error 
	a = 50;
	cout <<"a의 값 : " << a << endl;
	
	increase10(&a); // 값을 증가시키는 함수
	cout <<"함수 호출 후 증가된 a의 값 : " << a << endl;

	Sum(a, b); // 두 값을 더하는 함수
	cout <<"Sum함수 호출 후 값 : " << Sum(a, b) << endl;
	// 120이 나오는 이유는 참조변수 b는 a를 참조하고있다. 
	// a가 increase10()함수를 통해 값이 증가되었기 때문에 60 + 60 = 120 이 나온다.
	cout << endl;


	int arr[5] = { 15,25,35,45,55 };
	cout <<"arr배열의 1번째 인덱스와 4번째 인덱스의 합 : " << Sum(arr[1], arr[4]) << endl;
	// 배열의 인덱스를 통해서 값을 반환할 수 있다.

	int c = 30;
	cout << "기존 a ,c 값 : " << a <<" " << c << endl;
	Swap(&a, &c);
	cout <<"a와 c의 값을 Swap 함수를 통해서 바꾼 값 : " << a << " " << c << endl;

	cout << "기존 arr[0] ,arr[4]의 값 : " << arr[0] << " " << arr[4] << endl;
	Swap(&arr[0], &arr[4]);
	cout <<"arr[0]와 arr[4]의 값을 Swap 함수를 통해서 바꾼 값 : " << arr[0] << " " << arr[4] << endl;
	// 배열의 인덱스를 통해서 값을 바꿀 수 있다.
	cout << endl;

	// arr[2] = 1;
	cout<< "Maxvalue함수를 호출해 찾은 값 : " <<Maxvalue(arr, 5)<< endl;
	// arr 배열에 있는 최대값을 찾는 함수호출

	cout<< "Minvalue함수를 호출해 찾은 값 : "<<Minvalue(arr, 5)<<endl;
	// arr 배열에 있는 최솟값을 찾는 함수호출
	
	cout << "Middlevalue함수를 호출해 찾은 값 : " << Middlevalue(arr, 5) << endl;
	// arr 배열중 중간값을 구하는 함수호출


	return 0;
}

void increase10(int *val)
{

	*val += 10;
}
/*
void increase10(const int* val)
{
	
	*val += 10;
	cout<<*val<<endl;
}
*/
void increase11(int& val)
{

	val += 10;
}


int Sum(int val1, int val2)
{
	return val1 + val2;
}

void Swap(int *val1, int *val2)
{

	int temp = 0;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}


int Maxvalue(int arr[],int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;

}

int Minvalue(int arr[], int size)
{
	int min=arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
	
}

int Middlevalue(int arr[], int size)
{
	if (size <= 0)
	{
		return false;
	}
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		else if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return (max + min) / 2;

}