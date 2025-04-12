#include <iostream>
#include <algorithm>

using namespace std;
struct singly_ll_node
{
	int data; // �� ĭ�� ����� ���� ���� ������
	singly_ll_node* next; // ���� ����� ����Ű�� ������. 
	// ���� ĭ�� ������ nullptr�� �ȴ�.
};


class singly_ll // ���� ���� ����Ʈ ��ü�� �����ϴ� Ŭ����
{
public:
	using node = singly_ll_node; // singly_ll_node �� ���� 'node' ��� ª�� �� �� �ִ�.
	using node_ptr = node*; // singly_ll_node* �� ���� 'node_ptr' �̶�� ª�� �� �� �ִ�.


private:
	node_ptr head;
	// ����Ʈ�� ���� ù ��° ��带 ����Ű�� ������. ����Ʈ�� ��������� nullptr

public:
	// ����Ʈ�� �� �տ� ���ο� ���� �߰��ϴ� �Լ�
	void push_front(int val)
	{
		// 1.���ο� ��带 �����. data���� val ���� �ְ�, 
		// next�� ���� head�� ����Ű�� ���� ����Ű�� �Ѵ�.
		// ���� ����Ʈ�� ����־��ٸ� head�� nullptr�̾��� ���̰�, 
		// new_node->next�� nullptr�� �ȴ�.
		auto new_node = new node{ val,NULL };
		if (head != NULL)
		{
			new_node->next = head;
		}
		// 2. ����Ʈ�� ������(head)�� ��� ���� �� ��带 ����Ű���� �����Ѵ�.
		head = new_node;
	}
	// ����Ʈ�� �� �� ��带 �����ϴ� �Լ�
	void pop_front()
	{
		// 1. ���� �� �� ���(������ ���)�� �ּҸ� first��� �ӽ� �����Ϳ� �����Ѵ�.
		auto first = head;
		// 2. ����Ʈ�� ������� ������ Ȯ���Ѵ�. (head�� nullptr�� �ƴ���)
		if (head)
		{
			head = head->next;
			// 3. head�� ���� �� ��° ���(first->next)�� �����Ͽ�, ����Ʈ�� �������� ���� ���� �ű��.
			delete first;
			// 4. �Ʊ� �����ص� ���� head ���(first)�� �޸𸮿��� �����Ѵ�.
		}
	}


	// ����Ʈ�� ��ȸ(�ϳ��� �湮)�ϱ� ���� ���ͷ�����(�ݺ���) Ŭ�����̴�. (for ���� ��� ���)
	// ���ͷ����ʹ� ����Ʈ�� Ư�� ��带 ����Ű�� ������ �Ѵ�.
	struct singly_LL_iterator
	{
	private:
		node_ptr ptr; // ���� ���ͷ����Ͱ� ����Ű�� �ִ� ����� �ּҸ� �����ϴ� ������

	public:
		// ������: Ư�� ��� ������(p)�� �޾Ƽ� ���ͷ����͸� �����.
		singly_LL_iterator(node_ptr p) :ptr(p) {}

		// ������ ������ (*): ���ͷ����Ͱ� ����Ű�� ����� data ���� �����ϰ� ���ش�. (���� �аų� ����)
		int& operator*() { return ptr->data; }
		// ���� ����Ű�� ����� �����͸� ��ȯ�ϴ� �Լ�
		node_ptr get() { return ptr; }

		// ���� ���� ������ (++it): ���ͷ����͸� ���� ���� �̵���Ű��, �̵��� '��'�� ���ͷ����͸� ��ȯ�Ѵ�.
		singly_LL_iterator& operator++() // ���� ����
		{
			ptr = ptr->next; // ���� �����͸� ���� ���� �̵�
			return *this;   // ����� ���ͷ����� �ڽ��� ��ȯ
		}

		// ���� ���� ������ (it++): ���ͷ����͸� ���� ���� �̵���Ű����, �̵��ϱ� '��'�� ���ͷ����͸� ��ȯ�Ѵ�.
		singly_LL_iterator operator++(int) // ���� ���� (int�� ������ �����ϱ� ���� ���� �Ķ����)
		{
			singly_LL_iterator result = *this; // ���� ����(���� ��)�� �����ؼ� ����
			++(*this); // ���� ���� �����ڸ� ȣ���Ͽ� ������ ���� ���� �̵�
			return result; // �����ص� ���� �� ���¸� ��ȯ
		}

		// �� ������ (==): �� ���ͷ����Ͱ� ���� ��带 ����Ű���� Ȯ���Ѵ�.
		friend bool operator==(const singly_LL_iterator& left,
			const singly_LL_iterator& right)
		{
			return left.ptr == right.ptr; // ���� �����Ͱ� ������ ���� ���ͷ����ͷ� ���
		}

		// �� ������ (!=): �� ���ͷ����Ͱ� �ٸ� ��带 ����Ű���� Ȯ���Ѵ�.
		friend bool operator!=(const singly_LL_iterator& left,
			const singly_LL_iterator& right)
		{
			// return !(left == right); �� ����
			return left.ptr != right.ptr; 
		}

	};
	// ����Ʈ�� ����(ù ��° ���)�� ����Ű�� ���ͷ����͸� ��ȯ�ϴ� �Լ� (for �������� ���)
	singly_LL_iterator begin() { return singly_LL_iterator(head); }
	// ����Ʈ�� ��(������ ��� ����, �� nullptr)�� ����Ű�� ���ͷ����͸� ��ȯ�ϴ� �Լ� (for �������� ���)
	singly_LL_iterator end() { return singly_LL_iterator(nullptr); } // ����Ʈ�� ���� nullptr�� ǥ��

