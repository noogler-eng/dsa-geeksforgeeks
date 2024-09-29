// checked for balanced binary tree
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

// height of the bianry tree
int heightOfTree(Node* root){
    if(root == NULL) return 0;

    int heightOfLeft = heightOfTree(root->left);
    int heightOfRight = heightOfTree(root->right);
    return max(heightOfLeft, heightOfRight) + 1;
}

// for balanced binary tree ervery node, h(left) - h(right) <= 1
// means left can be greater then right but not smaller then right
// time compelxity is o(n * n)
bool isBalanced(Node* root){
    if (root == NULL) return true;
    return (heightOfTree(root->left) - heightOfTree(root->right) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}   


// direct methods on way finding the heght
// time complexity is o(n)
int heightOfTree___(Node* root){
    if(root == NULL) return 1;

    int heightOfLeft = heightOfTree___(root->left);
    int heightOfRight = heightOfTree___(root->right);
    
    // only calls when there is some error
    if(heightOfLeft == -1 || heightOfRight == -1) return -1;
    if(heightOfLeft - heightOfRight <= 1) return -1; 
    
    return max(heightOfLeft, heightOfRight) + 1;
}

int main(){
    // this is not balanced bianry tree
    Node* root_1 = new Node(3);
    root_1->left = new Node(9);
    root_1->right = new Node(20);
    root_1->right->left = new Node(15);
    root_1->right->right = new Node(7);

    // this one is balanced bianry tree
    Node* root_2 = new Node(1);
    root_2->left = new Node(3);
    root_2->right = new Node(2);
    root_2->left->left = new Node(5);
    root_2->left->right = new Node(4);
    root_2->left->left->left = new Node(7);
    root_2->left->left->right = new Node(6);

    bool ans = isBalanced(root_2);
    cout<<"isBalanced: "<<ans<<endl;
    return 0;
}