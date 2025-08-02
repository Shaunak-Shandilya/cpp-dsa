#include <iostream>

using namespace std;

// Linked List node

class Node{

public:
	int data;
	Node* next;
};
// Hash Table
class HashTable{

public:
	Node** HT;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	~HashTable();
};

HashTable::HashTable() {
	HT = new Node* [10];
	for (int i=0; i<10; i++){
		HT[i] = nullptr;
	}
}

int HashTable::hash(int key) {
	return key % 10;
}

void HashTable::Insert(int key) {
	int hIdx = hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = nullptr;
	// Case: No nodes in the linked list
	if (HT[hIdx] == nullptr){
		HT[hIdx] = t;
	} else {
		Node* p = HT[hIdx];
		Node *q=HT[hIdx];
		// Traverse to find insert position
		while (p && p->data < key){
			q=p;
			p = p->next;
		}
		// Case: insert position is first
		if (q == HT[hIdx]){
			t->next = HT[hIdx];
			HT[hIdx] = t;
		} else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int HashTable::Search(int key) {
	int hIdx = hash(key);
	Node* p = HT[hIdx];
	while (p){
		if (p->data == key){
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable() {
	for (int i=0; i<10; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int main() {
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for (int i=0; i<n; i++){
		H.Insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}

//--------------------------------------------------------------------

#include <iostream>
#define SIZE 10

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key){
    return key % SIZE;
}
 
int LinearProbe(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i) % SIZE] != 0){
        i++;
    }
    return (idx + i) % SIZE;
}
 
void Insert(int H[], int key){
    int idx = Hash(key);
 
    if (H[idx] != 0){
        idx = LinearProbe(H, key);
    }
    H[idx] = key;
}
 
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i) % SIZE] != key){
        i++;
        if (H[(idx + i) % SIZE] == 0){
            return -1;
        }
    }
    return (idx + i) % SIZE;
}
 
 
int main() {
 
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
 
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;
 
    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
 
    return 0;
}

//--------------------------------------------------------------------

#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key){
    return key % SIZE;
}
 
int PrimeHash(int key){
    return PRIME - (key % PRIME);
}
 
int DoubleHash(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0){
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}
 
void Insert(int H[], int key){
    int idx = Hash(key);
 
    if (H[idx] != 0){
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}
 
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key){
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0){
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
}
 
 
int main() {
 
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
 
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;
 
    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
 
    return 0;
}

//--------------------------------------------------------------------

#include <iostream>
#define SIZE 10

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key){
    return key % SIZE;
}
 
int QuadraticProbe(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i*i) % SIZE] != 0){
        i++;
    }
    return (idx + i*i) % SIZE;
}
 
void Insert(int H[], int key){
    int idx = Hash(key);
 
    if (H[idx] != 0){
        idx = QuadraticProbe(H, key);
    }
    H[idx] = key;
}
 
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i*i) % SIZE] != key){
        i++;
        if (H[(idx + i*i) % SIZE] == 0){
            return -1;
        }
    }
    return (idx + i*i) % SIZE;
}
 
 
int main() {
 
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
 
    int index = Search(HT, 25);
    cout << "key found at: " << index << endl;
 
    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
 
    return 0;
}
