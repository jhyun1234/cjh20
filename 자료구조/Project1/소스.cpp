#include <iostream>
#include <stdlib.h>

using namespace std;
using LData = int;
struct LinkedList
{
	Node* head;
	Node* cur; // ���� ��带 ����Ŵ
	Node* tail; // ����Ʈ�� ���� ����Ŵ
	Node* next; // ���� ��带 ����Ű�� ������
	Node* before; // ��� ������ ������ ���
	int numofData; // ����� ������ ���� ����ϴ� ���
	int (*comp)(LData Data1, LData Data2); // ������ ������ ���ϴ� ���
};
using List = LinkedList;

struct Node
{
	LData data;
	Node* next;
};

class Linkedlist1
{
private:
	List list;
	Node node;

public:
	Linkedlist1() {};
	void Listinit(List* plist)
	{
		plist->head = new Node; // ���� ���
		plist->head->next = NULL;
		plist->comp = NULL;
		plist->numofData = 0;
	}

	void FInsert(List* plist, int data) // �Ӹ��� ��带 �߰�
	{
		Node* newNode = new Node; // �� ��� �������� ����
		newNode->data = data; // �� ��忡 ������ ����

		newNode->next = plist->head->next;  // �� ��尡 �ٸ� ��带 ����Ű�� �Ѵ�
		plist->head->next = newNode; // ���� ��尡 �� ��带 ����Ű�� �Ѵ�
		(plist->numofData)++; // ����� ����� ���� �ϳ� ������Ų��
	}

	void FInsert(List* plist, LData data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		newNode->next = plist->head->next;
		plist->head->next = newNode;
		(plist->numofData)++;
	}
	int LFirst(List* plist, LData* pdata)
	{
		if (plist->head->next == nullptr)
			return false;

		plist->before = plist->head;
		plist->cur = plist->head->next;

		*pdata = plist->cur->data;
		return true;
	}

	int LNext(List* plist, LData* pdata)
	{
		if (plist->cur->next == nullptr)
			return false;

		plist->before = plist->cur;
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;
		return true;

	}
	void SetSortRule(List* plist, int(*comp)(LData d1, LData d2))
	{
		plist->comp = comp;
	}
	void SInsert(List* plist, LData data) // ���ı��ظ���
	{
		Node* newNode = new Node;
		Node* pred = plist->head;
		newNode->data = data;

		while (pred->next != nullptr && plist->comp(data, plist->next->data) != 0)
		{
			pred = pred->next;
		}
		newNode = pred->next;
		pred->next = newNode;
		(plist->numofData)++;
	}
	void LInsert(List* plist, LData data) // ��� �߰��� �������� �ϰڳ�
	{
		if (plist->comp == NULL) // ���ı����� ���õ��� �ʾҴٸ�
		{
			FInsert(plist, data); // �Ӹ��� ��带 �߰�
		}
		else // ���ı����� ���õǾ��ٸ�
		{
			SInsert(plist, data); // ���ı��ؿ� ���缭 ��带 �߰�
		}
	}
	LData ReMove(List* plist)
	{
		Node* rpos = plist->cur; // ������ ���(cur�� ����Ű�� ���)�� �ּҸ� �ӽ� ������ rpos�� ����
		LData rdata = rpos->data; // rpos�� �������ִ� �����͸� rdata�� ����

		plist->before->next = plist->cur->next; // cur->next�� before�� next�� ����
		// befoe->next �����Ͱ� ������ ��� cur �� ���� ��带 ����Ű���� ����
		plist->cur = plist->before; // cur�� before�� ���� ��ġ�� ����

		delete rpos; // rpos�� ����Ű�� ����� �޸� �Ҵ� ����
		(plist->numofData)--; // ����Ʈ�� ��� ������ �ϳ� ����
		return rdata; // ������ �� ��ȯ

	}
};


int main()
{
	
	

	


}
void Listinit(List* plist)
{
	plist->head = new Node; // ���� ���
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numofData = 0;
}
void FInsert(List* plist,int data) // �Ӹ��� ��带 �߰�
{
	Node* newNode = new Node; // �� ��� �������� ����
	newNode->data =data; // �� ��忡 ������ ����

	newNode->next = plist->head->next;  // �� ��尡 �ٸ� ��带 ����Ű�� �Ѵ�
	plist->head->next = newNode; // ���� ��尡 �� ��带 ����Ű�� �Ѵ�
	(plist->numofData)++; // ����� ����� ���� �ϳ� ������Ų��
}

void FInsert(List* plist, LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;
	(plist->numofData)++;
}
int LFirst(List* plist, LData *pdata)
{
	if (plist->head->next == nullptr)
		return false;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return true;
}

int LNext(List* plist, LData *pdata)
{
	if (plist->cur->next == nullptr)
		return false;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return true;

} 

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}
void SInsert(List *plist, LData data) // ���ı��ظ���
{
	Node* newNode = new Node;
	Node* pred = plist->head;
	newNode->data = data;

	while (plist->next != nullptr && plist->comp(data, plist->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode = pred->next;
	pred->next = newNode;
	(plist->numofData)++;


}

void LInsert(List *plist,LData data) // ��� �߰��� �������� �ϰڳ�
{
	if (plist->comp == NULL) // ���ı����� ���õ��� �ʾҴٸ�
	{
		FInsert(plist,data); // �Ӹ��� ��带 �߰�
	}
	else // ���ı����� ���õǾ��ٸ�
	{
		SInsert(plist, data); // ���ı��ؿ� ���缭 ��带 �߰�
	}
}

LData ReMove(List* plist)
{
	Node* rpos = plist->cur; // ������ ���(cur�� ����Ű�� ���)�� �ּҸ� �ӽ� ������ rpos�� ����
	LData rdata = rpos->data; // rpos�� �������ִ� �����͸� rdata�� ����

	plist->before->next = plist->cur->next; // cur->next�� before�� next�� ����
	// befoe->next �����Ͱ� ������ ��� cur �� ���� ��带 ����Ű���� ����
	plist->cur = plist->before; // cur�� before�� ���� ��ġ�� ����
	
	delete rpos; // rpos�� ����Ű�� ����� �޸� �Ҵ� ����
	(plist->numofData)--; // ����Ʈ�� ��� ������ �ϳ� ����
	return rdata; // ������ �� ��ȯ

}