
#include <iostream>
using namespace std;

int add(int a, int b); // 함수 선언 

int main() {
    cout << add(3, 4); // 함수 호출
    return 0;
}

// 함수 정의
int add(int a, int b) {
    return a + b;
}