#include <iostream>
using namespace std;

#define SIZE 5  // fixed stack size

struct Stack {
    int arr[SIZE];
    int top;

    Stack() {
        top = -1;
    }

    // Push element
    void push(int val) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = val;
            cout << val << " pushed to stack\n";
        }
    }

    // Pop element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top--] << " popped from stack\n";
        }
    }

    // Peek top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();

    return 0;
}
