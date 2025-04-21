#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	// Labs
	// 1��
	int ages[5] = { 10, 40, 30 };

	cout << ages[0] << endl; // ��� 1
	cout << ages[1] << endl; // ��� 2
	cout << ages[3] << endl; // ��� 3
	cout << ages[5] << endl; // ��� 4

	// ages[0] �� ���� 10 
	// ages[1] �� ���� 40 
	// ages[3] �� ���� 0 
	// ages[5] �� �迭���� ���� �� �̻��� �޸� �ּҿ�
	// �����Ϸ��� �ϴ� ����ġ���Ѱ��� ���´�.
	
	// 2��
	int ages1[] = { 10, 40, 30 };

	cout << ages1[0]<<" "<<sizeof(ages1[0]) << endl; // ��� 1
	cout << ages1[1] <<" "<< sizeof(ages1[1]) << endl; // ��� 2
	cout << ages1[3] <<" "<< sizeof(ages1[3]) << endl; // ��� 3

	// ages1[0] �� ���� 10  ������� 4����Ʈ�̴�. int���� �迭�� ��ұ� ������ 4����Ʈ�� �Ҵ�ȴ�.
	// ages1[1] �� ���� 40  �Ȱ��� ����
	// ages1[3] �� ���� ����ġ���� ���� ���´�. ������������ ���� �����°� ages1[3]�� �޸��� ������ ������ȱ�
	// �����̰� ����� ������ ��ó�� ���̴� ������ ages1[3]�� ǥ������ Ÿ���� int �̱� �����̴�.

	// 3��
	char grades[] = { 'A', 'B', 'C', 'D', 'F' };      // ���� �迭 
	char name[] = { 'P', 'e', 't', 'e', 'r', '\0' }; // ���ڿ� �迭

	cout << grades[0] << endl; // ��� 1
	cout << name[0] << endl;   // ��� 2

	// grades[0] �� ���ڴ� �迭�� 0��°�� ��ġ�� A�� ����� �ȴ�.
	// name[0] �� ���ڴ� �迭�� 0��°�� ��ġ�� P�� ����� �ȴ�.

	cout << name[5] << endl;   // ��� 3
	cout << grades[5] << endl; // ��� 4

	// name[5]�� �ι��� \0 �� ����ϰ� �ִ�. 
	// grades[5]�� ���� ������ �����ϰ� �޸��� ������ ��� ������ �õ��ϱ� ������
	// ���ǵ��� ���� �ൿ�� �ؼ� �ƹ��͵� ������ �ʴ°�ó�� ���̴°��̴�.

	cout << name << endl;      // ��� 5
	cout << grades << endl;    // ��� 6

	// name�� �迭�� \0 �ι��ڰ� ���ԵǾ� �־� �ι��ڸ� ������ ����� ���ᰡ ������
	// grades�� �ι��� \0 �� ���� ������ ����ؼ� �������� �õ��� �ϱ� ������ ���ǵ������� �ൿ�� �Ѵ�.
	// �׷��� ������ �̻��� ���ڵ��� ����� �ȴ�.


	cout << sizeof(grades) << endl; 
	cout << sizeof(name) << endl;

	// ����� �ٸ� ������ name���� \0���ڸ� �����ؼ� ����� 6�̵ȴ�.
	// grades�� ������� 5�� ����̵ȴ�.

	cout << endl;

	//4��
	char grades1[] = "ABCDF";     // ���ڿ� �迭 
	char name1[] = "Peter";       // ���ڿ� �迭

	cout << grades1[0] << endl; // ��� A
	cout << name1[0] << endl;   // ��� P

	cout << name1[5] << endl;   // ��� X 
	cout << grades1[5] << endl; // ��� X
	// �޸𸮿� ������ ������ ����� ������ ����

	cout << name1 << endl;      // ��� Peter
	cout << grades1 << endl;    // ��� ABCDF
	
	cout << endl;

	// 5�� 6��
	float data[10], initlal_value = 10.1;

	for (int i = 0; i < 10; i++) {
		data[i] = initlal_value+(i*0.3); // ���ٷ� �ۼ�
		
		cout << data[i] << endl; // ���
	}
	cout << endl;
	// 7�� 

	int num;
	char name2[] = "Chul-Soo Kim";
	int values[] = { 10, 40, 50, 60, 80, 100 };

	num = sizeof(name2) / sizeof(name2[0]); 
	cout << "num_of_name: " << num << endl; // 13���
	num = sizeof(values) / sizeof(values[0]);
	cout << "num of values: " << num << endl; // 6���
	// name2�� �迭 ������� 13�̴�.
	// values�� �迭 ������� 24�̴�.
	// name2�� char�� �迭�̱� ������ �ϳ��� �ε����� 1����Ʈ�� ũ�⸦ ������.
	// values2�� int�� �迭�̱� ������ �ϳ��� �ε����� 4����Ʈ�� ũ�⸦ ������.
	// �� 13/1 = 13 , 24/4 = 6 �� �ȴٴ� ���̴�.


	cout << endl;
	// 8��
	long long data1[6];

	cout << "�迭 ���� ���� ũ��: " << sizeof(data1) << endl;
	// ����� 48�� ���Դ�.
	// long long �ڷ��� 6�� 8*6=48
	// ��, long long�� �ڷ����� ������� 8����Ʈ�̴�.

	cout << endl;

	// 9��

	int data3[10];

	for (int i = 0; i < 10; i++) {
		data3[i] = (i + 1);
		cout << data3[i] << endl;
	}
	// �� �ݺ����� 0��° �ε������� 9��° �ε�������
	// ���������� i�� ���� 1�� �������� �� �ε����� �����ϰ��ִ�.
	cout << endl;
	for (int i = 1; i < 10; i++) {
		data3[0] += data3[i];
		cout << data3[i] << endl;
	}
	// �� �ݺ����� 0��° �ε����� 1����10���� ����ؼ� ���ϴ� �ݺ����̴�.

	cout << data3[0] << endl; // ��� 55

	cout << endl;

	// 10��
	int data4[] = { 1, 2, 3, 4, 5 };

	for (auto& e : data) {
		e *= 15;
	}

	for (const auto& e : data) {
		cout << e << "  ";
	}
	cout << endl;

	int a = 20203324;  
	cout << a % 3; // �����ڸ� 1 

	return 0;
}