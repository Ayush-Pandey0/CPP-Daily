#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int heap[],int size){
    int i=size;
    int parent=(i-1)/2;
    while(i>0&&heap[parent]>heap[i]){
        swap(heap[parent],heap[i]);
        i=parent;
        parent=(i-1)/2;
    }
}
void insertElement(int heap[],int &size,int value,int capacity){
    heap[size]=value;
    heapify(heap,size);
    size++;
}
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int findMaxValue(int heap[], int size)
{   int max=heap[0];
    for(int i=1;i<size;i++){
        if(max<heap[i]){
            max=heap[i];
        }
    }
    return max;
}
int main() {
    int n;
    cin >> n;

    int capacity = n; 
    int heap[capacity]; 
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, capacity);
    }

    displayMinHeap(heap, size);

    int maxValue = findMaxValue(heap, size);
    cout << "Maximum: " << maxValue;

    return 0;
}