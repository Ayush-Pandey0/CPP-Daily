#include <bits/stdc++.h>
using namespace std;
int main(){
    fstream myfile("main.txt");
    if(myfile.is_open()){
        string s;
        while(getline(myfile,s)){
            cout<<s<<endl;
        }
        cout<<"File read successfully";
        myfile.clear();
        myfile.seekp(0,ios::end);
        myfile<<"This is written using seekp"<<endl;
        myfile.close();
    }
    else{
        cout<<"Error";
    }
}