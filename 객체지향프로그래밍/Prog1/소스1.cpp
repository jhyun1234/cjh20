#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
	// 0번
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
	
	// 변수의 범위는 {} 안에서만 유효하다 
	// a(3) 과 a(4)의 값이 같은 이유는 같은 {} 큰 범위안에 있기 때문이다.


	// 1번 2번
	int input;
	cout << "정수를 입력하시오: ";
	cin >> input;

	if (input <= 100) 
	{
		cout << "100 이하 정수이다" << endl;
	}
	else
	{

		cout << "100 초과 정수이다" << endl;
	}

	// 원래의 코드 였다면 출력이 동시에 나온다.
	// 하지만 else를 사용한다면 그 if문 조건에 맞는 답변만 출력을 할 수 있다.
	
	// 3번
	int value;

	cout << "정수를 입력하시오: ";
	cin >> value;
	if (value > 10)
	{
		cout << "입력한 값은 " << value << endl;
		cout << "10보다 큰 정수이다" << endl;
	}
	else
	{
		cout << "10보다 작은 정수이다" << endl;
	}

	// 처음 코드가 오류가 뜨는 이유는 컴파일러가 정확한 범위를 몰라서 그런것이다.

	// 4번과 5번
	int value1;

	cout << "정수를 입력하시오: ";
	cout << "0을 제외한 다른 수를 입력하시오" << endl;
	cin >> value1;
	if (value1 % 2==0 && value1!=0)
	{
		cout << " 짝수 " << endl;
	}
	else if (value1 == 0)
	{
		cout << " 0을 제외한 다른값을 입력하시오. " << endl;
	}
	else
	{
		cout << " 홀수 " << endl;
	}
	// 처음 if(value1 % 2) 어떠한 조건도 없었기 때문에 짝수를 입력해도 홀수가 출력된다.

	if (value1 % 3 == 0 && value1 != 0)
	{
		cout << " 3의 배수 " << endl;
	}
	else if(value1 == 0)
	{
		cout << " 0을 제외한 다른값을 입력하시오. " << endl;
	}
	else
	{
		cout << "3의 배수가 아님" << endl;
	}
	// 3의 배수가 맞는지 아닌지 확인하는 코드를 작성했다.
	// 원래의 코드에서의 문제점은 0이 들어왔을 때 이다.
	// 추가적으로 0이 들어오면 따로 처리를 해주어야한다.
	// 그렇지 않으면 혼란을 야기할 수 있다.

	// 6,7번
	char ch;
	cout << "A, B, C 문자 중 하나를 입력하시오:";
	cin >> ch;

	switch (ch) {
	case 'A':
	case 'a':
		cout << "A가 입력" << endl;
		break;
	case 'B':
	case 'b':
		cout << "B가 입력" << endl;
		break;
	case 'C':
	case 'c':
		cout << "C가 입력" << endl;
		break;
	default:
		cout << "원하는 문자가 아니다" << endl;
		break;

	}
	// 처음에 모든 출력이 다 있는 이유는 break가 없어서 였고
	// 추가적으로 a,b,c를 출력하고 싶으면 case문을 2개 같이 사용해야 한다.

	// 8번
	int value2;
	cout << "1 ~ 3 중의 정수를 입력하시오: ";
	cin >> value2;

	switch (value2) {
	case 1:
		cout << "1이 입력" << endl;
		break;
	case 2:
		cout << "2가 입력" << endl;
		break;
	case 3:
		cout << "3이 입력" << endl;
		break;
	default:
		cout << "원하는 수가 아니다" << endl;
	}
	// 원하는 수가 아니다 라는 출력이 나오는 이유는
	// 자료형을 정수형으로 할당하고 입력을 받는데
	// case 문에서는 문자를 받게끔 되어 있었기 때문이다.

	// 9번
	int input1;
	int count = 0;
	do {
		++count;
		cout << "정수를 입력하시오: ";
		cin >> input1;
		cout << "입력값: " << input1 << endl;
	} while (input1 != 0);
	cout << count << endl;
	// 반복되는 문장은 정수를 입력하시오 와 입력값 두가지 이다.
	// 여기서 반복되는 횟수를 추론하는 코드를 작성해보겠다.
	// 선 증가를 한 이유는 do while은 무조건 한 번 실행이 되기 때문에
	// 선 증가를 사용했다.
	
	// 10번 
	int count1 =0, num;
	cout << "반복 횟수를 입력하시오: ";
	cin >> num;

	while (count1 < num-2) {
		cout << "repeat (" << count1 << ")" << endl;
		count1++;
	}
	// 입력받은 값에서 2를 빼면 된다.

	// 11번
	for (int i = 0; i < 10; i++) {
		if (i == 3 || i == 6) continue;
		cout << i << ", ";
	}
	cout << endl;
	// 결과의 값은 0,1,2,4,5,7,8,9 가 나올것이다.
	// if문 조건에 맞다면 continue를 만나서
	// i를 1 증가 시키고 다시 반복을 실행하게 된다.
	// 예상한값과 동일하게 나옴

	// 12번
	for (int i = 0; i < 10; i++) {
		if (i == 3 || i == 6) break;
		cout << i << ", ";
	}
	cout << endl;
	// i가 3일 때 if문을 만족해서 break를 통해
	// 프로그램이 종료가 될것이다.
	// 예상 결과는 0 , 1 , 2가 나올 것이다.
	// 결과는 예상대로 나옴

	// 13번
	for (int i = 0; i < 10; i++) {
		
		cout << i%4 << ", ";
	}
	cout << endl;

	// 예상 결과가 0,1,2,3,0,1,2,3,0,1 이 나오게 하려면
	// i를 4로 나눈 나머지로 계산하면 된다.

	// 14번
	int sum;
	sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;  // 1 ~ 10 까지의 정수 더하기 

	cout << "(1): 1+2+3+4+5+6+7+8+9+10 = " << sum << endl;

	sum = 0;
	for (int i = 1; i <= 10; i++) {
		
		sum += i;
	}
	cout << "(2): 1+2+3+4+5+6+7+8+9+10 = " << sum << endl;

	// sum변수에 i가 증가하는 값을 계속해서 더해주면 된다.

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

	// sum2에서는 int자료형을 사용할시 저장가능한값을 넘어버려 -가 나온다.

	// 18번
	int data, res;
	int sum3 = 0;
	cin >> data;

	do {
		res = data % 10;
		cout << "data: " << data << ", res: " << res << endl;
		data /= 10;
		// data를 10으로 나눈 몫을 다시 data에 저장
		sum3 += res;
		if (data < 10) sum3 += data;
	} while (data >= 10);
	cout << "data: " << data << " sum: " << sum3 << endl;
	// data의 값이 10 이상이면 즉, data가 아직 두 자릿수 이상이면
	// 루프를 계속 반복. data가 한 자릿수(0~9)가 되면 루프를 종료.
	// data를 10으로 나눈 나머지, 
	// 즉 data의 가장 마지막 자릿수(일의 자리 숫자)를 구해서 res에 저장
	// 현재 data 값과 방금 추출한 마지막 자릿수(res)를 화면에 출력


	return 0;
}