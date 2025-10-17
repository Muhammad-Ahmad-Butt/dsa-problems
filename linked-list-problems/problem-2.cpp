// Write C++ code to Copy all elements of Linked List to an array.
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
void input_linked_list(int n){
    for(int i = 0; i < n; i++){
        int val;
        cout << "Enter a value for index " << i << " and " << i + 1 << " element: ";
        cin >> val;
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void linked_list_to_array(int* arr, int n){
    Node* temp = head;
    for(int i = 0; i < n; i++){

        if(head == NULL){
            cout << "no list elements to copy";
            return;
        } else {    
            arr[i] = temp->data;
            temp = temp->next;
            
        }
    }
}

void display_linked_list(){
    Node* temp = head;
    if(temp == NULL){
        cout << "list is empty";
        return;
    } else {
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL " << endl;
    }
}

void dipslay_array(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n = 0;
    cout << "Enter the size of the list: ";
    cin >> n;
    int* arr = new int[n];

    input_linked_list(n);
    display_linked_list();   

    linked_list_to_array(arr, n);
    dipslay_array(arr, n);
    return 0;
}