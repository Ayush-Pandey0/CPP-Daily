#include<bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
    ifstream myfile("main.txt");
    if(myfile.is_open()){
        string s;
        while(getline(myfile,s)){
            cout<<s<<endl;
        }
        cout<<"File read successfully";
        myfile.close();
    }
    else{
        cout<<"Error while reading the file";
    }
}