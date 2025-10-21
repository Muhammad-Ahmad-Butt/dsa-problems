#include <iostream>
#include <list>
using namespace std;
struct Stack {
    list<int> ll;

    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int peek(){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}