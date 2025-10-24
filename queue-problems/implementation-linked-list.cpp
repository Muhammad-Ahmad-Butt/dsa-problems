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

struct Queue{
    Node* front;
    Node* rear;

    Queue(){
        front = rear = NULL;
    }

    void enqueue(int val){
        Node* newNode = new Node(val);
        if(front == NULL){
            front = rear = newNode;
            return;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(front == NULL){
            cout << "empty\n";
            return;
        }
        Node* temp = front;
        cout << front-> data << " dequeued\n";
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete temp;

    }

    int peek(){
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    void display(){
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;
    return 0;
}