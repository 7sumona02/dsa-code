// min element in bst

#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* right;
        Node* left;
        Node(int data){
            val = data;
            right = NULL;
            left = NULL;
        }
};

int findMin(Node* root){
    if(!root){
        cout<<"empty"<<endl;
        return -1;
    }

    Node* curr = root;
    while(curr->left!=NULL){
        curr = curr->left;
    }
    return curr->val;
}

Node* insert(Node* root, int data){
    Node* temp = new Node(data);
    if(root==NULL){
        root = temp;
    }
    if(data<root->val){
        root->left = insert(root->left,data);
    } else if(data>root->val){
        root->right = insert(root->right,data);
    }
    return root;
}

int main(){

    return 0;
}