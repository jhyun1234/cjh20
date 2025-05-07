#include <iostream>

using namespace std;
void increase10(int *val);
int Sum(int val1, int val2);
void Swap(int* val1, int* val2);
int Maxvalue(int arr[], int size);
int Minvalue(int arr[], int size);
int Middlevalue(int arr[], int size);
int main()
{
	int a = 10;
	
	// a = 30; error const를 붙이면 값을 변경할 수 없다.
	
	const int& b=a;
	
	a = 50;
	cout << a << endl;
	
	increase10(&a);
	cout << a << endl;

	Sum(a, b);
	cout << Sum(a, b) << endl;


	int arr[5] = { 10,20,30,40,50 };
	cout << Sum(arr[1], arr[4]) << endl;
	// 배열의 인덱스를 통해서 값을 반환할 수 있다.

	int c = 30;
	Swap(&a, &c);
	cout << a << " " << c << endl;

	Swap(&arr[0], &arr[4]);
	cout << arr[0] << " " << arr[4] << endl;
	// 배열의 인덱스를 통해서 값을 바꿀 수 있다.
	
	// arr[2] = 1;
	cout<<Maxvalue(arr, 5)<<endl;
	cout<<Minvalue(arr, 5)<<endl;

	cout << Middlevalue(arr, 5) << endl;

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
	int mid = 0;
	int max = 0;
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return (max + min) / 2;

}