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
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* build_bst(int size, int arr[]){
    Node* root = NULL;
    for(int i = 0; i < size; i++){
        root = insert(root, arr[i]);
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

Node* get_inorder_successor(Node* root){
    
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delete_node(Node* root, int key){
    if(root == NULL){
        return NULL;    //  return root;
    }

    if(key < root->data){
        root->left = delete_node(root->left, key);
    } else if(key > root->data){
        root->right = delete_node(root->right, key);
    } else {
        // key == root->data
        // actual deletion
        if(root->left == NULL) {    //  0 or 1 child
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        } else {    // 2 child case
            Node* is = get_inorder_successor(root->right);
            root->data = is->data;
            root->right = delete_node(root->right, is->data);
        }
    }
    return root;
}

void inorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
int main(){
    int size = 6;
    int arr[] = {3, 2, 1, 5, 6, 4};
    Node* root = build_bst(size, arr);
    inorder_traversal(root);
    cout << endl;

    delete_node(root, 6);
    inorder_traversal(root);
    cout << endl;
    return 0;
}