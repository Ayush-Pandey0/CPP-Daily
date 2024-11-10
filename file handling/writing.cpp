#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
    ofstream myfile("main.txt");
    if(myfile.is_open()){
        myfile<<"My name is ayush"<<endl;
        myfile<<"My title is pandey"<<endl;
        myfile.close();
        cout<<"File written successfully";
    }
    else{
        cout<<"Error while file handling";
    }
}