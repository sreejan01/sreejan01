#include <iostream>
using namespace std;

#define MAX 5  // Define the maximum size of the queue

int queue[MAX];  // Array to store queue elements
int front = -1, rear = -1;  // Initialize front and rear as -1 (empty queue)

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
bool isFull() {
    return rear == MAX - 1;
}

// Function to enqueue an element (insert at the rear of the queue)
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue " << value << endl;
    } else {
        if (front == -1) {  // If the queue is empty
            front = 0;  // Set front to 0
        }
        queue[++rear] = value;  // Increment rear and insert value
        cout << "Enqueued " << value << endl;
    }
}

// Function to dequeue an element (remove from the front of the queue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
    } else {
        cout << "Dequeued " << queue[front] << endl;
        front++;  // Move front pointer to the next element
        if (front > rear) {  // If all elements are dequeued, reset the queue
            front = rear = -1;
        }
    }
}

// Function to peek at the front element of the queue (without dequeuing)
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty. No front element." << endl;
    } else {
        cout << "Front element is " << queue[front] << endl;
    }
}

// Function to traverse and display all elements in the queue
void traverse() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// Function to search for an element in the queue
bool search(int value) {
    for (int i = front; i <= rear; i++) {
        if (queue[i] == value) {
            return true;  // Element found
        }
    }
    return false;  // Element not found
}

int main() {
    // Perform operations on the queue
    enqueue(10);  // Enqueue 10
    enqueue(20);  // Enqueue 20
    enqueue(30);  // Enqueue 30
    enqueue(40);  // Enqueue 40
    enqueue(50);  // Enqueue 50
    enqueue(60);  // Try enqueueing 60 (queue full)

    traverse();  // Traverse the queue

    peek();  // Peek at the front element

    dequeue();  // Dequeue one element
    dequeue();  // Dequeue another element

    traverse();  // Traverse the queue after dequeuing

    // Search for a value in the queue
    int searchValue = 30;
    if (search(searchValue)) {
        cout << "Value " << searchValue << " found in the queue." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the queue." << endl;
    }

    return 0;
}