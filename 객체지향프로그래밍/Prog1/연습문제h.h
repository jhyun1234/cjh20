#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace my {   // namespace ����
	// namespace �̸������� ����,�Լ�,Ŭ���� ��� ���� �ĺ����� ������
	// �����ϴ� ������ �����̴�.
	// ��, �ڵ��� Ư�� �κ��� �������� �׷�ȭ�ϰ�, ���� �̸��� ����
	// �ĺ��ڵ��� ���� �浹���� �ʵ��� �����ϴ� ������ �Ѵ�.
	int value = 10;
}

namespace your {
	int value = 20;
}

void Hello(); // �Լ� ����
void Hello1(int a);
// void fun()  ��ȯ �ڷ��� ,�Լ���(�Լ��� �޴� �Է� �����͵�)
//{
	// �Լ��� ����� ���� �Ѵ�.
//}

int main(int argc, char const* argv[])
{
	// �ǽ�

	Hello1(10); // �Լ� ȣ��
	Hello();
	Hello1(20);
	Hello();
	Hello1(30);
	Hello();


	// 1�� ����
	// ���� �ٿ� ȭ�鿡 Hello World!! �� ����ϴ� �ڵ� �ۼ�

	cout << "Hello World" << endl;
	cout << endl;

	// 2�� ����
	int first = 0, second = 0;
	// ���� �ٿ� �տ��� ����� ���� first, second�� ���� 10, 20�� �����ϴ� �ڵ� �ۼ�

	//cin >> first>>second;
	//cout << first << ", " << second << endl;
	cout << endl;

	// 3�� ����
	// char buf[255] = "Hello World!";
	char buf[255] = {};

	// ���� �ٿ� Ű����� ���� Hello World! �� �Է¹޾� buf �� �����ϴ� �ڵ� �ۼ�
	// cin >> buf; �̷��Ը� ����Ѵٸ� ����,�ٹٲ��� �ϸ� �� ������ ���ڿ��� �����Ѵ�.
	// �׷��� ������ getline()�Լ��� ����ؾ� �Ѵ�.
	cin.getline(buf, 255);

	cout << buf << endl;
	cout << endl;

	// 4�� ����
	// ���� �ٿ� 10�� ����� ���� value ���� ȭ�鿡 ����ϴ� �ڵ� �ۼ� 
	cout << my::value << endl;
	// namespace ���
	cout << your::value << endl;

	cout << endl;
	// ���� �ٿ� 20�� ����� ���� value ���� ȭ�鿡 ����ϴ� �ڵ� �ۼ�

	// 5�� ����
	cout << "Hello" << endl;
	cout << "World" << endl;
	cout << endl;

	// 6�� ����

	int a = 20;

	cout << a << endl;
	cout << endl;

	// 7�� ����
	int value = 65;  // 'A' �� ASCII ���� 65 �� 
	cout << value << endl;
	cout << endl;
	// value�� ����� ���� ���� ch�� �����ϰ� value�� ���� ch�� �����ϴ� �ڵ带 �ۼ�
	char ch = value;
	cout << ch << endl;
	cout << endl;

	// 8�� ����
	cout << "true" << endl;
	cout << true << endl;
	cout << "false" << endl;
	cout << false << endl;

	// "true"�� ���ڿ�
	// true�� bool������ 1
	// "false"�� ���ڿ�
	// faslse�� bool������ 0

	return 0;
}

void Hello() // �Լ� ����
{
	// void �ڷ����� ����ϴ� ������?
	// �ش� �Լ��� ��� ���� ��ȯ���� �ʴ´ٴ� ���� �����Ϸ��� ����ڿ��� ��Ȯ�ϰ� �˸���.
	// void �Լ��� return ���� ����ϰų� ������ �� ������, return���� ���� �����ϸ�
	// ������ ������ �߻��Ѵ�.
	cout << "Hello World" << endl;
	cout << endl;
}
void Hello1(int a) // �ڷ����� �ְ� �Ű������� �־�� �ϴ� ������?
{
	// �Լ��� �Ű������� �ڷ����� ����ϴ� ���� �����Ϸ��� �ڷ��� �˻�,�Լ� ȣ�� ��
	// �ڷ��� ��ġ, �Լ� ���� �ڵ��� �ڷ��� ��ġ�� ���� �ʼ����̴�.

	// �Ű������� ����ϴ� ���� �Լ� ���ο��� �ܺηκ��� ���޹��� ���� ����ϰ�,
	// �Լ� ȣ�� �� �μ��� �����ϱ� ���� �ʼ����̴�.
	cout << "Hello World" << endl;
	cout << a << endl;
}