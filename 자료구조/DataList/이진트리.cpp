#include <iostream>

using namespace std;
// 노드 구조체 정의
struct Node {
    int data;
    Node* left;
    Node* right;

   
};

// 이진 탐색 트리 클래스 정의
class BST
{
private:
    Node* root;

public:
    Node* searchNode(Node* root, int key) // 반복적인 탐색
    {
        while (root != NULL)
        {
            if (root->data == key) return root;
            else if (root->data > key)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return NULL;
    }
    Node* searchNode(Node* root, int key) // 순환적인 탐색
    {
        if (root == NULL) return NULL;
        if (root->data == key) return root;
        else if (root->data > key)
            return searchNode(root->left, key);
        else
            return searchNode(root->right, key);
    }

    void insertNode(Node** root, int key)
    {
        Node* parentNode = NULL, * currentNode, * newNode;
        currentNode = *root;
        // 키가 삽입되어야 할 위치를 반복적으로 찾는 과정
        while (currentNode != NULL)
        {
            if (currentNode->data == key)
                return;
            parentNode = currentNode;
            if (currentNode->data > key)
            {
                currentNode = currentNode->left;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }

        newNode = new Node;
        if (newNode == NULL)
        {
            return;
        }
        newNode->data = key;
        newNode->left = newNode->right = NULL;

        if (parentNode != NULL)
        {
            if (parentNode->data > key)
            {
                parentNode->left = newNode;
            }
            else
            {
                parentNode->right = newNode;
            }

        }
        else
        {
            *root = newNode;
        }
    }
};

// 예시 사용법
int main() {
    

    return 0;
}