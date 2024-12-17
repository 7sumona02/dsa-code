#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int data){
            val = data;
            next = NULL;
        }
};

int findSum(Node* head){
    int sum = 0;
    Node* temp = head;
    while(temp!=NULL){
        sum += temp->val;
        temp = temp->next;
    }
    return sum;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout<<findSum(head)<<endl;

    return 0;
}