#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	// 0��
	int a = 10;
	{
		int a = 20;
		cout << "a(1): " << a << endl;
	}
	{
		int a = 30;
		cout << "a(2): " << a << endl;
	}
	{
		int a = 40;
		{
			cout << "a(3): " << a << endl;
		}
		cout << "a(4): " << a << endl;
	}
	cout << "a(5): " << a << endl;
	
	// ������ ������ {} �ȿ����� ��ȿ�ϴ� 
	// a(3) �� a(4)�� ���� ���� ������ ���� {} ū �����ȿ� �ֱ� �����̴�.


	// 1�� 2��
	int input;
	cout << "������ �Է��Ͻÿ�: ";
	cin >> input;

	if (input <= 100) 
	{
		cout << "100 ���� �����̴�" << endl;
	}
	else
	{

		cout << "100 �ʰ� �����̴�" << endl;
	}

	// ������ �ڵ� ���ٸ� ����� ���ÿ� ���´�.
	// ������ else�� ����Ѵٸ� �� if�� ���ǿ� �´� �亯�� ����� �� �� �ִ�.
	
	// 3��
	int value;

	cout << "������ �Է��Ͻÿ�: ";
	cin >> value;
	if (value > 10)
	{
		cout << "�Է��� ���� " << value << endl;
		cout << "10���� ū �����̴�" << endl;
	}
	else
	{
		cout << "10���� ���� �����̴�" << endl;
	}

	// ó�� �ڵ尡 ������ �ߴ� ������ �����Ϸ��� ��Ȯ�� ������ ���� �׷����̴�.

	// 4���� 5��
	int value1;

	cout << "������ �Է��Ͻÿ�: ";
	cout << "0�� ������ �ٸ� ���� �Է��Ͻÿ�" << endl;
	cin >> value1;
	if (value1 % 2==0 && value1!=0)
	{
		cout << " ¦�� " << endl;
	}
	else if (value1 == 0)
	{
		cout << " 0�� ������ �ٸ����� �Է��Ͻÿ�. " << endl;
	}
	else
	{
		cout << " Ȧ�� " << endl;
	}
	// ó�� if(value1 % 2) ��� ���ǵ� ������ ������ ¦���� �Է��ص� Ȧ���� ��µȴ�.

	if (value1 % 3 == 0 && value1 != 0)
	{
		cout << " 3�� ��� " << endl;
	}
	else if(value1 == 0)
	{
		cout << " 0�� ������ �ٸ����� �Է��Ͻÿ�. " << endl;
	}
	else
	{
		cout << "3�� ����� �ƴ�" << endl;
	}
	// 3�� ����� �´��� �ƴ��� Ȯ���ϴ� �ڵ带 �ۼ��ߴ�.
	// ������ �ڵ忡���� �������� 0�� ������ �� �̴�.
	// �߰������� 0�� ������ ���� ó���� ���־���Ѵ�.
	// �׷��� ������ ȥ���� �߱��� �� �ִ�.

	// 6,7��
	char ch;
	cout << "A, B, C ���� �� �ϳ��� �Է��Ͻÿ�:";
	cin >> ch;

	switch (ch) {
	case 'A':
	case 'a':
		cout << "A�� �Է�" << endl;
		break;
	case 'B':
	case 'b':
		cout << "B�� �Է�" << endl;
		break;
	case 'C':
	case 'c':
		cout << "C�� �Է�" << endl;
		break;
	default:
		cout << "���ϴ� ���ڰ� �ƴϴ�" << endl;
		break;

	}
	// ó���� ��� ����� �� �ִ� ������ break�� ��� ����
	// �߰������� a,b,c�� ����ϰ� ������ case���� 2�� ���� ����ؾ� �Ѵ�.

	// 8��
	int value2;
	cout << "1 ~ 3 ���� ������ �Է��Ͻÿ�: ";
	cin >> value2;

	switch (value2) {
	case 1:
		cout << "1�� �Է�" << endl;
		break;
	case 2:
		cout << "2�� �Է�" << endl;
		break;
	case 3:
		cout << "3�� �Է�" << endl;
		break;
	default:
		cout << "���ϴ� ���� �ƴϴ�" << endl;
	}
	// ���ϴ� ���� �ƴϴ� ��� ����� ������ ������
	// �ڷ����� ���������� �Ҵ��ϰ� �Է��� �޴µ�
	// case �������� ���ڸ� �ްԲ� �Ǿ� �־��� �����̴�.

	// 9��
	int input1;
	int count = 0;
	do {
		++count;
		cout << "������ �Է��Ͻÿ�: ";
		cin >> input1;
		cout << "�Է°�: " << input1 << endl;
	} while (input1 != 0);
	cout << count << endl;
	// �ݺ��Ǵ� ������ ������ �Է��Ͻÿ� �� �Է°� �ΰ��� �̴�.
	// ���⼭ �ݺ��Ǵ� Ƚ���� �߷��ϴ� �ڵ带 �ۼ��غ��ڴ�.
	// �� ������ �� ������ do while�� ������ �� �� ������ �Ǳ� ������
	// �� ������ ����ߴ�.
	
	// 10�� 
	int count1 =0, num;
	cout << "�ݺ� Ƚ���� �Է��Ͻÿ�: ";
	cin >> num;

	while (count1 < num-2) {
		cout << "repeat (" << count1 << ")" << endl;
		count1++;
	}
	// �Է¹��� ������ 2�� ���� �ȴ�.

	// 11��
	for (int i = 0; i < 10; i++) {
		if (i == 3 || i == 6) continue;
		cout << i << ", ";
	}
	cout << endl;
	// ����� ���� 0,1,2,4,5,7,8,9 �� ���ð��̴�.
	// if�� ���ǿ� �´ٸ� continue�� ������
	// i�� 1 ���� ��Ű�� �ٽ� �ݺ��� �����ϰ� �ȴ�.
	// �����Ѱ��� �����ϰ� ����

	// 12��
	for (int i = 0; i < 10; i++) {
		if (i == 3 || i == 6) break;
		cout << i << ", ";
	}
	cout << endl;
	// i�� 3�� �� if���� �����ؼ� break�� ����
	// ���α׷��� ���ᰡ �ɰ��̴�.
	// ���� ����� 0 , 1 , 2�� ���� ���̴�.
	// ����� ������ ����

	// 13��
	for (int i = 0; i < 10; i++) {
		
		cout << i%4 << ", ";
	}
	cout << endl;

	// ���� ����� 0,1,2,3,0,1,2,3,0,1 �� ������ �Ϸ���
	// i�� 4�� ���� �������� ����ϸ� �ȴ�.

	// 14��
	int sum;
	sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;  // 1 ~ 10 ������ ���� ���ϱ� 

	cout << "(1): 1+2+3+4+5+6+7+8+9+10 = " << sum << endl;

	sum = 0;
	for (int i = 1; i <= 10; i++) {
		
		sum += i;
	}
	cout << "(2): 1+2+3+4+5+6+7+8+9+10 = " << sum << endl;

	// sum������ i�� �����ϴ� ���� ����ؼ� �����ָ� �ȴ�.

	int sum1 = 1;
	for (int i = 1; i <= 16; i++) {

		sum1 *= i;
	}
	cout << sum1 << endl;

	double sum2 = 1;
	for (int i = 1; i <= 17; i++) {

		sum2 *= i;
	}
	cout << sum2 << endl;

	// sum2������ int�ڷ����� ����ҽ� ���尡���Ѱ��� �Ѿ���� -�� ���´�.

	// 18��
	int data, res;
	int sum3 = 0;
	cin >> data;

	do {
		res = data % 10;
		cout << "data: " << data << ", res: " << res << endl;
		data /= 10;
		// data�� 10���� ���� ���� �ٽ� data�� ����
		sum3 += res;
		if (data < 10) sum3 += data;
	} while (data >= 10);
	cout << "data: " << data << " sum: " << sum3 << endl;
	// data�� ���� 10 �̻��̸� ��, data�� ���� �� �ڸ��� �̻��̸�
	// ������ ��� �ݺ�. data�� �� �ڸ���(0~9)�� �Ǹ� ������ ����.
	// data�� 10���� ���� ������, 
	// �� data�� ���� ������ �ڸ���(���� �ڸ� ����)�� ���ؼ� res�� ����
	// ���� data ���� ��� ������ ������ �ڸ���(res)�� ȭ�鿡 ���


	return 0;
}