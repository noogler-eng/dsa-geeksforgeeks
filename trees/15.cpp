// search in the binary search tree
// search a node in BST

#include<iostream>
using namespace std;
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
bool BST(Node* root, int key){
    
    // here structure of if-else is important as no two steps can run smae time or in same loop
    while(root != NULL){
        if(root->data == key) return true;
        else if(root->data > key) root = root->left;
        else root = root->right;
    }
    return false;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int key = 4;

    bool ans = BST(root, key);
    cout<<ans<<endl;
    return 0;
}