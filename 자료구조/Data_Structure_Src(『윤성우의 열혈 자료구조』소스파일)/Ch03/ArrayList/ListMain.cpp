#include<iostream>
#include "ArrayList.h"

using namespace std;
int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data;
	ListInit(&list);

	/*** 5개의 데이터 저장 ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 33);
	LInsert(&list, 33);

	
	/*** 저장된 데이터의 전체 출력 ***/
	//printf("현재 데이터의 수: %d \n", LCount(&list));
	cout << "현재 데이터의 수 : " << LCount(&list) << endl;
	if(LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		//printf("%d ", data);
		cout << data<<" ";
		while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회
			//printf("%d ", data);
			cout << data<<" ";
	}
	//printf("\n\n");
	cout << endl<<endl;
	/*** 숫자 22을 탐색하여 모두 삭제 ***/
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

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	//printf("현재 데이터의 수: %d \n", LCount(&list));
	cout << "현재 데이터의 수 : " << LCount(&list) << endl;
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