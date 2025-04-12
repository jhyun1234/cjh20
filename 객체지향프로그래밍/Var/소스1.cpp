#include <iostream>
#include <array> // array 사용
#include <type_traits> // 타입 연산 도구(common_type 등)를 사용하기 위해
using namespace std;

// 가변 인자를 받아 std::array를 생성하는 함수 템플릿
// Args : 가변 인자 템플릿을 사용해 다양한 타입의 매개변수를 받을 수 있음


template<typename ... Args>
auto build_array(Args&&...args) -> array<typename common_type<Args...>::type, sizeof...(args)>
{
	// common_type을 사용하여 인자들 간의 공통 타입을 계산
	// 공통 타입 : 모든 인자가 변환될 수 있는 최소 공통 타입
	using commonType = typename common_type<Args...>::type;

	// std::forward를 사용하여 전달받은 인자를 그대로 유지하며 std::array를 초기화
	return { forward<commonType>((Args && )args)... };
}

int main()
{
	// build_array를 호출하여 다양한 타입의 값을 인자로 전달
	// 1 (int), 0u(unsigned int), 'a'(char) 3.2f(float) , false(bool)
	// 가 공통 타입으로 변환됨
	// 공통 타입은 모든 인자가 변환 가능한 최소한의 공통 타입으로,
	// 여기서는 double(float,int,char 등이 모두 변환 가능)로 결정됨
	
	auto data = build_array(1, 0u, 'a', 3.2f, false);
	// 생성된 std::array의 각 원소를 출력
	for (auto i : data)
		cout << i << " ";
	cout << endl;

	// 1 -> int에서 double로 변환
	// 0u -> unsigned int에서 double로 변환
	// 'a' -> char에서 double로 변환 ('a'의 ASCII 값 97)
	// 3.2f -> float에서 double로 변환
	// false -> bool에서 double로 변환 (0으로 처리)
}