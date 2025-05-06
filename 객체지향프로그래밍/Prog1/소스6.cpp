#include <iostream>

using namespace std;

int sum(int a, int b);
float sum(float a, float b);
void swap(int &a, int &b);
void swap(float *a, float *b);
int Arr(int arr[], int a);
int SumArr(int arr[], int size);
// �Լ��� �Է°��� �ִ°Ͱ� ���°Ϳ� ���ؼ�
// �Է°��� ������ ������ return ���� �־�� �ϴ°�? NO
// �ڷ����� ����ؼ� �Լ��� ����ٸ� ������ return ���� �־�� �ϴ°�? YES
// default �Ķ���� �⺻������ ������ �Լ��ȿ� ���� ���������
// �Լ� �����ε� �Լ��� �̸��� ���Ƶ� �ڷ����� �ٸ��ų� �Ķ������ �ڷ����� �ٸ��� �����ϴ�.
// call by value ���� ������ ������ ������� ���Ӱ� ��������� �Ҵ��ؾ���
// call by ref ���� ������ ���Ұ��
int main()
{
	cout << "�� ������ �� int" << endl;
	int var1, var2 = 0;
	cin >> var1 >> var2;
	cout<<sum(var1,var2)<<endl;
	// sum(30) error ����Ʈ �Ķ���ʹ� �������� ���ֶ� , �߰��� ���� ������ �ȵȴ�.
	cout << "�� �Ǽ��� �� float" << endl;
	float c, d = 0;
	cin >> c >> d;
	cout << sum(c, d) << endl;

	cout << "�� ������ �� ��ȯ" << endl;
	int a, b = 0;
	float e, f = 0;

	cin >> a >> b;
	swap(a, b);
	cout << a<<" "<< b << endl;
	cout << "�� �Ǽ��� �� ��ȯ" << endl;
	cin >> e >> f;
	swap(&e, &f);
	cout << e <<" "<<  f << endl;
	
	cout << "�迭�� ���� �� �Է� �� �հ� �迭�� ������ ���" << endl;
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
	

	
	// ù ��° �迭
	int farry[5];

	SumArr(farry, 5);

	// �� ��° �迭

	int searry[10];

	// searry�� �պκ�(0~4)�� farry ������ ����
	for (int i = 0; i < 5; i++)
	{
		searry[i] = farry[i];
	}

	// searry�� �޺κ�(5~9) ����� �Է¹ޱ�
	int toinput = 5;
	cout << "�޺κ� �Է� : " << toinput << endl;
	for (int i = 5; i < 10; i++)
	{
		cin >> searry[i];
	}

	// ����
	int total = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << searry[i] << " ";
		total += searry[i];
	}
	cout << " ���� : "<< total << endl;


	return 0;
}

int sum(int a, int b)
{
	return a + b;
}

float sum(float a, float b) // �ڷ����� �ٸ��� ���� �Լ� �̸��� ����ص� �ȴ�.
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

int SumArr(int arr[], int size)
{
	int sum = 0;
	cout << "�迭�� �� ���� �Է� " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "���ҵ��� �� ��� ���" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		sum += arr[i]; // �հ� ����
	}
	cout << endl;

	// �� ���
	cout << sum << endl;
	return sum;
}