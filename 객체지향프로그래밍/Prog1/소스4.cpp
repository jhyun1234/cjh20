#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	// Labs
	// 1번
	int ages[5] = { 10, 40, 30 };

	cout << ages[0] << endl; // 출력 1
	cout << ages[1] << endl; // 출력 2
	cout << ages[3] << endl; // 출력 3
	cout << ages[5] << endl; // 출력 4

	// ages[0] 의 값은 10 
	// ages[1] 의 값은 40 
	// ages[3] 의 값은 0 
	// ages[5] 는 배열에서 정한 그 이상의 메모리 주소에
	// 접근하려고 하니 예상치못한값이 나온다.
	
	// 2번
	int ages1[] = { 10, 40, 30 };

	cout << ages1[0]<<" "<<sizeof(ages1[0]) << endl; // 출력 1
	cout << ages1[1] <<" "<< sizeof(ages1[1]) << endl; // 출력 2
	cout << ages1[3] <<" "<< sizeof(ages1[3]) << endl; // 출력 3

	// ages1[0] 의 값은 10  사이즈는 4바이트이다. int형의 배열을 잡았기 때문에 4바이트가 할당된다.
	// ages1[1] 의 값은 40  똑같은 이유
	// ages1[3] 의 값은 예상치못한 값이 나온다. 예상하지못한 값이 나오는건 ages1[3]은 메모리의 범위를 벗어나버렸기
	// 때문이고 사이즈가 나오는 것처럼 보이는 이유는 ages1[3]의 표현식의 타입이 int 이기 때문이다.

	// 3번
	char grades[] = { 'A', 'B', 'C', 'D', 'F' };      // 문자 배열 
	char name[] = { 'P', 'e', 't', 'e', 'r', '\0' }; // 문자열 배열

	cout << grades[0] << endl; // 출력 1
	cout << name[0] << endl;   // 출력 2

	// grades[0] 의 문자는 배열의 0번째에 위치한 A가 출력이 된다.
	// name[0] 의 문자는 배열의 0번째에 위치한 P가 출력이 된다.

	cout << name[5] << endl;   // 출력 3
	cout << grades[5] << endl; // 출력 4

	// name[5]는 널문자 \0 를 출력하고 있다. 
	// grades[5]는 위의 문제와 동일하게 메모리의 범위를 벗어나 접근을 시도하기 때문에
	// 정의되지 않은 행동을 해서 아무것도 나오지 않는것처럼 보이는것이다.

	cout << name << endl;      // 출력 5
	cout << grades << endl;    // 출력 6

	// name은 배열에 \0 널문자가 포함되어 있어 널문자를 만나서 제대로 종료가 됐지만
	// grades은 널문자 \0 가 없기 때문에 계속해서 읽을려는 시도를 하기 때문에 정의되지않은 행동을 한다.
	// 그렇기 때문에 이상한 문자들이 출력이 된다.


	cout << sizeof(grades) << endl; 
	cout << sizeof(name) << endl;

	// 사이즈가 다른 이유는 name에는 \0문자를 포함해서 사이즈가 6이된다.
	// grades의 사이즈는 5로 출력이된다.

	cout << endl;

	//4번
	char grades1[] = "ABCDF";     // 문자열 배열 
	char name1[] = "Peter";       // 문자열 배열

	cout << grades1[0] << endl; // 출력 A
	cout << name1[0] << endl;   // 출력 P

	cout << name1[5] << endl;   // 출력 X 
	cout << grades1[5] << endl; // 출력 X
	// 메모리에 정해진 범위를 벗어나서 나오지 않음

	cout << name1 << endl;      // 출력 Peter
	cout << grades1 << endl;    // 출력 ABCDF
	
	cout << endl;

	// 5번 6번
	float data[10], initlal_value = 10.1;

	for (int i = 0; i < 10; i++) {
		data[i] = initlal_value+(i*0.3); // 한줄로 작성
		
		cout << data[i] << endl; // 출력
	}
	cout << endl;
	// 7번 

	int num;
	char name2[] = "Chul-Soo Kim";
	int values[] = { 10, 40, 50, 60, 80, 100 };

	num = sizeof(name2) / sizeof(name2[0]); 
	cout << "num_of_name: " << num << endl; // 13출력
	num = sizeof(values) / sizeof(values[0]);
	cout << "num of values: " << num << endl; // 6출력
	// name2의 배열 사이즈는 13이다.
	// values의 배열 사이즈는 24이다.
	// name2는 char형 배열이기 때문에 하나의 인덱스가 1바이트의 크기를 가진다.
	// values2는 int형 배열이기 때문에 하나의 인덱스가 4바이트의 크기를 가진다.
	// 즉 13/1 = 13 , 24/4 = 6 이 된다는 뜻이다.


	cout << endl;
	// 8번
	long long data1[6];

	cout << "배열 저장 공간 크기: " << sizeof(data1) << endl;
	// 출력이 48이 나왔다.
	// long long 자료형 6개 8*6=48
	// 즉, long long의 자료형의 사이즈는 8바이트이다.

	cout << endl;

	// 9번

	int data3[10];

	for (int i = 0; i < 10; i++) {
		data3[i] = (i + 1);
		cout << data3[i] << endl;
	}
	// 이 반복문은 0번째 인덱스부터 9번째 인덱스까지
	// 순차적으로 i의 값을 1씩 증가시켜 각 인덱스에 대입하고있다.
	cout << endl;
	for (int i = 1; i < 10; i++) {
		data3[0] += data3[i];
		cout << data3[i] << endl;
	}
	// 이 반복문은 0번째 인덱스에 1부터10까지 계속해서 더하는 반복문이다.

	cout << data3[0] << endl; // 출력 55

	cout << endl;

	// 10번
	int data4[] = { 1, 2, 3, 4, 5 };

	for (auto& e : data) {
		e *= 15;
	}

	for (const auto& e : data) {
		cout << e << "  ";
	}
	cout << endl;

	int a = 20203324;  
	cout << a % 3; // 시험자리 1 

	return 0;
}