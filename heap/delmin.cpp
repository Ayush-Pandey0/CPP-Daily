#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void swap(int& a, int& b) {
    int t=a;
    a=b;
    b=t;
    
}
void minHeapify(int arr[], int size, int i) {
    int min=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size&&arr[left]<arr[min]){
        min=left;
    }
    if(right<size&&arr[right]<arr[min]){
        min=right;
    }
    if(min!=i){
        swap(arr[min],arr[i]);
        minHeapify(arr,size,min);
    }
}

void buildMinHeap(int arr[], int size) {
    //Type your code here
    for(int i=size/2-1;i>=0;i--){
        minHeapify(arr,size,i);
    }
    
}

void deleteElement(int arr[], int* size, int key) {
    int index=-1;
    for(int i=0;i<*size;i++){
        if(arr[i]==key){
            index=i;
            break;
        }
    }
    if(index==-1) return;
    swap(arr[index],arr[*size-1]);
    (*size)--;
    minHeapify(arr,*size,index);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    scanf("%d", &key);

    buildMinHeap(arr, n);

    deleteElement(arr, &n, key);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}