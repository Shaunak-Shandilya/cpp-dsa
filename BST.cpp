#include <iostream>
#include <stdio.h>
using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node** Q;
public:
    Queue() {
        front = rear = -1;
        size = 10;
        Q = new Node * [size];
    }
    Queue(int size) {
        front = rear = -1;
        this->size = size;
        Q = new Node * [this->size];
        // [] creates dynamic array of pointers to node
        // Q is declared as Node **Q which makes it a pointer to pointers (array of ptrs) to nodes
        // Q points to first element of the array similar to how an array points at 
        // Q behaves like array
    }
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty() {
        return front == rear; //if iterators are equal return empty
    }
    ~Queue() {
        delete[] Q;
    }
};

void Queue::enqueue(Node* x) {
    if (rear == size - 1)
        printf("Queue Full\n");
    else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() {
    Node* x = NULL;
    if (front == rear)
        printf("Queue is Empty\n");
    else {
        front++;
        x = Q[front];
    }
    return x;
}

class Tree {
    Node* root;
public:
    Tree() {
        root = NULL;
    }
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Inorder() { Inorder(root); }
    void Postorder() { Postorder(root); }
    void Levelorder() { Levelorder(root); }
    int Height() { return Height(root); }

private:
    void Preorder(Node* p);
    void Inorder(Node* p);
    void Postorder(Node* p);
    void Levelorder(Node* p);
    int Height(Node* root);
};

void Tree::CreateTree() {
    Node* p, * t;
    int x;
    Queue q(100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;

    q.enqueue(root);

    while (!q.isEmpty()) {
        p = q.dequeue();

        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node* p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(Node* p) {
    Queue q(100);
    if (!p) return;

    printf("%d ", p->data);
    q.enqueue(p);

    while (!q.isEmpty()) {
        p = q.dequeue();

        if (p->lchild) {
            printf("%d ", p->lchild->data);
            q.enqueue(p->lchild);
        }

        if (p->rchild) {
            printf("%d ", p->rchild->data);
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node* root) {
    int x = 0, y = 0;
    if (root == NULL)
        return 0;

    x = Height(root->lchild);
    y = Height(root->rchild);
    return x > y ? x + 1 : y + 1;
}

int main() {
    Tree t;
    t.CreateTree();

    cout << "\nPreorder: ";
    t.Preorder();

    cout << "\nInorder: ";
    t.Inorder();

    cout << "\nPostorder: ";
    t.Postorder();

    cout << "\nLevel Order: ";
    t.Levelorder();

    cout << "\nHeight of Tree: " << t.Height() << endl;

    return 0;
}
