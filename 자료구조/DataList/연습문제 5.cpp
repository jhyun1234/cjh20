#include <iostream>
#include <algorithm>

using namespace std;
struct singly_ll_node
{
	int data; // 이 칸에 저장될 실제 정수 데이터
	singly_ll_node* next; // 다음 노드을 가리키는 포인터. 
	// 다음 칸이 없으면 nullptr이 된다.
};


class singly_ll // 단일 연결 리스트 전체를 관리하는 클래스
{
public:
	using node = singly_ll_node; // singly_ll_node 를 이제 'node' 라고 짧게 쓸 수 있다.
	using node_ptr = node*; // singly_ll_node* 를 이제 'node_ptr' 이라고 짧게 쓸 수 있다.


private:
	node_ptr head;
	// 리스트의 가장 첫 번째 노드를 가리키는 포인터. 리스트가 비어있으면 nullptr

public:
	// 리스트의 맨 앞에 새로운 값을 추가하는 함수
	void push_front(int val)
	{
		// 1.새로운 노드를 만든다. data에는 val 값을 넣고, 
		// next는 현재 head가 가리키는 곳을 가리키게 한다.
		// 만약 리스트가 비어있었다면 head는 nullptr이었을 것이고, 
		// new_node->next도 nullptr이 된다.
		auto new_node = new node{ val,NULL };
		if (head != NULL)
		{
			new_node->next = head;
		}
		// 2. 리스트의 시작점(head)이 방금 만든 새 노드를 가리키도록 변경한다.
		head = new_node;
	}
	// 리스트의 맨 앞 노드를 제거하는 함수
	void pop_front()
	{
		// 1. 현재 맨 앞 노드(삭제될 노드)의 주소를 first라는 임시 포인터에 저장한다.
		auto first = head;
		// 2. 리스트가 비어있지 않은지 확인한다. (head가 nullptr이 아닌지)
		if (head)
		{
			head = head->next;
			// 3. head를 현재 두 번째 노드(first->next)로 변경하여, 리스트의 시작점을 다음 노드로 옮긴다.
			delete first;
			// 4. 아까 저장해둔 이전 head 노드(first)를 메모리에서 삭제한다.
		}
	}


	// 리스트를 순회(하나씩 방문)하기 위한 이터레이터(반복자) 클래스이다. (for 루프 등에서 사용)
	// 이터레이터는 리스트의 특정 노드를 가리키는 역할을 한다.
	struct singly_LL_iterator
	{
	private:
		node_ptr ptr; // 현재 이터레이터가 가리키고 있는 노드의 주소를 저장하는 포인터

	public:
		// 생성자: 특정 노드 포인터(p)를 받아서 이터레이터를 만든다.
		singly_LL_iterator(node_ptr p) :ptr(p) {}

		// 역참조 연산자 (*): 이터레이터가 가리키는 노드의 data 값에 접근하게 해준다. (값을 읽거나 변경)
		int& operator*() { return ptr->data; }
		// 현재 가리키는 노드의 포인터를 반환하는 함수
		node_ptr get() { return ptr; }

		// 전위 증가 연산자 (++it): 이터레이터를 다음 노드로 이동시키고, 이동된 '후'의 이터레이터를 반환한다.
		singly_LL_iterator& operator++() // 선행 증가
		{
			ptr = ptr->next; // 내부 포인터를 다음 노드로 이동
			return *this;   // 변경된 이터레이터 자신을 반환
		}

		// 후위 증가 연산자 (it++): 이터레이터를 다음 노드로 이동시키지만, 이동하기 '전'의 이터레이터를 반환한다.
		singly_LL_iterator operator++(int) // 후행 증가 (int는 전위와 구분하기 위한 더미 파라미터)
		{
			singly_LL_iterator result = *this; // 현재 상태(변경 전)를 복사해서 저장
			++(*this); // 전위 증가 연산자를 호출하여 실제로 다음 노드로 이동
			return result; // 저장해둔 변경 전 상태를 반환
		}

		// 비교 연산자 (==): 두 이터레이터가 같은 노드를 가리키는지 확인한다.
		friend bool operator==(const singly_LL_iterator& left,
			const singly_LL_iterator& right)
		{
			return left.ptr == right.ptr; // 내부 포인터가 같으면 같은 이터레이터로 취급
		}

		// 비교 연산자 (!=): 두 이터레이터가 다른 노드를 가리키는지 확인한다.
		friend bool operator!=(const singly_LL_iterator& left,
			const singly_LL_iterator& right)
		{
			// return !(left == right); 와 같음
			return left.ptr != right.ptr; 
		}

	};
	// 리스트의 시작(첫 번째 노드)을 가리키는 이터레이터를 반환하는 함수 (for 루프에서 사용)
	singly_LL_iterator begin() { return singly_LL_iterator(head); }
	// 리스트의 끝(마지막 노드 다음, 즉 nullptr)을 가리키는 이터레이터를 반환하는 함수 (for 루프에서 사용)
	singly_LL_iterator end() { return singly_LL_iterator(nullptr); } // 리스트의 끝은 nullptr로 표현

