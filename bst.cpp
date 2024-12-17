#include <iostream>
using namespace std;

//height of bst

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int data){
            val = data;
            left = right = NULL;
        }
};

int findHeight(Node* root){
    if(root==NULL){
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight,rightHeight) + 1;
}

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

Node* delete(Node* root, int data){
    if(root==NULL){
        return root;
    }

    if(data<root->val){
        root->left = delete(root->left, data);
    } else if(data>root->val){
        root->right = delete(root->right, data);
    } else{
        // 1 child
        if(root->left==NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        } else if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // 2 children
        // inorder successor
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = delete(root->right,temp->val);
    }
    return root;
}

void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left); //l
        cout<<root->val<<" "; //n
        inOrder(root->right); //r
    }
}