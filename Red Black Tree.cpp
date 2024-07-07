#include<iostream>
using namespace std;

enum Color{RED,BLACK};

struct Node
{
    int data;
    Color color;
    Node *left,*right,*parent;

    Node(int data):data(data),parent(nullptr),left(nullptr),right(nullptr),color(RED){}
};

class RedBlackTree

{
private:
    Node *root;

    void rotateLeft(Node *&x)
     {
        Node *y=x->right;
        x->right=y->left;
        if (y->left!=nullptr)
            y->left->parent = x;
        y->parent=x->parent;
        if (x->parent==nullptr)
            root=y;
        else if(x==x->parent->left)
            x->parent->left=y;
        else
            x->parent->right=y;
        y->left=x;
        x->parent=y;
    }

    void rotateRight(Node *&x)
    {
        Node *y=x->left;
        x->left=y->right;
        if (y->right!=nullptr)
            y->right->parent=x;
        y->parent=x->parent;
        if (x->parent==nullptr)
            root=y;
        else if(x==x->parent->right)
            x->parent->right=y;
        else
            x->parent->left=y;
        y->right=x;
        x->parent=y;
    }

    void fixInsertRBTree(Node *&z)
    {
        while (z!=root&&z->parent->color==RED)
            {
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateRight(z->parent->parent);
                }
            } else {
                Node *y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void inorderHelper(Node *root) {
        if (root == nullptr) return;
        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(const int &data) {
        Node *node = new Node(data);
        Node *y = nullptr;
        Node *x = root;

        while (x != nullptr) {
            y = x;
            if (node->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        node->parent=y;
        if (y==nullptr)
            root=node;
        else if(node->data<y->data)
            y->left=node;
        else
            y->right=node;
    fixInsertRBTree(node);
    }
    void inorder()
    {
        inorderHelper(root);
        cout<<endl;
    }
};

int main() {
    RedBlackTree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    cout<<"Inorder Traversal of Red-Black Tree:\n";
    tree.inorder();
    return 0;
}
