#include<iostream>
#include<string>

using namespace std;

struct Human // ����ü�� ���� �ٸ� ������ ������(������)�� �ϳ��� ��� �����ϱ� ���� Ʋ�̴�.
// �̿� ������ ����� class ��� ���� �ִ�. 
// �� ���� �������� �⺻ ���� �����ڰ� �ٸ���.
// ����ü�� public�̰� class�� private�̴�.
// �� ����ϴ°�? ���� ������ ���� - ���� ������ �ϳ��� ������ ������ ��Ÿ�� ��, 
// �� �������� ����ü�� ������ �ڵ��� �������� ���� ȿ���� ũ�� ���ȴ�.
// ��) �л� ���� (�̸�, �й�, ����), å ���� (����, ����),��¥ (��, ��, ��)
{
private:
	int age, height, weight; // ����� ����,Ű,�����Ը� �����ϴ� ��� ���� ����
	string name; // �̸��� ������ �� �ִ� string ��� ���� ����
	char blood_type; // �������� ��Ÿ���� ���� ��� ���� ����
	
public:
	Human() :age(0), height(0), weight(0), name("NULL"), blood_type('?')
		// �⺻ ������: ���� ���� ȣ��� �� ���. ��� ������ �⺻���� �����Ѵ�.
	{

	}
	Human(int a, int h, int w, const string& n, char b)
		: age(a), height(h), weight(w), name(n), blood_type(b)
		// �Ű����� �ִ� ������: ��ü ���� �� �ܺο��� ���� �޾� �ʱ�ȭ�Ѵ�.
	{
	
	}

	int getAge() const // private�� �������� �о���� ������ �Ѵ�.
	{
		return age;
	}

	int getHeight() const // private�� �������� �о���� ������ �Ѵ�.
	{
		return height;
	}

	int getWeight() const // private�� �������� �о���� ������ �Ѵ�.
	{
		return weight;
	}

	const string& getName() const // private�� �������� �о���� ������ �Ѵ�.
	{
		return name;
	}

	char getBloodType() const // private�� �������� �о���� ������ �Ѵ�.
	{
		return blood_type;
	}

	void setAge(int newAge) // �� ���� ���� ���ڷ� ����
	{
		// ��ȿ�� �˻�: ���̴� 0���� ���� �� ����.
		if (newAge >= 0 && newAge <= 120) 
		{
			age = newAge; // ��ȿ�ϸ� ��� ���� age�� �� ������ ����
			// cout << "���� ����: " << age << endl; // ���� Ȯ�� �޽���
		}
		else
		{
			cerr << "����: ��ȿ���� ���� ���� �� (" << newAge << "). ���̸� �������� �ʴ´�." << endl; // ���� �޽���
		}
	}

	// Ű(height) ���� �����ϴ� �Լ�
	void setHeight(int newHeight)
	{
		// ��ȿ�� �˻�: Ű�� 0���� �۰ų� ���� �� ����.
		if (newHeight > 0 && newHeight < 300) 
		{
			height = newHeight; // ��ȿ�ϸ� ����
			// cout << "Ű ����: " << height << endl;
		}
		else
		{
			cerr << "����: ��ȿ���� ���� Ű �� (" << newHeight << "). Ű�� �������� �ʴ´�." << endl;
		}
	}

	// ������(weight) ���� �����ϴ� �Լ�
	void setWeight(int newWeight)
	{
		// ��ȿ�� �˻�: �����Դ� 0���� �۰ų� ���� �� ����.
		if (newWeight > 0 && newWeight < 1000) 
		{
			weight = newWeight; // ��ȿ�ϸ� ����
			// cout << "������ ����: " << weight << endl;
		}
		else
		{
			cerr << "����: ��ȿ���� ���� ������ �� (" << newWeight << "). �����Ը� �������� �ʴ´�." << endl;
		}
	}

	// �̸�(name) ���� �����ϴ� �Լ�
	void setName(const string& newName) // string ���� const string&�� ����
	{
		// ��ȿ�� �˻�: �̸��� ������� ������ Ȯ��
		if (!newName.empty()) // name.empty()�� string�� ��������� true ��ȯ
		{
			name = newName; // ��ȿ�ϸ� ����
			// cout << "�̸� ����: " << name << endl;
		}
		else
		{
			cerr << "����: �̸��� ������� �� ����. �̸��� �������� �ʴ´�." << endl;
		}
	}

	void Print() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
		cout << "Ű :  " << height << endl;
		cout << "������ : " << weight << endl;
		cout << "������ : " << blood_type << endl;
	}
	void Printget_set() const
	{
		
		cout << "�̸� : " << getName() << endl; // getName() getter ȣ��
		cout << "���� : " << getAge() << endl;   // getAge() getter ȣ��
		cout << "Ű : " << getHeight() << endl; // getHeight() getter ȣ��
		cout << "������ : " << getWeight() << endl; // getWeight() getter ȣ��
		cout << "������ : " << getBloodType() << endl; // getBloodType() getter ȣ��
		
	}
};


int main()
{
	//Human man;
	//man.Print();
	cout << endl;
	Human man2(25,170,67,"������",'B'); // �Ű������� ���� �� �ʱ�ȭ ���
	man2.Print();
	
	cout << endl;
	Human man;
	man.setAge(25);
	man.setHeight(150);
	man.setWeight(75);
	man.setName("ȫ�浿");
	man.Printget_set();
	
	
	return 0;
}