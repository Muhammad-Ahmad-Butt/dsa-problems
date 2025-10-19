#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

void insert_end(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse_iterative() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;     // save next
        curr->next = prev;     // reverse current link
        prev = curr;           // move prev ahead
        curr = next;           // move curr ahead
    }

    head = prev; // new head is the last node
}

int main() {
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);

    cout << "Original List: ";
    display();

    reverse_iterative();
    cout << "Reversed List (Iterative): ";
    display();
}
