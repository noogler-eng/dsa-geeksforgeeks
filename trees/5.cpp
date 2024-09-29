// maximum depth of any given binary tree
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

// time complexity is o(n)
// space complexity is o(n)
int maximumDepth(Node* root){
    if( root == NULL ) return 0;

    int heightOfLeft = maximumDepth(root->left);
    int heightOfRight = maximumDepth(root->right);
    return max(heightOfLeft, heightOfRight) + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    if(root == NULL) return 0;

    int ans = maximumDepth(root);
    cout<<"max depth: "<<ans<<endl;
    return 0;
}