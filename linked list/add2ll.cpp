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
// node* addTwoNumbers(node* l1, node* l2) {
//         node *dummy = new node(-1); 
//         node *temp = dummy; 
//         int carry = 0;
//         while( (l1 != NULL || l2 != NULL) || carry) {
//             int sum = 0; 
//             if(l1 != NULL) {
//                 sum += l1->data; 
//                 l1 = l1 -> next; 
//             }
            
//             if(l2 != NULL) {
//                 sum += l2 -> data; 
//                 l2 = l2 -> next; 
//             }
//             sum += carry; 
//             carry = sum / 10; 
//             node *nde = new node(sum % 10); 
//                temp -> next = nde; 
//             temp = temp -> next; 
//         }
//         return dummy -> next; 
//     }
 node* addTwoNumbers(node* l1, node* l2) {
        node* dummyHead = new node(0);
        node* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->data : 0;
            int digit2 = (l2 != nullptr) ? l2->data : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            node* newNode = new node(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

    node* result = dummyHead->next;
    delete dummyHead;
    return result;
}
int main(){
    vector <int> vec={3,4,9 ,5,7};
    node* head1=vec2dll(vec);
    vector <int> vec2={3,4,2};
    node* head2=vec2dll(vec2);
    cout<<"new ll: "<<endl;
    node* ew=addTwoNumbers(head1,head2);
    print(ew);
}