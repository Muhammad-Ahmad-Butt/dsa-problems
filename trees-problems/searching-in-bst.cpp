#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else if(val >= root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int key){
    if(root == NULL) return false;  // bst empty
    if(root->data == key) return true;  //  key found

    if(key < root->data){
        return search(root->left, key);
    }
    if(key > root->data){
        return search(root->right, key);
    }
    return false;
}

Node* build_bst(int arr[], int size){
    Node* root = NULL;
    for(int i = 0; i < size; i++){
       root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    int size = 6;
    int arr[] = {4, 2, 6, 1, 3, 5};
    Node* root = build_bst(arr, size);
    cout << search(root, 6);
    return 0;
}