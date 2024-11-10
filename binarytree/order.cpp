#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=nullptr;
    }
};
void preorder(node* head){
    if(head==nullptr) return;
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);

}
void postorder(node* head){
    if(head==nullptr){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}
void Inorder(node* head){
    if(head==nullptr){
        return;
    }
    Inorder(head->left);
    cout<<head->data<<" ";
    Inorder(head->right);
}
int main(){
    node* root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    Inorder(root);
}