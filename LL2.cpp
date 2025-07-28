#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList(int arr[], int size) : head(nullptr) {
		if (size <= 0) return;

		head = new Node;
		head->data = arr[0];
		head->next = nullptr;

		Node* prev = head;

		for (int i = 1; i < size; i++) {
			Node* temp = new Node;
			temp->data = arr[i];
			temp->next = nullptr;

			prev->next = temp;
			prev = temp;
		}
	}

	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	void Display() {
		Node* display = head;
		while (display != nullptr) {
			std::cout << display->data << std::endl;
			display = display->next;
		}
	}
	
	void Insert(int data, int pos) {
		if (pos < 0) return; // Guard against negative positions

		if (pos == 0) {
			Node* temp = new Node;
			temp->data = data;
			temp->next = head;
			head = temp;
		} else {
			Node* temp = head;
			for (int i = 1; i < pos; i++) {
				if (temp == nullptr) return; // Out of bounds
				temp = temp->next;
			}
			if (temp == nullptr) return; // Out of bounds

			Node* newnode = new Node;
			newnode->data = data;
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
};

int main() {
	int arr[] = {10,20,30,40,50,60,70,80,90,100};
	LinkedList* l1 = new LinkedList(arr, sizeof(arr) / sizeof(arr[0]));

	l1->Display();
	delete l1;
}
