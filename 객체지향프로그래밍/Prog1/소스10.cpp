#include <iostream>
using namespace std;
/**
 * add_10: �Է��ϴ� ���� ���� 10�� ���ؼ� ��ȯ�ϴ� �Լ�
 * @param {int} in [���� �Ű�����]
 * @return {int}
 */
int add_10(int in)  // 1�� Labs main�Լ� ���� ���� ���� ���ǿ� ������ ���ÿ� ����
{               // �Լ� ����
	return in += 10;
}
int min_value(int x, int y);  // (4) min_value �Լ� ����
// sum: �Է� �Ű������� ���޹��� �� ������ ���ϰ� ����� ��ȯ�ϴ� �Լ�
int sum(int a, int b);   // �Լ� ���� (function declaration)
float mul(float a, float b);
void increase(int &x);
void swap1(int x, int y); // call of val  
void swap2(int& x, int& y); // call of ref
double div_eq(double x = 10, double y = 10) { return x / y; }
// ����Ʈ �Ű������� �Լ� �Ű������� �⺻���� ���� �־�δ°��̴�.
// �� �Լ��� �׳� ȣ��� ����Ʈ �Ű������� �ִ� ������ ������ �־��� ����� ����ȴ�.
// �Լ� ȣ��� ���� ���� �� ���� ������ �� ������ ����� ����ȴ�.
int main(int argc, char const* argv[]) // (2) main �Լ� ����
{

	int data;

	cout << "������ �Է��Ͻÿ�: ";
	cin >> data;

	cout << add_10(data) << endl;  // �Լ� ȣ�� 


	cout << min_value(3, 5) << endl;   // (1) �Լ� ȣ�� 
	// 2�� Labs 
	// 2 - 3 - 4 -1 

	// 3�� Labs
	int x = 10, y = 30;

	int result = sum(x, y);  // �Լ� ȣ�� (function call)

	cout << x << " + " << y << " = " << result << endl;

	

	
	// 6�� Labs
	float x1, y1;

	cout << "�Ǽ� �ΰ��� �Է��Ͻÿ�: " << endl;
	cin >> x1 >> y1;

	cout << mul(x1, y1) << endl;
	cout << endl;
	// 7�� Labs
	int x2 = 10;

	increase(x2);

	cout << "���: " << x2 << endl;
	cout << endl;
	// 8�� Labs
	int x3 = 10, y3 = 20;

	cout << "(��� 1) x: " << x3 << ", y: " << y3 << endl;
	swap1(x3, y3);
	cout << "(��� 2) x: " << x3 << ", y: " << y3 << endl;
	swap2(x3, y3);
	cout << "(��� 3) x: " << x3 << ", y: " << y3 << endl;
	// swap1�� �Լ� �ȿ����� ���� �ٲ�� call of value�̰�
	// swap2�� �Լ� �ۿ����� �� ���� ������ �ִ� call of ref�̴�.
	cout << endl;
	// 9�� Labs
	cout << "���(1): " << div_eq() << endl; // 
	cout << "���(2): " << div_eq(5) << endl;
	cout << "���(3): " << div_eq(50, 10) << endl;
	

	return 0;
}
int min_value(int x, int y) { return x > y ? y : x; } // (3) min_value �Լ� ����

int sum(int x, int y) { return x + y; }

float mul(float a, float b) {return a * b;}

void increase(int &x) {	x++;} // main�Լ��� �ִ� ������ �ּҸ� �����ؾ��� 
//�Լ��� �� �ּҸ� �о ���� �ٲٸ� main�Լ����� ���� �ٲ�� ����

void swap1(int x, int y) {
	cout << "(swap1 ���� �� ���) x:" << x << ", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap1 ���� �� ���) x:" << x << ", y: " << y << endl;
}

void swap2(int& x, int& y) {
	cout << "(swap2 ���� �� ���) x:" << x << ", y: " << y << endl;
	int tmp = x;
	x = y;
	y = tmp;
	cout << "(swap2 ���� �� ���) x:" << x << ", y: " << y << endl;
}
