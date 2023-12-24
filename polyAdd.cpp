#include <iostream>
using namespace std;

struct Node {
    int coef;
    int pow;
    Node* next;

    Node(int c, int p) : coef(c), pow(p), next(nullptr) {}
};

void insert(Node*& head, int c, int p) {
    Node* newNode = new Node(c, p);

    if (!head) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void display(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->coef << "x^" << curr->pow;
        if (curr->next) {
            cout << " + ";
        }
        curr = curr->next;
    }
    cout << endl;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* curr1 = poly1;
    Node* curr2 = poly2;

    while (curr1 && curr2) {
        if (curr1->pow == curr2->pow) {
            insert(result, curr1->coef + curr2->coef, curr1->pow);
            curr1 = curr1->next;
            curr2 = curr2->next;
        } else if (curr1->pow > curr2->pow) {
            insert(result, curr1->coef, curr1->pow);
            curr1 = curr1->next;
        } else {
            insert(result, curr2->coef, curr2->pow);
            curr2 = curr2->next;
        }
    }

    while (curr1) {
        insert(result, curr1->coef, curr1->pow);
        curr1 = curr1->next;
    }

    while (curr2) {
        insert(result, curr2->coef, curr2->pow);
        curr2 = curr2->next;
    }
    return result;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    int n1, n2;
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int c, p;
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> c >> p;
        insert(poly1, c, p);
    }

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int c, p;
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> c >> p;
        insert(poly2, c, p);
    }

    Node* result = addPolynomials(poly1, poly2);

    cout << "Resulting Polynomial: ";
    display(result);

    return 0;
}
