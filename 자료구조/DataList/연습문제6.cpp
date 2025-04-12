#include<iostream>
#include<list>
using namespace std;
int main()
{
	// int(정수) 타입의 데이터를 저장하는 표준 list 객체 list1을 생성.
	// list는 내부적으로 '이중 연결 리스트'로 구현되어 있어, 데이터의 삽입/삭제가 특정 위치에서 효율적임.
	// 중괄호 {} 를 사용하여 초기값 {1, 2, 3, 4, 5} 로 리스트를 초기화한다.
	list<int> list1 = { 1,2,3,4,5 };
	// list1의 맨 뒤(back)에 값 6을 추가(push)한다.
	list1.push_back(6); // 1 2 3 4 5 6
	// list1의 특정 위치에 값을 삽입(insert)한다,
	// list1.begin()은 리스트의 가장 첫 번째 원소(1)를 가리키는 위치(이터레이터)이다.
	// next(list1.begin())은 list1.begin()의 바로 다음 위치, 즉 두 번째 원소(2)를 가리킨다.
	// insert 함수는 지정된 위치 바로 앞에 값을 삽입한다.
	// 따라서 두 번째 원소 2 앞에 0을 삽입한다.
	list1.insert(next(list1.begin()), 0); // 1 0 2 3 4 5 6 

	// list1의 맨 끝 바로 앞에 값 7을 삽입한다.
	// list1.end()는 마지막 원소 다음 위치를 가리키는 특별한 이터레이터이다.
	// end() 앞에 삽입하는 것은 결국 리스트의 맨 뒤에 추가하는 것과 같다.
	list1.insert(list1.end(), 7); // 1 0 2 3 4 5 6 7

	// list1의 맨 뒤(back) 원소를 제거(pop)합니다.가장 마지막의 7이 제거된다.
	list1.pop_back(); // 1 0 2 3 4 5 6

	cout << "삽입 & 삭제 후 리스트 : ";
	for (auto i : list1)
		cout << i << " ";
	return 0;
}