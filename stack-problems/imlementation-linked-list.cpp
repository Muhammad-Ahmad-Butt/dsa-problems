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
struct Stack {
    Node* top;

    Stack(){
        top = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(top == NULL){
            top = newNode;
            return;
        } else {
            newNode -> next = top;
            top = newNode;
        }
    }

    void pop(){
        if(top == NULL){
            cout << "underflow" << endl;
            return;
        } else {
            Node* temp = top;
            cout << top->data << " popped\n";
            top = top -> next;
            delete temp;
        }
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1; // or throw
        }
        return top->data;
    } 

    void display(){
        Node* temp = top;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout << "\n";
    }
};


int main(){
     Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    s.pop();
    s.display();
    return 0;
}