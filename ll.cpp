#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    Node(int data) {
        val = data;
        next = NULL;
    }
};

// Insert a new node at the head of the list
void insertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Insert a new node after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        return;
    }
    Node* temp = new Node(data);
    temp->next = prevNode->next;
    prevNode->next = temp;
}

// Delete the node at the head of the list
void deleteAtHead(Node*& head) {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;  // Use delete instead of free for C++
}

// Delete the node after the given node
void deleteAfter(Node*& prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        return;
    }
    prevNode->next = prevNode->next->next;
    delete prevNode->next;  // Use delete instead of free for C++
}

// Reverse the linked list
void reverse(Node*& head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {  // Fixed typo: "whle" to "while"
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

// Insert a new node at the tail of the list
void insertAtTail(Node*& head, int data) {
    Node* temp = new Node(data);
    
    if (head == NULL) {  // If the list is empty
        head = temp;
        return;
    }

    Node* current = head;  // Traverse to the end of the list
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = temp;  // Link the new node at the end
}

// Traverse and print the linked list
void traverseList(Node* head) {
    Node* current = head;
    
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    
    cout << endl;  // Print a newline at the end
}

// Search for a node with a specific key
Node* searchNode(Node* head, int key) {  // Changed return type to Node*
    Node* current = head;

    while (current != NULL) {
        if (current->val == key) {
            return current;  // Return found node
        }
        current = current->next;
    }
    
    return NULL;  // Return NULL if not found
}

void deleteNodeByValue(Node*& head, int value) {
    if (head == NULL) {
        return; // List is empty
    }

    // Handle deletion of the head node
    if (head->val == value) {
        deleteAtHead(head);
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    // Traverse the list to find the node to delete
    while (current != NULL && current->val != value) {
        previous = current;
        current = current->next;
    }

    // If the node was found, unlink it from the list
    if (current != NULL) {
        previous->next = current->next;
        delete current; // Free memory
    }
}

int getIthElement(Node* head, int pos){
    Node* curr = head;
    for(int i=0; i<pos; i++){
        if(curr == NULL){
            return -1;
        }
        curr = curr->next;
        if(curr!=NULL){
            return curr->val;
        }
        return -1;
    }
}


int main() {
    Node* head = NULL;

    // Example usage:
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    
    cout << "List after inserting at head: ";
    traverseList(head);
    
    insertAtTail(head, 30);
    
    cout << "List after inserting at tail: ";
    traverseList(head);
    
    insertAfter(head, 25);  // Insert after first node (20)
    
    cout << "List after inserting after first node: ";
    traverseList(head);

    reverse(head);
    
    cout << "List after reversing: ";
    traverseList(head);

    deleteAtHead(head);
    
    cout << "List after deleting at head: ";
    traverseList(head);

   return 0;  
}