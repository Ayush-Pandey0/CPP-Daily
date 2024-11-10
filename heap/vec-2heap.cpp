#include <bits/stdc++.h>
using namespace std;

// Heapify function for downward maintenance of the min-heap
void downHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        downHeapify(heap, n, smallest);
    }
}

// Function to build the heap using downHeapify
void buildHeap(vector<int>& m, int heap[], int n) {
    for (int i = 0; i < n; i++) {
        heap[i] = m[i];
    }
    
    // Build the heap by calling downHeapify on non-leaf nodes
    for (int i = (n / 2) - 1; i >= 0; i--) {
        downHeapify(heap, n, i);
    }

    // Output the heap after building
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, p;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    cin >> p; // Input threshold age

    int heap[100];
    buildHeap(m, heap, n);

    // Count elements in the heap less than the threshold age p
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (heap[i] < p) {
            count++;
        }
    }

    // Output the count of participants younger than the threshold
    cout << count << endl;

    return 0;
}
