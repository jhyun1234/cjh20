#include <iostream>

using namespace std;
// ��� ����ü ����
struct Node {
    int data;
    Node* left;
    Node* right;

   
};

// ���� Ž�� Ʈ�� Ŭ���� ����
class BST
{
private:
    Node* root;

public:
    Node* searchNode(Node* root, int key) // �ݺ����� Ž��
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
    Node* searchNode(Node* root, int key) // ��ȯ���� Ž��
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
        // Ű�� ���ԵǾ�� �� ��ġ�� �ݺ������� ã�� ����
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

// ���� ����
int main() {
    

    return 0;
}