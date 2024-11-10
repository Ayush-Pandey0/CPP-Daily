#include <bits/stdc++.h>
using namespace std;

// Definition of a tree node
class node {
    public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Preorder Traversal: Root -> Left -> Right
void preorder(node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

// Inorder Traversal: Left -> Root -> Right
void inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);        // Traverse left subtree
    cout << root->data << " ";  // Visit root
    inorder(root->right);       // Traverse right subtree
}

// Postorder Traversal: Left -> Right -> Root
void post(node* root) {
    if (root == nullptr) return;
    post(root->left);           // Traverse left subtree
    post(root->right);          // Traverse right subtree
    cout << root->data << " ";  // Visit root
}

// Level Order Traversal (BFS)
void level(node* root) {
    if (root == nullptr) return;

    queue<node*> q;     // Queue to store nodes at each level
    q.push(root);       // Start with the root node

    while (!q.empty()) {
        node* current = q.front();  // Get the front node
        q.pop();                    // Remove it from the queue

        cout << current->data << " ";  // Visit current node

        // Push left child to the queue if it exists
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Push right child to the queue if it exists
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    // Creating the binary tree
    struct node* root = new node(1);
    root->left = new node(3);
    root->right = new node(5);
    root->left->right = new node(9);

    // Perform different tree traversals
    cout << "Preorder Traversal: ";
    preorder(root);  // Preorder
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);   // Inorder
    cout << endl;

    cout << "Postorder Traversal: ";
    post(root);      // Postorder
    cout << endl;

    cout << "Level Order Traversal: ";
    level(root);     // Level order (BFS)
    cout << endl;

    return 0;
}
