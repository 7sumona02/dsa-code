#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class dLL {
public:
    Node* head;
    Node* tail;
    int size;
    dLL() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = tail = temp;
        } else {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    bool isEmpty() {
        return size == 0;
    }

    int deleteAtHead() {
        if (!isEmpty()) {
            Node* temp = head;
            int delValue = temp->val;

            if (head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }

            delete temp;
            size--;
            return delValue;
        }
    }

    int deleteAtTail() {
        if (!isEmpty()) {
            Node* temp = tail;
            int delValue = temp->val;

            if (head == tail) {
                head = tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }

            delete temp;
            size--;
            return delValue;
        }
    }

    int deleteNodeByValue(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete.\n";
        return -1; // Indicating failure
    }

    Node* current = head;

    // Search for the node with the specified value
    while (current != NULL) {
        if (current->val == value) {
            int delValue = current->val;

            // If it's the only node in the list
            if (current == head && current == tail) {
                head = tail = NULL;
            } else if (current == head) { // If it's the head node
                head = head->next;
                head->prev = NULL;
            } else if (current == tail) { // If it's the tail node
                tail = tail->prev;
                tail->next = NULL;
            } else { // Node is in the middle
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current; // Free memory
            size--;
            return delValue; // Return the deleted value
        }
        current = current->next; // Move to next node
    }

    cout << "Value " << value << " not found in the list.\n";
    return -1; // Indicating failure
}


    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->val == x) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not found\n";
    }

    Node* reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void removeDuplicates(Node* &head){
    if(head==NULL){
        return;
    }
    
    Node* curr = head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->val==curr->next->val){
            Node* dup = curr->next;
            curr->next = curr->next->next;
            if(curr->next!=NULL){
                curr->next->prev = curr;
            }
            free(curr->next);
        } else{
            curr = curr->next;
        }
    }
}

    // Function to delete a node by position
    void deleteNodeByPosition(int position) {
        if (head == nullptr) return; // List is empty

        if (position == 0) { // Delete at head
            deleteAtHead();
            return;
        }

        Node* current = head;
        int currPos = 0;

        while (current != nullptr && currPos < position) {
            current = current->next;
            currPos++;
        }

        if (current == nullptr) { 
            cout << "Position out of bounds" << endl; 
            return; 
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next; // Unlink from previous
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev; // Unlink from next
        }

        delete current; // Free memory
    }
};

int main() {
    dLL d;
    int choice, val;

    while (true) {
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete at Head\n";
        cout << "4. Delete at Tail\n";
        cout << "5. Display\n";
        cout << "6. Search\n";
        cout << "7. Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            d.insertAtHead(val);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> val;
            d.insertAtTail(val);
            break;
        case 3:
            d.deleteAtHead();
            break;
        case 4:
            d.deleteAtTail();
            break;
        case 5:
            d.display();
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            d.search(val);
            break;
        case 7:
            cout << "reversed: ";
            d.reverse();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } 

    return 0;
}