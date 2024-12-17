#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    int itemno;
    char itemname[10];
    Node* next;
};

void QUEUEL(Node* &front, Node* &rear){
    if(front==NULL){
        return;
    }
    Node* temp = front;
    cout<<temp->itemno<<endl;
    cout<<temp->itemname<<endl;

    front = front->next;
    free(temp);
}