	// const 버전: 리스트의 내용을 변경하지 않는 경우에 사용되는 begin/end 함수
	singly_LL_iterator begin() const { return singly_LL_iterator(head); }
	singly_LL_iterator end() const { return singly_LL_iterator(nullptr); }

	// 기본 생성자: 컴파일러가 자동으로 만들어주는 것을 사용한다.
	singly_ll() = default;

	// 복사 생성자: 다른 리스트(other)를 받아서 똑같은 내용을 가진 새 리스트를 만든다. (깊은 복사)
	singly_ll(const singly_ll& other) : head(NULL) // 새 리스트의 head를 NULL로 초기화
	{
		// 1. 복사할 원본 리스트(other)가 비어있지 않은지 확인한다.
		if (other.head)
		{
			// 2. 새 리스트의 첫 번째 노드를 임시로 만든다 (데이터는 0, next는 nullptr).
			head = new node{ 0,NULL };
			// 3. 새 리스트에서 현재 마지막으로 추가된 노드를 가리킬 포인터 cur (처음엔 head)
			auto cur = head;
			// 4. 원본 리스트를 순회할 이터레이터 'it' (원본의 첫 번째 노드에서 시작)
			auto it = other.begin();
			// 5. 무한 루프 시작 (내부에서 break로 탈출)
			while (true)
			{
				// 6. 현재 원본 노드(it)의 데이터를 새 리스트의 현재 노드(cur)에 복사한다. (첫 노드의 0을 덮어씀)
				cur->data = *it;
				// 7. 원본 리스트의 다음 노드를 가리키는 임시 이터레이터 tmp를 만든다.
				auto tmp = it;
				++tmp;
				// 8. 만약 원본 리스트의 다음 노드가 끝(nullptr)이라면, 복사가 끝난 것이므로 루프를 탈출한다.
				if (tmp == other.end())
					break;
				// 9. 새 리스트에 다음 노드를 만들 준비를 한다. 임시 노드(데이터 0)를 만들어 현재 노드(cur)의 next에 연결한다.
				cur->next = new node{ 0,NULL };
				// 10. 새 리스트의 현재 노드(cur)를 방금 만든 다음 노드로 이동한다.
				cur = cur->next;
				// 11. 원본 리스트의 이터레이터(it)도 다음 노드로 이동한다.
				it = tmp;
			}
		}
	}
	// 초기화 리스트 생성자: 중괄호 {1, 2, 3} 형태로 리스트를 만들 수 있게 해준다.
	singly_ll(const initializer_list<int>& ilist) :head(NULL) // 새 리스트의 head를 nullptr로 초기화
	{
		// 1. 초기화 리스트({1, 2, 3})를 뒤에서부터(rbegin) 거꾸로(rend) 순회한다. (즉, 3, 2, 1 순서)
		for (auto it = rbegin(ilist); it != rend(ilist); it++)
			// 2. 각 원소를 리스트의 맨 앞에 추가(push_front)한다,
			// (3 추가 -> 2 추가 -> 1 추가 => 결과적으로 1 -> 2 -> 3 순서의 리스트가 만들어짐)
			push_front(*it);
	}

};

int main()
{
	// 초기화 리스트 생성자를 이용해 sll 리스트 생성: 1 -> 2 -> 3
	singly_ll sll = { 1, 2, 3 };
	// push_front 함수를 이용해 맨 앞에 0 추가: 0 -> 1 -> 2 -> 3
	sll.push_front(0);
	sll.push_front(1);
	sll.push_front(2);
	cout << "첫 번째 리스트 : ";
	// 범위 기반 for 루프: sll 리스트의 처음(begin)부터 끝(end)까지 순회
	// 내부적으로 begin(), end(), ++, * 연산자를 사용
	for (auto i : sll)
		// 각 노드의 데이터(i)를 출력하고 한 칸 띄움
		cout << i << " "; // 출력 0 1 2 3
	cout << endl;

	// 복사 생성자를 이용해 sll 리스트를 sll2 리스트로 깊은 복사
	// sll2는 sll과 똑같은 내용(0 -> 1 -> 2 -> 3)을 가지지만, 서로 다른 메모리 공간을 사용
	auto sll2 = sll;
	// sll2 리스트의 맨 앞에 -1 추가: -1 -> 0 -> 1 -> 2 -> 3
	sll2.push_front(-1);
	sll2.push_front(-2);
	sll2.push_front(-3);
	cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가";
	for (auto i : sll2)
		cout << i << ' '; // 출력 -1 0 1 2 3
	cout << endl;

	cout << "깊은 복사 후 첫 번째 리스트 : ";
	// sll2를 변경한 것이 sll에 영향을 주지 않았는지 확인 (깊은 복사 확인)
	for (auto i : sll)
		cout << i << ' '; // 출력 0 1 2 3
	cout << endl;
}