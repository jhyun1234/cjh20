#include <iostream>

using namespace std;

int sum(int a, int b);
void swap(int &a, int &b);
void swap(float *a, float *b);
int Arr(int arr[], int a);

// �Լ��� �Է°��� �ִ°Ͱ� ���°Ϳ� ���ؼ�
// �Է°��� ������ ������ return ���� �־�� �ϴ°�? NO
// �ڷ����� ����ؼ� �Լ��� ����ٸ� ������ return ���� �־�� �ϴ°�? YES
// default �Ķ���� �⺻������ ������ �Լ��ȿ� ���� ���������
// �Լ� �����ε� �Լ��� �̸��� ���Ƶ� �ڷ����� �ٸ��ų� �Ķ������ �ڷ����� �ٸ��� �����ϴ�.
// call by value ���� ������ ������ ������� ���Ӱ� ��������� �Ҵ��ؾ���
// call by ref ���� ������ ���Ұ��
int main()
{
	/*
	int var1, var2 = 0;
	cin >> var1 >> var2;
	cout<<sum(var1,var2)<<endl;
	// sum(30) error ����Ʈ �Ķ���ʹ� �������� ���ֶ� , �߰��� ���� ������ �ȵȴ�.
	float c, d = 0;
	cin >> c >> d;
	cout << sum(c, d) << endl;


	int a, b = 0;
	float e, f = 0;

	cin >> a >> b;
	swap(a, b);
	cout << a<<" "<< b << endl;

	cin >> e >> f;
	swap(&e, &f);
	cout << e <<" "<<  f << endl;
	*/
	cout << "�迭" << endl;
	/*
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

	int data[5] = {};
	
	int data2[10] = {};
	
	for (int i = 0; i < 5; i++)
	{
		data2[i] = data[i];
	}

	int input = 5;
	for (int i = 5; i < 10; i++)
	{
		cin >> data2[i];

		cout << data2[i] << endl;
	}


	return 0;
}

int sum(int a, int b)
{
	return a + b;
}

float sum(float a, float b)
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

int Arr(int arr[],int size) // �ּҸ� �����԰� ���ÿ� �����͸� ��� �����ؾ� �ϴ����� �˾ƾ� �Ѵ�.
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
	cout << sizeof(arr) << endl;  // 8 �� ������ ������ ������ ������ ũ�� �����̴�.
	return sum;
}
