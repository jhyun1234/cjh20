#include <iostream>
#include <stdlib.h>

using namespace std;
using LData = int;
struct LinkedList
{
	Node* head;
	Node* cur; // 현재 노드를 가리킴
	Node* tail; // 리스트의 끝을 가리킴
	Node* next; // 다음 노드를 가리키는 포인터
	Node* before; // 노드 삭제를 도와줄 멤버
	int numofData; // 저장된 데이터 수를 기록하는 멤버
	int (*comp)(LData Data1, LData Data2); // 정렬의 기준을 정하는 멤버
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
		plist->head = new Node; // 더미 노드
		plist->head->next = NULL;
		plist->comp = NULL;
		plist->numofData = 0;
	}

	void FInsert(List* plist, int data) // 머리에 노드를 추가
	{
		Node* newNode = new Node; // 새 노드 동적으로 생성
		newNode->data = data; // 새 노드에 데이터 저장

		newNode->next = plist->head->next;  // 새 노드가 다른 노드를 가리키게 한다
		plist->head->next = newNode; // 더미 노드가 새 노드를 가리키게 한다
		(plist->numofData)++; // 저장된 노드의 수를 하나 증가시킨다
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
	void SInsert(List* plist, LData data) // 정렬기준마련
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
	void LInsert(List* plist, LData data) // 노드 추가를 어떤방식으로 하겠냐
	{
		if (plist->comp == NULL) // 정렬기준이 마련되지 않았다면
		{
			FInsert(plist, data); // 머리에 노드를 추가
		}
		else // 정렬기준이 마련되었다면
		{
			SInsert(plist, data); // 정렬기준에 맞춰서 노드를 추가
		}
	}
	LData ReMove(List* plist)
	{
		Node* rpos = plist->cur; // 삭제할 노드(cur가 가리키는 노드)의 주소를 임시 포인터 rpos에 저장
		LData rdata = rpos->data; // rpos가 가지고있는 데이터를 rdata에 저장

		plist->before->next = plist->cur->next; // cur->next를 before의 next에 저장
		// befoe->next 포인터가 삭제될 노드 cur 의 다음 노드를 가리키도록 변경
		plist->cur = plist->before; // cur와 before가 같은 위치에 있음

		delete rpos; // rpos가 가리키는 노드의 메모리 할당 해제
		(plist->numofData)--; // 리스트의 노드 개수를 하나 줄임
		return rdata; // 삭제된 값 반환

	}
};


int main()
{
	
	

	


}
void Listinit(List* plist)
{
	plist->head = new Node; // 더미 노드
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numofData = 0;
}
void FInsert(List* plist,int data) // 머리에 노드를 추가
{
	Node* newNode = new Node; // 새 노드 동적으로 생성
	newNode->data =data; // 새 노드에 데이터 저장

	newNode->next = plist->head->next;  // 새 노드가 다른 노드를 가리키게 한다
	plist->head->next = newNode; // 더미 노드가 새 노드를 가리키게 한다
	(plist->numofData)++; // 저장된 노드의 수를 하나 증가시킨다
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
void SInsert(List *plist, LData data) // 정렬기준마련
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

void LInsert(List *plist,LData data) // 노드 추가를 어떤방식으로 하겠냐
{
	if (plist->comp == NULL) // 정렬기준이 마련되지 않았다면
	{
		FInsert(plist,data); // 머리에 노드를 추가
	}
	else // 정렬기준이 마련되었다면
	{
		SInsert(plist, data); // 정렬기준에 맞춰서 노드를 추가
	}
}

LData ReMove(List* plist)
{
	Node* rpos = plist->cur; // 삭제할 노드(cur가 가리키는 노드)의 주소를 임시 포인터 rpos에 저장
	LData rdata = rpos->data; // rpos가 가지고있는 데이터를 rdata에 저장

	plist->before->next = plist->cur->next; // cur->next를 before의 next에 저장
	// befoe->next 포인터가 삭제될 노드 cur 의 다음 노드를 가리키도록 변경
	plist->cur = plist->before; // cur와 before가 같은 위치에 있음
	
	delete rpos; // rpos가 가리키는 노드의 메모리 할당 해제
	(plist->numofData)--; // 리스트의 노드 개수를 하나 줄임
	return rdata; // 삭제된 값 반환

}