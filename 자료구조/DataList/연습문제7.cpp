#include<iostream>
#include<queue>
#include<string>

using namespace std;
struct Node
{
	string position; // 직책입력 문자열
	Node* first;
	Node* second;
};
struct tree
{
	Node* root;

	// static 함수: 이 함수는 특정 tree '객체'에 속하는 것이 아니라, tree '구조체 자체'에 속한다.
	// 따라서 tree::create_structure() 와 같이 클래스(구조체) 이름으로 바로 호출할 수 있다.
	static tree create_structure(const string& pos) // 트리의 루트 노드를 생성하는 함수
	{
		tree tree; // tree 타입의 지역 변수 tree를 생성한다.
		tree.root = new Node{ pos,NULL,NULL }; // 새로 생성한 Node를 tree의 root로 설정한다.
		return tree; // 생성된 tree 객체를 반환
	}


	// 트리를 탐색하여 특정 값을 가진 노드를 찾는 함수
	// static 함수이므로 tree::find() 와 같이 호출한다.
	static Node* find(Node* root, const string& value)
	{				// 탐색을 시작할 노드 포인터 , 찾을 값

		// 현재 노드가 NULL이면(해당 경로에 노드가 없으면) 값을 찾지 못한 것이므로 NULL 반환 
		if (root == NULL)
			return NULL;

		// 현재 노드의 position 값이 찾으려는 값과 일치하면 노드를 찾는 것이므로 현재 노드 포인터 반환
		if (root->position == value)
			return root;

		// 왼쪽 서브트리를 탐색을 시도
		// tree::find(root->first, value): 현재 노드의 first 자식을 루트로 하여 find 함수를 재귀 호출한다.
		// auto firstFound: 반환되는 Node* 타입의 포인터를 저장한다.
		auto firstFound = tree::find(root->first, value);

		// 만약 first 서브트리에서 값을 찾았다면
		if (firstFound != NULL)
			return firstFound; // 찾은 노드 포인터를 즉시 반환하고 탐색을 종료한다.
		
		// first 서브트리에서 찾지 못했다면, 오른쪽(second) 서브트리에서 탐색을 시도 찾으면 값을 반환하고 탐색 종료
		return tree::find(root->second, value);
	}

	// 객체 멤버 함수는 객체가 생성된 후, 해당 객체에 속하여 동작한다.
	bool addSubordinate(const string& manager, const string& subordinate) // manager 직책 아래 subordinate 직책 추가
	{
		// 먼저 manager 부모에 해당하는 노드를 트리에서 찾는다.
		// find 함수는 static이므로 tree::find() 형태로 호출하고, 이 트리의 root부터 탐색 시작한다.
		auto managerNode = tree::find(root, manager);

		// manager 노드를 찾지 못했다면
		if (!managerNode) // managerNode가 NULL인 경우
		{
			cout << manager << "을(를) 찾을 수 없습니다 : " << endl;
			return false;
		}

		// manager 노드를 찾았지만 이미 자식이 두 명 모두 더 있다면 더 추가할 수 없다.
		if (managerNode->first && managerNode->second) // first와 second 포인터 둘 다 NULL이 아닌 경우
		{
			cout << manager <<  " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << endl;
			return false;
		}
		
		// manager 아래에 추가할 자리가 있다면 subordinate 노드를 생성하고 연결한다.
		if (!managerNode->first) // manager의 first 자리가 비어있다면 (first 포인터가 NULL이라면)
		{
			// 새로운 Node를 생성하고 subordinate 직책으로 초기화하여 first 자식으로 연결한다.
			managerNode->first = new Node{ subordinate,NULL,NULL };
		}
		else // manager의 first 자리가 차 있다면 (second 자리가 비어있음)
		{

			managerNode->second = new Node{ subordinate,NULL,NULL };
		}
		cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << endl;

		return true; // 추가 성공을 알림

	}

	// 트리를 레벨 순서(층별 순서)로 순회하며 노드를 방문하는 함수
	// Queue 자료구조를	사용하며 구현
	static void levelOrder(Node* start) // 순회를 시작할 노드 포인터(start)
	{
		// 시작 노드가 NULL이면 순회할 트리가 없으므로 종료
		if (!start)
			return;
		// Node 포인터를 저장할 큐(Queue)를 생성.
		queue<Node*> q;
		// 순회 시작 노드를 큐에 넣는다.
		q.push(start);

		// 큐가 빌 때까지 반복. 큐가 비면 모든 노드를 방문한 것이다.
		while (!q.empty())
		{
			// 현재 큐에 들어있는 노드의 개수를 저장한다. 이 개수는 현재 레벨에 있는	노드의 수이다.
			int size = q.size();

			// 현재 레벨에 있는 모든 노드를 처리하기 위해 size 만큼 반복한다.
			for (int i = 0; i < size; i++)
			{
				// 큐의 맨 앞에 있는 노드를 가져온다.(제거는 하지 않음)
				auto current = q.front();
				// 큐에서 맨 앞의 노드를 제거한다.
				q.pop();

				// 현재 노드를 방문하여 처리한다.(position 값을 출력한다.)
				cout << current->position << " , ";

				// 현재 노드의 first 자식이 있다면 큐의 맨 뒤에 넣는다.(다음 레벨에서 방문 예정)
				if (current->first)
					q.push(current->first);
				// 현재 노드의 second 자식이 있다면 큐의 맨 뒤에 넣는다.(다음 레벨에서 방문 예정)
				if (current->second)
					q.push(current->second);
			}
			// 현재 레벨의 모든 노드 처리가 끝나면 줄바꿈하여 다음 레벨 노드 출력을 구분한다.
			cout << endl;
		}
	}




};
int main()
{

	auto tree = tree::create_structure("CEO");

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	tree.levelOrder(tree.root);
}
