#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert_node(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val < root->data){
        root->left = insert_node(root->left, val);

    } else if(val > root->data){
        root->right = insert_node(root->right, val);
    }
    return root;
}

Node* build_bst(int size, int arr[]){
    Node* root = NULL;
    for(int i = 0; i < size; i++){
        root = insert_node(root, arr[i]);
    }
    return root;
}

bool search_node(Node* root, int key){
    if(root == NULL) return false;  // bst empty
    if(root->data == key) return true;  //  key found

    if(key < root->data){
        return search_node(root->left, key);
    }
    if(key > root->data){
        return search_node(root->right, key);
    }
    return false;
}



void inorder_traversal(Node* root){
    if(root == NULL) return;

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
int main(){
    int size = 6;
    int arr[size] = {5, 6, 4, 7, 1, 10};
    Node* root = build_bst(size, arr);
    search_node(root, 4);
    inorder_traversal(root);

    return 0;
}