#pragma once
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int* ptr = &a;
	int* ptr2;
	int& ref = *ptr;   // ���� ������ ���� a�� ���� �ٲ� �� �ִ�.
	cout << ptr << endl;
	*ptr = 30; // �̶��� * �� �������̴�. 
	cout << *ptr << endl; // 30 
	cout << a << endl; // 30
	ref = 40;
	cout << ref << endl; // 40
	cout << a << endl; // 40
	cout << endl;

	// ���� ������
	int** ptr1 = &ptr;
	cout << ptr1 << endl; // ptr1�� �ּ�
	cout << *ptr1 << endl; // *ptr1�� ����Ű�� ��(ptr�� �ּ�)
	cout << **ptr1 << endl; // **ptr1�� ����Ű�� ��(a�� ��)

	// �迭 ����
	cout << endl;
	int arr[3] = { 1,2,3 };

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	arr[0] = 10;
	cout << arr[0] << endl;
	cout << sizeof(arr) << endl; // 4����Ʈ �ڷ����� int���� 3���� ������ �ֱ� ������ 12�� ���´�.
	for (int i = 0; i < 3; i++) // for���� ���� ��ȸ�ϸ� arr�迭�� �ּҰ��� ����ϰ� �Ѵ�.
	{
		cout << &arr[i] << endl; // ��������� 4����Ʈ��ŭ ����� ����� �ɰ��̴�.
	}


	int a1;
	double d1;
	char c1;

	// sizeof()
	// Ư�� ������ Ÿ���� �󸶳� ���� �޸𸮸� ����ϴ��� �� �� �ִ�.
	// �迭 ��ü�� ũ�⸦ ����Ʈ ������ ���� �� �ִ�.
	// �̸� ���� �迭�� ��� ������ ����� �� �ִ�.
	// ����ü�� Ŭ������ �޸𸮿��� �����ϴ� �� ũ�⸦ �� �� �ִ�.
	cout << "int �ڷ����� ũ��: " << sizeof(int) << " ����Ʈ" << std::endl;
	cout << "double �ڷ����� ũ��: " << sizeof(double) << " ����Ʈ" << std::endl;
	cout << "char �ڷ����� ũ��: " << sizeof(char) << " ����Ʈ" << std::endl;
	cout << "int ���� a1�� ũ��: " << sizeof(a1) << " ����Ʈ" << std::endl;
	cout << "double ���� d1�� ũ��: " << sizeof(d1) << " ����Ʈ" << std::endl;
	cout << "char ���� c1�� ũ��: " << sizeof(c1) << " ����Ʈ" << std::endl;
	cout << "�迭 arr ũ��: " << sizeof(arr) << " ����Ʈ" << std::endl;

	unsigned char c2;
	cout << "unsigned char c2�� ũ��" << sizeof(c2) << endl;
	// char �ڷ����� �Ϲ������� 1����Ʈ(8��Ʈ)�� ũ�⸦ ������ �ִ�.
	// unsigned Ű���尡 �پ��ֱ� ������ ��ȣ�� ���� (non-negative) �������̴�.���� ���� ǥ���� �� ����.
	// 8��Ʈ�� ǥ���� �� �ִ� ��� ��Ʈ�� ���� ũ�⸦ ��Ÿ���� �� ����ϹǷ�, 0���� 255������ ���� ���� ǥ���Ѵ�.
	// 
	// ����ϴ� ���� 
	// �Ϲ������� -128���� 127������ ���� ǥ���ϰų�
	// 0���� 255������ ���� ǥ���� �� �ִ�. 
	// � ������ ���������� �����Ϸ� �� �÷����� ���� �ٸ���.
	// �׷��� ������ Ȯ���ϰ� ���� ������ ǥ���ϱ� ���ؼ� unsigned �� ����Ѵ�.
	// ����) �̹��� ó�� �������� �ȼ� ���� 0~255 ������ ���� �����Ƿ� unsigned�� ����ؾ� �Ѵ�.

	return 0;
}
