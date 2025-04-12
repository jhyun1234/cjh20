#include <string> // string Ŭ������ ����ϱ� ���� ��� ���� ����
#include <iostream> // cout, endl �� ����� ����� ����ϱ� ���� ��� ���� ����
#include <forward_list> // forward_list �����̳ʸ� ����ϱ� ���� ��� ���� ����

using namespace std;
// �ù� ������ �����ϴ� ����ü ����
struct citizen
{
	string name; // �ù��� �̸��� �����ϴ� ���ڿ� ����
	int age; // �ù��� ���̸� �����ϴ� ������ ����
};

// citizen ����ü ��ü�� ��� ��Ʈ���� ����ϴ� ������ �����ε�
// citizen ��ü�� "[�̸�,����]" �������� ����ϵ��� ����
ostream& operator<<(ostream& os, const citizen& c)
{
	return(os << "[" << c.name << "," << c.age << "]");
}

int main()
{
	// citizen ����ü�� ��ҷ� ������ forward_list �����̳� ���� �� �ʱ�ȭ
	// forward_list�� �ܹ��� ���� ����Ʈ��, ����� ����/������ ȿ������
	forward_list<citizen> citizens =
	{
		{"Kim",22},{"Lee",25},{"Park",19},{"Jin",16}
	};
	// citizens forward_list�� �����Ͽ� citizen_copy forward_list ���� (���� ����)
	// forward_list�� ���� �����ڴ� ���� ���縦 �����Ͽ� ����� ������� ������
	auto citizen_copy = citizens; // ���� ����

	// ��ü �ù� ������ ���
	cout << "��ü �ùε� : ";
	// for ������ ����Ͽ� citizens�� ��� ��ҿ� ����
	for (const auto& c : citizens)
		cout << c << " "; // �� �ù� ������ ���
	cout << endl;

	// remove_if �Լ��� ����Ͽ� ���̰� 19�� �̸��� �ù��� ����Ʈ���� ����
	// ���� ǥ������ ����Ͽ� ���� ������ ����	
	citizens.remove_if([](const citizen &c)
		{
			// ���̰� 19������ ������ ����Ʈ���� �����Ѵ�.
			return (c.age < 19);
		});

	// ��ǥ���� �ִ� �ù� ����(19�� �̻�)�� ���
	cout << "��ǥ���� �ִ� �ùε�: ";
	// for ������ ����Ͽ� citizens�� ��� ��ҿ� ����
	for (const auto& c : citizens)
		cout << c << " "; // �� �ù� ������ ���
	cout << endl;

	// �߰� �ڵ� �ۼ� 16���� ���⿡�� ��ǥ���� ���� ������ ���� ����
	citizens.remove_if([](const citizen &c)
		{
			return (c.age == 16);
			
		});
	

	// remove_if �Լ��� ����Ͽ� ���̰� 18���� �ƴ� �ù��� ����Ʈ���� ����
	citizens.remove_if([](const citizen &c)
		{
			return (c.age == 18); 
			// ���̰� 18���̸� true�� ��ȯ�Ͽ� �ش� ��Ҹ� ����
		});

	// ���⿡ ��ǥ���� ����� �ù� ����(19��)�� ���
	// citizen_copy�� citizens�� ���纻�̹Ƿ�, citizens�� ���� ������ �ݿ����� ����
	cout << "���⿡ ��ǥ���� ����� �ùε� : ";
	// for ������ ����Ͽ� citizen_copy�� ��� ��ҿ� ����
	// �߰� �ּ� �ۼ� 16���� ���⿡ ��ǥ���� ����� �ùε鿡 ����� �Ǵ°��� �̻��Ͽ�
	// 16���̸� ���⿡�� ��ǥ���� ���� ������ ���ܸ� �ع�����
	// citizen_copy�� ���ؼ� ������ �ҷ����°� �ƴ� ������ ������ ����ϰ� ��.
	for (const auto& c : citizens) // �� �ù� ������ ���
		cout << c << " ";
	cout << endl;
	

	

}