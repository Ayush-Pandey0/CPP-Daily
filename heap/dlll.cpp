#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// Function to maintain Min-Heap property after inserting an element
void heapify(int heap[], int size) {
    int i = size;
    int parent = (i - 1) / 2;

    // Bubble up the element to restore the Min-Heap property
    while (i > 0 && heap[parent] < heap[i]) {
        swap(heap[parent], heap[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

// Function to build a Min-Heap from an array
void buildMinHeap(int arr[], int size) {
    // Apply heapify from the start to each element
    for (int i = 1; i < size; i++) {
        heapify(arr, i);
    }
}

// Function to delete an element from the Min-Heap
void deleteElement(int arr[], int& size, int key) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    // Find the index of the element to delete
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    // If element is not found, display message and return
    if (index == -1) {
        cout << "Element not found in the heap." << endl;
        return;
    }

    // Replace the element with the last element and decrease the heap size
    arr[index] = arr[size - 1];
    size--;

    // Restore the Min-Heap property after deletion
    if (index < size) {
        heapify(arr, index);
    }
}

// Function to print the heap
void printHeap(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int heap[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    // Build the Min-Heap
    buildMinHeap(heap, n);
    cout << "Min-Heap: ";
    printHeap(heap, n);

    // Delete an element from the Min-Heap
    int key;
    cout << "Enter element to delete: ";
    cin >> key;
    deleteElement(heap, n, key);

    cout << "Min-Heap after deletion: ";
    printHeap(heap, n);

    return 0;
}
