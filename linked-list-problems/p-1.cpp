// Write C++ code to copy all elements of 1D array to Linked List
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

// functions 
void input_array(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << "Array element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void array_to_linked_list(int* arr, int n){

}
void display_array(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

void display_linked_list(int* arr, int n){

}
int main(){
    int n = 5;
    int* arr = new int[n];
    
    input_array(arr, n);
    display_array(arr, n);

    delete[] arr;
    return 0;
}