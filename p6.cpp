#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int data){
            val = data;
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
            temp->next = top;
            top = temp;
        }

        void pop(){
            while(top!=NULL){
                Node* temp = top
                top = top->next;
                free(temp);
            }
        }

        int peek(){
            if(top==NULL){
                cout<<"empty"<<endl;
            }
            return top->val;
        }

        bool empty(){
            return top==NULL;
        }
};

class QueueUsingStacks{
    public:
        Stack s1;
        Stack s2;

        void transfer(){
            while(!s1.empty()){
                s2.push(s1.peek());
                s1.pop();
            }
        }

        void enqueue(int data){
            s1.push(data);
        }

        int dequeue(){
            if(s2.empty()){
                if(s1.empty()){
                    cout<<"empty"<<endl;
                }
                transfer();
            }
            int delVal = s2.peek();
            s2.pop();
            return delVal;
        }

        bool empty(){
            return s1.empty() && s2.empty();
        }
};