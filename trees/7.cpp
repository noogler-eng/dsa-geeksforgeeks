// diameter of bianry tree
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

// this is the longest path between any two nodes
// this path not need to pass via by root
int getsDiameter(Node* root){
    if(root == NULL) return 0;

    int diameter = heightOfTree(root->left) + heightOfTree(root->right) + 1;
    return max(getsDiameter(root->left), max(getsDiameter(root->right), diameter));
}

int main(){
    Node* root_1 = new Node(1);
    root_1->left = new Node(2);
    root_1->right = new Node(3);
    root_1->left->left = new Node(4);
    root_1->left->right = new Node(5);

    Node* root_2 = new Node(1);
    root_2->left = new Node(2);
    root_2->right = new Node(3);
    root_2->right->left = new Node(4);
    root_2->right->right = new Node(7);
    root_2->right->left->left = new Node(5);
    root_2->right->left->left->left = new Node(5);
    root_2->right->right->right = new Node(8);
    root_2->right->right->right->right = new Node(9);

    int ans = getsDiameter(root_2);
    cout<<ans<<endl;
    return 0;
}