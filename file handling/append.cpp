#include <bits/stdc++.h>
using namespace std;

int main(){
    ofstream myfile("main.txt",ios::app);
    if(myfile.is_open()){
        myfile<<"\nMy age is 19";
        myfile.close();
        cout<<"File read successfully";
    }
    else{
        cout<<"error while reading file";
    }
}