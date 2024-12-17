#include <iostream>
using namespace std;

const int max_size = 100; // Define the maximum size of the stack

class Stack {
public:
    int arr[max_size]; // Array to hold stack elements
    int top;           // Index of the top element in the stack

    // Constructor to initialize the stack
    Stack() {
        top = -1; // Initialize top to -1 indicating the stack is empty
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1; 
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == max_size - 1; 
    }

    // Function to push an element onto the stack
    void push(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
        }
        arr[++top] = x; // Increment top and add element
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
        }
        return arr[top--]; // Return top element and decrement top
    }

    // Function to peek at the top element of the stack without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value for empty stack
        }
        return arr[top]; // Return the top element
    }
};

int main() {
    Stack s; // Create a Stack object

    s.push(10); // Push elements onto the stack
    s.push(20);
    
    cout << "Top element is: " << s.peek() << endl; // Peek at the top element
    
    cout << "Popped element: " << s.pop() << endl; // Pop an element from the stack
    cout << "Popped element: " << s.pop() << endl; // Pop another element
    
    s.pop(); // Attempt to pop from an empty stack

    return 0;
}
