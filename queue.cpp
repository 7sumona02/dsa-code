#include <iostream>
using namespace std;

const int max_size = 100; // Define the maximum size of the queue

class Queue {
public:
    int arr[max_size]; // Array to hold queue elements
    int front;         // Index of the front element in the queue
    int rear;          // Index of the rear element in the queue

    // Constructor to initialize the queue
    Queue() {
        front = rear = -1; // Initialize both front and rear to -1 indicating an empty queue
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1; 
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == max_size - 1; 
    }

    // Function to add an element to the queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // If the queue is empty, set front to 0
        }
        arr[++rear] = x; // Increment rear and add element
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1; // Return a sentinel value for underflow
        }
        int removedValue = arr[front]; // Get the value at the front
        if (front == rear) { // If there's only one element left
            front = rear = -1; // Reset both front and rear
        } else {
            front++; // Move front forward
        }
        return removedValue; // Return the removed value
    }

    // Function to peek at the front element of the queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return a sentinel value for empty queue
        }
        return arr[front]; // Return the front element
    }
};

int main() {
    Queue q; // Create a Queue object

    q.enqueue(10); // Enqueue elements into the queue
    q.enqueue(20);
    
    cout << "Front element is: " << q.peek() << endl; // Peek at the front element
    
    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeue an element from the queue
    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeue another element
    
    q.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}