	// const ����: ����Ʈ�� ������ �������� �ʴ� ��쿡 ���Ǵ� begin/end �Լ�
	singly_LL_iterator begin() const { return singly_LL_iterator(head); }
	singly_LL_iterator end() const { return singly_LL_iterator(nullptr); }

	// �⺻ ������: �����Ϸ��� �ڵ����� ������ִ� ���� ����Ѵ�.
	singly_ll() = default;

	// ���� ������: �ٸ� ����Ʈ(other)�� �޾Ƽ� �Ȱ��� ������ ���� �� ����Ʈ�� �����. (���� ����)
	singly_ll(const singly_ll& other) : head(NULL) // �� ����Ʈ�� head�� NULL�� �ʱ�ȭ
	{
		// 1. ������ ���� ����Ʈ(other)�� ������� ������ Ȯ���Ѵ�.
		if (other.head)
		{
			// 2. �� ����Ʈ�� ù ��° ��带 �ӽ÷� ����� (�����ʹ� 0, next�� nullptr).
			head = new node{ 0,NULL };
			// 3. �� ����Ʈ���� ���� ���������� �߰��� ��带 ����ų ������ cur (ó���� head)
			auto cur = head;
			// 4. ���� ����Ʈ�� ��ȸ�� ���ͷ����� 'it' (������ ù ��° ��忡�� ����)
			auto it = other.begin();
			// 5. ���� ���� ���� (���ο��� break�� Ż��)
			while (true)
			{
				// 6. ���� ���� ���(it)�� �����͸� �� ����Ʈ�� ���� ���(cur)�� �����Ѵ�. (ù ����� 0�� ���)
				cur->data = *it;
				// 7. ���� ����Ʈ�� ���� ��带 ����Ű�� �ӽ� ���ͷ����� tmp�� �����.
				auto tmp = it;
				++tmp;
				// 8. ���� ���� ����Ʈ�� ���� ��尡 ��(nullptr)�̶��, ���簡 ���� ���̹Ƿ� ������ Ż���Ѵ�.
				if (tmp == other.end())
					break;
				// 9. �� ����Ʈ�� ���� ��带 ���� �غ� �Ѵ�. �ӽ� ���(������ 0)�� ����� ���� ���(cur)�� next�� �����Ѵ�.
				cur->next = new node{ 0,NULL };
				// 10. �� ����Ʈ�� ���� ���(cur)�� ��� ���� ���� ���� �̵��Ѵ�.
				cur = cur->next;
				// 11. ���� ����Ʈ�� ���ͷ�����(it)�� ���� ���� �̵��Ѵ�.
				it = tmp;
			}
		}
	}
	// �ʱ�ȭ ����Ʈ ������: �߰�ȣ {1, 2, 3} ���·� ����Ʈ�� ���� �� �ְ� ���ش�.
	singly_ll(const initializer_list<int>& ilist) :head(NULL) // �� ����Ʈ�� head�� nullptr�� �ʱ�ȭ
	{
		// 1. �ʱ�ȭ ����Ʈ({1, 2, 3})�� �ڿ�������(rbegin) �Ųٷ�(rend) ��ȸ�Ѵ�. (��, 3, 2, 1 ����)
		for (auto it = rbegin(ilist); it != rend(ilist); it++)
			// 2. �� ���Ҹ� ����Ʈ�� �� �տ� �߰�(push_front)�Ѵ�,
			// (3 �߰� -> 2 �߰� -> 1 �߰� => ��������� 1 -> 2 -> 3 ������ ����Ʈ�� �������)
			push_front(*it);
	}

};

int main()
{
	// �ʱ�ȭ ����Ʈ �����ڸ� �̿��� sll ����Ʈ ����: 1 -> 2 -> 3
	singly_ll sll = { 1, 2, 3 };
	// push_front �Լ��� �̿��� �� �տ� 0 �߰�: 0 -> 1 -> 2 -> 3
	sll.push_front(0);
	sll.push_front(1);
	sll.push_front(2);
	cout << "ù ��° ����Ʈ : ";
	// ���� ��� for ����: sll ����Ʈ�� ó��(begin)���� ��(end)���� ��ȸ
	// ���������� begin(), end(), ++, * �����ڸ� ���
	for (auto i : sll)
		// �� ����� ������(i)�� ����ϰ� �� ĭ ���
		cout << i << " "; // ��� 0 1 2 3
	cout << endl;

	// ���� �����ڸ� �̿��� sll ����Ʈ�� sll2 ����Ʈ�� ���� ����
	// sll2�� sll�� �Ȱ��� ����(0 -> 1 -> 2 -> 3)�� ��������, ���� �ٸ� �޸� ������ ���
	auto sll2 = sll;
	// sll2 ����Ʈ�� �� �տ� -1 �߰�: -1 -> 0 -> 1 -> 2 -> 3
	sll2.push_front(-1);
	sll2.push_front(-2);
	sll2.push_front(-3);
	cout << "ù ��° ����Ʈ�� ������ ��, �� �տ� -1�� �߰�";
	for (auto i : sll2)
		cout << i << ' '; // ��� -1 0 1 2 3
	cout << endl;

	cout << "���� ���� �� ù ��° ����Ʈ : ";
	// sll2�� ������ ���� sll�� ������ ���� �ʾҴ��� Ȯ�� (���� ���� Ȯ��)
	for (auto i : sll)
		cout << i << ' '; // ��� 0 1 2 3
	cout << endl;
}