#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Stack{
public:
    Node* top;
    Stack(){
        top = NULL;
    }
    
    void push(int data){
        Node* temp = new Node(data);
        if(top==NULL){
            top = temp;
        }
        top = top->next;
        top = temp;
    }
    
    void pop(){
        while(top!=NULL){
            Node* curr= top;
            top = top->next;
            free(curr);
        }
    }
    
    int peek(){
        while(top!=NULL){
            return top->val;
        }
    }
};

void preorder(Node* root){
    while(root!=NULL){
        Stack s;
        s.push(root);
        
        while(!s.empty()){
            Node* temp = s.peek();
            s.pop();
            cout<<temp->val<<" ";
            
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
        }
    }
}

void inorder(Node* root){
    Stack s;
    Node* curr = root;
    
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
    }
    
    curr = s.peek();
    s.pop();
    cout<<curr->val<<endl;
    
    curr = curr->right;
}

void postorder(Node* root){
    while(root!=NULL){
        Stack s1;
        Stack s2;
        s1.push(root);
        
        while(!s1.empty()){
            Node* temp = s1.peek();
            s1.pop();
            s2.push(temp);
            
            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
        }
        
        while(!s2.empty()){
            cout<<s2.peek()<<" ";
            s2.pop();
        })
    }
}