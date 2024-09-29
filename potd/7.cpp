#include<iostream>
using namespace std;
// Given two binary trees, the task is to find if both of them are identical or not.

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


bool isIdentical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL || r2 == NULL) return false;

    // we have to return only true or false in one condition
    return (r1->data == r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
}


int main(){
    // binary tree formation
    Node* root_1 = new Node(1);
    root_1->left = new Node(2);
    root_1->right = new Node(3);

    Node* root_2 = new Node(1);
    root_2->left = new Node(2);
    root_2->right = new Node(3);

    bool isBothIdentical = isIdentical(root_1, root_2);
    cout<<isBothIdentical<<endl;
    return 0;
}