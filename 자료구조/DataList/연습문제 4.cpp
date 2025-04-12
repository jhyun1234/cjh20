#include <iostream> // 표준 입출력 스트림을 사용하기 위한 헤더 파일 포함
#include <forward_list> // 단방향 연결 리스트인 forward_list 컨테이너를 사용하기 위한 헤더 파일 포함
#include <vector> // 동적 배열인 vector 컨테이너를 사용하기 위한 헤더 파일 포함

using namespace std;
int main()
{
	// 문자열을 요소로 가지는 vector 컨테이너 vec 생성 및 초기화
	vector<string> vec =
	{
		"Lewis Hamilton","Lewis Hamilton","Nico Roseberg",
		"Sebastian Vettel","Lewis Hamilton","Sebastian Vettel",
		"Sebastian Vettel","Sebastian Vettel","Fernando Alonso"
	};
	
	// vector의 시작 반복자(iterator)를 it 변수에 할당 (상수 시간 복잡도)
	// 반복자는 컨테이너의 요소를 가리키는 포인터와 유사한 객체
	auto it = vec.begin(); // 상수 시간
	// 가장 최근 우승자 출력 (vector의 첫 번째 요소)
	cout << "가장 최근 우승자 : " << *it << endl;

	it += 8; // 상수 시간
	// 반복자를 8칸 뒤로 이동 (상수 시간 복잡도)
	// vector는 임의 접근 반복자를 제공하므로, 상수 시간 내에 임의의 위치로 이동 가능
	// 8년 전 우승자 출력 (vector의 8번째 요소)
	cout << "8년 전 우승자 : " << *it << endl;

	advance(it, -3); // 상수 시간
	// 반복자를 3칸 앞으로 이동 (상수 시간 복잡도)
	// vector는 양방향 이동을 지원하므로, 음수 값을 사용하여 앞으로 이동 가능
	// 3년 뒤 우승자 출력 (vector의 5번째 요소)
	cout << "그후 3년 뒤 우승자 : " << *it << endl;


	// vector의 모든 요소를 복사하여 forward_list 컨테이너 fwd 생성 및 초기화
   // forward_list는 단방향 연결 리스트이므로, 순차적인 접근만 가능
	forward_list<string> fwd(vec.begin(), vec.end());

	// forward_list의 시작 반복자를 it1 변수에 할당
	auto it1 = fwd.begin();

	// 가장 최근 우승자 출력 (forward_list의 첫 번째 요소)
	cout << "가장 최근 우승자 : " << *it1 << endl;

	// 반복자를 5칸 뒤로 이동 (선형 시간 복잡도)
	// forward_list는 단방향 연결 리스트이므로, 순차적으로 이동해야 함
	advance(it1, 5); // 선형 시간
	// 5년 전 우승자 출력 (forward_list의 5번째 요소)
	cout << "5년 전 우승자 : " << *it1 << endl;


	advance(it1, 2);
	// 7년 전 우승자 출력(forward_list의 7번째 요소)
	cout << "7년 전 우승자 : " << *it1 << endl;
	cout << endl;
	// forward_list는 순방형으로만 이동할 수 있으므로
	// advance(it1,-2)는 에러가 발생한다.
	// vector는 양방향으로 접근이 가능
	// forward_list는 단방향이라서 순차적인 접근이 가능 

	// vector의 모든 우승자를 순차적으로 출력
	cout << "vector의 우승자 목록:" << endl;
	for (const auto& winner : vec) {
		cout << winner << endl;
	}
	cout << endl;
	// forward_list의 모든 우승자를 순차적으로 출력
	cout << "forward_list의 우승자 목록:" << endl;
	for (const auto& winner : fwd) {
		cout << winner << endl;
	}

	return 0;
}