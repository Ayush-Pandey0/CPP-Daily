#include <bits/stdc++.h>
using namespace std;

// class Node{
//     public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// Node* insert(Node* root, int val){
//     if(root == NULL) return new Node(val);
//     if(val<root->val){
//         root->left = insert(root->left,val);
//     }
//     else{
//         root->right = insert(root->right,val);
//     }
//     return root;
// }
// void display(Node* root){
//     if(root == NULL) return;
//     display(root->left);
//     display(root->right);
//     cout<<root->val<<" ";
// }

// int main(){
//     int n;
//     Node* root = NULL;
//     do{
//        cin>>n; 
//        if(n>0){
//            root = insert(root,n);
//        }
//     }
//     while(n!=-1);
//     display(root);
    
// }