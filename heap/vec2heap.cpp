// You are using GCC   
// 9
// 5 3 8 2 9 1 7 6 4
#include <bits/stdc++.h>
using namespace std;
void heapify(int heap[],int n){
    int parentindex=(n-1)/2;
    while(n>0&&heap[n]<heap[parentindex]){
        swap(heap[n],heap[parentindex]);
        n=parentindex;
        parentindex=(n-1)/2;
    }
}
void buildheap(vector <int> m,int heap[],int n){
    int size=0;       
    for(int i=0;i<n;i++){
        heap[size]=m[i];
        heapify(heap,size);
        size++;
    } 
    for(int i=0;i<size;i++){
        cout<< heap[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int k;
    vector<int> m;
    for(int i=0;i<n;i++){
        cin>>k;
        m.push_back(k);
    }
    int heap[100];
    buildheap(m,heap,n);
}