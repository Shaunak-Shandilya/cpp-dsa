

#include<iostream>

struct node {
    node* prev;
    int data;
    node* next;
};

void create_dll(int *data, int size) {
    // exception handling
    if (size < 1) {
        printf("size is too small");
        return;
    }

    node* head = new node;
    head->prev = nullptr;
    head->data = data[0];
    head->next = nullptr;

    node* last = head;
    for (int i = 1; i < size; i++) {
        // temp node creation
        node* temp = new node;
        temp->data = data[i];
        temp->prev = last;
        temp->next = nullptr;

        last->next = temp;
        last = temp;
    }
}

void display(node * head) {
    node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data <<std::endl;
        temp = temp->next;
    }
}


/*

 |\,5,nxt|<->|prev,1,nxt|<->|prev,4,nxt|<->|prev,2,nxt|<->|prev,8,nxt|<->|prev,0,nxt|<->|prev,7,nxt|<->|prev,3,/|
                
                mover           ahead

0         1             2               3               4              5              6              7              8

*/

// Flawed logic: The original insert function does not update the head pointer when inserting at position 0.
// Flawed logic: The original function assumes mover and ahead are always valid, which can cause crashes if pos is out of bounds or at the end.
// Flawed logic: The function does not handle the case where ahead is nullptr (inserting at the end).
// Flawed logic: The function does not check if mover is nullptr (pos out of bounds).

// FIXED: insert now takes node*& head to allow head updates.
// FIXED: Added nullptr checks for mover and ahead.
// FIXED: Handles insertion at head and at end correctly.
// FIXED: Added comments to highlight changes.



void insert(node*& head, int data, int pos) {
    if (pos < 0) return;

    node* temp = new node;
    temp->data = data;
    temp->prev = temp->next = nullptr;

    // HIGHLIGHT: Handle insertion at head (pos == 0)
    if (pos == 0) {
        temp->next = head;
        if (head) head->prev = temp;
        head = temp; // HIGHLIGHT: Update head pointer!
        return;
    }

    node* mover = head;
    for (int i = 0; i < pos - 1 && mover; i++) mover = mover->next;

    // HIGHLIGHT: Check if mover is nullptr (pos out of bounds)
    if (!mover) {
        // Flawed logic: original code would crash here
        delete temp;
        return;
    }

    temp->next = mover->next;
    temp->prev = mover;

    // HIGHLIGHT: Handle insertion at end (mover->next == nullptr)
    if (mover->next) {
        mover->next->prev = temp;
    }
    mover->next = temp;
}

