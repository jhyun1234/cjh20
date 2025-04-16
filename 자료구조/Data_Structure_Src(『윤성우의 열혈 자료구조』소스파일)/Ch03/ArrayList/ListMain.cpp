#include<iostream>
#include "ArrayList.h"

using namespace std;
int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	int data;
	ListInit(&list);

	/*** 5���� ������ ���� ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 33);
	LInsert(&list, 33);

	
	/*** ����� �������� ��ü ��� ***/
	//printf("���� �������� ��: %d \n", LCount(&list));
	cout << "���� �������� �� : " << LCount(&list) << endl;
	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		//printf("%d ", data);
		cout << data<<" ";
		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			//printf("%d ", data);
			cout << data<<" ";
	}
	//printf("\n\n");
	cout << endl<<endl;
	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if(LFirst(&list, &data))
	{
		if (data % 2 == 0)
			LRemove(&list);
		else
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if (data % 2 == 0)
				LRemove(&list);
			else
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	//printf("���� �������� ��: %d \n", LCount(&list));
	cout << "���� �������� �� : " << LCount(&list) << endl;
	if(LFirst(&list, &data))
	{
		//printf("%d ", data);
		cout << data<<" ";
		while(LNext(&list, &data))
			//printf("%d ", data);
			cout << data<<" ";
	}
	cout << endl << endl;
	printf("\n\n");
	return 0;
}