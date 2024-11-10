#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// Function to minHeapify a subtree rooted at index `i`
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is smaller than root
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    // If right child is smaller than smallest
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // If smallest is not root, swap and heapify
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Function to build a Min-Heap from an array
void buildMinHeap(int arr[], int size) {
    // Start from the last non-leaf node and heapify each node
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(arr, size, i);
    }
}

// Function to delete the root (minimum element) of the Min-Heap
void deleteElement(int arr[], int& size, int key) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    // Find the index of the element to be deleted
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    // If the element was not found
    if (index == -1) {
        cout << "Element not found in the heap." << endl;
        return;
    }

    // Swap the element with the last element in the heap
    swap(arr[index], arr[size - 1]);

    // Decrease the size of the heap
    size--;

    // Heapify the root or the affected node to maintain heap property
    minHeapify(arr, size, index);
}

// Function to print the heap (array representation)
void printHeap(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n; // Input size of the array

    int heap[n];
    // Input the array
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }

    // Build the Min-Heap
    buildMinHeap(heap, n);

    // Output the Min-Heap after building it
    cout << "Min-Heap: ";
    printHeap(heap, n);

    // Deleting an element from the heap
    int key;
    cin >> key;  // Element to delete
    deleteElement(heap, n, key);

    // Output the Min-Heap after deletion
    cout << "Min-Heap after deletion: ";
    printHeap(heap, n);

    return 0;
}
