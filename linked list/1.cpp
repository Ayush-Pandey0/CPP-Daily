#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node* back;
    node(int data,node* next,node* back){
        this->back=back;
        this->data=data;
        this->next=next;
    }
    node(int data){
        this->data=data;
        this->back=this->next=nullptr;
    }
};
node* vec2ll(vector <int> vec){
    if(vec.empty()) return nullptr;
    node* head=new node(vec[0]);
    node* prev=head;
    for(int i=1;i<vec.size();i++){
        node* temp=new node(vec[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    vector <int> vec={3,2,5,6,2};
    node* head=vec2ll(vec);
    print(head);
}