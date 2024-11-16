#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void swap(int* a, int* b) {
    //Type your code here
}

void heapify(int arr[], int size, int root) {
    //Type your code here
}


void heapSort(int arr[], int size) {
    //Type your code here
    sort(arr,arr+size);
}

int* filterBelow30(int arr[], int size, int* count) {
    //Type your code here
    *count = 0;
    for(int i=0;i<size;i++){
        if(arr[i]<30){
            arr[*count] = arr[i];
            (*count)++;
        }
    }
    return arr;
}
int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int countBelow30;
    int* below30 = filterBelow30(arr, size, &countBelow30);
    heapSort(below30, countBelow30);
    for (int i = 0; i < countBelow30; i++) {
        cout << below30[i] << " ";
    }
    delete[] arr;
    delete[] below30;
    return 0;
}