#include <iostream> // ǥ�� ����� ��Ʈ���� ����ϱ� ���� ��� ���� ����
#include <forward_list> // �ܹ��� ���� ����Ʈ�� forward_list �����̳ʸ� ����ϱ� ���� ��� ���� ����
#include <vector> // ���� �迭�� vector �����̳ʸ� ����ϱ� ���� ��� ���� ����

using namespace std;
int main()
{
	// ���ڿ��� ��ҷ� ������ vector �����̳� vec ���� �� �ʱ�ȭ
	vector<string> vec =
	{
		"Lewis Hamilton","Lewis Hamilton","Nico Roseberg",
		"Sebastian Vettel","Lewis Hamilton","Sebastian Vettel",
		"Sebastian Vettel","Sebastian Vettel","Fernando Alonso"
	};
	
	// vector�� ���� �ݺ���(iterator)�� it ������ �Ҵ� (��� �ð� ���⵵)
	// �ݺ��ڴ� �����̳��� ��Ҹ� ����Ű�� �����Ϳ� ������ ��ü
	auto it = vec.begin(); // ��� �ð�
	// ���� �ֱ� ����� ��� (vector�� ù ��° ���)
	cout << "���� �ֱ� ����� : " << *it << endl;

	it += 8; // ��� �ð�
	// �ݺ��ڸ� 8ĭ �ڷ� �̵� (��� �ð� ���⵵)
	// vector�� ���� ���� �ݺ��ڸ� �����ϹǷ�, ��� �ð� ���� ������ ��ġ�� �̵� ����
	// 8�� �� ����� ��� (vector�� 8��° ���)
	cout << "8�� �� ����� : " << *it << endl;

	advance(it, -3); // ��� �ð�
	// �ݺ��ڸ� 3ĭ ������ �̵� (��� �ð� ���⵵)
	// vector�� ����� �̵��� �����ϹǷ�, ���� ���� ����Ͽ� ������ �̵� ����
	// 3�� �� ����� ��� (vector�� 5��° ���)
	cout << "���� 3�� �� ����� : " << *it << endl;


	// vector�� ��� ��Ҹ� �����Ͽ� forward_list �����̳� fwd ���� �� �ʱ�ȭ
   // forward_list�� �ܹ��� ���� ����Ʈ�̹Ƿ�, �������� ���ٸ� ����
	forward_list<string> fwd(vec.begin(), vec.end());

	// forward_list�� ���� �ݺ��ڸ� it1 ������ �Ҵ�
	auto it1 = fwd.begin();

	// ���� �ֱ� ����� ��� (forward_list�� ù ��° ���)
	cout << "���� �ֱ� ����� : " << *it1 << endl;

	// �ݺ��ڸ� 5ĭ �ڷ� �̵� (���� �ð� ���⵵)
	// forward_list�� �ܹ��� ���� ����Ʈ�̹Ƿ�, ���������� �̵��ؾ� ��
	advance(it1, 5); // ���� �ð�
	// 5�� �� ����� ��� (forward_list�� 5��° ���)
	cout << "5�� �� ����� : " << *it1 << endl;


	advance(it1, 2);
	// 7�� �� ����� ���(forward_list�� 7��° ���)
	cout << "7�� �� ����� : " << *it1 << endl;
	cout << endl;
	// forward_list�� ���������θ� �̵��� �� �����Ƿ�
	// advance(it1,-2)�� ������ �߻��Ѵ�.
	// vector�� ��������� ������ ����
	// forward_list�� �ܹ����̶� �������� ������ ���� 

	// vector�� ��� ����ڸ� ���������� ���
	cout << "vector�� ����� ���:" << endl;
	for (const auto& winner : vec) {
		cout << winner << endl;
	}
	cout << endl;
	// forward_list�� ��� ����ڸ� ���������� ���
	cout << "forward_list�� ����� ���:" << endl;
	for (const auto& winner : fwd) {
		cout << winner << endl;
	}

	return 0;
}