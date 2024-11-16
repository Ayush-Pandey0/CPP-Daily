#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void swap(int arr[], int a, int b) {
    //Type your code here
}

void maxHeapify(int arr[], int n, int i) {
    //Type your code here
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
}

void insertIntoMaxHeap(int arr[], int &n, int value) {
    //Type your code here
    arr[n]=value;
    int index=n;
    n++;
    while(index>0&&arr[(index-1)/2]<arr[index]){
        swap(arr[(index-1)/2],arr[index]);
        index=(index-1)/2;
    }
    
}

void printMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, n, value);
    }
    buildMaxHeap(arr, n);
    printMaxHeap(arr, n);
    if (n > 0) {
        int sum = arr[0] + arr[n - 1]; 
        cout << sum;
    } else {
        cout << "Heap is empty";
    }
    return 0;
}