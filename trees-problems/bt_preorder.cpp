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
static int idx = -1;
Node* buildTree(int arr[]){
    idx++;
    if(arr[idx] == -1){
        return NULL;
    }

    Node* root = new Node(arr[idx]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);

    return root;
}

void traverse_preorderly(Node* root){
    if(root == NULL){
        return;
    }

    cout << root-> data << " ";
    traverse_preorderly(root->left);
    traverse_preorderly(root-> right);
}
int main(){
    int arr[11] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(arr);
    
    traverse_preorderly(root);

    return 0;
}