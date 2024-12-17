#include <iostream>
using namespace std;

class Node{
    public:
        int coeff;
        int pow;
        Node* next;
        Node(int c,int p){
            coeff = c;
            pow = p;
            next = NULL;
        }
};

class Polynomial{
    public:
        Node* head;
        Polynomial(){
            head = NULL;
        }

        void insert(int c, int p){
            Node* temp = new Node(c,p);

            if(!head){
                head = temp;
            } else{
                Node* curr = head;
                while(curr->next){
                    curr = curr->next;
                }
                curr->next = temp;
            }
        }

        void display(){
            Node* curr = head;
            while(curr!=NULL){
                cout<<curr->coeff<<"^"<<curr->pow<<"->";
                curr = curr->next;
            }cout<<endl;
        }
};

int main(){
    Polynomial poly;
    poly.insert(5,2);
    poly.insert(8,0);

    poly.display();

    return 0;
}