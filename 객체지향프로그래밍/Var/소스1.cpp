#include <iostream>
#include <array> // array ���
#include <type_traits> // Ÿ�� ���� ����(common_type ��)�� ����ϱ� ����
using namespace std;

// ���� ���ڸ� �޾� std::array�� �����ϴ� �Լ� ���ø�
// Args : ���� ���� ���ø��� ����� �پ��� Ÿ���� �Ű������� ���� �� ����


template<typename ... Args>
auto build_array(Args&&...args) -> array<typename common_type<Args...>::type, sizeof...(args)>
{
	// common_type�� ����Ͽ� ���ڵ� ���� ���� Ÿ���� ���
	// ���� Ÿ�� : ��� ���ڰ� ��ȯ�� �� �ִ� �ּ� ���� Ÿ��
	using commonType = typename common_type<Args...>::type;

	// std::forward�� ����Ͽ� ���޹��� ���ڸ� �״�� �����ϸ� std::array�� �ʱ�ȭ
	return { forward<commonType>((Args && )args)... };
}

int main()
{
	// build_array�� ȣ���Ͽ� �پ��� Ÿ���� ���� ���ڷ� ����
	// 1 (int), 0u(unsigned int), 'a'(char) 3.2f(float) , false(bool)
	// �� ���� Ÿ������ ��ȯ��
	// ���� Ÿ���� ��� ���ڰ� ��ȯ ������ �ּ����� ���� Ÿ������,
	// ���⼭�� double(float,int,char ���� ��� ��ȯ ����)�� ������
	
	auto data = build_array(1, 0u, 'a', 3.2f, false);
	// ������ std::array�� �� ���Ҹ� ���
	for (auto i : data)
		cout << i << " ";
	cout << endl;

	// 1 -> int���� double�� ��ȯ
	// 0u -> unsigned int���� double�� ��ȯ
	// 'a' -> char���� double�� ��ȯ ('a'�� ASCII �� 97)
	// 3.2f -> float���� double�� ��ȯ
	// false -> bool���� double�� ��ȯ (0���� ó��)
}