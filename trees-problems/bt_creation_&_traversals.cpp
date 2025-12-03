#include <iostream>
#include <queue> // to traverse // levelorderly
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

void traverse_inorderly(Node* root){
    if(root == NULL) return;

    traverse_inorderly(root->left);
    cout << root->data << " ";
    traverse_inorderly(root->right);
}

void traverse_postorderly(Node* root){
    if(root == NULL) return;

    traverse_postorderly(root->left);
    traverse_postorderly(root->right);
    cout << root->data << " ";
}

void traverse_levelorderly(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        
        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}
int main(){
    int arr[11] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(arr);
    
    // traverse_preorderly(root);
    // cout << " preorderly" << endl;
    // traverse_inorderly(root);
    // cout << " inorderly" << endl;
    // traverse_postorderly(root);
    // cout << " postorderly" << endl;
    
    traverse_levelorderly(root);
    cout << " levelorderly" << endl; 
    return 0;
}