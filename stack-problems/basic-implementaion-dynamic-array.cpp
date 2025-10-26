#include <iostream>
using namespace std;
struct Stack {
    int* arr;
    int top;
    int size;

    Stack(int s = 5){
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int val){
        if(top == size - 1){
            cout << "Stack overflow!" << endl;
            return;
        }  else {
            arr[++top] = val;
            cout << val << "stored in stack!" << endl;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
        } else { 
            cout << arr[top--] << " popped from stack!" << endl;
        }
    }
    void peek(){
        if (top == -1) {
                cout << "Stack is empty" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }
    
    ~Stack() {  // Destructor to free memory
        delete[] arr;
        cout << "Stack memory released!" << endl;
    }
};

int main(){
    Stack s;       // default size = 5
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.pop();
    s.peek();
    return 0;
}