#include <iostream>

using namespace std;
// ��� ����ü ����
struct Node {
    int data; // ��尡 �����ϴ� ������ ��
    Node* left; // ���� �ڽ� ��带 ����Ű�� ������
    Node* right; // ������ �ڽ� ��带 ����Ű�� ������

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    // �Ҹ���: ��� �޸� ���� Ȯ�ο�
    ~Node() { cout << "Node " << data << " deleted" << endl; }
};

// ���� Ž�� Ʈ�� Ŭ���� ����
class BST
{
private:
    Node* root; // Ʈ���� ��Ʈ ��带 ����Ű�� ������

    // ��� ���� �Լ�
    // node : ���� Ž�� ���� ����Ʈ���� ��Ʈ
    // value : ������ ��
    // ��ȯ�� : ���� �� ����� ����Ʈ���� ��Ʈ ���
    Node* insertNode(Node* node, int value)
    {
        if (node == nullptr)
        {
            cout << "��� ���� : " << value << endl;
            return new Node(value); // �� ��带 �����Ͽ� ��ȯ
        }

        // ���� ���� �� ���Ͽ� �̵�
        if (value < node->data)
        {
            // ���� ���� ��庸�� ������ ���� ����Ʈ���� �̵� �� ����
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            // ���� ���� ��庸�� ũ�� ������ ����Ʈ���� �̵� �� ����
            node->right = insertNode(node->right, value);
        }
        // else value == node->data �ߺ��� ���� �������� �ʰ� ����
        return node; // ������� ���� ���� ��� ��ȯ
    }

    // ��� ���� �Լ�
    // node : ���� Ž�� ���� ����Ʈ���� ��Ʈ
    // value : ������ ��
    // ��ȯ�� : ���� �� ����� ����Ʈ���� ��Ʈ ���

    Node* deleteNode(Node* node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // ���� ���� �� ���Ͽ� ������ ��� Ž��
        if (value < node->data)
        {
            // ������ ���� ���� ��庸�� ������ ���� ����Ʈ������ ��� ȣ��
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            // ������ ���� ���� ��庸�� ũ�� ������ ����Ʈ������ ��� ȣ��
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // ������ ��带 ã���� �� value == node -> data;

            // �ڽ� ��尡 ���ų� �ϳ��� �ִ� ���
            if (node->left == nullptr)
            {
                // ���� �ڽ��� ������ ������ �ڽ��� ��ȯ
                Node* temp = node->right;
                cout << "��� ����" << node->data << endl;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node* temp = node->left;
                cout << "��� ����" << node->data << endl;
                delete node;
                return temp;
            }

            // �ڽ� ��尡 �� �� �ִ� ���
            // ������ ����Ʈ������ ���� ���� ���� ã�Ƽ� ��ü
            Node* temp = MinNode(node->right);

            // ���� ���� ���� ���� ���� ��忡 ����
            cout << "��� ���� (2���� �ڽ�)" << node->data << " " << temp->data << endl;
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node; // ������� ���� ���� ��� ��ȯ
    }

    // ����Ʈ������ ���� ���� ��(���� ���� ���)�� ���� ��带 ã�� �Լ�
    // node: Ž���� ������ ����Ʈ���� ��Ʈ
    // ��ȯ��: ���� ���� ���� ���� ��� ������ 
    Node* MinNode(Node* node)
    {
        Node* current = node;
        // ���� ���� ������ �̵�
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    // ����Ʈ������ Ư�� ���� ���� ��带 ã�� �Լ�
    // node: ���� Ž�� ���� ����Ʈ���� ��Ʈ
    // value: ã������ ��
    // ��ȯ��: ���� ���� ��� ������ 
    Node* searchNode(Node* node, int value)
    {
        if (node == nullptr || node->data == value)
        {
            return node;
        }
        // ���� ��� ���� ���Ͽ� ���� �Ǵ� ���������� �̵�
        if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }

    }
    // ���� ��ȸ ���� �Լ�
    // node : ���� �湮 ���� ���
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

    // Ʈ�� �ʱ�ȭ
    BST() : root(nullptr)
    {

    }
    ~BST() {}

    // ��� ����
    void insert(int value)
    {
        root = insertNode(root, value); // ��Ʈ ������ ��� ���� ����
    }
    // ��� ����
    void deleteNode(int value)
    {
        root = deleteNode(root, value); // ��Ʈ ������ ��� ���� ����
    }

    // ��� Ž��
    // value : ã������ ��
    // ��ȯ�� : ���� �����ϸ� true, ������ false
    bool search(int value)
    {
        Node* found = searchNode(root, value);
        if (found)
        {
            cout << "�� " << value << " ã�� " << endl;
            return true;
        }
        else
        {
            cout << "�� " << value << " ��ã�� " << endl;
            return false;
        }
    }

    // ���� ��ȸ
    void inorder()
    {
        cout << "BST inorder";
        inorderTrav(root);
        cout << endl;
    }

    // �߰� : Ʈ���� ����ִ��� Ȯ���ϴ� �Լ�
    bool isEmpty()
    {
        return root == nullptr;
    }

};


int main()
{

    BST bst;
    cout << "��� ����" << endl;
    bst.insert(30);
    bst.insert(40);
    bst.insert(20);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);

    cout << endl;
    bst.inorder();

    cout << "��� Ž��" << endl;
    bst.search(40);
    bst.search(50);
    bst.search(30);

    cout << "��� ���� 20" << endl;
    bst.deleteNode(20);
    bst.inorder();

    cout << "��� ���� 25" << endl;
    bst.deleteNode(25);
    bst.inorder();

    cout << "��� ���� 35" << endl;
    bst.deleteNode(35);
    bst.inorder();




    return 0;
}

