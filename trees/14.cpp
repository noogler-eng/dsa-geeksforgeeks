// check for symmetrical tree, wheather the tree is symmetryical or not
// formaing an mirror around its center

//          1
//      2       2
//  3      5 5       3
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

bool isMirror(Node* root_1, Node* root_2){
    if(root_1 == NULL && root_2 == NULL) return true;
    if(root_1 == NULL || root_2 == NULL) return false;

    return (root_1->data == root_2->data && isMirror(root_1->left, root_2->right) && isMirror(root_1->right, root_2->left));
}

bool isSymmetric(Node* root){
    // mirror concept of two tree
    bool isTreeSymmetric = isMirror(root->left, root->right);
    return isTreeSymmetric;
}

int main(){
    Node* root_1 = new Node(1);
    root_1->left = new Node(2);
    root_1->right = new Node(3);
    root_1->left->left = new Node(4);
    root_1->left->right = new Node(5);
    root_1->right->left = new Node(6);
    root_1->right->right = new Node(7);

    Node* root_2 = new Node(1);
    root_2->left = new Node(2);
    root_2->right = new Node(2);
    root_2->left->right = new Node(3);
    root_2->right->left = new Node(3);

    // right base conditions for tree in gfg

    cout<<"tree_1: "<<isSymmetric(root_1)<<endl;
    cout<<"tree_2: "<<isSymmetric(root_2)<<endl;
    return 0;
}