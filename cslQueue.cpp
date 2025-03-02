#include <iostream>
using namespace std;

class Node {
public:
    int val;      // Data stored in the node
    Node* next;    // Pointer to the next node

    Node(int data) {
        val = data;
        next = NULL; // Initialize next to NULL
    }
};

class Queue {
private:
    Node* front;   // Pointer to the front node
    Node* rear;    // Pointer to the rear node

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = NULL; // Initialize both front and rear to NULL
    }

    // Function to add an item to the queue
    void enqueue(int data) {
        Node* temp = new Node(data); // Create a new node
        if (rear == NULL) { // If the queue is empty
            front = rear = temp; // Both front and rear point to the new node
            rear->next = front; // Point rear's next to front (circular link)
        } else {
            rear->next = temp; // Link old rear to new node
            rear = temp;       // Update rear to point to new node
            rear->next = front;   // Maintain circular link
        }
        cout << data << " enqueued to queue." << endl;
    }

    // Function to remove an item from the queue
    int dequeue() {
        if (front == NULL) { // If the queue is empty
            cout << "Queue Underflow! Unable to dequeue." << endl;
            return -1; // Return -1 for underflow condition
        }
        int delValue = front->val; // Get the front item
        Node* temp = front;     // Store the front node temporarily
        
        if (front == rear) {    // If there's only one element in the queue
            front = rear = NULL; // Queue becomes empty after dequeue
        } else {
            front = front->next;  // Move front to the next node
            rear->next = front;   // Maintain circular link
        }
        
        delete temp;           // Free memory of dequeued node
        return delValue;           // Return dequeued item
    }

    // Function to return the front item from the queue without removing it
    int peek() {
        if (front == NULL) { // If the queue is empty
            cout << "Queue is empty." << endl;
            return -1; // Return -1 if queue is empty
        }
        return front->val;  // Return front item
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL; // True if front is NULL, meaning queue is empty
    }

    // Destructor to free allocated memory
    ~Queue() {
        while (!isEmpty()) {  // Free all nodes in the queue
            dequeue();
        }
    }
};

int main() {
    Queue q; // Create a queue

    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                value = q.dequeue();
                if (value != -1) {  // Only print if a valid dequeue occurred
                    cout << "Dequeued element: " << value << endl;
                }
                break;

            case 3:
                value = q.peek();
                if (value != -1) {  // Only print if queue is not empty
                    cout << "Front element: " << value << endl;
                }
                break;

            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
