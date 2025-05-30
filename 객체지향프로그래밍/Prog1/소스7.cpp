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
	// a = 30; error const�� ���̸� ���� ������ �� ����.
	
	const int& b=a;
	// �������� �տ��� const�� ���� �� �ִ�.
	// b = 50; error 
	a = 50;
	cout <<"a�� �� : " << a << endl;
	
	increase10(&a); // ���� ������Ű�� �Լ�
	cout <<"�Լ� ȣ�� �� ������ a�� �� : " << a << endl;

	Sum(a, b); // �� ���� ���ϴ� �Լ�
	cout <<"Sum�Լ� ȣ�� �� �� : " << Sum(a, b) << endl;
	// 120�� ������ ������ �������� b�� a�� �����ϰ��ִ�. 
	// a�� increase10()�Լ��� ���� ���� �����Ǿ��� ������ 60 + 60 = 120 �� ���´�.
	cout << endl;


	int arr[5] = { 15,25,35,45,55 };
	cout <<"arr�迭�� 1��° �ε����� 4��° �ε����� �� : " << Sum(arr[1], arr[4]) << endl;
	// �迭�� �ε����� ���ؼ� ���� ��ȯ�� �� �ִ�.

	int c = 30;
	cout << "���� a ,c �� : " << a <<" " << c << endl;
	Swap(&a, &c);
	cout <<"a�� c�� ���� Swap �Լ��� ���ؼ� �ٲ� �� : " << a << " " << c << endl;

	cout << "���� arr[0] ,arr[4]�� �� : " << arr[0] << " " << arr[4] << endl;
	Swap(&arr[0], &arr[4]);
	cout <<"arr[0]�� arr[4]�� ���� Swap �Լ��� ���ؼ� �ٲ� �� : " << arr[0] << " " << arr[4] << endl;
	// �迭�� �ε����� ���ؼ� ���� �ٲ� �� �ִ�.
	cout << endl;

	// arr[2] = 1;
	cout<< "Maxvalue�Լ��� ȣ���� ã�� �� : " <<Maxvalue(arr, 5)<< endl;
	// arr �迭�� �ִ� �ִ밪�� ã�� �Լ�ȣ��

	cout<< "Minvalue�Լ��� ȣ���� ã�� �� : "<<Minvalue(arr, 5)<<endl;
	// arr �迭�� �ִ� �ּڰ��� ã�� �Լ�ȣ��
	
	cout << "Middlevalue�Լ��� ȣ���� ã�� �� : " << Middlevalue(arr, 5) << endl;
	// arr �迭�� �߰����� ���ϴ� �Լ�ȣ��


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