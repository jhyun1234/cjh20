
#include <iostream>
using namespace std;

int add(int a, int b); // �Լ� ���� 

int main() {
    cout << add(3, 4); // �Լ� ȣ��
    return 0;
}

// �Լ� ����
int add(int a, int b) {
    return a + b;
}