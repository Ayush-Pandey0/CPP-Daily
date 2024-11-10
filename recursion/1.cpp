#include <bits/stdc++.h>
using namespace std;
void f(int i,int n){
    if(i>n) return;
    else{
        cout<<"Ayush"<<endl;
        f(i+1,n);
    }
}
int main(){
    int n=5;
    cout<<endl;
    cout<<"N times: "<<endl;
    f(1,n);
}