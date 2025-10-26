#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* head = NULL;
Node* tail = NULL;

void push_front(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

void push_back(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pop_front(){
    if(head == NULL){
        cout << "list is empty";
        return;
    } else {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
}

void pop_back(){
    if(head == NULL){
        cout << "Empty list";
        return;
    } else {
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
}

void insert_middle(int val, int pos){
    Node* newNode = new Node(val);
    if(pos < 0){
        cout << "invalid position";
        return;
    } else if(pos == 0){
        push_front(val);
        return;
    } else {
        Node* temp = head;
        for(int i = 0; i < pos-1; i++){
            if(temp == NULL) return;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display_list(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int search(int key){
    Node* temp = head;
    int index = 0;
    while(temp != NULL){
        if(temp->data == key){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

void reverse_linked_list(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    tail = head;
    head = prev;
}
int main(){
    push_front(10);
    push_front(20);
    push_front(30);
    push_back(40);
    insert_middle(35,1);
    display_list();
    reverse_linked_list();
    display_list();
    return 0;
}