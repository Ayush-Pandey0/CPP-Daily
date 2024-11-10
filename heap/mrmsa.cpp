// You are using GCC
#include <bits/stdc++.h>
using namespace std;
void heapify(int heap[],int n){
    int parent=(n-1)/2;
    while(n>=0&&heap[n]<heap[parent]){
        swap(heap[parent],heap[n]);
        n=parent;
        parent=(n-1)/2;
    }
}
void buildheap(int heap[],vector<int>& vec,int n){
    int size=0,sum=0;
    vector<int> mec;
    
    for(int i=0;i<n;i++){
        heap[size]=vec[i];
        heapify(heap,size);
        size++;
    }
    cout<<"Min Heap: ";
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    } 
    cout<<endl;
    cout<<"Root node: "<<heap[0]<<endl;
    
    for(int i=1;i<n;i++){
        sum+=heap[i];
        vec.push_back(heap[i]);
    } 
    sort(vec.begin(),vec.end(),greater<int>());
    cout<<"Maximum value: "<<vec[0]<<endl;
    cout<<"Sum of nodes: "<<sum<<endl;
    double av=(double)sum/(n-1);
    cout<<"Average of nodes: "<<setprecision(2)<<fixed<<av<<endl;
    
    
    
    
}
int main(){
    int n,k;
    cin>>n;
    vector <int> vec;
    for(int i=0;i<n;i++){
        cin>>k;
        vec.push_back(k);
    }
    int heap[100];
    buildheap(heap,vec,n);
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=heap[i];
    } 
    cout << "sadjhasd";
}
//hdagfhjdbfh

