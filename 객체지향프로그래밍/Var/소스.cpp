#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
template<typename T>
class dynamic_array
{
	T* data; // ���� �迭 �����͸� �����ϴ� ������
	size_t n; // �迭�� ũ�� ���� ����


public:
	// ������ : �迭�� ũ�⸦ n���� �����ϰ� �޸𸮸� �������� �Ҵ��Ѵ�.
	dynamic_array(int n)
	{
		this->n = n;  // �迭 ũ�� �ʱ�ȭ
		data = new T[n]; // ũ�⿡ �°� �޸� �Ҵ�
	}

	// ���� ������ : ���� ���縦 �����Ͽ� ��ü ���� �� �������� �������� �����Ѵ�.
	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n; // �迭 ũ�� ����
		data = new T[n]; // �� �޸� �Ҵ�

		for (int i = 0; i < n; i++)
		{
			data[i] = other.data[i]; // �����͸� ���������� ����

		}
	}
	// �迭 �ε����� ���� ��� ������ ����	
	T& operator[](int index)
	{
		return data[index]; // �ε����� �ش��ϴ� ���� ��ȯ
	}
	// �迭 �ε����� ���� ��� ������ ����	
	const T& operator[](int index) const
	{
		return data[index]; // const ��ü�� ���ؼ��� �б� ����
	}
	// ������ ������ �����ϸ�, �߸��� �ε��� ���� �� ���ܸ� �߻���Ŵ
	T& at(int index)
	{
		if (index >= n) // ��ȿ�� ���� �ʰ� ���� Ȯ��
		{
			throw "Index out of range"; // ���� �߻�
		}
		return data[index]; // ���� �� ����
	}


	// �迭 ũ�� ��ȯ
	size_t size() const
	{
		return n; // �迭 ���� ���� ��ȯ
	}
	// �Ҹ��� : �������� �Ҵ�� �޸𸮸� �����Ͽ� �޸� ������ �����Ѵ�.
	~dynamic_array()
	{
		delete[] data; // ���� �޸� ����
	}

	// begin() �� end() �Լ�: �ݺ���ó�� �����ϴ� �����͸� ��ȯ�Ѵ�.
	T* begin() { return data; } // ���� ������ ��ȯ
	const T* begin() const { return data; } // const ���� ������ ��ȯ
	T* end() { return data + n; } // �� ������ ��ȯ
	const T* end() const { return data + n; } // const �� ������ ��ȯ

	// operator+ �Լ�: �� dynamic_array ��ü�� �����Ͽ� ���ο� ��ü�� �����Ѵ�.
	// �迭 ��ġ�� ����� �����Ѵ�.
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size()); // �� �迭 ũ���� �ո�ŭ ���ο� �迭 ����
		copy(arr1.begin(), arr1.end(), result.begin()); // ù ��° �迭�� ������ ����
		copy(arr2.begin(), arr2.end(), result.begin()+arr1.size()); // �� ��° �迭�� ������ ����

		return result; // ���յ� �迭 ��ȯ
		
	}
	// to_string() �Լ� : �迭�� ������ ���ڿ��� ��ȯ�Ѵ�.
	// sep �Ķ���͸� ����Ͽ� �� ���� ������ �����ڸ� ������ �� �ִ�.
	string to_string(const string& sep = " , ")
	{
		if (n == 0)
			return ""; // �迭�� ��� ������ �� ���ڿ� ��ȯ

		ostringstream os; // ���ڿ� ��Ʈ�� ��ü ����
		os << data[0]; // ù ��° ���� �߰�

		for (int i = 1; i < n; i++) // �� ��° ���Һ��� �����ڸ� �߰��ϸ� ���ڿ� ����
			os << sep << data[i];
		return os.str(); // ������ ���ڿ� ��ȯ
	}

	

};

// student ����ü : �л��� �̸��� �г��� �����ϱ� ���� ������ ����
struct student
{
	string name; // �л� �̸�
	int standard; // �л� �г�
};

// operator<< ������ �����ε� : student ��ü�� ����� �� ���ڿ� ������ �����Ѵ�.
ostream& operator<<(ostream& os, const student& s)
{
	return (os << " [ " << s.name << " ," << s.standard << "]");
}

int main()
{
	int nStudents;
	cout << "1�� �л� ���� �Է��ϼ��� : ";
	cin >> nStudents;

	// ù ��° �б��� ���� dynamic_array ��ü ����
	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int standard;
		cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ��� : ";
		cin >> name >> standard;
		class1[i] = student{ name,standard };
	}

	// �迭 ũ�⺸�� ū �ε����� �л��� ����
	try
	{
		// �Ʒ� �ּ��� �����ϸ� ���α׷��� ������ ����
		// class1[nStudents] = student{ "John",8 }; // ������ �� ���� ����
		// ��ȿ���� ���� �ε��� ����

		class1.at(nStudents) = student{ "John",8 }; // ���� �߻�

	}
	catch (...)
	{
		cout << "���� �߻�!" << endl;
	}


	// ���� ���� : ���� �б� class1�� �����Ͽ� �� �б� calss2 ����
	auto class2 = class1;
	cout << "1���� �����Ͽ� 2�� ���� : " << class2.to_string() << endl;

	// �� �б��� ���ļ� ���ο� ū �б��� ����
	auto class3 = class1 + class2;
	cout << "1�ݰ� 2���� ���� 3�� ���� : " << class3.to_string() << endl;
	return 0;
}