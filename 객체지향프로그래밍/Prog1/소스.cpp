#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(int i) // �Լ� ����, ����
{
	cout << "�Լ� ȣ��" << endl;
	cout << i << endl;
}

int main(int argc, char const* argv[])
{
	/*
	int a = 10;
	int b;
	cin >> b; // b �� �Է¹���
	
	
	print(a); // a�� ����� 10�� ���� print�Լ��� ��
	cout << endl;

	print(b=b-a); // b�� 5�� �Է��ϸ� -5�� b�� ����ȴ�.
	// ��°��� -5�̴�.
	cout << endl;

	print(a = a - b); 
	// ��ư��� 15
	cout << endl;

	cout << a << endl;
	print(a - 10);
	// ��°��� 5
	cout << endl;

	print(b - 5);
	// ��°� -10
	cout << endl;
	print(10);
	// �Լ��� ����� �����߱� ������ ��°��� 10�̴�. 
	
	
	
	cout << (a > 6) << endl; // ���� ������ �Ǻ��ؼ� 0(false) �Ǵ� 1(true)�� ��ȯ��.
	// true�� ��ǻ�Ϳ��� � ������ ����� ���̸� 1�̶�� ����Ѵ�.1���� �ٸ� ���� �� ����
	cout << (a - 11 > 6) << endl;
	cout << (a - 11 < 6) << endl;
	cout << ((a - b) >= 10) << endl; // ()�� �������߿��� ���� ���� ������ �ؾ��Ѵ�.

	int c, d;
	int* ptr1 = &c; 
	int* ptr2 = &d;
	cout << (ptr1 - ptr2) << endl;
	// ������ ���굵 �����ϴ�.
	// ������� -4�� ���´�.
	// �� -4�� �����ĸ� ptr2�� �ּҹ����� ptr1�� �ּҹ������� �� ���� �����̴�.
	// �޸� �󿡼� d�� c���� ���� �ּҿ� ��ġ
	// ptr1�� ���� ������ �ߴµ� �� 4�� �ƴϰ� -4�� ���������� ��ǻ�͸��� �ٸ���.
	// �����Ϸ��� ������ �޸𸮿� ��ġ�ϴ� ���, ����, ������ ���� ���� ���� �ٸ� �� ����
	//����� - 4��� ���� d�� �ּҿ� c�� �ּ� ���̿� int Ÿ�� ��� 4����ŭ�� ���� ���̰� �ְ�,
	// c�� d���� �޸� �ּҰ� ���ٴ� ���� �ǹ��Ѵ�.
	// �� '4'��� ���� �����Ϸ��� ���� c�� d�� �޸𸮿� ��� ��ġ�ߴ����� 
	// ���� ������ ������� �Ÿ��� ��, �������� ��Ģ�� �ƴϴ�.

	int e = 0;
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		print(e);
	}
	*/
	// �ԷµǴ� ���ڸ�ŭ ��µǴ°��� ���� or �����ϱ�?
	// �ԷµǴ� ���ڸ�ŭ �Լ��� ȣ��Ǵ°��� �������� ó���� �ȴ�.
	// ���α׷��� ����Ǵ� ���߿� ���� �޾Ƽ� ȣ���ϱ� ������ �������� ó���� �ȴ�.
	
	/*

	int i = 0; // �ݺ�Ƚ���� ���ϱ� ���� ���� ����
	cin >> i;
	
	do 
	{	
		cin >> i;
		cout << "Hello World" << endl;
		// i++;
	} while (i!=0); // ��ǻ�ʹ� 0�� false�� �Ǵ��ϱ� ������ i=0�̸� i�� false�̱⶧���� �� ���� ��µȴ�.
	// �������
	
	
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
	// �ʱ�ȭĭ�� ����� �� �ִ�. �ֳ��ϸ� ���� ���ۿ� �ʿ��� ���� i1�� �ʱ�ȭ(int i1 = 0;)�� 
	// �̹� for�� �ٱ����� �̷������ �����̴�. 
	// �׷��� for�� ��ü������ ������ �ʱ�ȭ�� �� �ʿ䰡 ���� �Ŵ�. 
	// �����ݷ��� �ݵ�� �־�� �Ѵ�.
	*/
	// ù ��° do while , while ��
	// string�� ���� �Է��� ����, �Էµ� ���ڿ��� ���̰� 15�̻��̸� ���α׷��� ���ᰡ �ǰԲ� �ۼ�
	
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
	

	// �� ��° do while , while ��
	
	// do while�� �� ���� ������ �����ؾ� �Ѵ�.
	// ó������ ������ �������� ������ �ϰ� ����� Ȯ���ϸ�
	int i2 = 100;
	do
	{
		i2++;
	} while (i2<100);
	cout <<"i2 : "<< i2 << endl;
	// ������� i�� 101�� ���´�.
	int ii = 100;
	while (ii < 100)
	{
		ii++;
	}
	cout <<"ii :"<< ii << endl;
	// ii�� 100�� ��µǰ� �ȴ�.


	// �� ��° do while , while ��
	// �Է��� ���� ���� do while�� ������ �ʱ�ȭ�� ���� �ʾƵ� �ȴ�.
	// ������, while�� ���� ������ �˻��ϱ� ������ 0���� �ʱ�ȭ ���� �ʾƾ��ϴ�
	// ���ŷο��� �����Ѵ�.
	// ����� �Է� ���� ���� �ݺ� ���� ���� (0 �Է� �� ����)
	int input;
	do {
		cout << "���� �Է�: ";
		cin >> input; // ���� �Է��� ����
		cout << "�Է°�: " << input << endl;
	} while (input!= 0); // �Է°��� 0���� �˻�
	cout << input<< endl;

	cout << endl;

	int input1 = -1; // while ������ �����ϱ� ���� 0�� �ƴ� ������ �ʱ�ȭ
	// �Ǵ� �Է��� ���� ���� �� �� �޾ƾ� ��
	// ���� input_while�� 0���� �ʱ�ȭ�ߴٸ� �Ʒ� ������ ������� ����.
	// ���� while�� ����Ϸ��� ���� �̷��� ���� �Է¹޴� ��찡 ����
	// cin >> input_while;

	while (input1!= 0) { // ���� ������ �˻�
		cout << "���� �Է�: ";
		cin >> input1;
		cout << "�Է°�: " << input1 << endl;
	}
	cout <<input1 << endl;
	
	
	// �� ��° do while , while �� 


	int* ptr = nullptr; // �����Ͱ� �ƹ��͵� ����Ű�� ���� 
	int counter = 0;
	do {
		// �ϴ� ���� ������ ���ͼ� ����!
		cout << "do-while ���� �� ���� Ƚ��: " << ++counter<< endl;
		// ���⼭ ptr�� ����Ű�� ���� ����Ϸ��� �ϸ� ����
		// �� ���������� �׳� ������ �������� Ȯ��.

		// ���� ���Ḧ ���� ������ �ٲ��� ���� (������ ptr!= nullptr ������ ����)
	} while (ptr!= nullptr); // ������ ���߿� �˻� (nullptr != nullptr -> ����)

	cout << counter << "�� �����." << endl;

	cout << endl;


	int* ptr5 = nullptr; // �����Ͱ� �ƹ��͵� ����Ű�� ����
	int counter2 = 0;
	// ������ ���� �˻�(nullptr != nullptr -> ����)
	while (ptr5!= nullptr) {
		// ������ ó������ �����̹Ƿ� �� ���� ���� ������� ����.
		cout << "while ���� �� ���� Ƚ��: " << ++counter2<< endl;
	}
	cout << counter2 << "�� �����." << endl;


	// �ټ� ��° do while, while ��

	int arr[] = { 1,2,3,4,5 };
	int *num = arr;
	int count = 0;
	do
	{
		++count; 
		cout << "*num�� ����Ű�� �� : " << *num << endl;
		// num�� ����Ű�� ��(�ּҰ� X)
		num++;
		// �ּ� 1 ����
		// ����Ƚ�� üũ
	} while (*num == 0);
	cout << count <<"�� ����"<< endl;
	// ������ �� �� ������ �߱� ������ ���� Ƚ���� 1��

	cout << endl;

	int* num2 = arr;
	int count2 = 0;
	while (*num2 == 0)
	{
		++count2;
		cout << "*num�� ����Ű�� �� :" << *num2 << endl;
		num2++;
	}
	cout << count2 << "�� ����" << endl;
	// ������ ���ʿ� �����̱� ������ ���� Ƚ���� 0��

	return 0;
	
}

