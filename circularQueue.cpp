#include <iostream>
using namespace std;

const int max_size = 100; // Define the maximum size of the queue

class CircularQueue {
public:
    int arr[max_size]; // Array to hold queue elements
    int front;         // Index of the front element in the queue
    int rear;          // Index of the rear element in the queue

    // Constructor to initialize the circular queue
    CircularQueue() {
        front = rear = -1; // Initialize both front and rear to -1 indicating an empty queue
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1; 
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % max_size == front; 
    }

    // Function to add an element to the circular queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // If the queue is empty, set both front and rear to 0
        } else {
            rear = (rear + 1) % max_size; // Increment rear circularly
        }
        arr[rear] = x; // Add element at rear position
    }

    // Function to remove an element from the circular queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1; // Return a sentinel value for underflow
        }
        int removedValue = arr[front]; // Get the value at the front
        if (front == rear) { // If there's only one element left
            front = rear = -1; // Reset both front and rear
        } else {
            front = (front + 1) % max_size; // Move front forward circularly
        }
        return removedValue; // Return the removed value
    }

    // Function to peek at the front element of the circular queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return a sentinel value for empty queue
        }
        return arr[front]; // Return the front element
    }
};

int main() {
    CircularQueue q; // Create a CircularQueue object

    q.enqueue(10); // Enqueue elements into the queue
    q.enqueue(20);
    
    cout << "Front element is: " << q.peek() << endl; // Peek at the front element
    
    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeue an element from the queue
    cout << "Dequeued element: " << q.dequeue() << endl; // Dequeue another element
    
    q.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}
