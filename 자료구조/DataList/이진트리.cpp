#include <iostream>

using namespace std;
// 노드 구조체 정의
struct Node {
    int data; // 노드가 저장하는 데이터 값
    Node* left; // 왼쪽 자식 노드를 가리키는 포인터
    Node* right; // 오른쪽 자식 노드를 가리키는 포인터

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    // 소멸자: 노드 메모리 해제 확인용
    ~Node() { cout << "Node " << data << " deleted" << endl; }
};

// 이진 탐색 트리 클래스 정의
class BST
{
private:
    Node* root; // 트리의 루트 노드를 가리키는 포인터

    // 노드 삽입 함수
    // node : 현재 탐색 중인 서브트리의 루트
    // value : 삽입할 값
    // 반환값 : 삽입 후 변경된 서브트리의 루트 노드
    Node* insertNode(Node* node, int value)
    {
        if (node == nullptr)
        {
            cout << "노드 삽입 : " << value << endl;
            return new Node(value); // 새 노드를 생성하여 반환
        }

        // 현재 노드와 값 비교하여 이동
        if (value < node->data)
        {
            // 값이 현재 노드보다 작으면 왼쪽 서브트리로 이동 및 삽입
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            // 값이 현재 노드보다 크면 오른쪽 서브트리로 이동 및 삽입
            node->right = insertNode(node->right, value);
        }
        // else value == node->data 중복된 값은 삽입하지 않고 무시
        return node; // 변경되지 않은 현재 노드 반환
    }

    // 노드 삭제 함수
    // node : 현재 탐색 중인 서브트리의 루트
    // value : 삭제할 값
    // 반환값 : 삭제 후 변경된 서브트리의 루트 노드

    Node* deleteNode(Node* node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // 현재 노드와 값 비교하여 삭제할 노드 탐색
        if (value < node->data)
        {
            // 삭제할 값이 현재 노드보다 작으면 왼쪽 서브트리에서 재귀 호출
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            // 삭제할 값이 현재 노드보다 크면 오른쪽 서브트리에서 재귀 호출
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // 삭제할 노드를 찾았을 때 value == node -> data;

            // 자식 노드가 없거나 하나만 있는 경우
            if (node->left == nullptr)
            {
                // 왼쪽 자식이 없으면 오른쪽 자식을 반환
                Node* temp = node->right;
                cout << "노드 삭제" << node->data << endl;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                cout << "노드 삭제" << node->data << endl;
                delete node;
                return temp;
            }

            // 자식 노드가 두 개 있는 경우
            // 오른쪽 서브트리에서 가장 작은 값을 찾아서 대체
            Node* temp = MinNode(node->right);

            // 가장 작은 값의 값을 현재 노드에 복사
            cout << "노드 삭제 (2개의 자식)" << node->data << " " << temp->data << endl;
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node; // 변경되지 않은 현재 노드 반환
    }

    // 서브트리에서 가장 작은 값(가장 왼쪽 노드)을 가진 노드를 찾는 함수
    // node: 탐색을 시작할 서브트리의 루트
    // 반환값: 가장 작은 값을 가진 노드 포인터 
    Node* MinNode(Node* node)
    {
        Node* current = node;
        // 가장 왼쪽 노드까지 이동
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    // 서브트리에서 특정 값을 가진 노드를 찾는 함수
    // node: 현재 탐색 중인 서브트리의 루트
    // value: 찾으려는 값
    // 반환값: 값을 가진 노드 포인터 
    Node* searchNode(Node* node, int value)
    {
        if (node == nullptr || node->data == value)
        {
            return node;
        }
        // 현재 노드 값과 비교하여 왼쪽 또는 오른쪽으로 이동
        if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }

    }
    // 중위 순회 헬퍼 함수
    // node : 현재 방문 중인 노드
    void inorderTrav(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTrav(node->left);
        cout << node->data << " ";
        inorderTrav(node->right);
    }


public:

    // 트리 초기화
    BST() : root(nullptr)
    {

    }
    ~BST() {}

    // 노드 삽입
    void insert(int value)
    {
        root = insertNode(root, value); // 루트 노드부터 재귀 삽입 시작
    }
    // 노드 삭제
    void deleteNode(int value)
    {
        root = deleteNode(root, value); // 루트 노드부터 재귀 삭제 시작
    }

    // 노드 탐색
    // value : 찾으려는 값
    // 반환값 : 값이 존재하면 true, 없으면 false
    bool search(int value)
    {
        Node* found = searchNode(root, value);
        if (found)
        {
            cout << "값 " << value << " 찾음 " << endl;
            return true;
        }
        else
        {
            cout << "값 " << value << " 못찾음 " << endl;
            return false;
        }
    }

    // 중위 순회
    void inorder()
    {
        cout << "BST inorder";
        inorderTrav(root);
        cout << endl;
    }

    // 추가 : 트리가 비어있는지 확인하는 함수
    bool isEmpty()
    {
        return root == nullptr;
    }

};


int main()
{

    BST bst;
    cout << "노드 삽입" << endl;
    bst.insert(30);
    bst.insert(40);
    bst.insert(20);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);

    cout << endl;
    bst.inorder();

    cout << "노드 탐색" << endl;
    bst.search(40);
    bst.search(50);
    bst.search(30);

    cout << "노드 삭제 20" << endl;
    bst.deleteNode(20);
    bst.inorder();

    cout << "노드 삭제 25" << endl;
    bst.deleteNode(25);
    bst.inorder();

    cout << "노드 삭제 35" << endl;
    bst.deleteNode(35);
    bst.inorder();




    return 0;
}

