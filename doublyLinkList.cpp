#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insertAtBeginning(int new_data) {
    struct Node* new_node = createNode(new_data);

    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void insertAtEnd(int new_data) {
    struct Node* new_node = createNode(new_data);

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertAtPosition(int new_data, int position) {
    if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1 || head == NULL) {
        insertAtBeginning(new_data);
        return;
    }

    struct Node* new_node = createNode(new_data);
    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position exceeds the length of the list. Node added at the end." << endl;
        insertAtEnd(new_data);
    } else {
        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
    }
}

void display() {
    struct Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    insertAtBeginning(9);
    insertAtBeginning(5);
    insertAtEnd(6);
    insertAtEnd(2);
    cout << "The doubly linked list is: ";
    display();

    insertAtPosition(7, 2); // Insert at a defined position
    cout << "After inserting at position 2: ";
    display();

    insertAtPosition(8, 6); // Position exceeds the length, should insert at the end
    cout << "After inserting at position 6: ";
    display();

    return 0;
}
