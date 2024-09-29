// Binary tree is given we have to convert it into mirror tree
#include<iostream>
using namespace std;

// this is how Node will be look like
class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// mirroring the tree
// left to be right
// right to be left
// space complexity is o(n)
// time complexity is o(n)
void mirror(Node* &root){
    if(root == NULL) return;

    Node* rootLeft = root->left;
    Node* rootRight = root->right;
    root->left = rootRight;
    root->right = rootLeft;
    mirror(rootLeft);
    mirror(rootRight);
}   

// inorder traversal print
void print(Node* &root){
    if(root == NULL) return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main(){
    // making of binary tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    if(root == NULL) return;

    mirror(root);
    print(root);
    return 0;
}