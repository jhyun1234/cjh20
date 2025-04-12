#include <string> // string 클래스를 사용하기 위한 헤더 파일 포함
#include <iostream> // cout, endl 등 입출력 기능을 사용하기 위한 헤더 파일 포함
#include <forward_list> // forward_list 컨테이너를 사용하기 위한 헤더 파일 포함

using namespace std;
// 시민 정보를 저장하는 구조체 정의
struct citizen
{
	string name; // 시민의 이름을 저장하는 문자열 변수
	int age; // 시민의 나이를 저장하는 정수형 변수
};

// citizen 구조체 객체를 출력 스트림에 출력하는 연산자 오버로딩
// citizen 객체를 "[이름,나이]" 형식으로 출력하도록 정의
ostream& operator<<(ostream& os, const citizen& c)
{
	return(os << "[" << c.name << "," << c.age << "]");
}

int main()
{
	// citizen 구조체를 요소로 가지는 forward_list 컨테이너 생성 및 초기화
	// forward_list는 단방향 연결 리스트로, 요소의 삽입/삭제가 효율적임
	forward_list<citizen> citizens =
	{
		{"Kim",22},{"Lee",25},{"Park",19},{"Jin",16}
	};
	// citizens forward_list를 복사하여 citizen_copy forward_list 생성 (깊은 복사)
	// forward_list의 복사 생성자는 깊은 복사를 수행하여 요소의 내용까지 복사함
	auto citizen_copy = citizens; // 깊은 복사

	// 전체 시민 정보를 출력
	cout << "전체 시민들 : ";
	// for 루프를 사용하여 citizens의 모든 요소에 접근
	for (const auto& c : citizens)
		cout << c << " "; // 각 시민 정보를 출력
	cout << endl;

	// remove_if 함수를 사용하여 나이가 19세 미만인 시민을 리스트에서 제거
	// 람다 표현식을 사용하여 제거 조건을 정의	
	citizens.remove_if([](const citizen &c)
		{
			// 나이가 19세보다 작으면 리스트에서 제거한다.
			return (c.age < 19);
		});

	// 투표권이 있는 시민 정보(19세 이상)를 출력
	cout << "투표권이 있는 시민들: ";
	// for 루프를 사용하여 citizens의 모든 요소에 접근
	for (const auto& c : citizens)
		cout << c << " "; // 각 시민 정보를 출력
	cout << endl;

	// 추가 코드 작성 16세는 내년에도 투표권이 없기 때문에 완전 제외
	citizens.remove_if([](const citizen &c)
		{
			return (c.age == 16);
			
		});
	

	// remove_if 함수를 사용하여 나이가 18세가 아닌 시민을 리스트에서 제거
	citizens.remove_if([](const citizen &c)
		{
			return (c.age == 18); 
			// 나이가 18세이면 true를 반환하여 해당 요소를 제거
		});

	// 내년에 투표권이 생기는 시민 정보(19세)를 출력
	// citizen_copy는 citizens의 복사본이므로, citizens의 변경 사항이 반영되지 않음
	cout << "내년에 투표권이 생기는 시민들 : ";
	// for 루프를 사용하여 citizen_copy의 모든 요소에 접근
	// 추가 주석 작성 16세가 내년에 투표권이 생기는 시민들에 출력이 되는것이 이상하여
	// 16세이면 내년에도 투표권이 없기 때문에 제외를 해버리고
	// citizen_copy를 통해서 원본을 불러오는게 아닌 삭제된 정보를 출력하게 함.
	for (const auto& c : citizens) // 각 시민 정보를 출력
		cout << c << " ";
	cout << endl;
	

	

}