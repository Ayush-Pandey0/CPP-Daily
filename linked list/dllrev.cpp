#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node* back;
    node(int data,node* next,node* back){
        this->data=data;
        this->next=next;
        this->back=back;
    }
    node(int data){
        this->data=data;
        this->next=this->back=nullptr;
    }
};
node* vec2dll(vector <int> vec){
    node* head=new node(vec[0]);
    node* mover=head;
    for(int i=1;i<vec.size();i++){
        node* temp=new node(vec[i],nullptr,mover);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* rvdll(node* head){
    /*    this is using stack and has time complexity of o(2n) and space complexity of o(n)
    stack <int> st;
    node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;*/

    if(head==NULL||head->next==NULL) return head;  
    node*last=NULL;
    node* current=head;
    while(current!=NULL){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    if (last != nullptr) {
        head = last->back;
    }
    return head;
}
int main(){
    vector <int> vec={3,4,2,5,7};
    node* head=vec2dll(vec);
    cout<<"original ll: "<<endl;
    print(head);
    cout<<"new ll: "<<endl;
    head=rvdll(head);
    print(head);
}