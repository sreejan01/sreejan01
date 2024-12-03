#include<iostream>
using namespace std;
#define max 100

void push_(int *array, int &top, int n) {
    if (top == n - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        top++;
        cout << "Enter element to push: ";
        cin >> array[top];
    }
}

void pop_(int *array, int &top) {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << "Popped element: " << array[top] << endl;
        top--;
    }
}

void peak_(int *array, int top) {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Peak element is: " << array[top] << endl;
    }
}

void search_(int *array, int top) {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = 0; i <= top; i++) { // Changed i < top to i <= top
            cout << array[i] << endl;
        }
    }
}

int search_(int *array, int top, int element) {
    for (int i = 0; i <= top; i++) { // Changed i < top to i <= top
        if (array[i] == element) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int array[max];
    int top = -1; // Initialize top to -1 to indicate an empty stack
    int n;
    cout << "Enter the maximum number of elements in the stack: ";
    cin >> n;
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peak\n";
        cout << "4. Display Stack\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push_(array, top, n);
                break;
            case 2:
                pop_(array, top);
                break;
            case 3:
                peak_(array, top);
                break;
            case 4:
                search_(array, top);
                break;
            case 5: {
                int element;
                cout << "Enter element to search: ";
                cin >> element;
                int index = search_(array, top, element);
                if (index != -1) {
                    cout << "Element " << element << " found at index " << index << endl;
                } else {
                    cout << "Element " << element << " not found in the stack." << endl;
                }
                break;    
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);
    
    return 0;
}