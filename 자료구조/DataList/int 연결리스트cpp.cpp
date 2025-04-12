#include <iostream> 
#include <vector>  
#include <initializer_list> // �߰�ȣ �ʱ�ȭ {1, 2, 3} �� ����ϱ� ���� �ʿ�
using namespace std;
class intList {

private:
    // vector<int> �� ����Ͽ� �������� ����
    // vector�� �ʿ信 ���� �ڵ����� ũ�Ⱑ �����Ǵ� ���� �迭
    vector<int> data;

public:
    // 1. ������ (��ü�� ó�� ������� �� ȣ��Ǵ� �Լ���)
    // �⺻ ������: �ƹ��� �ʱⰪ ���� �� ����Ʈ�� �����.
    // Ư���� �ڵ尡 ��� ������ vector�� �ڵ����� ����ִ� ���·� �ʱ�ȭ�Ѵ�.
    intList() {};

    // �ʱ�ȭ ����Ʈ ������: �߰�ȣ { } �ȿ� ������ �־� ����Ʈ�� ������ �� �ְ� �Ѵ�.
    intList(initializer_list<int> init_list) : data(init_list) 
    {
        // ��� �ʱ�ȭ ����Ʈ(: data(init_list))�� ����ؼ�
        // vector�� ���޹��� �ʱⰪ��� �ٷ� �ʱ�ȭ�Ѵ�.
    }

    // 2. ��� �Լ� (��ü�� �� �� �ִ� ��ɵ�)

    // ����Ʈ�� �� �ڿ� ���� ���� �߰��ϴ� �Լ�
    void add_element(int value) 
    {
        // vector�� push_back �Լ��� ����Ͽ� �� �ڿ� ��Ҹ� �߰�.
        data.push_back(value);
    }

    // ����Ʈ�� ����� ��� ������ ����ϴ� �Լ�
    // �Լ� �ڿ� 'const'�� ���̸� �� �Լ��� ��� ������ ������
    // �������� �ʴ´ٴ� ����̴�.
    void print_list() const 
    {
        if (data.empty()) 
        { // vector�� ����ִ��� Ȯ��
            cout << "����Ʈ�� ����ֽ��ϴ�.";
        }
        else 
        {
            // ���� ��� for ������ ����Ͽ� vector�� ��� ��Ҹ� ���.
            for (int element : data) 
            {
                cout << element << " ";
            }
        }
        cout << endl; // �ٹٲ�
    }

    // ����Ʈ�� ����� ������ ������ ��ȯ�ϴ� �Լ�
    size_t get_size() const {
        // vector�� size �Լ��� ����Ͽ� ����� ����� ������ ��ȯ.
        // size_t�� ���� ��ȣ ���� ����(unsigned int) Ÿ��.
        return data.size();
    }

    // 3. �Ҹ��� (��ü�� �޸𸮿��� ������� ������ ȣ��Ǵ� �Լ�)
    // �� Ŭ������ vector�� ����ϰ� vector�� �޸� ������ ���ֹǷ�,
    // ���� new/delete�� ���� �ʾҴٸ� Ư���� �ۼ��� �ڵ�� ����.
    ~intList() {
        cout << "intList ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
    }
};



int main() {
   
    // 1. �ʱ�ȭ ����Ʈ �����ڸ� ����Ͽ� List1 ��ü ����
    intList List1 = { 10, 20, 30 };
    List1.print_list(); // ������ ����Ʈ ���� ���
    cout << "List1�� ũ��: " << List1.get_size() << endl;
 
    // 2. add_element ��� �Լ��� ����Ͽ� ��� �߰�
    List1.add_element(40);
    List1.add_element(50);
    List1.print_list(); // ����� ����Ʈ ���� ���
    cout << "List1�� ũ��: " << List1.get_size() << endl;

    // 3. �⺻ �����ڸ� ����Ͽ� ����ִ� List2 ��ü ����
    intList List2;
    List2.print_list(); // ����ִ� ����Ʈ ���
    cout << "List2�� ũ��: " << List2.get_size() << endl;
  
    // 4. ����ִ� myList2�� ��� �߰�

    List2.add_element(5);
    List2.add_element(15);
    List2.add_element(25);

    List2.print_list(); // ����� ����Ʈ ���� ���
    cout << "myList2�� ũ��: " << List2.get_size() << endl;
    return 0;
}